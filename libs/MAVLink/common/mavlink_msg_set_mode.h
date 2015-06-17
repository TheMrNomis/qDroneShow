#ifndef MAVLINK_MSG_SET_MODE_H
#define MAVLINK_MSG_SET_MODE_H

#include "../mavlinkmessage.h"

class MAVLink_msg_set_mode : public MAVLinkMessage
{
public:
  MAVLink_msg_set_mode(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber, uint8_t target_system, uint8_t base_mode, uint32_t custom_mode);
};

#endif // MAVLINK_MSG_SET_MODE_H
