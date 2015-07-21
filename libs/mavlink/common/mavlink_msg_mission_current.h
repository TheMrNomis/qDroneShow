#ifndef MAVLINK_CPP_MSG_MISSION_CURRENT_H
#define MAVLINK_CPP_MSG_MISSION_CURRENT_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t mission_current_id = 42;
    const uint8_t mission_current_length = 2;
    const uint8_t mission_current_crc = 28;

    class mission_current : public mavlink::message
    {
      public:
        mission_current(uint8_t system_id, uint8_t component_id,  uint16_t seq):
          mavlink::message( mavlink::msg::mission_current_length,
                            system_id,
                            component_id,
                            mavlink::msg::mission_current_id,
                            mavlink::msg::mission_current_crc)
        {
           m_payload.push_back<uint16_t>(seq); ///< Sequence
          
        }

      	uint16_t get_seq() const
          {return m_payload.get<uint16_t>(0);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_MISSION_CURRENT_H
    