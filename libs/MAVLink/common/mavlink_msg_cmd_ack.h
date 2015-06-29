#ifndef MAVLINK_MSG_CMD_ACK_H
#define MAVLINK_MSG_CMD_ACK_H

#include "../mavlinkmessage.h"

class MAVLink_msg_cmd_ack : public MAVLinkMessage
{
public:
  MAVLink_msg_cmd_ack(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber,
                      uint16_t command, uint8_t result);

  uint16_t get_command() const;
  uint8_t get_result() const;
};

#endif // MAVLINK_MSG_CMD_ACK_H
