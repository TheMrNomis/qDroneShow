#ifndef MAVLINK_CPP_MSG_NAMED_VALUE_FLOAT_H
#define MAVLINK_CPP_MSG_NAMED_VALUE_FLOAT_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t named_value_float_id = 251;
    const uint8_t named_value_float_length = 18;
    const uint8_t named_value_float_crc = 170;

    class named_value_float : public mavlink::message
    {
      public:
        named_value_float(uint8_t system_id, uint8_t component_id,  uint32_t time_boot_ms, const char *name, float value):
          mavlink::message( mavlink::msg::named_value_float_length,
                            system_id,
                            component_id,
                            mavlink::msg::named_value_float_id,
                            mavlink::msg::named_value_float_crc)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot)
           m_payload.push_back<float>(value); ///< Floating point value
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	float get_value() const
          {return m_payload.get<float>(4);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_NAMED_VALUE_FLOAT_H
    