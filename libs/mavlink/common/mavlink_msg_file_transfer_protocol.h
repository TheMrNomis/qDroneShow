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
        file_transfer_protocol(uint8_t system_id, uint8_t component_id,  uint8_t target_network, uint8_t target_system, uint8_t target_component, const uint8_t *payload):
          mavlink::message( mavlink::msg::file_transfer_protocol_length,
                            system_id,
                            component_id,
                            mavlink::msg::file_transfer_protocol_id,
                            mavlink::msg::file_transfer_protocol_crc)
        {
           m_payload.push_back<uint8_t>(target_network); ///< Network ID (0 for broadcast)
           m_payload.push_back<uint8_t>(target_system); ///< System ID (0 for broadcast)
           m_payload.push_back<uint8_t>(target_component); ///< Component ID (0 for broadcast)
          
        }

      	uint8_t get_target_network() const
          {return m_payload.get<uint8_t>(0);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(1);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(2);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_FILE_TRANSFER_PROTOCOL_H
    