#ifndef MAVLINK_CPP_MSG_MISSION_SET_CURRENT_H
#define MAVLINK_CPP_MSG_MISSION_SET_CURRENT_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t mission_set_current_id = 41;
    const uint8_t mission_set_current_length = 4;
    const uint8_t mission_set_current_crc = 28;

    class mission_set_current : public mavlink::message
    {
      public:
        mission_set_current(uint8_t system_id, uint8_t component_id,  uint8_t  target_system, uint8_t  target_component, uint16_t  seq):
          mavlink::message( mavlink::msg::mission_set_current_length,
                            system_id,
                            component_id,
                            mavlink::msg::mission_set_current_id)
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

#endif //MAVLINK_CPP_MSG_MISSION_SET_CURRENT_H
    