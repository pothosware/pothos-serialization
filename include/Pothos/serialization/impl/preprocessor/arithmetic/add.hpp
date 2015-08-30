# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef POTHOS_PREPROCESSOR_ARITHMETIC_ADD_HPP
# define POTHOS_PREPROCESSOR_ARITHMETIC_ADD_HPP
#
# include <Pothos/serialization/impl/preprocessor/arithmetic/dec.hpp>
# include <Pothos/serialization/impl/preprocessor/arithmetic/inc.hpp>
# include <Pothos/serialization/impl/preprocessor/config/config.hpp>
# include <Pothos/serialization/impl/preprocessor/control/while.hpp>
# include <Pothos/serialization/impl/preprocessor/tuple/elem.hpp>
#
# /* POTHOS_PP_ADD */
#
# if ~POTHOS_PP_CONFIG_FLAGS() & POTHOS_PP_CONFIG_EDG()
#    define POTHOS_PP_ADD(x, y) POTHOS_PP_TUPLE_ELEM(2, 0, POTHOS_PP_WHILE(POTHOS_PP_ADD_P, POTHOS_PP_ADD_O, (x, y)))
# else
#    define POTHOS_PP_ADD(x, y) POTHOS_PP_ADD_I(x, y)
#    define POTHOS_PP_ADD_I(x, y) POTHOS_PP_TUPLE_ELEM(2, 0, POTHOS_PP_WHILE(POTHOS_PP_ADD_P, POTHOS_PP_ADD_O, (x, y)))
# endif
#
# define POTHOS_PP_ADD_P(d, xy) POTHOS_PP_TUPLE_ELEM(2, 1, xy)
#
# if ~POTHOS_PP_CONFIG_FLAGS() & POTHOS_PP_CONFIG_MWCC()
#    define POTHOS_PP_ADD_O(d, xy) POTHOS_PP_ADD_O_I xy
# else
#    define POTHOS_PP_ADD_O(d, xy) POTHOS_PP_ADD_O_I(POTHOS_PP_TUPLE_ELEM(2, 0, xy), POTHOS_PP_TUPLE_ELEM(2, 1, xy))
# endif
#
# define POTHOS_PP_ADD_O_I(x, y) (POTHOS_PP_INC(x), POTHOS_PP_DEC(y))
#
# /* POTHOS_PP_ADD_D */
#
# if ~POTHOS_PP_CONFIG_FLAGS() & POTHOS_PP_CONFIG_EDG()
#    define POTHOS_PP_ADD_D(d, x, y) POTHOS_PP_TUPLE_ELEM(2, 0, POTHOS_PP_WHILE_ ## d(POTHOS_PP_ADD_P, POTHOS_PP_ADD_O, (x, y)))
# else
#    define POTHOS_PP_ADD_D(d, x, y) POTHOS_PP_ADD_D_I(d, x, y)
#    define POTHOS_PP_ADD_D_I(d, x, y) POTHOS_PP_TUPLE_ELEM(2, 0, POTHOS_PP_WHILE_ ## d(POTHOS_PP_ADD_P, POTHOS_PP_ADD_O, (x, y)))
# endif
#
# endif
