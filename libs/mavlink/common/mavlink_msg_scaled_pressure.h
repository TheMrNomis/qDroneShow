#ifndef MAVLINK_CPP_MSG_SCALED_PRESSURE_H
#define MAVLINK_CPP_MSG_SCALED_PRESSURE_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t scaled_pressure_id = 29;
    const uint8_t scaled_pressure_length = 14;
    const uint8_t scaled_pressure_crc = 115;

    class scaled_pressure : public mavlink::message
    {
      public:
        scaled_pressure(uint8_t system_id, uint8_t component_id,  uint32_t  time_boot_ms, float  press_abs, float  press_diff, int16_t  temperature):
          mavlink::message( mavlink::msg::scaled_pressure_length,
                            system_id,
                            component_id,
                            mavlink::msg::scaled_pressure_id)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot)
           m_payload.push_back<float>(press_abs); ///< Absolute pressure (hectopascal)
           m_payload.push_back<float>(press_diff); ///< Differential pressure 1 (hectopascal)
           m_payload.push_back<int16_t>(temperature); ///< Temperature measurement (0.01 degrees celsius)
          
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	float get_press_abs() const
          {return m_payload.get<float>(4);}
      	float get_press_diff() const
          {return m_payload.get<float>(8);}
      	int16_t get_temperature() const
          {return m_payload.get<int16_t>(12);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_SCALED_PRESSURE_H
    