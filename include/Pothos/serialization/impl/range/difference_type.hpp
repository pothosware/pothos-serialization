// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef POTHOS_RANGE_DIFFERENCE_TYPE_HPP
#define POTHOS_RANGE_DIFFERENCE_TYPE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <Pothos/serialization/impl/range/config.hpp>
#include <Pothos/serialization/impl/range/iterator.hpp>
#include <Pothos/serialization/impl/iterator/iterator_traits.hpp>

namespace Pothos
{
    template< class T >
    struct range_difference : iterator_difference< typename range_iterator<T>::type >
    { };
}

#endif
