/*
Copyright Redshift Software, Inc. 2012-2013
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef POTHOS_PREDEF_OS_BSD_FREE_H
#define POTHOS_PREDEF_OS_BSD_FREE_H

#include <Pothos/serialization/impl/predef/os/bsd.h>

/*`
[heading `POTHOS_OS_BSD_FREE`]

[@http://en.wikipedia.org/wiki/Freebsd FreeBSD] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__FreeBSD__`] [__predef_detection__]]

    [[`__FreeBSD_version`] [V.R.P]]
    ]
 */

#define POTHOS_OS_BSD_FREE POTHOS_VERSION_NUMBER_NOT_AVAILABLE

#if !POTHOS_PREDEF_DETAIL_OS_DETECTED && ( \
    defined(__FreeBSD__) \
    )
#   ifndef POTHOS_OS_BSD_AVAILABLE
#       define POTHOS_OS_BSD POTHOS_VERSION_NUMBER_AVAILABLE
#       define POTHOS_OS_BSD_AVAILABLE
#   endif
#   undef POTHOS_OS_BSD_FREE
#   if defined(__FreeBSD_version)
#       if __FreeBSD_version < 500000
#           define POTHOS_OS_BSD_FREE \
                POTHOS_PREDEF_MAKE_10_VRP000(__FreeBSD_version)
#       else
#           define POTHOS_OS_BSD_FREE \
                POTHOS_PREDEF_MAKE_10_VRR000(__FreeBSD_version)
#       endif
#   else
#       define POTHOS_OS_BSD_FREE POTHOS_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if POTHOS_OS_BSD_FREE
#   define POTHOS_OS_BSD_FREE_AVAILABLE
#   include <Pothos/serialization/impl/predef/detail/os_detected.h>
#endif

#define POTHOS_OS_BSD_FREE_NAME "Free BSD"

#include <Pothos/serialization/impl/predef/detail/test.h>
POTHOS_PREDEF_DECLARE_TEST(POTHOS_OS_BSD_FREE,POTHOS_OS_BSD_FREE_NAME)

#endif
