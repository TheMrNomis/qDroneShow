#ifndef MAVLINK_CPP_MSG_BATTERY_STATUS_H
#define MAVLINK_CPP_MSG_BATTERY_STATUS_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t battery_status_id = 147;
    const uint8_t battery_status_length = 36;
    const uint8_t battery_status_crc = 154;

    class battery_status : public mavlink::message
    {
      public:
        battery_status(uint8_t system_id, uint8_t component_id,  uint8_t  id, uint8_t  battery_function, uint8_t  type, int16_t  temperature, const uint16_t * voltages, int16_t  current_battery, int32_t  current_consumed, int32_t  energy_consumed, int8_t  battery_remaining):
          mavlink::message( mavlink::msg::battery_status_length,
                            system_id,
                            component_id,
                            mavlink::msg::battery_status_id)
        {
           m_payload.push_back<int32_t>(current_consumed); ///< Consumed charge, in milliampere hours (1 = 1 mAh), -1: autopilot does not provide mAh consumption estimate
           m_payload.push_back<int32_t>(energy_consumed); ///< Consumed energy, in 100*Joules (intergrated U*I*dt)  (1 = 100 Joule), -1: autopilot does not provide energy consumption estimate
           m_payload.push_back<int16_t>(temperature); ///< Temperature of the battery in centi-degrees celsius. INT16_MAX for unknown temperature.
           m_payload.push_back<int16_t>(current_battery); ///< Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current
           m_payload.push_back<uint8_t>(id); ///< Battery ID
           m_payload.push_back<uint8_t>(battery_function); ///< Function of the battery
           m_payload.push_back<uint8_t>(type); ///< Type (chemistry) of the battery
           m_payload.push_back<int8_t>(battery_remaining); ///< Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot does not estimate the remaining battery
          
          	m_payload.push_back_array<uint16_t>(voltages, 10); ///< Battery voltage of cells, in millivolts (1 = 1 millivolt)
          
        }

      	int32_t get_current_consumed() const
          {return m_payload.get<int32_t>(0);}
      	int32_t get_energy_consumed() const
          {return m_payload.get<int32_t>(4);}
      	int16_t get_temperature() const
          {return m_payload.get<int16_t>(8);}
      	int16_t get_current_battery() const
          {return m_payload.get<int16_t>(30);}
      	uint8_t get_id() const
          {return m_payload.get<uint8_t>(32);}
      	uint8_t get_battery_function() const
          {return m_payload.get<uint8_t>(33);}
      	uint8_t get_type() const
          {return m_payload.get<uint8_t>(34);}
      	int8_t get_battery_remaining() const
          {return m_payload.get<int8_t>(35);}
      
       uint16_t * get_voltages() const
          {return m_payload.get_array<uint16_t>(10, 10);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_BATTERY_STATUS_H
    