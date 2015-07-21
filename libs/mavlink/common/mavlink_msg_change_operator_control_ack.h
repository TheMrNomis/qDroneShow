#ifndef MAVLINK_CPP_MSG_CHANGE_OPERATOR_CONTROL_ACK_H
#define MAVLINK_CPP_MSG_CHANGE_OPERATOR_CONTROL_ACK_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t change_operator_control_ack_id = 6;
    const uint8_t change_operator_control_ack_length = 3;
    const uint8_t change_operator_control_ack_crc = 104;

    class change_operator_control_ack : public mavlink::message
    {
      public:
        change_operator_control_ack(uint8_t system_id, uint8_t component_id,  uint8_t gcs_system_id, uint8_t control_request, uint8_t ack):
          mavlink::message( mavlink::msg::change_operator_control_ack_length,
                            system_id,
                            component_id,
                            mavlink::msg::change_operator_control_ack_id,
                            mavlink::msg::change_operator_control_ack_crc)
        {
           m_payload.push_back<uint8_t>(gcs_system_id); ///< ID of the GCS this message 
           m_payload.push_back<uint8_t>(control_request); ///< 0: request control of this MAV, 1: Release control of this MAV
           m_payload.push_back<uint8_t>(ack); ///< 0: ACK, 1: NACK: Wrong passkey, 2: NACK: Unsupported passkey encryption method, 3: NACK: Already under control
          
        }

      	uint8_t get_gcs_system_id() const
          {return m_payload.get<uint8_t>(0);}
      	uint8_t get_control_request() const
          {return m_payload.get<uint8_t>(1);}
      	uint8_t get_ack() const
          {return m_payload.get<uint8_t>(2);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_CHANGE_OPERATOR_CONTROL_ACK_H
    