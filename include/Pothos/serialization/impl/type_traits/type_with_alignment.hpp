//  (C) Copyright John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef POTHOS_TT_TYPE_WITH_ALIGNMENT_INCLUDED
#define POTHOS_TT_TYPE_WITH_ALIGNMENT_INCLUDED

#include <Pothos/serialization/impl/mpl/if.hpp>
#include <Pothos/serialization/impl/preprocessor/list/for_each_i.hpp>
#include <Pothos/serialization/impl/preprocessor/tuple/to_list.hpp>
#include <Pothos/serialization/impl/preprocessor/cat.hpp>
#include <Pothos/serialization/impl/preprocessor/list/transform.hpp>
#include <Pothos/serialization/impl/preprocessor/list/append.hpp>
#include <Pothos/serialization/impl/type_traits/alignment_of.hpp>
#include <Pothos/serialization/impl/type_traits/is_pod.hpp>
#include <Pothos/serialization/impl/static_assert.hpp>
#include <Pothos/serialization/impl/config.hpp>

// should be the last #include
#include <Pothos/serialization/impl/type_traits/detail/bool_trait_def.hpp>

#include <cstddef>

#ifdef POTHOS_MSVC
#   pragma warning(push)
#   pragma warning(disable: 4121) // alignment is sensitive to packing
#endif

namespace Pothos {

#ifndef __BORLANDC__

namespace detail {

class alignment_dummy;
typedef void (*function_ptr)();
typedef int (alignment_dummy::*member_ptr);
typedef int (alignment_dummy::*member_function_ptr)();

#ifdef POTHOS_HAS_LONG_LONG
#define POTHOS_TT_ALIGNMENT_BASE_TYPES POTHOS_PP_TUPLE_TO_LIST( \
        12, ( \
        char, short, int, long,  ::Pothos::long_long_type, float, double, long double \
        , void*, function_ptr, member_ptr, member_function_ptr))
#else
#define POTHOS_TT_ALIGNMENT_BASE_TYPES POTHOS_PP_TUPLE_TO_LIST( \
        11, ( \
        char, short, int, long, float, double, long double \
        , void*, function_ptr, member_ptr, member_function_ptr))
#endif

#define POTHOS_TT_HAS_ONE_T(D,Data,T) Pothos::detail::has_one_T< T >

#define POTHOS_TT_ALIGNMENT_STRUCT_TYPES                         \
        POTHOS_PP_LIST_TRANSFORM(POTHOS_TT_HAS_ONE_T,             \
                                X,                              \
                                POTHOS_TT_ALIGNMENT_BASE_TYPES)

#define POTHOS_TT_ALIGNMENT_TYPES                                \
        POTHOS_PP_LIST_APPEND(POTHOS_TT_ALIGNMENT_BASE_TYPES,     \
                             POTHOS_TT_ALIGNMENT_STRUCT_TYPES)

//
// lower_alignment_helper --
//
// This template gets instantiated a lot, so use partial
// specialization when available to reduce the compiler burden.
//
#ifdef POTHOS_NO_TEMPLATE_PARTIAL_SPECIALIZATION
template <bool found = true>
struct lower_alignment_helper_impl
{
    template <std::size_t, class>
    struct apply
    {
        typedef char type;
        enum { value = true };
    };
};

template <>
struct lower_alignment_helper_impl<false>
{
    template <std::size_t target, class TestType>
    struct apply
      : public mpl::if_c<(alignment_of<TestType>::value == target), TestType, char>
    {
        enum { value = (alignment_of<TestType>::value == target) };
    };
};

template <bool found, std::size_t target, class TestType>
struct lower_alignment_helper
  : public lower_alignment_helper_impl<found>::template apply<target,TestType>
{
};
#else
template <bool found, std::size_t target, class TestType>
struct lower_alignment_helper
{
    typedef char type;
    enum { value = true };
};

template <std::size_t target, class TestType>
struct lower_alignment_helper<false,target,TestType>
{
    enum { value = (alignment_of<TestType>::value == target) };
    typedef typename mpl::if_c<value, TestType, char>::type type;
};
#endif

#define POTHOS_TT_CHOOSE_MIN_ALIGNMENT(R,P,I,T)                                  \
        typename lower_alignment_helper<                                        \
          POTHOS_PP_CAT(found,I),target,T                                        \
        >::type POTHOS_PP_CAT(t,I);                                              \
        enum {                                                                  \
            POTHOS_PP_CAT(found,POTHOS_PP_INC(I))                                 \
              = lower_alignment_helper<POTHOS_PP_CAT(found,I),target,T >::value  \
        };

