#ifndef MAVLINK_CPP_MSG_HIL_STATE_QUATERNION_H
#define MAVLINK_CPP_MSG_HIL_STATE_QUATERNION_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t hil_state_quaternion_id = 115;
    const uint8_t hil_state_quaternion_length = 64;
    const uint8_t hil_state_quaternion_crc = 4;

    class hil_state_quaternion : public mavlink::message
    {
      public:
        hil_state_quaternion(uint8_t system_id, uint8_t component_id,  uint64_t time_usec, const float *attitude_quaternion, float rollspeed, float pitchspeed, float yawspeed, int32_t lat, int32_t lon, int32_t alt, int16_t vx, int16_t vy, int16_t vz, uint16_t ind_airspeed, uint16_t true_airspeed, int16_t xacc, int16_t yacc, int16_t zacc):
          mavlink::message( mavlink::msg::hil_state_quaternion_length,
                            system_id,
                            component_id,
                            mavlink::msg::hil_state_quaternion_id,
                            mavlink::msg::hil_state_quaternion_crc)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
           m_payload.push_back<float>(rollspeed); ///< Body frame roll / phi angular speed (rad/s)
           m_payload.push_back<float>(pitchspeed); ///< Body frame pitch / theta angular speed (rad/s)
           m_payload.push_back<float>(yawspeed); ///< Body frame yaw / psi angular speed (rad/s)
           m_payload.push_back<int32_t>(lat); ///< Latitude, expressed as * 1E7
           m_payload.push_back<int32_t>(lon); ///< Longitude, expressed as * 1E7
           m_payload.push_back<int32_t>(alt); ///< Altitude in meters, expressed as * 1000 (millimeters)
           m_payload.push_back<int16_t>(vx); ///< Ground X Speed (Latitude), expressed as m/s * 100
           m_payload.push_back<int16_t>(vy); ///< Ground Y Speed (Longitude), expressed as m/s * 100
           m_payload.push_back<int16_t>(vz); ///< Ground Z Speed (Altitude), expressed as m/s * 100
           m_payload.push_back<uint16_t>(ind_airspeed); ///< Indicated airspeed, expressed as m/s * 100
           m_payload.push_back<uint16_t>(true_airspeed); ///< True airspeed, expressed as m/s * 100
           m_payload.push_back<int16_t>(xacc); ///< X acceleration (mg)
           m_payload.push_back<int16_t>(yacc); ///< Y acceleration (mg)
           m_payload.push_back<int16_t>(zacc); ///< Z acceleration (mg)
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	float get_rollspeed() const
          {return m_payload.get<float>(24);}
      	float get_pitchspeed() const
          {return m_payload.get<float>(28);}
      	float get_yawspeed() const
          {return m_payload.get<float>(32);}
      	int32_t get_lat() const
          {return m_payload.get<int32_t>(36);}
      	int32_t get_lon() const
          {return m_payload.get<int32_t>(40);}
      	int32_t get_alt() const
          {return m_payload.get<int32_t>(44);}
      	int16_t get_vx() const
          {return m_payload.get<int16_t>(48);}
      	int16_t get_vy() const
          {return m_payload.get<int16_t>(50);}
      	int16_t get_vz() const
          {return m_payload.get<int16_t>(52);}
      	uint16_t get_ind_airspeed() const
          {return m_payload.get<uint16_t>(54);}
      	uint16_t get_true_airspeed() const
          {return m_payload.get<uint16_t>(56);}
      	int16_t get_xacc() const
          {return m_payload.get<int16_t>(58);}
      	int16_t get_yacc() const
          {return m_payload.get<int16_t>(60);}
      	int16_t get_zacc() const
          {return m_payload.get<int16_t>(62);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_HIL_STATE_QUATERNION_H
    