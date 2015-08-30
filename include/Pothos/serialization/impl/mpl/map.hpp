
#ifndef POTHOS_MPL_MAP_HPP_INCLUDED
#define POTHOS_MPL_MAP_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: map.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-10 23:19:02 -0700 (Fri, 10 Oct 2008) $
// $Revision: 49267 $

#if !defined(POTHOS_MPL_PREPROCESSING_MODE)
#   include <Pothos/serialization/impl/mpl/limits/map.hpp>
#   include <Pothos/serialization/impl/mpl/aux_/na.hpp>
#   include <Pothos/serialization/impl/mpl/aux_/config/preprocessor.hpp>

#   include <Pothos/serialization/impl/preprocessor/inc.hpp>
#   include <Pothos/serialization/impl/preprocessor/cat.hpp>
#   include <Pothos/serialization/impl/preprocessor/stringize.hpp>

#if !defined(POTHOS_NEEDS_TOKEN_PASTING_OP_FOR_TOKENS_JUXTAPOSING)
#   define AUX778076_MAP_HEADER \
    POTHOS_PP_CAT(map, POTHOS_MPL_LIMIT_MAP_SIZE).hpp \
    /**/
#else
#   define AUX778076_MAP_HEADER \
    POTHOS_PP_CAT(map, POTHOS_MPL_LIMIT_MAP_SIZE)##.hpp \
    /**/
#endif

#   include POTHOS_PP_STRINGIZE(Pothos/serialization/impl/mpl/map/AUX778076_MAP_HEADER)
#   undef AUX778076_MAP_HEADER
#endif

#include <Pothos/serialization/impl/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(POTHOS_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(POTHOS_MPL_PREPROCESSING_MODE)

#   define POTHOS_MPL_PREPROCESSED_HEADER map.hpp
#   include <Pothos/serialization/impl/mpl/aux_/include_preprocessed.hpp>

#else

#   include <Pothos/serialization/impl/mpl/limits/map.hpp>

#   define AUX778076_SEQUENCE_NAME map
#   define AUX778076_SEQUENCE_LIMIT POTHOS_MPL_LIMIT_MAP_SIZE
#   include <Pothos/serialization/impl/mpl/aux_/sequence_wrapper.hpp>

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_MAP_HPP_INCLUDED
