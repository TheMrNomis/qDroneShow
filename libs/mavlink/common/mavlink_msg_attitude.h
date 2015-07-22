#ifndef MAVLINK_CPP_MSG_ATTITUDE_H
#define MAVLINK_CPP_MSG_ATTITUDE_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t attitude_id = 30;
    const uint8_t attitude_length = 28;
    const uint8_t attitude_crc = 39;

    class attitude : public mavlink::message
    {
      public:
        attitude(uint8_t system_id, uint8_t component_id,  uint32_t  time_boot_ms, float  roll, float  pitch, float  yaw, float  rollspeed, float  pitchspeed, float  yawspeed):
          mavlink::message( mavlink::msg::attitude_length,
                            system_id,
                            component_id,
                            mavlink::msg::attitude_id)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot)
           m_payload.push_back<float>(roll); ///< Roll angle (rad, -pi..+pi)
           m_payload.push_back<float>(pitch); ///< Pitch angle (rad, -pi..+pi)
           m_payload.push_back<float>(yaw); ///< Yaw angle (rad, -pi..+pi)
           m_payload.push_back<float>(rollspeed); ///< Roll angular speed (rad/s)
           m_payload.push_back<float>(pitchspeed); ///< Pitch angular speed (rad/s)
           m_payload.push_back<float>(yawspeed); ///< Yaw angular speed (rad/s)
          
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	float get_roll() const
          {return m_payload.get<float>(4);}
      	float get_pitch() const
          {return m_payload.get<float>(8);}
      	float get_yaw() const
          {return m_payload.get<float>(12);}
      	float get_rollspeed() const
          {return m_payload.get<float>(16);}
      	float get_pitchspeed() const
          {return m_payload.get<float>(20);}
      	float get_yawspeed() const
          {return m_payload.get<float>(24);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_ATTITUDE_H
    