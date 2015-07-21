#ifndef MAVLINK_CPP_MSG_MANUAL_SETPOINT_H
#define MAVLINK_CPP_MSG_MANUAL_SETPOINT_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t manual_setpoint_id = 81;
    const uint8_t manual_setpoint_length = 22;
    const uint8_t manual_setpoint_crc = 106;

    class manual_setpoint : public mavlink::message
    {
      public:
        manual_setpoint(uint8_t system_id, uint8_t component_id,  uint32_t time_boot_ms, float roll, float pitch, float yaw, float thrust, uint8_t mode_switch, uint8_t manual_override_switch):
          mavlink::message( mavlink::msg::manual_setpoint_length,
                            system_id,
                            component_id,
                            mavlink::msg::manual_setpoint_id,
                            mavlink::msg::manual_setpoint_crc)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp in milliseconds since system boot
           m_payload.push_back<float>(roll); ///< Desired roll rate in radians per second
           m_payload.push_back<float>(pitch); ///< Desired pitch rate in radians per second
           m_payload.push_back<float>(yaw); ///< Desired yaw rate in radians per second
           m_payload.push_back<float>(thrust); ///< Collective thrust, normalized to 0 .. 1
           m_payload.push_back<uint8_t>(mode_switch); ///< Flight mode switch position, 0.. 255
           m_payload.push_back<uint8_t>(manual_override_switch); ///< Override mode switch position, 0.. 255
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	float get_roll() const
          {return m_payload.get<float>(4);}
      	float get_pitch() const
          {return m_payload.get<float>(8);}
      	float get_yaw() const
          {return m_payload.get<float>(12);}
      	float get_thrust() const
          {return m_payload.get<float>(16);}
      	uint8_t get_mode_switch() const
          {return m_payload.get<uint8_t>(20);}
      	uint8_t get_manual_override_switch() const
          {return m_payload.get<uint8_t>(21);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_MANUAL_SETPOINT_H
    