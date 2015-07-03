#ifndef MAVLINK_MSG_GPS_RAW_INT_H
#define MAVLINK_MSG_GPS_RAW_INT_H

#include "./mavlink.h"

class MAVLink_msg_gps_raw_int : public MAVLinkMessage
{
public:
  MAVLink_msg_gps_raw_int(
      uint8_t system_id, uint8_t component_id, uint8_t sequenceNumber,
      uint64_t time_usec, uint8_t fix_type,
      int32_t lat, int32_t lon, int32_t alt,
      uint16_t eph, uint16_t epv, uint16_t vel, uint16_t cog,
      uint8_t satellites_visible);

  uint64_t get_time_usec() const;
  uint8_t get_fix_type() const;

  int32_t get_lat() const;
  int32_t get_lon() const;
  int32_t get_alt() const;

  uint16_t get_eph() const;
  uint16_t get_epv() const;
  uint16_t get_vel() const;
  uint16_t get_cog() const;

  uint8_t get_satellites_visible() const;
};

#endif // MAVLINK_MSG_GPS_RAW_INT_H
