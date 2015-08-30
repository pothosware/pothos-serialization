// Copyright Vladimir Prus 2004.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <Pothos/serialization/impl/config.hpp>
#ifdef POTHOS_NO_STD_WSTREAMBUF
#error "wide char i/o not supported on this platform"
#else

#define POTHOS_UTF8_BEGIN_NAMESPACE \
     namespace Pothos { namespace archive { namespace detail {
#define POTHOS_UTF8_DECL
#define POTHOS_UTF8_END_NAMESPACE }}}
#include <Pothos/serialization/impl/detail/utf8_codecvt_facet.ipp>
#undef POTHOS_UTF8_END_NAMESPACE
#undef POTHOS_UTF8_DECL
#undef POTHOS_UTF8_BEGIN_NAMESPACE

#endif // BOOST_NO_STD_WSTREAMBUF

