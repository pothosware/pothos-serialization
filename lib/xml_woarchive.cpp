/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// xml_woarchive.cpp:

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#include <Pothos/serialization/impl/config.hpp>
#ifdef POTHOS_NO_STD_WSTREAMBUF
#error "wide char i/o not supported on this platform"
#else

#define POTHOS_WARCHIVE_SOURCE
#include <Pothos/archive/xml_woarchive.hpp>
#include <Pothos/archive/detail/archive_serializer_map.hpp>

// explicitly instantiate for this type of text stream
#include <Pothos/archive/impl/archive_serializer_map.ipp>
#include <Pothos/archive/impl/basic_xml_oarchive.ipp>
#include <Pothos/archive/impl/xml_woarchive_impl.ipp>

namespace Pothos {
namespace archive {

template class detail::archive_serializer_map<xml_woarchive>;
template class basic_xml_oarchive<xml_woarchive> ;
template class xml_woarchive_impl<xml_woarchive> ;

} // namespace archive
} // namespace boost

#endif // BOOST_NO_STD_WSTREAMBUF
