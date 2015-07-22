#ifndef MAVLINK_CPP_MSG_MISSION_ITEM_REACHED_H
#define MAVLINK_CPP_MSG_MISSION_ITEM_REACHED_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t mission_item_reached_id = 46;
    const uint8_t mission_item_reached_length = 2;
    const uint8_t mission_item_reached_crc = 11;

    class mission_item_reached : public mavlink::message
    {
      public:
        mission_item_reached(uint8_t system_id, uint8_t component_id,  uint16_t  seq):
          mavlink::message( mavlink::msg::mission_item_reached_length,
                            system_id,
                            component_id,
                            mavlink::msg::mission_item_reached_id)
        {
           m_payload.push_back<uint16_t>(seq); ///< Sequence
          
          
        }

      	uint16_t get_seq() const
          {return m_payload.get<uint16_t>(0);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_MISSION_ITEM_REACHED_H
    