#define POTHOS_TT_CHOOSE_T(R,P,I,T) T POTHOS_PP_CAT(t,I);

template <typename T>
struct has_one_T
{
  T data;
};

template <std::size_t target>
union lower_alignment
{
    enum { found0 = false };

    POTHOS_PP_LIST_FOR_EACH_I(
          POTHOS_TT_CHOOSE_MIN_ALIGNMENT
        , ignored
        , POTHOS_TT_ALIGNMENT_TYPES
        )
};

union max_align
{
    POTHOS_PP_LIST_FOR_EACH_I(
          POTHOS_TT_CHOOSE_T
        , ignored
        , POTHOS_TT_ALIGNMENT_TYPES
        )
};

#undef POTHOS_TT_ALIGNMENT_BASE_TYPES
#undef POTHOS_TT_HAS_ONE_T
#undef POTHOS_TT_ALIGNMENT_STRUCT_TYPES
#undef POTHOS_TT_ALIGNMENT_TYPES
#undef POTHOS_TT_CHOOSE_MIN_ALIGNMENT
#undef POTHOS_TT_CHOOSE_T

template<std::size_t TAlign, std::size_t Align>
struct is_aligned
{
    POTHOS_STATIC_CONSTANT(bool,
        value = (TAlign >= Align) & (TAlign % Align == 0)
        );
};

#ifdef POTHOS_NO_TEMPLATE_PARTIAL_SPECIALIZATION
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::detail::max_align,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::detail::lower_alignment<1> ,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::detail::lower_alignment<2> ,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::detail::lower_alignment<4> ,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::detail::lower_alignment<8> ,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::detail::lower_alignment<10> ,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::detail::lower_alignment<16> ,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::detail::lower_alignment<32> ,true)
#endif

} // namespace detail

#ifndef POTHOS_NO_TEMPLATE_PARTIAL_SPECIALIZATION
template<std::size_t Align>
struct is_pod< ::Pothos::detail::lower_alignment<Align> >
{
        POTHOS_STATIC_CONSTANT(std::size_t, value = true);
};
#endif

// This alignment method originally due to Brian Parker, implemented by David
// Abrahams, and then ported here by Doug Gregor.
namespace detail{

template <std::size_t Align>
class type_with_alignment_imp
{
    typedef ::Pothos::detail::lower_alignment<Align> t1;
    typedef typename mpl::if_c<
          ::Pothos::detail::is_aligned< ::Pothos::alignment_of<t1>::value,Align >::value
        , t1
        , ::Pothos::detail::max_align
        >::type align_t;

    POTHOS_STATIC_CONSTANT(std::size_t, found = alignment_of<align_t>::value);

    POTHOS_STATIC_ASSERT(found >= Align);
    POTHOS_STATIC_ASSERT(found % Align == 0);

 public:
    typedef align_t type;
};

}

template <std::size_t Align>
class type_with_alignment 
  : public ::Pothos::detail::type_with_alignment_imp<Align>
{
};

#if defined(__GNUC__)
namespace align {
struct __attribute__((__aligned__(2))) a2 {};
struct __attribute__((__aligned__(4))) a4 {};
struct __attribute__((__aligned__(8))) a8 {};
struct __attribute__((__aligned__(16))) a16 {};
struct __attribute__((__aligned__(32))) a32 {};
struct __attribute__((__aligned__(64))) a64 {};
struct __attribute__((__aligned__(128))) a128 {};
}

template<> class type_with_alignment<1>  { public: typedef char type; };
template<> class type_with_alignment<2>  { public: typedef align::a2 type; };
template<> class type_with_alignment<4>  { public: typedef align::a4 type; };
template<> class type_with_alignment<8>  { public: typedef align::a8 type; };
template<> class type_with_alignment<16> { public: typedef align::a16 type; };
template<> class type_with_alignment<32> { public: typedef align::a32 type; };
template<> class type_with_alignment<64> { public: typedef align::a64 type; };
template<> class type_with_alignment<128> { public: typedef align::a128 type; };

