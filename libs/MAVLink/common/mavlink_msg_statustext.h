#ifndef MAVLINK_MSG_STATUSTEXT_H
#define MAVLINK_MSG_STATUSTEXT_H

#include "./mavlink.h"

class MAVLink_msg_statustext : public MAVLinkMessage
{
public:
  MAVLink_msg_statustext(uint8_t system_id, uint8_t component_id, uint8_t sequenceNumber,
                         uint8_t severity, std::string text);

  uint8_t get_severity() const;
  std::string get_text() const;
};

#endif // MAVLINK_MSG_STATUSTEXT_H
