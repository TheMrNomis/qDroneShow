#ifndef MAVLINK_CPP_MSG_CHANGE_OPERATOR_CONTROL_H
#define MAVLINK_CPP_MSG_CHANGE_OPERATOR_CONTROL_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t change_operator_control_id = 5;
    const uint8_t change_operator_control_length = 28;
    const uint8_t change_operator_control_crc = 217;

    class change_operator_control : public mavlink::message
    {
      public:
        change_operator_control(uint8_t system_id, uint8_t component_id,  uint8_t  target_system, uint8_t  control_request, uint8_t  version, const char * passkey):
          mavlink::message( mavlink::msg::change_operator_control_length,
                            system_id,
                            component_id,
                            mavlink::msg::change_operator_control_id)
        {
           m_payload.push_back<uint8_t>(target_system); ///< System the GCS requests control for
           m_payload.push_back<uint8_t>(control_request); ///< 0: request control of this MAV, 1: Release control of this MAV
           m_payload.push_back<uint8_t>(version); ///< 0: key as plaintext, 1-255: future, different hashing/encryption variants. The GCS should in general use the safest mode possible initially and then gradually move down the encryption level if it gets a NACK message indicating an encryption mismatch.
          
          	m_payload.push_back_array<char>(passkey, 25); ///< Password / Key, depending on version plaintext or encrypted. 25 or less characters, NULL terminated. The characters may involve A-Z, a-z, 0-9, and "!?,.-"
          
        }

      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(0);}
      	uint8_t get_control_request() const
          {return m_payload.get<uint8_t>(1);}
      	uint8_t get_version() const
          {return m_payload.get<uint8_t>(2);}
      
       char * get_passkey() const
          {return m_payload.get_array<char>(3, 25);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_CHANGE_OPERATOR_CONTROL_H
    