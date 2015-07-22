#ifndef MAVLINK_CPP_MSG_V2_EXTENSION_H
#define MAVLINK_CPP_MSG_V2_EXTENSION_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t v2_extension_id = 248;
    const uint8_t v2_extension_length = 254;
    const uint8_t v2_extension_crc = 8;

    class v2_extension : public mavlink::message
    {
      public:
        v2_extension(uint8_t system_id, uint8_t component_id,  uint8_t  target_network, uint8_t  target_system, uint8_t  target_component, uint16_t  message_type, const uint8_t * payload):
          mavlink::message( mavlink::msg::v2_extension_length,
                            system_id,
                            component_id,
                            mavlink::msg::v2_extension_id)
        {
           m_payload.push_back<uint16_t>(message_type); ///< A code that identifies the software component that understands this message (analogous to usb device classes or mime type strings).  If this code is less than 32768, it is considered a 'registered' protocol extension and the corresponding entry should be added to https://github.com/mavlink/mavlink/extension-message-ids.xml.  Software creators can register blocks of message IDs as needed (useful for GCS specific metadata, etc...). Message_types greater than 32767 are considered local experiments and should not be checked in to any widely distributed codebase.
           m_payload.push_back<uint8_t>(target_network); ///< Network ID (0 for broadcast)
           m_payload.push_back<uint8_t>(target_system); ///< System ID (0 for broadcast)
           m_payload.push_back<uint8_t>(target_component); ///< Component ID (0 for broadcast)
          
          	m_payload.push_back_array<uint8_t>(payload, 249); ///< Variable length payload. The length is defined by the remaining message length when subtracting the header and other fields.  The entire content of this block is opaque unless you understand any the encoding message_type.  The particular encoding used can be extension specific and might not always be documented as part of the mavlink specification.
          
        }

      	uint16_t get_message_type() const
          {return m_payload.get<uint16_t>(0);}
      	uint8_t get_target_network() const
          {return m_payload.get<uint8_t>(2);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(3);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(4);}
      
       uint8_t * get_payload() const
          {return m_payload.get_array<uint8_t>(5, 249);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_V2_EXTENSION_H
    