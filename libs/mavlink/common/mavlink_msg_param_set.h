#ifndef MAVLINK_CPP_MSG_PARAM_SET_H
#define MAVLINK_CPP_MSG_PARAM_SET_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t param_set_id = 23;
    const uint8_t param_set_length = 23;
    const uint8_t param_set_crc = 168;

    class param_set : public mavlink::message
    {
      public:
        param_set(uint8_t system_id, uint8_t component_id,  uint8_t  target_system, uint8_t  target_component, const char * param_id, float  param_value, uint8_t  param_type):
          mavlink::message( mavlink::msg::param_set_length,
                            system_id,
                            component_id,
                            mavlink::msg::param_set_id)
        {
           m_payload.push_back<float>(param_value); ///< Onboard parameter value
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
           m_payload.push_back<uint8_t>(param_type); ///< Onboard parameter type: see the MAV_PARAM_TYPE enum for supported data types.
          
          	m_payload.push_back_array<char>(param_id, 16); ///< Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
          
        }

      	float get_param_value() const
          {return m_payload.get<float>(0);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(4);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(5);}
      	uint8_t get_param_type() const
          {return m_payload.get<uint8_t>(22);}
      
       char * get_param_id() const
          {return m_payload.get_array<char>(6, 16);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_PARAM_SET_H
    