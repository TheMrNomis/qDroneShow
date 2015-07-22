#ifndef MAVLINK_CPP_MSG_MISSION_COUNT_H
#define MAVLINK_CPP_MSG_MISSION_COUNT_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t mission_count_id = 44;
    const uint8_t mission_count_length = 4;
    const uint8_t mission_count_crc = 221;

    class mission_count : public mavlink::message
    {
      public:
        mission_count(uint8_t system_id, uint8_t component_id,  uint8_t  target_system, uint8_t  target_component, uint16_t  count):
          mavlink::message( mavlink::msg::mission_count_length,
                            system_id,
                            component_id,
                            mavlink::msg::mission_count_id)
        {
           m_payload.push_back<uint16_t>(count); ///< Number of mission items in the sequence
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
          
          
        }

      	uint16_t get_count() const
          {return m_payload.get<uint16_t>(0);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(2);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(3);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_MISSION_COUNT_H
    