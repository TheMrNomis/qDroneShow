#ifndef MAVLINK_CPP_MSG_FILE_TRANSFER_PROTOCOL_H
#define MAVLINK_CPP_MSG_FILE_TRANSFER_PROTOCOL_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t file_transfer_protocol_id = 110;
    const uint8_t file_transfer_protocol_length = 254;
    const uint8_t file_transfer_protocol_crc = 84;

    class file_transfer_protocol : public mavlink::message
    {
      public:
        file_transfer_protocol(uint8_t system_id, uint8_t component_id,  uint8_t  target_network, uint8_t  target_system, uint8_t  target_component, const uint8_t * payload):
          mavlink::message( mavlink::msg::file_transfer_protocol_length,
                            system_id,
                            component_id,
                            mavlink::msg::file_transfer_protocol_id)
        {
           m_payload.push_back<uint8_t>(target_network); ///< Network ID (0 for broadcast)
           m_payload.push_back<uint8_t>(target_system); ///< System ID (0 for broadcast)
           m_payload.push_back<uint8_t>(target_component); ///< Component ID (0 for broadcast)
          
          	m_payload.push_back_array<uint8_t>(payload, 251); ///< Variable length payload. The length is defined by the remaining message length when subtracting the header and other fields.  The entire content of this block is opaque unless you understand any the encoding message_type.  The particular encoding used can be extension specific and might not always be documented as part of the mavlink specification.
          
        }

      	uint8_t get_target_network() const
          {return m_payload.get<uint8_t>(0);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(1);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(2);}
      
       uint8_t * get_payload() const
          {return m_payload.get_array<uint8_t>(3, 251);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_FILE_TRANSFER_PROTOCOL_H
    