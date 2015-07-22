#ifndef MAVLINK_CPP_MSG_AUTH_KEY_H
#define MAVLINK_CPP_MSG_AUTH_KEY_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t auth_key_id = 7;
    const uint8_t auth_key_length = 32;
    const uint8_t auth_key_crc = 119;

    class auth_key : public mavlink::message
    {
      public:
        auth_key(uint8_t system_id, uint8_t component_id,  const char * key):
          mavlink::message( mavlink::msg::auth_key_length,
                            system_id,
                            component_id,
                            mavlink::msg::auth_key_id)
        {
          
          	m_payload.push_back_array<char>(key, 32); ///< key
          
        }

      
       char * get_key() const
          {return m_payload.get_array<char>(0, 32);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_AUTH_KEY_H
    