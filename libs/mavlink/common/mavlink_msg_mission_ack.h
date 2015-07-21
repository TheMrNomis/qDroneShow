#ifndef MAVLINK_CPP_MSG_MISSION_ACK_H
#define MAVLINK_CPP_MSG_MISSION_ACK_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t mission_ack_id = 47;
    const uint8_t mission_ack_length = 3;
    const uint8_t mission_ack_crc = 153;

    class mission_ack : public mavlink::message
    {
      public:
        mission_ack(uint8_t system_id, uint8_t component_id,  uint8_t target_system, uint8_t target_component, uint8_t type):
          mavlink::message( mavlink::msg::mission_ack_length,
                            system_id,
                            component_id,
                            mavlink::msg::mission_ack_id,
                            mavlink::msg::mission_ack_crc)
        {
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
           m_payload.push_back<uint8_t>(type); ///< See MAV_MISSION_RESULT enum
          
        }

      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(0);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(1);}
      	uint8_t get_type() const
          {return m_payload.get<uint8_t>(2);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_MISSION_ACK_H
    