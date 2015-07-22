#ifndef MAVLINK_CPP_MSG_ATTITUDE_QUATERNION_H
#define MAVLINK_CPP_MSG_ATTITUDE_QUATERNION_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t attitude_quaternion_id = 31;
    const uint8_t attitude_quaternion_length = 32;
    const uint8_t attitude_quaternion_crc = 246;

    class attitude_quaternion : public mavlink::message
    {
      public:
        attitude_quaternion(uint8_t system_id, uint8_t component_id,  uint32_t  time_boot_ms, float  q1, float  q2, float  q3, float  q4, float  rollspeed, float  pitchspeed, float  yawspeed):
          mavlink::message( mavlink::msg::attitude_quaternion_length,
                            system_id,
                            component_id,
                            mavlink::msg::attitude_quaternion_id)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot)
           m_payload.push_back<float>(q1); ///< Quaternion component 1, w (1 in null-rotation)
           m_payload.push_back<float>(q2); ///< Quaternion component 2, x (0 in null-rotation)
           m_payload.push_back<float>(q3); ///< Quaternion component 3, y (0 in null-rotation)
           m_payload.push_back<float>(q4); ///< Quaternion component 4, z (0 in null-rotation)
           m_payload.push_back<float>(rollspeed); ///< Roll angular speed (rad/s)
           m_payload.push_back<float>(pitchspeed); ///< Pitch angular speed (rad/s)
           m_payload.push_back<float>(yawspeed); ///< Yaw angular speed (rad/s)
          
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	float get_q1() const
          {return m_payload.get<float>(4);}
      	float get_q2() const
          {return m_payload.get<float>(8);}
      	float get_q3() const
          {return m_payload.get<float>(12);}
      	float get_q4() const
          {return m_payload.get<float>(16);}
      	float get_rollspeed() const
          {return m_payload.get<float>(20);}
      	float get_pitchspeed() const
          {return m_payload.get<float>(24);}
      	float get_yawspeed() const
          {return m_payload.get<float>(28);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_ATTITUDE_QUATERNION_H
    