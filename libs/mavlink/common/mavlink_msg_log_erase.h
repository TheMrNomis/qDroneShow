#ifndef MAVLINK_CPP_MSG_LOG_ERASE_H
#define MAVLINK_CPP_MSG_LOG_ERASE_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t log_erase_id = 121;
    const uint8_t log_erase_length = 2;
    const uint8_t log_erase_crc = 237;

    class log_erase : public mavlink::message
    {
      public:
        log_erase(uint8_t system_id, uint8_t component_id,  uint8_t target_system, uint8_t target_component):
          mavlink::message( mavlink::msg::log_erase_length,
                            system_id,
                            component_id,
                            mavlink::msg::log_erase_id,
                            mavlink::msg::log_erase_crc)
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

#endif //MAVLINK_CPP_MSG_LOG_ERASE_H
    