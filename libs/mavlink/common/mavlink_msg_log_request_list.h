#ifndef MAVLINK_CPP_MSG_LOG_REQUEST_LIST_H
#define MAVLINK_CPP_MSG_LOG_REQUEST_LIST_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t log_request_list_id = 117;
    const uint8_t log_request_list_length = 6;
    const uint8_t log_request_list_crc = 128;

    class log_request_list : public mavlink::message
    {
      public:
        log_request_list(uint8_t system_id, uint8_t component_id,  uint8_t  target_system, uint8_t  target_component, uint16_t  start, uint16_t  end):
          mavlink::message( mavlink::msg::log_request_list_length,
                            system_id,
                            component_id,
                            mavlink::msg::log_request_list_id)
        {
           m_payload.push_back<uint16_t>(start); ///< First log id (0 for first available)
           m_payload.push_back<uint16_t>(end); ///< Last log id (0xffff for last available)
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
          
          
        }

      	uint16_t get_start() const
          {return m_payload.get<uint16_t>(0);}
      	uint16_t get_end() const
          {return m_payload.get<uint16_t>(2);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(4);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(5);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_LOG_REQUEST_LIST_H
    