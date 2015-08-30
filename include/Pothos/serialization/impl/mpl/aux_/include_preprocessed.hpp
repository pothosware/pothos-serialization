
// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION

// Copyright Aleksey Gurtovoy 2000-2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: include_preprocessed.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-10 23:19:02 -0700 (Fri, 10 Oct 2008) $
// $Revision: 49267 $

#include <Pothos/serialization/impl/mpl/aux_/config/compiler.hpp>
#include <Pothos/serialization/impl/mpl/aux_/config/preprocessor.hpp>
#include <Pothos/serialization/impl/mpl/aux_/config/workaround.hpp>
#include <Pothos/serialization/impl/preprocessor/cat.hpp>
#include <Pothos/serialization/impl/preprocessor/stringize.hpp>

#if !defined(POTHOS_NEEDS_TOKEN_PASTING_OP_FOR_TOKENS_JUXTAPOSING)
#   define AUX778076_PREPROCESSED_HEADER \
    POTHOS_MPL_CFG_COMPILER_DIR/POTHOS_MPL_PREPROCESSED_HEADER \
/**/
#else
#   define AUX778076_PREPROCESSED_HEADER \
    POTHOS_PP_CAT(POTHOS_MPL_CFG_COMPILER_DIR,/)##POTHOS_MPL_PREPROCESSED_HEADER \
/**/
#endif

#if POTHOS_WORKAROUND(__IBMCPP__, POTHOS_TESTED_AT(700))
#   define AUX778076_INCLUDE_STRING POTHOS_PP_STRINGIZE(Pothos/serialization/impl/mpl/aux_/preprocessed/AUX778076_PREPROCESSED_HEADER)
#   include AUX778076_INCLUDE_STRING
#   undef AUX778076_INCLUDE_STRING
#else
#   include POTHOS_PP_STRINGIZE(Pothos/serialization/impl/mpl/aux_/preprocessed/AUX778076_PREPROCESSED_HEADER)
#endif

#   undef AUX778076_PREPROCESSED_HEADER

#undef POTHOS_MPL_PREPROCESSED_HEADER
