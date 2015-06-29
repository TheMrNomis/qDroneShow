#ifndef MAVLINK_MSG_ATTITUDE_H
#define MAVLINK_MSG_ATTITUDE_H

#include "./mavlink.h"

class MAVLink_msg_attitude : public MAVLinkMessage
{
public:
  MAVLink_msg_attitude(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber,
                       uint32_t time_boot_ms, float roll, float pitch, float yaw, float rollspeed, float pitchspeed, float yawspeed);

  uint32_t get_time_boot_ms() const;
  float get_roll() const;
  float get_pitch() const;
  float get_yaw() const;
  float get_rollspeed() const;
  float get_pitchspeed() const;
  float get_yawspeed() const;
};

#endif // MAVLINK_MSG_ATTITUDE_H
