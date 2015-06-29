#include "mavlink_msg_cmd_ack.h"

MAVLink_msg_cmd_ack::MAVLink_msg_cmd_ack(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber, uint16_t command, uint8_t result):
  MAVLinkMessage(3,sequenceNumber,systemID,componentID,77,true,143)
{
  m_payload << command;
  m_payload << result;
}

uint16_t MAVLink_msg_cmd_ack::get_command() const
  {return m_payload.get<uint16_t>(0);}
uint8_t MAVLink_msg_cmd_ack::get_result() const
  {return m_payload.get<uint8_t>(sizeof(uint16_t));}
