#ifndef MAVLINK_CPP_MSG_REQUEST_DATA_STREAM_H
#define MAVLINK_CPP_MSG_REQUEST_DATA_STREAM_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t request_data_stream_id = 66;
    const uint8_t request_data_stream_length = 6;
    const uint8_t request_data_stream_crc = 148;

    class request_data_stream : public mavlink::message
    {
      public:
        request_data_stream(uint8_t system_id, uint8_t component_id,  uint8_t target_system, uint8_t target_component, uint8_t req_stream_id, uint16_t req_message_rate, uint8_t start_stop):
          mavlink::message( mavlink::msg::request_data_stream_length,
                            system_id,
                            component_id,
                            mavlink::msg::request_data_stream_id,
                            mavlink::msg::request_data_stream_crc)
        {
           m_payload.push_back<uint16_t>(req_message_rate); ///< The requested interval between two messages of this type
           m_payload.push_back<uint8_t>(target_system); ///< The target requested to send the message stream.
           m_payload.push_back<uint8_t>(target_component); ///< The target requested to send the message stream.
           m_payload.push_back<uint8_t>(req_stream_id); ///< The ID of the requested data stream
           m_payload.push_back<uint8_t>(start_stop); ///< 1 to start sending, 0 to stop sending.
          
        }

      	uint16_t get_req_message_rate() const
          {return m_payload.get<uint16_t>(0);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(2);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(3);}
      	uint8_t get_req_stream_id() const
          {return m_payload.get<uint8_t>(4);}
      	uint8_t get_start_stop() const
          {return m_payload.get<uint8_t>(5);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_REQUEST_DATA_STREAM_H
    