
//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, Howard
//  Hinnant & John Maddock 2000.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.


#ifndef POTHOS_TT_REMOVE_CV_HPP_INCLUDED
#define POTHOS_TT_REMOVE_CV_HPP_INCLUDED

#include <Pothos/serialization/impl/type_traits/broken_compiler_spec.hpp>
#include <Pothos/serialization/impl/type_traits/detail/cv_traits_impl.hpp>
#include <Pothos/serialization/impl/config.hpp>
#include <Pothos/serialization/impl/detail/workaround.hpp>

#include <cstddef>

#if POTHOS_WORKAROUND(POTHOS_MSVC,<=1300)
#include <Pothos/serialization/impl/type_traits/msvc/remove_cv.hpp>
#endif

// should be the last #include
#include <Pothos/serialization/impl/type_traits/detail/type_trait_def.hpp>

namespace Pothos {

#ifndef POTHOS_NO_TEMPLATE_PARTIAL_SPECIALIZATION

namespace detail{

template <class T>
struct rvalue_ref_filter_rem_cv
{
   typedef typename Pothos::detail::cv_traits_imp<T*>::unqualified_type type;
};

#ifndef POTHOS_NO_CXX11_RVALUE_REFERENCES
//
// We can't filter out rvalue_references at the same level as
// references or we get ambiguities from msvc:
//
template <class T>
struct rvalue_ref_filter_rem_cv<T&&>
{
   typedef T&& type;
};
#endif

}


//  convert a type T to a non-cv-qualified type - remove_cv<T>
POTHOS_TT_AUX_TYPE_TRAIT_DEF1(remove_cv,T,typename Pothos::detail::rvalue_ref_filter_rem_cv<T>::type)
POTHOS_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_cv,T&,T&)
#if !defined(POTHOS_NO_ARRAY_TYPE_SPECIALIZATIONS)
POTHOS_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,remove_cv,T const[N],T type[N])
POTHOS_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,remove_cv,T volatile[N],T type[N])
POTHOS_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,remove_cv,T const volatile[N],T type[N])
#endif

#elif !POTHOS_WORKAROUND(POTHOS_MSVC,<=1300)

namespace detail {
template <typename T>
struct remove_cv_impl
{
    typedef typename remove_volatile_impl< 
          typename remove_const_impl<T>::type
        >::type type;
};
}

POTHOS_TT_AUX_TYPE_TRAIT_DEF1(remove_cv,T,typename Pothos::detail::remove_cv_impl<T>::type)

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

} // namespace boost

#include <Pothos/serialization/impl/type_traits/detail/type_trait_undef.hpp>

#endif // BOOST_TT_REMOVE_CV_HPP_INCLUDED
