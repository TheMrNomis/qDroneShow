#ifndef MAVLINK_CPP_MSG_HIL_STATE_H
#define MAVLINK_CPP_MSG_HIL_STATE_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t hil_state_id = 90;
    const uint8_t hil_state_length = 56;
    const uint8_t hil_state_crc = 183;

    class hil_state : public mavlink::message
    {
      public:
        hil_state(uint8_t system_id, uint8_t component_id,  uint64_t time_usec, float roll, float pitch, float yaw, float rollspeed, float pitchspeed, float yawspeed, int32_t lat, int32_t lon, int32_t alt, int16_t vx, int16_t vy, int16_t vz, int16_t xacc, int16_t yacc, int16_t zacc):
          mavlink::message( mavlink::msg::hil_state_length,
                            system_id,
                            component_id,
                            mavlink::msg::hil_state_id,
                            mavlink::msg::hil_state_crc)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
           m_payload.push_back<float>(roll); ///< Roll angle (rad)
           m_payload.push_back<float>(pitch); ///< Pitch angle (rad)
           m_payload.push_back<float>(yaw); ///< Yaw angle (rad)
           m_payload.push_back<float>(rollspeed); ///< Body frame roll / phi angular speed (rad/s)
           m_payload.push_back<float>(pitchspeed); ///< Body frame pitch / theta angular speed (rad/s)
           m_payload.push_back<float>(yawspeed); ///< Body frame yaw / psi angular speed (rad/s)
           m_payload.push_back<int32_t>(lat); ///< Latitude, expressed as * 1E7
           m_payload.push_back<int32_t>(lon); ///< Longitude, expressed as * 1E7
           m_payload.push_back<int32_t>(alt); ///< Altitude in meters, expressed as * 1000 (millimeters)
           m_payload.push_back<int16_t>(vx); ///< Ground X Speed (Latitude), expressed as m/s * 100
           m_payload.push_back<int16_t>(vy); ///< Ground Y Speed (Longitude), expressed as m/s * 100
           m_payload.push_back<int16_t>(vz); ///< Ground Z Speed (Altitude), expressed as m/s * 100
           m_payload.push_back<int16_t>(xacc); ///< X acceleration (mg)
           m_payload.push_back<int16_t>(yacc); ///< Y acceleration (mg)
           m_payload.push_back<int16_t>(zacc); ///< Z acceleration (mg)
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	float get_roll() const
          {return m_payload.get<float>(8);}
      	float get_pitch() const
          {return m_payload.get<float>(12);}
      	float get_yaw() const
          {return m_payload.get<float>(16);}
      	float get_rollspeed() const
          {return m_payload.get<float>(20);}
      	float get_pitchspeed() const
          {return m_payload.get<float>(24);}
      	float get_yawspeed() const
          {return m_payload.get<float>(28);}
      	int32_t get_lat() const
          {return m_payload.get<int32_t>(32);}
      	int32_t get_lon() const
          {return m_payload.get<int32_t>(36);}
      	int32_t get_alt() const
          {return m_payload.get<int32_t>(40);}
      	int16_t get_vx() const
          {return m_payload.get<int16_t>(44);}
      	int16_t get_vy() const
          {return m_payload.get<int16_t>(46);}
      	int16_t get_vz() const
          {return m_payload.get<int16_t>(48);}
      	int16_t get_xacc() const
          {return m_payload.get<int16_t>(50);}
      	int16_t get_yacc() const
          {return m_payload.get<int16_t>(52);}
      	int16_t get_zacc() const
          {return m_payload.get<int16_t>(54);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_HIL_STATE_H
    