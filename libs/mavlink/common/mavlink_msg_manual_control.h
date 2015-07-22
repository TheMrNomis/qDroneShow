#ifndef MAVLINK_CPP_MSG_MANUAL_CONTROL_H
#define MAVLINK_CPP_MSG_MANUAL_CONTROL_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t manual_control_id = 69;
    const uint8_t manual_control_length = 11;
    const uint8_t manual_control_crc = 243;

    class manual_control : public mavlink::message
    {
      public:
        manual_control(uint8_t system_id, uint8_t component_id,  uint8_t  target, int16_t  x, int16_t  y, int16_t  z, int16_t  r, uint16_t  buttons):
          mavlink::message( mavlink::msg::manual_control_length,
                            system_id,
                            component_id,
                            mavlink::msg::manual_control_id)
        {
           m_payload.push_back<int16_t>(x); ///< X-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to forward(1000)-backward(-1000) movement on a joystick and the pitch of a vehicle.
           m_payload.push_back<int16_t>(y); ///< Y-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to left(-1000)-right(1000) movement on a joystick and the roll of a vehicle.
           m_payload.push_back<int16_t>(z); ///< Z-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to a separate slider movement with maximum being 1000 and minimum being -1000 on a joystick and the thrust of a vehicle.
           m_payload.push_back<int16_t>(r); ///< R-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to a twisting of the joystick, with counter-clockwise being 1000 and clockwise being -1000, and the yaw of a vehicle.
           m_payload.push_back<uint16_t>(buttons); ///< A bitfield corresponding to the joystick buttons' current state, 1 for pressed, 0 for released. The lowest bit corresponds to Button 1.
           m_payload.push_back<uint8_t>(target); ///< The system to be controlled.
          
          
        }

      	int16_t get_x() const
          {return m_payload.get<int16_t>(0);}
      	int16_t get_y() const
          {return m_payload.get<int16_t>(2);}
      	int16_t get_z() const
          {return m_payload.get<int16_t>(4);}
      	int16_t get_r() const
          {return m_payload.get<int16_t>(6);}
      	uint16_t get_buttons() const
          {return m_payload.get<uint16_t>(8);}
      	uint8_t get_target() const
          {return m_payload.get<uint8_t>(10);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_MANUAL_CONTROL_H
    