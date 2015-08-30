//  Copyright John Maddock 2006.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef POTHOS_MATH_TOOLS_REAL_CAST_HPP
#define POTHOS_MATH_TOOLS_REAL_CAST_HPP

#ifdef _MSC_VER
#pragma once
#endif

namespace Pothos{ namespace math
{
  namespace tools
  {
    template <class To, class T>
    inline To real_cast(T t)
    {
       return static_cast<To>(t);
    }
  } // namespace tools
} // namespace math
} // namespace boost

#endif // BOOST_MATH_TOOLS_REAL_CAST_HPP



