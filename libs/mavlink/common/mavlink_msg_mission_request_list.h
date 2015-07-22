#ifndef MAVLINK_CPP_MSG_MISSION_REQUEST_LIST_H
#define MAVLINK_CPP_MSG_MISSION_REQUEST_LIST_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t mission_request_list_id = 43;
    const uint8_t mission_request_list_length = 2;
    const uint8_t mission_request_list_crc = 132;

    class mission_request_list : public mavlink::message
    {
      public:
        mission_request_list(uint8_t system_id, uint8_t component_id,  uint8_t  target_system, uint8_t  target_component):
          mavlink::message( mavlink::msg::mission_request_list_length,
                            system_id,
                            component_id,
                            mavlink::msg::mission_request_list_id)
        {
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
          
          
        }

      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(0);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(1);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_MISSION_REQUEST_LIST_H
    