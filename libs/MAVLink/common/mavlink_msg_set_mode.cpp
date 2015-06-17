#include "mavlink_msg_set_mode.h"

MAVLink_msg_set_mode::MAVLink_msg_set_mode(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber, uint8_t target_system, uint8_t base_mode, uint32_t custom_mode):
  MAVLinkMessage(6,sequenceNumber,systemID,componentID,11,true,89)
{
  m_payload << custom_mode;
  m_payload << target_system;
  m_payload << base_mode;
}

