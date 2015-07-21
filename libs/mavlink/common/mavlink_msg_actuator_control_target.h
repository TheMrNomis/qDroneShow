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
        actuator_control_target(uint8_t system_id, uint8_t component_id,  uint64_t time_usec, uint8_t group_mlx, const float *controls):
          mavlink::message( mavlink::msg::actuator_control_target_length,
                            system_id,
                            component_id,
                            mavlink::msg::actuator_control_target_id,
                            mavlink::msg::actuator_control_target_crc)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (micros since boot or Unix epoch)
           m_payload.push_back<uint8_t>(group_mlx); ///< Actuator group. The "_mlx" indicates this is a multi-instance message and a MAVLink parser should use this field to difference between instances.
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	uint8_t get_group_mlx() const
          {return m_payload.get<uint8_t>(40);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_ACTUATOR_CONTROL_TARGET_H
    