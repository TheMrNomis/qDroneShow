#ifndef MAVLINK_CPP_MSG_DATA_STREAM_H
#define MAVLINK_CPP_MSG_DATA_STREAM_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t data_stream_id = 67;
    const uint8_t data_stream_length = 4;
    const uint8_t data_stream_crc = 21;

    class data_stream : public mavlink::message
    {
      public:
        data_stream(uint8_t system_id, uint8_t component_id,  uint8_t  stream_id, uint16_t  message_rate, uint8_t  on_off):
          mavlink::message( mavlink::msg::data_stream_length,
                            system_id,
                            component_id,
                            mavlink::msg::data_stream_id)
        {
           m_payload.push_back<uint16_t>(message_rate); ///< The requested interval between two messages of this type
           m_payload.push_back<uint8_t>(stream_id); ///< The ID of the requested data stream
           m_payload.push_back<uint8_t>(on_off); ///< 1 stream is enabled, 0 stream is stopped.
          
          
        }

      	uint16_t get_message_rate() const
          {return m_payload.get<uint16_t>(0);}
      	uint8_t get_stream_id() const
          {return m_payload.get<uint8_t>(2);}
      	uint8_t get_on_off() const
          {return m_payload.get<uint8_t>(3);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_DATA_STREAM_H
    