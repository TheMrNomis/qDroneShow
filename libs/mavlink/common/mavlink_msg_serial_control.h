#ifndef MAVLINK_CPP_MSG_SERIAL_CONTROL_H
#define MAVLINK_CPP_MSG_SERIAL_CONTROL_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t serial_control_id = 126;
    const uint8_t serial_control_length = 79;
    const uint8_t serial_control_crc = 220;

    class serial_control : public mavlink::message
    {
      public:
        serial_control(uint8_t system_id, uint8_t component_id,  uint8_t  device, uint8_t  flags, uint16_t  timeout, uint32_t  baudrate, uint8_t  count, const uint8_t * data):
          mavlink::message( mavlink::msg::serial_control_length,
                            system_id,
                            component_id,
                            mavlink::msg::serial_control_id)
        {
           m_payload.push_back<uint32_t>(baudrate); ///< Baudrate of transfer. Zero means no change.
           m_payload.push_back<uint16_t>(timeout); ///< Timeout for reply data in milliseconds
           m_payload.push_back<uint8_t>(device); ///< See SERIAL_CONTROL_DEV enum
           m_payload.push_back<uint8_t>(flags); ///< See SERIAL_CONTROL_FLAG enum
           m_payload.push_back<uint8_t>(count); ///< how many bytes in this transfer
          
          	m_payload.push_back_array<uint8_t>(data, 70); ///< serial data
          
        }

      	uint32_t get_baudrate() const
          {return m_payload.get<uint32_t>(0);}
      	uint16_t get_timeout() const
          {return m_payload.get<uint16_t>(4);}
      	uint8_t get_device() const
          {return m_payload.get<uint8_t>(6);}
      	uint8_t get_flags() const
          {return m_payload.get<uint8_t>(7);}
      	uint8_t get_count() const
          {return m_payload.get<uint8_t>(8);}
      
       uint8_t * get_data() const
          {return m_payload.get_array<uint8_t>(9, 70);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_SERIAL_CONTROL_H
    