namespace detail {
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a2,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a4,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a8,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a16,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a32,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a64,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a128,true)
}
#endif
#if (defined(POTHOS_MSVC) || (defined(POTHOS_INTEL) && defined(_MSC_VER))) && _MSC_VER >= 1300
//
// MSVC supports types which have alignments greater than the normal
// maximum: these are used for example in the types __m64 and __m128
// to provide types with alignment requirements which match the SSE
// registers.  Therefore we extend type_with_alignment<> to support
// such types, however, we have to be careful to use a builtin type
// whenever possible otherwise we break previously working code:
// see http://article.gmane.org/gmane.comp.lib.boost.devel/173011
// for an example and test case.  Thus types like a8 below will
// be used *only* if the existing implementation can't provide a type
// with suitable alignment.  This does mean however, that type_with_alignment<>
// may return a type which cannot be passed through a function call
// by value (and neither can any type containing such a type like
// Boost.Optional).  However, this only happens when we have no choice 
// in the matter because no other "ordinary" type is available.
//
namespace align {
struct __declspec(align(8)) a8 { 
   char m[8]; 
   typedef a8 type;
};
struct __declspec(align(16)) a16 { 
   char m[16]; 
   typedef a16 type;
};
struct __declspec(align(32)) a32 { 
   char m[32]; 
   typedef a32 type;
};
struct __declspec(align(64)) a64 
{ 
   char m[64]; 
   typedef a64 type;
};
struct __declspec(align(128)) a128 { 
   char m[128]; 
   typedef a128 type;
};
}

template<> class type_with_alignment<8>  
{ 
   typedef mpl::if_c<
      ::Pothos::alignment_of<Pothos::detail::max_align>::value < 8,
      align::a8,
      Pothos::detail::type_with_alignment_imp<8> >::type t1; 
public: 
   typedef t1::type type;
};
template<> class type_with_alignment<16> 
{ 
   typedef mpl::if_c<
      ::Pothos::alignment_of<Pothos::detail::max_align>::value < 16,
      align::a16,
      Pothos::detail::type_with_alignment_imp<16> >::type t1; 
public: 
   typedef t1::type type;
};
template<> class type_with_alignment<32> 
{ 
   typedef mpl::if_c<
      ::Pothos::alignment_of<Pothos::detail::max_align>::value < 32,
      align::a32,
      Pothos::detail::type_with_alignment_imp<32> >::type t1; 
public: 
   typedef t1::type type;
};
template<> class type_with_alignment<64> {
   typedef mpl::if_c<
      ::Pothos::alignment_of<Pothos::detail::max_align>::value < 64,
      align::a64,
      Pothos::detail::type_with_alignment_imp<64> >::type t1; 
public: 
   typedef t1::type type;
};
template<> class type_with_alignment<128> {
   typedef mpl::if_c<
      ::Pothos::alignment_of<Pothos::detail::max_align>::value < 128,
      align::a128,
      Pothos::detail::type_with_alignment_imp<128> >::type t1; 
public: 
   typedef t1::type type;
};

namespace detail {
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a8,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a16,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a32,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a64,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a128,true)
}
#endif

#else

//
// Borland specific version, we have this for two reasons:
// 1) The version above doesn't always compile (with the new test cases for example)
// 2) Because of Borlands #pragma option we can create types with alignments that are
//    greater that the largest aligned builtin type.

namespace align{
#pragma option push -a16
struct a2{ short s; };
struct a4{ int s; };
struct a8{ double s; };
struct a16{ long double s; };
#pragma option pop
}

namespace detail {

typedef ::Pothos::align::a16 max_align;

//#if ! BOOST_WORKAROUND(__CODEGEARC__, BOOST_TESTED_AT(0x610))
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a2,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a4,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a8,true)
POTHOS_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,::Pothos::align::a16,true)
//#endif
}

template <std::size_t N> struct type_with_alignment
{
   // We should never get to here, but if we do use the maximally
   // aligned type:
   // BOOST_STATIC_ASSERT(0);
   typedef align::a16 type;
};
template <> struct type_with_alignment<1>{ typedef char type; };
template <> struct type_with_alignment<2>{ typedef align::a2 type; };
template <> struct type_with_alignment<4>{ typedef align::a4 type; };
template <> struct type_with_alignment<8>{ typedef align::a8 type; };
template <> struct type_with_alignment<16>{ typedef align::a16 type; };

#endif

} // namespace boost

#ifdef POTHOS_MSVC
#   pragma warning(pop)
#endif

#include <Pothos/serialization/impl/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TT_TYPE_WITH_ALIGNMENT_INCLUDED


