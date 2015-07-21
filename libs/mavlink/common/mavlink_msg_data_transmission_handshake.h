#ifndef MAVLINK_CPP_MSG_DATA_TRANSMISSION_HANDSHAKE_H
#define MAVLINK_CPP_MSG_DATA_TRANSMISSION_HANDSHAKE_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t data_transmission_handshake_id = 130;
    const uint8_t data_transmission_handshake_length = 13;
    const uint8_t data_transmission_handshake_crc = 29;

    class data_transmission_handshake : public mavlink::message
    {
      public:
        data_transmission_handshake(uint8_t system_id, uint8_t component_id,  uint8_t type, uint32_t size, uint16_t width, uint16_t height, uint16_t packets, uint8_t payload, uint8_t jpg_quality):
          mavlink::message( mavlink::msg::data_transmission_handshake_length,
                            system_id,
                            component_id,
                            mavlink::msg::data_transmission_handshake_id,
                            mavlink::msg::data_transmission_handshake_crc)
        {
           m_payload.push_back<uint32_t>(size); ///< total data size in bytes (set on ACK only)
           m_payload.push_back<uint16_t>(width); ///< Width of a matrix or image
           m_payload.push_back<uint16_t>(height); ///< Height of a matrix or image
           m_payload.push_back<uint16_t>(packets); ///< number of packets beeing sent (set on ACK only)
           m_payload.push_back<uint8_t>(type); ///< type of requested/acknowledged data (as defined in ENUM DATA_TYPES in mavlink/include/mavlink_types.h)
           m_payload.push_back<uint8_t>(payload); ///< payload size per packet (normally 253 byte, see DATA field size in message ENCAPSULATED_DATA) (set on ACK only)
           m_payload.push_back<uint8_t>(jpg_quality); ///< JPEG quality out of [1,100]
          
        }

      	uint32_t get_size() const
          {return m_payload.get<uint32_t>(0);}
      	uint16_t get_width() const
          {return m_payload.get<uint16_t>(4);}
      	uint16_t get_height() const
          {return m_payload.get<uint16_t>(6);}
      	uint16_t get_packets() const
          {return m_payload.get<uint16_t>(8);}
      	uint8_t get_type() const
          {return m_payload.get<uint8_t>(10);}
      	uint8_t get_payload() const
          {return m_payload.get<uint8_t>(11);}
      	uint8_t get_jpg_quality() const
          {return m_payload.get<uint8_t>(12);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_DATA_TRANSMISSION_HANDSHAKE_H
    