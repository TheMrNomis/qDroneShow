#ifndef MAVLINK_CPP_MSG_SIM_STATE_H
#define MAVLINK_CPP_MSG_SIM_STATE_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t sim_state_id = 108;
    const uint8_t sim_state_length = 84;
    const uint8_t sim_state_crc = 32;

    class sim_state : public mavlink::message
    {
      public:
        sim_state(uint8_t system_id, uint8_t component_id,  float  q1, float  q2, float  q3, float  q4, float  roll, float  pitch, float  yaw, float  xacc, float  yacc, float  zacc, float  xgyro, float  ygyro, float  zgyro, float  lat, float  lon, float  alt, float  std_dev_horz, float  std_dev_vert, float  vn, float  ve, float  vd):
          mavlink::message( mavlink::msg::sim_state_length,
                            system_id,
                            component_id,
                            mavlink::msg::sim_state_id)
        {
           m_payload.push_back<float>(q1); ///< True attitude quaternion component 1, w (1 in null-rotation)
           m_payload.push_back<float>(q2); ///< True attitude quaternion component 2, x (0 in null-rotation)
           m_payload.push_back<float>(q3); ///< True attitude quaternion component 3, y (0 in null-rotation)
           m_payload.push_back<float>(q4); ///< True attitude quaternion component 4, z (0 in null-rotation)
           m_payload.push_back<float>(roll); ///< Attitude roll expressed as Euler angles, not recommended except for human-readable outputs
           m_payload.push_back<float>(pitch); ///< Attitude pitch expressed as Euler angles, not recommended except for human-readable outputs
           m_payload.push_back<float>(yaw); ///< Attitude yaw expressed as Euler angles, not recommended except for human-readable outputs
           m_payload.push_back<float>(xacc); ///< X acceleration m/s/s
           m_payload.push_back<float>(yacc); ///< Y acceleration m/s/s
           m_payload.push_back<float>(zacc); ///< Z acceleration m/s/s
           m_payload.push_back<float>(xgyro); ///< Angular speed around X axis rad/s
           m_payload.push_back<float>(ygyro); ///< Angular speed around Y axis rad/s
           m_payload.push_back<float>(zgyro); ///< Angular speed around Z axis rad/s
           m_payload.push_back<float>(lat); ///< Latitude in degrees
           m_payload.push_back<float>(lon); ///< Longitude in degrees
           m_payload.push_back<float>(alt); ///< Altitude in meters
           m_payload.push_back<float>(std_dev_horz); ///< Horizontal position standard deviation
           m_payload.push_back<float>(std_dev_vert); ///< Vertical position standard deviation
           m_payload.push_back<float>(vn); ///< True velocity in m/s in NORTH direction in earth-fixed NED frame
           m_payload.push_back<float>(ve); ///< True velocity in m/s in EAST direction in earth-fixed NED frame
           m_payload.push_back<float>(vd); ///< True velocity in m/s in DOWN direction in earth-fixed NED frame
          
          
        }

      	float get_q1() const
          {return m_payload.get<float>(0);}
      	float get_q2() const
          {return m_payload.get<float>(4);}
      	float get_q3() const
          {return m_payload.get<float>(8);}
      	float get_q4() const
          {return m_payload.get<float>(12);}
      	float get_roll() const
          {return m_payload.get<float>(16);}
      	float get_pitch() const
          {return m_payload.get<float>(20);}
      	float get_yaw() const
          {return m_payload.get<float>(24);}
      	float get_xacc() const
          {return m_payload.get<float>(28);}
      	float get_yacc() const
          {return m_payload.get<float>(32);}
      	float get_zacc() const
          {return m_payload.get<float>(36);}
      	float get_xgyro() const
          {return m_payload.get<float>(40);}
      	float get_ygyro() const
          {return m_payload.get<float>(44);}
      	float get_zgyro() const
          {return m_payload.get<float>(48);}
      	float get_lat() const
          {return m_payload.get<float>(52);}
      	float get_lon() const
          {return m_payload.get<float>(56);}
      	float get_alt() const
          {return m_payload.get<float>(60);}
      	float get_std_dev_horz() const
          {return m_payload.get<float>(64);}
      	float get_std_dev_vert() const
          {return m_payload.get<float>(68);}
      	float get_vn() const
          {return m_payload.get<float>(72);}
      	float get_ve() const
          {return m_payload.get<float>(76);}
      	float get_vd() const
          {return m_payload.get<float>(80);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_SIM_STATE_H
    