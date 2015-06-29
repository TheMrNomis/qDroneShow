#ifndef MAVLINK_MSG_VFR_HUD_H
#define MAVLINK_MSG_VFR_HUD_H

#include "./mavlink.h"

class MAVLink_msg_vfr_hud : public MAVLinkMessage
{
public:
  MAVLink_msg_vfr_hud(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber,
                      float airspeed, float groundspeed,
                      int16_t heading, uint16_t throttle,
                      float alt, float climb);

  float get_airspeed() const;
  float get_groundspeed() const;
  int16_t get_heading() const;
  uint16_t get_throttle() const;
  float get_alt() const;
  float get_climb() const;
};

#endif // MAVLINK_MSG_VFR_HUD_H
