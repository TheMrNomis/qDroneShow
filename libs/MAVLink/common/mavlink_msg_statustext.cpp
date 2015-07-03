#include "mavlink_msg_statustext.h"

MAVLink_msg_statustext::MAVLink_msg_statustext(
    uint8_t system_id, uint8_t component_id, uint8_t sequenceNumber,
    uint8_t severity, std::string text):

  MAVLinkMessage( mavlink_message::lengths[mavlink_message::statustext],
                  sequenceNumber,system_id,component_id,
                  mavlink_message::statustext,
                  mavlink_message::crcs[mavlink_message::statustext])
{
  m_payload << severity;
  for(unsigned int i = 0; i < 50; ++i)
    m_payload << ((i < text.size())? text[i] : ' ');
}

uint8_t MAVLink_msg_statustext::get_severity() const
{return m_payload.get<uint8_t>(0);}

std::string MAVLink_msg_statustext::get_text() const
{
  std::string str;
  for(unsigned int i = 0; i < 50; ++i)
    str.push_back(m_payload.get<char>(sizeof(uint8_t) + i*sizeof(char)));
  return str;
}
