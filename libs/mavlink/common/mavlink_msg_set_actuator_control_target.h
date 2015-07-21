#ifndef MAVLINK_CPP_MSG_SET_ACTUATOR_CONTROL_TARGET_H
#define MAVLINK_CPP_MSG_SET_ACTUATOR_CONTROL_TARGET_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t set_actuator_control_target_id = 139;
    const uint8_t set_actuator_control_target_length = 43;
    const uint8_t set_actuator_control_target_crc = 168;

    class set_actuator_control_target : public mavlink::message
    {
      public:
        set_actuator_control_target(uint8_t system_id, uint8_t component_id,  uint64_t time_usec, uint8_t group_mlx, uint8_t target_system, uint8_t target_component, const float *controls):
          mavlink::message( mavlink::msg::set_actuator_control_target_length,
                            system_id,
                            component_id,
                            mavlink::msg::set_actuator_control_target_id,
                            mavlink::msg::set_actuator_control_target_crc)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (micros since boot or Unix epoch)
           m_payload.push_back<uint8_t>(group_mlx); ///< Actuator group. The "_mlx" indicates this is a multi-instance message and a MAVLink parser should use this field to difference between instances.
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	uint8_t get_group_mlx() const
          {return m_payload.get<uint8_t>(40);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(41);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(42);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_SET_ACTUATOR_CONTROL_TARGET_H
    