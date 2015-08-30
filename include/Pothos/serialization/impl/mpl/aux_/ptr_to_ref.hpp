
#ifndef POTHOS_MPL_AUX_PTR_TO_REF_HPP_INCLUDED
#define POTHOS_MPL_AUX_PTR_TO_REF_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: ptr_to_ref.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-10 23:19:02 -0700 (Fri, 10 Oct 2008) $
// $Revision: 49267 $

#include <Pothos/serialization/impl/mpl/aux_/static_cast.hpp>
#include <Pothos/serialization/impl/mpl/aux_/config/msvc.hpp>
#include <Pothos/serialization/impl/mpl/aux_/config/workaround.hpp>


#if POTHOS_WORKAROUND(POTHOS_MSVC, POTHOS_TESTED_AT(1400)) \
    ||  ( POTHOS_WORKAROUND(__EDG_VERSION__, <= 245) \
        && !(defined(__STD_STRICT_ANSI) \
            || defined(__STD_STRICT_ANSI_ERRORS)) )

#   define POTHOS_MPL_AUX_PTR_TO_REF(X) \
    *POTHOS_MPL_AUX_STATIC_CAST(X*, 0) \
/**/

#else

#   define POTHOS_MPL_AUX_PTR_TO_REF(X) \
    aux::ptr_to_ref(POTHOS_MPL_AUX_STATIC_CAST(X*, 0)) \
/**/

#endif


namespace Pothos { namespace mpl { namespace aux {

template< typename T > static T const& ptr_to_ref(T*);

}}}

#endif // BOOST_MPL_AUX_PTR_TO_REF_HPP_INCLUDED
