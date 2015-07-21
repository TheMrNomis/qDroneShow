#ifndef MAVLINK_CPP_MSG_RAW_PRESSURE_H
#define MAVLINK_CPP_MSG_RAW_PRESSURE_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t raw_pressure_id = 28;
    const uint8_t raw_pressure_length = 16;
    const uint8_t raw_pressure_crc = 67;

    class raw_pressure : public mavlink::message
    {
      public:
        raw_pressure(uint8_t system_id, uint8_t component_id,  uint64_t time_usec, int16_t press_abs, int16_t press_diff1, int16_t press_diff2, int16_t temperature):
          mavlink::message( mavlink::msg::raw_pressure_length,
                            system_id,
                            component_id,
                            mavlink::msg::raw_pressure_id,
                            mavlink::msg::raw_pressure_crc)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
           m_payload.push_back<int16_t>(press_abs); ///< Absolute pressure (raw)
           m_payload.push_back<int16_t>(press_diff1); ///< Differential pressure 1 (raw)
           m_payload.push_back<int16_t>(press_diff2); ///< Differential pressure 2 (raw)
           m_payload.push_back<int16_t>(temperature); ///< Raw Temperature measurement (raw)
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	int16_t get_press_abs() const
          {return m_payload.get<int16_t>(8);}
      	int16_t get_press_diff1() const
          {return m_payload.get<int16_t>(10);}
      	int16_t get_press_diff2() const
          {return m_payload.get<int16_t>(12);}
      	int16_t get_temperature() const
          {return m_payload.get<int16_t>(14);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_RAW_PRESSURE_H
    