#ifndef MAVLINK_CPP_MSG_SYS_STATUS_H
#define MAVLINK_CPP_MSG_SYS_STATUS_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t sys_status_id = 1;
    const uint8_t sys_status_length = 31;
    const uint8_t sys_status_crc = 124;

    class sys_status : public mavlink::message
    {
      public:
        sys_status(uint8_t system_id, uint8_t component_id,  uint32_t  onboard_control_sensors_present, uint32_t  onboard_control_sensors_enabled, uint32_t  onboard_control_sensors_health, uint16_t  load, uint16_t  voltage_battery, int16_t  current_battery, int8_t  battery_remaining, uint16_t  drop_rate_comm, uint16_t  errors_comm, uint16_t  errors_count1, uint16_t  errors_count2, uint16_t  errors_count3, uint16_t  errors_count4):
          mavlink::message( mavlink::msg::sys_status_length,
                            system_id,
                            component_id,
                            mavlink::msg::sys_status_id)
        {
           m_payload.push_back<uint32_t>(onboard_control_sensors_present); ///< Bitmask showing which onboard controllers and sensors are present. Value of 0: not present. Value of 1: present. Indices defined by ENUM MAV_SYS_STATUS_SENSOR
           m_payload.push_back<uint32_t>(onboard_control_sensors_enabled); ///< Bitmask showing which onboard controllers and sensors are enabled:  Value of 0: not enabled. Value of 1: enabled. Indices defined by ENUM MAV_SYS_STATUS_SENSOR
           m_payload.push_back<uint32_t>(onboard_control_sensors_health); ///< Bitmask showing which onboard controllers and sensors are operational or have an error:  Value of 0: not enabled. Value of 1: enabled. Indices defined by ENUM MAV_SYS_STATUS_SENSOR
           m_payload.push_back<uint16_t>(load); ///< Maximum usage in percent of the mainloop time, (0%: 0, 100%: 1000) should be always below 1000
           m_payload.push_back<uint16_t>(voltage_battery); ///< Battery voltage, in millivolts (1 = 1 millivolt)
           m_payload.push_back<int16_t>(current_battery); ///< Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current
           m_payload.push_back<uint16_t>(drop_rate_comm); ///< Communication drops in percent, (0%: 0, 100%: 10'000), (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)
           m_payload.push_back<uint16_t>(errors_comm); ///< Communication errors (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)
           m_payload.push_back<uint16_t>(errors_count1); ///< Autopilot-specific errors
           m_payload.push_back<uint16_t>(errors_count2); ///< Autopilot-specific errors
           m_payload.push_back<uint16_t>(errors_count3); ///< Autopilot-specific errors
           m_payload.push_back<uint16_t>(errors_count4); ///< Autopilot-specific errors
           m_payload.push_back<int8_t>(battery_remaining); ///< Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot estimate the remaining battery
          
          
        }

      	uint32_t get_onboard_control_sensors_present() const
          {return m_payload.get<uint32_t>(0);}
      	uint32_t get_onboard_control_sensors_enabled() const
          {return m_payload.get<uint32_t>(4);}
      	uint32_t get_onboard_control_sensors_health() const
          {return m_payload.get<uint32_t>(8);}
      	uint16_t get_load() const
          {return m_payload.get<uint16_t>(12);}
      	uint16_t get_voltage_battery() const
          {return m_payload.get<uint16_t>(14);}
      	int16_t get_current_battery() const
          {return m_payload.get<int16_t>(16);}
      	uint16_t get_drop_rate_comm() const
          {return m_payload.get<uint16_t>(18);}
      	uint16_t get_errors_comm() const
          {return m_payload.get<uint16_t>(20);}
      	uint16_t get_errors_count1() const
          {return m_payload.get<uint16_t>(22);}
      	uint16_t get_errors_count2() const
          {return m_payload.get<uint16_t>(24);}
      	uint16_t get_errors_count3() const
          {return m_payload.get<uint16_t>(26);}
      	uint16_t get_errors_count4() const
          {return m_payload.get<uint16_t>(28);}
      	int8_t get_battery_remaining() const
          {return m_payload.get<int8_t>(30);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_SYS_STATUS_H
    