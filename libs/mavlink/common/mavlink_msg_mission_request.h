#ifndef MAVLINK_CPP_MSG_MISSION_REQUEST_H
#define MAVLINK_CPP_MSG_MISSION_REQUEST_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t mission_request_id = 40;
    const uint8_t mission_request_length = 4;
    const uint8_t mission_request_crc = 230;

    class mission_request : public mavlink::message
    {
      public:
        mission_request(uint8_t system_id, uint8_t component_id,  uint8_t target_system, uint8_t target_component, uint16_t seq):
          mavlink::message( mavlink::msg::mission_request_length,
                            system_id,
                            component_id,
                            mavlink::msg::mission_request_id,
                            mavlink::msg::mission_request_crc)
        {
           m_payload.push_back<uint16_t>(seq); ///< Sequence
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
          
        }

      	uint16_t get_seq() const
          {return m_payload.get<uint16_t>(0);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(2);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(3);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_MISSION_REQUEST_H
    