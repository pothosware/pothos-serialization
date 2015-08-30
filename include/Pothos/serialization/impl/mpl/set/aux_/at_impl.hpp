
#ifndef POTHOS_MPL_SET_AUX_AT_IMPL_HPP_INCLUDED
#define POTHOS_MPL_SET_AUX_AT_IMPL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: at_impl.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-10 23:19:02 -0700 (Fri, 10 Oct 2008) $
// $Revision: 49267 $

#include <Pothos/serialization/impl/mpl/at_fwd.hpp>
#include <Pothos/serialization/impl/mpl/set/aux_/has_key_impl.hpp>
#include <Pothos/serialization/impl/mpl/set/aux_/tag.hpp>
#include <Pothos/serialization/impl/mpl/if.hpp>
#include <Pothos/serialization/impl/mpl/void.hpp>

namespace Pothos { namespace mpl {

template<>
struct at_impl< aux::set_tag >
{
    template< typename Set, typename T > struct apply
    {
        typedef typename if_< 
              has_key_impl<aux::set_tag>::apply<Set,T>
            , T
            , void_
            >::type type;            
    };
};

}}

#endif // BOOST_MPL_SET_AUX_AT_IMPL_HPP_INCLUDED
