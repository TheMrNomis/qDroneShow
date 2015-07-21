/** @file
 *	@brief MAVLink comm protocol built from common.xml
 *	@see http://mavlink.org
 */
#ifndef MAVLINK_CPP_H
#define MAVLINK_CPP_H

#include <cstdint>

namespace mavlink
{
  const uint8_t PROTOCOL_MARKER = 254;
  const bool PROTOCOL_USE_LITTLE_ENDIAN = true;
  const bool ALIGNED_FIELDS = true;
  const bool USE_CRC_EXTRA = true;
};

#include "version.h"
#include "common.h"

#endif // MAVLINK_CPP_H
