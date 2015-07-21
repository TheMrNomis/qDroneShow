#ifndef MAVLINK_CPP_MSG_NAMED_VALUE_INT_H
#define MAVLINK_CPP_MSG_NAMED_VALUE_INT_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t named_value_int_id = 252;
    const uint8_t named_value_int_length = 18;
    const uint8_t named_value_int_crc = 44;

    class named_value_int : public mavlink::message
    {
      public:
        named_value_int(uint8_t system_id, uint8_t component_id,  uint32_t time_boot_ms, const char *name, int32_t value):
          mavlink::message( mavlink::msg::named_value_int_length,
                            system_id,
                            component_id,
                            mavlink::msg::named_value_int_id,
                            mavlink::msg::named_value_int_crc)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot)
           m_payload.push_back<int32_t>(value); ///< Signed integer value
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	int32_t get_value() const
          {return m_payload.get<int32_t>(4);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_NAMED_VALUE_INT_H
    