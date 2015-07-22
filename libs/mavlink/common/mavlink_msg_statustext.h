#ifndef MAVLINK_CPP_MSG_STATUSTEXT_H
#define MAVLINK_CPP_MSG_STATUSTEXT_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t statustext_id = 253;
    const uint8_t statustext_length = 51;
    const uint8_t statustext_crc = 83;

    class statustext : public mavlink::message
    {
      public:
        statustext(uint8_t system_id, uint8_t component_id,  uint8_t  severity, const char * text):
          mavlink::message( mavlink::msg::statustext_length,
                            system_id,
                            component_id,
                            mavlink::msg::statustext_id)
        {
           m_payload.push_back<uint8_t>(severity); ///< Severity of status. Relies on the definitions within RFC-5424. See enum MAV_SEVERITY.
          
          	m_payload.push_back_array<char>(text, 50); ///< Status text message, without null termination character
          
        }

      	uint8_t get_severity() const
          {return m_payload.get<uint8_t>(0);}
      
       char * get_text() const
          {return m_payload.get_array<char>(1, 50);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_STATUSTEXT_H
    