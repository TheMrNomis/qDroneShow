#ifndef MAVLINK_CPP_MSG_PING_H
#define MAVLINK_CPP_MSG_PING_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t ping_id = 4;
    const uint8_t ping_length = 14;
    const uint8_t ping_crc = 237;

    class ping : public mavlink::message
    {
      public:
        ping(uint8_t system_id, uint8_t component_id,  uint64_t time_usec, uint32_t seq, uint8_t target_system, uint8_t target_component):
          mavlink::message( mavlink::msg::ping_length,
                            system_id,
                            component_id,
                            mavlink::msg::ping_id,
                            mavlink::msg::ping_crc)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
           m_payload.push_back<uint32_t>(seq); ///< PING sequence
           m_payload.push_back<uint8_t>(target_system); ///< 0: request ping from all receiving systems, if greater than 0: message is a ping response and number is the system id of the requesting system
           m_payload.push_back<uint8_t>(target_component); ///< 0: request ping from all receiving components, if greater than 0: message is a ping response and number is the system id of the requesting system
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	uint32_t get_seq() const
          {return m_payload.get<uint32_t>(8);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(12);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(13);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_PING_H
    