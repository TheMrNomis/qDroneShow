#ifndef MAVLINK_CPP_MSG_MISSION_ITEM_H
#define MAVLINK_CPP_MSG_MISSION_ITEM_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t mission_item_id = 39;
    const uint8_t mission_item_length = 37;
    const uint8_t mission_item_crc = 254;

    class mission_item : public mavlink::message
    {
      public:
        mission_item(uint8_t system_id, uint8_t component_id,  uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t frame, uint16_t command, uint8_t current, uint8_t autocontinue, float param1, float param2, float param3, float param4, float x, float y, float z):
          mavlink::message( mavlink::msg::mission_item_length,
                            system_id,
                            component_id,
                            mavlink::msg::mission_item_id,
                            mavlink::msg::mission_item_crc)
        {
           m_payload.push_back<float>(param1); ///< PARAM1, see MAV_CMD enum
           m_payload.push_back<float>(param2); ///< PARAM2, see MAV_CMD enum
           m_payload.push_back<float>(param3); ///< PARAM3, see MAV_CMD enum
           m_payload.push_back<float>(param4); ///< PARAM4, see MAV_CMD enum
           m_payload.push_back<float>(x); ///< PARAM5 / local: x position, global: latitude
           m_payload.push_back<float>(y); ///< PARAM6 / y position: global: longitude
           m_payload.push_back<float>(z); ///< PARAM7 / z position: global: altitude (relative or absolute, depending on frame.
           m_payload.push_back<uint16_t>(seq); ///< Sequence
           m_payload.push_back<uint16_t>(command); ///< The scheduled action for the MISSION. see MAV_CMD in common.xml MAVLink specs
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
           m_payload.push_back<uint8_t>(frame); ///< The coordinate system of the MISSION. see MAV_FRAME in mavlink_types.h
           m_payload.push_back<uint8_t>(current); ///< false:0, true:1
           m_payload.push_back<uint8_t>(autocontinue); ///< autocontinue to next wp
          
        }

      	float get_param1() const
          {return m_payload.get<float>(0);}
      	float get_param2() const
          {return m_payload.get<float>(4);}
      	float get_param3() const
          {return m_payload.get<float>(8);}
      	float get_param4() const
          {return m_payload.get<float>(12);}
      	float get_x() const
          {return m_payload.get<float>(16);}
      	float get_y() const
          {return m_payload.get<float>(20);}
      	float get_z() const
          {return m_payload.get<float>(24);}
      	uint16_t get_seq() const
          {return m_payload.get<uint16_t>(28);}
      	uint16_t get_command() const
          {return m_payload.get<uint16_t>(30);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(32);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(33);}
      	uint8_t get_frame() const
          {return m_payload.get<uint8_t>(34);}
      	uint8_t get_current() const
          {return m_payload.get<uint8_t>(35);}
      	uint8_t get_autocontinue() const
          {return m_payload.get<uint8_t>(36);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_MISSION_ITEM_H
    