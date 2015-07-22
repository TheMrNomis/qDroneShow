#ifndef MAVLINK_CPP_MSG_DEBUG_H
#define MAVLINK_CPP_MSG_DEBUG_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t debug_id = 254;
    const uint8_t debug_length = 9;
    const uint8_t debug_crc = 46;

    class debug : public mavlink::message
    {
      public:
        debug(uint8_t system_id, uint8_t component_id,  uint32_t  time_boot_ms, uint8_t  ind, float  value):
          mavlink::message( mavlink::msg::debug_length,
                            system_id,
                            component_id,
                            mavlink::msg::debug_id)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot)
           m_payload.push_back<float>(value); ///< DEBUG value
           m_payload.push_back<uint8_t>(ind); ///< index of debug variable
          
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	float get_value() const
          {return m_payload.get<float>(4);}
      	uint8_t get_ind() const
          {return m_payload.get<uint8_t>(8);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_DEBUG_H
    