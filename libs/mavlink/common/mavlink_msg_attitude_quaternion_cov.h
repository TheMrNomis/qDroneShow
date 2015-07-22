#ifndef MAVLINK_CPP_MSG_ATTITUDE_QUATERNION_COV_H
#define MAVLINK_CPP_MSG_ATTITUDE_QUATERNION_COV_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t attitude_quaternion_cov_id = 61;
    const uint8_t attitude_quaternion_cov_length = 68;
    const uint8_t attitude_quaternion_cov_crc = 153;

    class attitude_quaternion_cov : public mavlink::message
    {
      public:
        attitude_quaternion_cov(uint8_t system_id, uint8_t component_id,  uint32_t  time_boot_ms, const float * q, float  rollspeed, float  pitchspeed, float  yawspeed, const float * covariance):
          mavlink::message( mavlink::msg::attitude_quaternion_cov_length,
                            system_id,
                            component_id,
                            mavlink::msg::attitude_quaternion_cov_id)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot)
           m_payload.push_back<float>(rollspeed); ///< Roll angular speed (rad/s)
           m_payload.push_back<float>(pitchspeed); ///< Pitch angular speed (rad/s)
           m_payload.push_back<float>(yawspeed); ///< Yaw angular speed (rad/s)
          
          	m_payload.push_back_array<float>(q, 4); ///< Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation)
          	m_payload.push_back_array<float>(covariance, 9); ///< Attitude covariance
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	float get_rollspeed() const
          {return m_payload.get<float>(20);}
      	float get_pitchspeed() const
          {return m_payload.get<float>(24);}
      	float get_yawspeed() const
          {return m_payload.get<float>(28);}
      
       float * get_q() const
          {return m_payload.get_array<float>(4, 4);}
       float * get_covariance() const
          {return m_payload.get_array<float>(32, 9);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_ATTITUDE_QUATERNION_COV_H
    