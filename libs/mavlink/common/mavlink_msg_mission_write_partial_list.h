#ifndef MAVLINK_CPP_MSG_MISSION_WRITE_PARTIAL_LIST_H
#define MAVLINK_CPP_MSG_MISSION_WRITE_PARTIAL_LIST_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t mission_write_partial_list_id = 38;
    const uint8_t mission_write_partial_list_length = 6;
    const uint8_t mission_write_partial_list_crc = 9;

    class mission_write_partial_list : public mavlink::message
    {
      public:
        mission_write_partial_list(uint8_t system_id, uint8_t component_id,  uint8_t  target_system, uint8_t  target_component, int16_t  start_index, int16_t  end_index):
          mavlink::message( mavlink::msg::mission_write_partial_list_length,
                            system_id,
                            component_id,
                            mavlink::msg::mission_write_partial_list_id)
        {
           m_payload.push_back<int16_t>(start_index); ///< Start index, 0 by default and smaller / equal to the largest index of the current onboard list.
           m_payload.push_back<int16_t>(end_index); ///< End index, equal or greater than start index.
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
          
          
        }

      	int16_t get_start_index() const
          {return m_payload.get<int16_t>(0);}
      	int16_t get_end_index() const
          {return m_payload.get<int16_t>(2);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(4);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(5);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_MISSION_WRITE_PARTIAL_LIST_H
    