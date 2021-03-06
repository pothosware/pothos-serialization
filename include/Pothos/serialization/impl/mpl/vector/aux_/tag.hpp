
#ifndef POTHOS_MPL_VECTOR_AUX_TAG_HPP_INCLUDED
#define POTHOS_MPL_VECTOR_AUX_TAG_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: tag.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-10 23:19:02 -0700 (Fri, 10 Oct 2008) $
// $Revision: 49267 $

#include <Pothos/serialization/impl/mpl/aux_/config/typeof.hpp>
#include <Pothos/serialization/impl/mpl/aux_/nttp_decl.hpp>

namespace Pothos { namespace mpl { namespace aux {

struct v_iter_tag;

#if defined(POTHOS_MPL_CFG_TYPEOF_BASED_SEQUENCES)
struct vector_tag;
#else
template< POTHOS_MPL_AUX_NTTP_DECL(long, N) > struct vector_tag;
#endif

}}}

#endif // BOOST_MPL_VECTOR_AUX_TAG_HPP_INCLUDED
