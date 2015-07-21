#ifndef MAVLINK_CPP_MSG_MISSION_REQUEST_PARTIAL_LIST_H
#define MAVLINK_CPP_MSG_MISSION_REQUEST_PARTIAL_LIST_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t mission_request_partial_list_id = 37;
    const uint8_t mission_request_partial_list_length = 6;
    const uint8_t mission_request_partial_list_crc = 212;

    class mission_request_partial_list : public mavlink::message
    {
      public:
        mission_request_partial_list(uint8_t system_id, uint8_t component_id,  uint8_t target_system, uint8_t target_component, int16_t start_index, int16_t end_index):
          mavlink::message( mavlink::msg::mission_request_partial_list_length,
                            system_id,
                            component_id,
                            mavlink::msg::mission_request_partial_list_id,
                            mavlink::msg::mission_request_partial_list_crc)
        {
           m_payload.push_back<int16_t>(start_index); ///< Start index, 0 by default
           m_payload.push_back<int16_t>(end_index); ///< End index, -1 by default (-1: send list to end). Else a valid index of the list
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

#endif //MAVLINK_CPP_MSG_MISSION_REQUEST_PARTIAL_LIST_H
    