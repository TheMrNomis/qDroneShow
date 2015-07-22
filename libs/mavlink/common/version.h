/** @file
 *	@brief MAVLink comm protocol built from common.xml
 *	@see http://mavlink.org
 */
#ifndef MAVLINK_CPP_VERSION_H
#define MAVLINK_CPP_VERSION_H

namespace mavlink
{
  namespace version
  {
    const char * const build_date = "Wed Jul 22 16:54:06 2015";
    const char * const wire_protocol = "1.0";
    const uint8_t max_dialect_payload_size = 255;
  };
};

#endif // MAVLINK_CPP_VERSION_H
