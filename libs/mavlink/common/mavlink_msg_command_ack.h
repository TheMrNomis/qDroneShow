#ifndef MAVLINK_CPP_MSG_COMMAND_ACK_H
#define MAVLINK_CPP_MSG_COMMAND_ACK_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t command_ack_id = 77;
    const uint8_t command_ack_length = 3;
    const uint8_t command_ack_crc = 143;

    class command_ack : public mavlink::message
    {
      public:
        command_ack(uint8_t system_id, uint8_t component_id,  uint16_t  command, uint8_t  result):
          mavlink::message( mavlink::msg::command_ack_length,
                            system_id,
                            component_id,
                            mavlink::msg::command_ack_id)
        {
           m_payload.push_back<uint16_t>(command); ///< Command ID, as defined by MAV_CMD enum.
           m_payload.push_back<uint8_t>(result); ///< See MAV_RESULT enum
          
          
        }

      	uint16_t get_command() const
          {return m_payload.get<uint16_t>(0);}
      	uint8_t get_result() const
          {return m_payload.get<uint8_t>(2);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_COMMAND_ACK_H
    