#ifndef MAVLINK_CPP_MSG_LOG_REQUEST_END_H
#define MAVLINK_CPP_MSG_LOG_REQUEST_END_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t log_request_end_id = 122;
    const uint8_t log_request_end_length = 2;
    const uint8_t log_request_end_crc = 203;

    class log_request_end : public mavlink::message
    {
      public:
        log_request_end(uint8_t system_id, uint8_t component_id,  uint8_t  target_system, uint8_t  target_component):
          mavlink::message( mavlink::msg::log_request_end_length,
                            system_id,
                            component_id,
                            mavlink::msg::log_request_end_id)
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

#endif //MAVLINK_CPP_MSG_LOG_REQUEST_END_H
    