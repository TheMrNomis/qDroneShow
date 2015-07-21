#ifndef MAVLINK_CPP_MSG_PARAM_REQUEST_READ_H
#define MAVLINK_CPP_MSG_PARAM_REQUEST_READ_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t param_request_read_id = 20;
    const uint8_t param_request_read_length = 20;
    const uint8_t param_request_read_crc = 214;

    class param_request_read : public mavlink::message
    {
      public:
        param_request_read(uint8_t system_id, uint8_t component_id,  uint8_t target_system, uint8_t target_component, const char *param_id, int16_t param_index):
          mavlink::message( mavlink::msg::param_request_read_length,
                            system_id,
                            component_id,
                            mavlink::msg::param_request_read_id,
                            mavlink::msg::param_request_read_crc)
        {
           m_payload.push_back<int16_t>(param_index); ///< Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored)
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
          
        }

      	int16_t get_param_index() const
          {return m_payload.get<int16_t>(0);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(2);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(3);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_PARAM_REQUEST_READ_H
    