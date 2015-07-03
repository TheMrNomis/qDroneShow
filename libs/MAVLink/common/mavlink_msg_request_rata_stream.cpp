#include "mavlink_msg_request_rata_stream.h"

MAVLink_msg_request_rata_stream::MAVLink_msg_request_rata_stream(
    uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber,
    uint8_t target_system, uint8_t target_component,
    uint8_t req_stream_id, uint16_t req_message_rate, uint8_t start_stop):

  MAVLinkMessage( mavlink_message::lengths[mavlink_message::request_data_stream],
                  sequenceNumber, systemID, componentID,
                  mavlink_message::request_data_stream,
                  mavlink_message::crcs[mavlink_message::request_data_stream])
{
  m_payload << req_message_rate;
  m_payload << target_system;
  m_payload << target_component;
  m_payload << req_stream_id;
  m_payload << start_stop;
}

uint16_t MAVLink_msg_request_rata_stream::get_req_message_rate() const
  {return m_payload.get<uint16_t>(0);}
uint8_t MAVLink_msg_request_rata_stream::get_target_system() const
  {return m_payload.get<uint8_t>(sizeof(uint16_t) + 0*sizeof(uint8_t));}
uint8_t MAVLink_msg_request_rata_stream::get_target_component() const
  {return m_payload.get<uint8_t>(sizeof(uint16_t) + 1*sizeof(uint8_t));}
uint8_t MAVLink_msg_request_rata_stream::get_req_stream_id() const
  {return m_payload.get<uint8_t>(sizeof(uint16_t) + 2*sizeof(uint8_t));}
uint8_t MAVLink_msg_request_rata_stream::get_start_stop() const
  {return m_payload.get<uint8_t>(sizeof(uint16_t) + 3*sizeof(uint8_t));}
