#ifndef MAVLINK_CPP_MSG_PARAM_VALUE_H
#define MAVLINK_CPP_MSG_PARAM_VALUE_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t param_value_id = 22;
    const uint8_t param_value_length = 25;
    const uint8_t param_value_crc = 220;

    class param_value : public mavlink::message
    {
      public:
        param_value(uint8_t system_id, uint8_t component_id,  const char *param_id, float param_value, uint8_t param_type, uint16_t param_count, uint16_t param_index):
          mavlink::message( mavlink::msg::param_value_length,
                            system_id,
                            component_id,
                            mavlink::msg::param_value_id,
                            mavlink::msg::param_value_crc)
        {
           m_payload.push_back<float>(param_value); ///< Onboard parameter value
           m_payload.push_back<uint16_t>(param_count); ///< Total number of onboard parameters
           m_payload.push_back<uint16_t>(param_index); ///< Index of this onboard parameter
           m_payload.push_back<uint8_t>(param_type); ///< Onboard parameter type: see the MAV_PARAM_TYPE enum for supported data types.
          
        }

      	float get_param_value() const
          {return m_payload.get<float>(0);}
      	uint16_t get_param_count() const
          {return m_payload.get<uint16_t>(4);}
      	uint16_t get_param_index() const
          {return m_payload.get<uint16_t>(6);}
      	uint8_t get_param_type() const
          {return m_payload.get<uint8_t>(24);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_PARAM_VALUE_H
    