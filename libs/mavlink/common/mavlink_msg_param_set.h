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
        param_set(uint8_t system_id, uint8_t component_id,  uint8_t target_system, uint8_t target_component, const char *param_id, float param_value, uint8_t param_type):
          mavlink::message( mavlink::msg::param_set_length,
                            system_id,
                            component_id,
                            mavlink::msg::param_set_id,
                            mavlink::msg::param_set_crc)
        {
           m_payload.push_back<float>(param_value); ///< Onboard parameter value
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
           m_payload.push_back<uint8_t>(param_type); ///< Onboard parameter type: see the MAV_PARAM_TYPE enum for supported data types.
          
        }

      	float get_param_value() const
          {return m_payload.get<float>(0);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(4);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(5);}
      	uint8_t get_param_type() const
          {return m_payload.get<uint8_t>(22);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_PARAM_SET_H
    