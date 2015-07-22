#ifndef MAVLINK_CPP_MSG_PARAM_MAP_RC_H
#define MAVLINK_CPP_MSG_PARAM_MAP_RC_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t param_map_rc_id = 50;
    const uint8_t param_map_rc_length = 37;
    const uint8_t param_map_rc_crc = 78;

    class param_map_rc : public mavlink::message
    {
      public:
        param_map_rc(uint8_t system_id, uint8_t component_id,  uint8_t  target_system, uint8_t  target_component, const char * param_id, int16_t  param_index, uint8_t  parameter_rc_channel_index, float  param_value0, float  scale, float  param_value_min, float  param_value_max):
          mavlink::message( mavlink::msg::param_map_rc_length,
                            system_id,
                            component_id,
                            mavlink::msg::param_map_rc_id)
        {
           m_payload.push_back<float>(param_value0); ///< Initial parameter value
           m_payload.push_back<float>(scale); ///< Scale, maps the RC range [-1, 1] to a parameter value
           m_payload.push_back<float>(param_value_min); ///< Minimum param value. The protocol does not define if this overwrites an onboard minimum value. (Depends on implementation)
           m_payload.push_back<float>(param_value_max); ///< Maximum param value. The protocol does not define if this overwrites an onboard maximum value. (Depends on implementation)
           m_payload.push_back<int16_t>(param_index); ///< Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored), send -2 to disable any existing map for this rc_channel_index.
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
           m_payload.push_back<uint8_t>(parameter_rc_channel_index); ///< Index of parameter RC channel. Not equal to the RC channel id. Typically correpsonds to a potentiometer-knob on the RC.
          
          	m_payload.push_back_array<char>(param_id, 16); ///< Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
          
        }

      	float get_param_value0() const
          {return m_payload.get<float>(0);}
      	float get_scale() const
          {return m_payload.get<float>(4);}
      	float get_param_value_min() const
          {return m_payload.get<float>(8);}
      	float get_param_value_max() const
          {return m_payload.get<float>(12);}
      	int16_t get_param_index() const
          {return m_payload.get<int16_t>(16);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(18);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(19);}
      	uint8_t get_parameter_rc_channel_index() const
          {return m_payload.get<uint8_t>(36);}
      
       char * get_param_id() const
          {return m_payload.get_array<char>(20, 16);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_PARAM_MAP_RC_H
    