#ifndef MAVLINK_MSG_GLOBAL_POSITION_INT_H
#define MAVLINK_MSG_GLOBAL_POSITION_INT_H

#include "../mavlinkmessage.h"
#include "mavlink.h"

class MAVLink_msg_global_position_int : public MAVLinkMessage
{
public:
  MAVLink_msg_global_position_int(uint8_t systemID, uint8_t componentID,
                                  uint8_t sequenceNumber, uint32_t time_boot_ms,
                                  int32_t lat, int32_t lon, int32_t alt,  int32_t relative_alt,
                                  int16_t vx, int16_t vy, int16_t vz, uint16_t hdg);

  uint32_t get_time_boot_ms() const;
  int32_t get_lat() const;
  int32_t get_lon() const;
  int32_t get_alt() const;
  int32_t get_relative_alt() const;
  int16_t get_vx() const;
  int16_t get_vy() const;
  int16_t get_vz() const;
  uint16_t get_hdg() const;
};

#endif // MAVLINK_MSG_GLOBAL_POSITION_INT_H
