
#ifndef POTHOS_MPL_SET_AUX_SET0_HPP_INCLUDED
#define POTHOS_MPL_SET_AUX_SET0_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: set0.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-10 23:19:02 -0700 (Fri, 10 Oct 2008) $
// $Revision: 49267 $

#include <Pothos/serialization/impl/mpl/long.hpp>
#include <Pothos/serialization/impl/mpl/void.hpp>
#include <Pothos/serialization/impl/mpl/aux_/na.hpp>
#include <Pothos/serialization/impl/mpl/set/aux_/tag.hpp>
#include <Pothos/serialization/impl/mpl/aux_/yes_no.hpp>
#include <Pothos/serialization/impl/mpl/aux_/overload_names.hpp>
#include <Pothos/serialization/impl/mpl/aux_/config/operators.hpp>

#include <Pothos/serialization/impl/preprocessor/cat.hpp>

namespace Pothos { namespace mpl {

#if defined(POTHOS_MPL_CFG_USE_OPERATORS_OVERLOADING)

#   define POTHOS_MPL_AUX_SET0_OVERLOAD(R, f, X, T) \
    friend R POTHOS_PP_CAT(POTHOS_MPL_AUX_OVERLOAD_,f)(X const&, T) \
/**/

#   define POTHOS_MPL_AUX_SET_OVERLOAD(R, f, X, T) \
    POTHOS_MPL_AUX_SET0_OVERLOAD(R, f, X, T) \
/**/

#else

#   define POTHOS_MPL_AUX_SET0_OVERLOAD(R, f, X, T) \
    static R POTHOS_PP_CAT(POTHOS_MPL_AUX_OVERLOAD_,f)(X const&, T) \
/**/

#   define POTHOS_MPL_AUX_SET_OVERLOAD(R, f, X, T) \
    POTHOS_MPL_AUX_SET0_OVERLOAD(R, f, X, T); \
    using Base::POTHOS_PP_CAT(POTHOS_MPL_AUX_OVERLOAD_,f) \
/**/

#endif

template< typename Dummy = na > struct set0
{
    typedef set0<>          item_;
    typedef item_           type;
    typedef aux::set_tag    tag;
    typedef void_           last_masked_;
    typedef void_           item_type_;
    typedef long_<0>        size;
    typedef long_<1>        order;

    POTHOS_MPL_AUX_SET0_OVERLOAD( aux::no_tag, ORDER_BY_KEY, set0<>, void const volatile* );
    POTHOS_MPL_AUX_SET0_OVERLOAD( aux::yes_tag, IS_MASKED, set0<>, void const volatile* );
};

}}

#endif // BOOST_MPL_SET_AUX_SET0_HPP_INCLUDED
