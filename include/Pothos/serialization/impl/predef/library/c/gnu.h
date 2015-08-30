/*
Copyright Redshift Software, Inc. 2008-2013
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef POTHOS_PREDEF_LIBRARY_C_GNU_H
#define POTHOS_PREDEF_LIBRARY_C_GNU_H

#include <Pothos/serialization/impl/predef/version_number.h>
#include <Pothos/serialization/impl/predef/make.h>

#include <Pothos/serialization/impl/predef/library/c/_prefix.h>

#if defined(__STDC__)
#include <stddef.h>
#elif defined(__cplusplus)
#include <cstddef>
#endif

/*`
[heading `POTHOS_LIB_C_GNU`]

[@http://en.wikipedia.org/wiki/Glibc GNU glibc] Standard C library.
Version number available as major, and minor.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__GLIBC__`] [__predef_detection__]]
    [[`__GNU_LIBRARY__`] [__predef_detection__]]

    [[`__GLIBC__`, `__GLIBC_MINOR__`] [V.R.0]]
    [[`__GNU_LIBRARY__`, `__GNU_LIBRARY_MINOR__`] [V.R.0]]
    ]
 */

#define POTHOS_LIB_C_GNU POTHOS_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__GLIBC__) || defined(__GNU_LIBRARY__)
#   undef POTHOS_LIB_C_GNU
#   if defined(__GLIBC__)
#       define POTHOS_LIB_C_GNU \
            POTHOS_VERSION_NUMBER(__GLIBC__,__GLIBC_MINOR__,0)
#   else
#       define POTHOS_LIB_C_GNU \
            POTHOS_VERSION_NUMBER(__GNU_LIBRARY__,__GNU_LIBRARY_MINOR__,0)
#   endif
#endif

#if POTHOS_LIB_C_GNU
#   define POTHOS_LIB_C_GNU_AVAILABLE
#endif

#define POTHOS_LIB_C_GNU_NAME "GNU"

#include <Pothos/serialization/impl/predef/detail/test.h>
POTHOS_PREDEF_DECLARE_TEST(POTHOS_LIB_C_GNU,POTHOS_LIB_C_GNU_NAME)


#endif
