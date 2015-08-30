
#ifndef POTHOS_MPL_AUX_CONFIG_FORWARDING_HPP_INCLUDED
#define POTHOS_MPL_AUX_CONFIG_FORWARDING_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: forwarding.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-10 23:19:02 -0700 (Fri, 10 Oct 2008) $
// $Revision: 49267 $

#include <Pothos/serialization/impl/mpl/aux_/config/workaround.hpp>

#if    !defined(POTHOS_MPL_CFG_NO_NESTED_FORWARDING) \
    && !defined(POTHOS_MPL_PREPROCESSING_MODE) \
    && POTHOS_WORKAROUND(__BORLANDC__, POTHOS_TESTED_AT(0x610))

#   define POTHOS_MPL_CFG_NO_NESTED_FORWARDING

#endif

#endif // BOOST_MPL_AUX_CONFIG_FORWARDING_HPP_INCLUDED
