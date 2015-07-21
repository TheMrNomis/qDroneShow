#ifndef MAVLINK_CPP_MSG_HIL_CONTROLS_H
#define MAVLINK_CPP_MSG_HIL_CONTROLS_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t hil_controls_id = 91;
    const uint8_t hil_controls_length = 42;
    const uint8_t hil_controls_crc = 63;

    class hil_controls : public mavlink::message
    {
      public:
        hil_controls(uint8_t system_id, uint8_t component_id,  uint64_t time_usec, float roll_ailerons, float pitch_elevator, float yaw_rudder, float throttle, float aux1, float aux2, float aux3, float aux4, uint8_t mode, uint8_t nav_mode):
          mavlink::message( mavlink::msg::hil_controls_length,
                            system_id,
                            component_id,
                            mavlink::msg::hil_controls_id,
                            mavlink::msg::hil_controls_crc)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
           m_payload.push_back<float>(roll_ailerons); ///< Control output -1 .. 1
           m_payload.push_back<float>(pitch_elevator); ///< Control output -1 .. 1
           m_payload.push_back<float>(yaw_rudder); ///< Control output -1 .. 1
           m_payload.push_back<float>(throttle); ///< Throttle 0 .. 1
           m_payload.push_back<float>(aux1); ///< Aux 1, -1 .. 1
           m_payload.push_back<float>(aux2); ///< Aux 2, -1 .. 1
           m_payload.push_back<float>(aux3); ///< Aux 3, -1 .. 1
           m_payload.push_back<float>(aux4); ///< Aux 4, -1 .. 1
           m_payload.push_back<uint8_t>(mode); ///< System mode (MAV_MODE)
           m_payload.push_back<uint8_t>(nav_mode); ///< Navigation mode (MAV_NAV_MODE)
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	float get_roll_ailerons() const
          {return m_payload.get<float>(8);}
      	float get_pitch_elevator() const
          {return m_payload.get<float>(12);}
      	float get_yaw_rudder() const
          {return m_payload.get<float>(16);}
      	float get_throttle() const
          {return m_payload.get<float>(20);}
      	float get_aux1() const
          {return m_payload.get<float>(24);}
      	float get_aux2() const
          {return m_payload.get<float>(28);}
      	float get_aux3() const
          {return m_payload.get<float>(32);}
      	float get_aux4() const
          {return m_payload.get<float>(36);}
      	uint8_t get_mode() const
          {return m_payload.get<uint8_t>(40);}
      	uint8_t get_nav_mode() const
          {return m_payload.get<uint8_t>(41);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_HIL_CONTROLS_H
    