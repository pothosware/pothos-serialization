
#ifndef POTHOS_MPL_AUX_VALUE_WKND_HPP_INCLUDED
#define POTHOS_MPL_AUX_VALUE_WKND_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: value_wknd.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-10 23:19:02 -0700 (Fri, 10 Oct 2008) $
// $Revision: 49267 $

#include <Pothos/serialization/impl/mpl/aux_/static_cast.hpp>
#include <Pothos/serialization/impl/mpl/aux_/config/integral.hpp>
#include <Pothos/serialization/impl/mpl/aux_/config/eti.hpp>
#include <Pothos/serialization/impl/mpl/aux_/config/workaround.hpp>

#if defined(POTHOS_MPL_CFG_BCC_INTEGRAL_CONSTANTS) \
    || defined(POTHOS_MPL_CFG_MSVC_60_ETI_BUG)

#   include <Pothos/serialization/impl/mpl/int.hpp>

namespace Pothos { namespace mpl { namespace aux {
template< typename C_ > struct value_wknd
    : C_
{
};

#if defined(POTHOS_MPL_CFG_MSVC_60_ETI_BUG)
template<> struct value_wknd<int>
    : int_<1>
{
    using int_<1>::value;
};
#endif
}}}


#if !defined(POTHOS_MPL_CFG_MSVC_60_ETI_BUG)
#   define POTHOS_MPL_AUX_VALUE_WKND(C) \
    ::POTHOS_MPL_AUX_ADL_BARRIER_NAMESPACE::aux::value_wknd< C > \
/**/
#    define POTHOS_MPL_AUX_MSVC_VALUE_WKND(C) POTHOS_MPL_AUX_VALUE_WKND(C)
#else
#   define POTHOS_MPL_AUX_VALUE_WKND(C) C
#   define POTHOS_MPL_AUX_MSVC_VALUE_WKND(C) \
    ::Pothos::mpl::aux::value_wknd< C > \
/**/
#endif

#else // BOOST_MPL_CFG_BCC_INTEGRAL_CONSTANTS

#   define POTHOS_MPL_AUX_VALUE_WKND(C) C
#   define POTHOS_MPL_AUX_MSVC_VALUE_WKND(C) C

#endif

#if POTHOS_WORKAROUND(__EDG_VERSION__, <= 238)
#   define POTHOS_MPL_AUX_NESTED_VALUE_WKND(T, C) \
    POTHOS_MPL_AUX_STATIC_CAST(T, C::value) \
/**/
#else
#   define POTHOS_MPL_AUX_NESTED_VALUE_WKND(T, C) \
    POTHOS_MPL_AUX_VALUE_WKND(C)::value \
/**/
#endif


namespace Pothos { namespace mpl { namespace aux {

template< typename T > struct value_type_wknd
{
    typedef typename T::value_type type;
};

#if defined(POTHOS_MPL_CFG_MSVC_ETI_BUG)
template<> struct value_type_wknd<int>
{
    typedef int type;
};
#endif

}}}

#endif // BOOST_MPL_AUX_VALUE_WKND_HPP_INCLUDED
