#ifndef MAVLINK_CPP_MSG_ACTUATOR_CONTROL_TARGET_H
#define MAVLINK_CPP_MSG_ACTUATOR_CONTROL_TARGET_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t actuator_control_target_id = 140;
    const uint8_t actuator_control_target_length = 41;
    const uint8_t actuator_control_target_crc = 181;

    class actuator_control_target : public mavlink::message
    {
      public:
        actuator_control_target(uint8_t system_id, uint8_t component_id,  uint64_t  time_usec, uint8_t  group_mlx, const float * controls):
          mavlink::message( mavlink::msg::actuator_control_target_length,
                            system_id,
                            component_id,
                            mavlink::msg::actuator_control_target_id)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (micros since boot or Unix epoch)
           m_payload.push_back<uint8_t>(group_mlx); ///< Actuator group. The "_mlx" indicates this is a multi-instance message and a MAVLink parser should use this field to difference between instances.
          
          	m_payload.push_back_array<float>(controls, 8); ///< Actuator controls. Normed to -1..+1 where 0 is neutral position. Throttle for single rotation direction motors is 0..1, negative range for reverse direction. Standard mapping for attitude controls (group 0): (index 0-7): roll, pitch, yaw, throttle, flaps, spoilers, airbrakes, landing gear. Load a pass-through mixer to repurpose them as generic outputs.
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	uint8_t get_group_mlx() const
          {return m_payload.get<uint8_t>(40);}
      
       float * get_controls() const
          {return m_payload.get_array<float>(8, 8);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_ACTUATOR_CONTROL_TARGET_H
    