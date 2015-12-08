if(DEFINED INCLUDED_POTHOS_SERIALIZATION_CONFIG_CMAKE)
    return()
endif()
set(INCLUDED_POTHOS_SERIALIZATION_CONFIG_CMAKE TRUE)

########################################################################
# PothosSerializationConfig - cmake project configuration for client libraries
#
# The following will be set after find_package(PothosSerialization):
# PothosSerialization_LIBRARIES    - development libraries
# PothosSerialization_INCLUDE_DIRS - development includes
########################################################################

########################################################################
## installation root
########################################################################
if (UNIX)
    get_filename_component(POTHOS_SERIALIZATION_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)
elseif (WIN32)
    get_filename_component(POTHOS_SERIALIZATION_ROOT "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)
endif ()

########################################################################
## locate the library
########################################################################
find_library(
    POTHOS_SERIALIZATION_LIBRARY PothosSerialization PothosSerializationd
    PATHS ${POTHOS_SERIALIZATION_ROOT}/lib${LIB_SUFFIX}
    PATH_SUFFIXES ${CMAKE_LIBRARY_ARCHITECTURE}
    NO_DEFAULT_PATH
)

if(NOT POTHOS_SERIALIZATION_LIBRARY)
    message(FATAL_ERROR "cannot find PothosSerialization library in ${POTHOS_SERIALIZATION_ROOT}/lib${LIB_SUFFIX}")
endif()

set(PothosSerialization_LIBRARIES ${POTHOS_SERIALIZATION_LIBRARY})

########################################################################
## locate the includes
########################################################################
find_path(
    POTHOS_SERIALIZATION_INCLUDE_DIR Pothos/serialization/config.hpp
    PATHS ${POTHOS_SERIALIZATION_ROOT}/include
    NO_DEFAULT_PATH
)

if(NOT POTHOS_SERIALIZATION_INCLUDE_DIR)
    message(FATAL_ERROR "cannot find PothosSerialization includes in ${POTHOS_SERIALIZATION_ROOT}/include")
endif()

set(PothosSerialization_INCLUDE_DIRS ${POTHOS_SERIALIZATION_INCLUDE_DIR})

