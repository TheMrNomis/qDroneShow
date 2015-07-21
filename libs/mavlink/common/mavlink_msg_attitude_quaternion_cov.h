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
        attitude_quaternion_cov(uint8_t system_id, uint8_t component_id,  uint32_t time_boot_ms, const float *q, float rollspeed, float pitchspeed, float yawspeed, const float *covariance):
          mavlink::message( mavlink::msg::attitude_quaternion_cov_length,
                            system_id,
                            component_id,
                            mavlink::msg::attitude_quaternion_cov_id,
                            mavlink::msg::attitude_quaternion_cov_crc)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot)
           m_payload.push_back<float>(rollspeed); ///< Roll angular speed (rad/s)
           m_payload.push_back<float>(pitchspeed); ///< Pitch angular speed (rad/s)
           m_payload.push_back<float>(yawspeed); ///< Yaw angular speed (rad/s)
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	float get_rollspeed() const
          {return m_payload.get<float>(20);}
      	float get_pitchspeed() const
          {return m_payload.get<float>(24);}
      	float get_yawspeed() const
          {return m_payload.get<float>(28);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_ATTITUDE_QUATERNION_COV_H
    