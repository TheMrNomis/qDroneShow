#ifndef MAVLINK_CPP_MSG_SET_MODE_H
#define MAVLINK_CPP_MSG_SET_MODE_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t set_mode_id = 11;
    const uint8_t set_mode_length = 6;
    const uint8_t set_mode_crc = 89;

    class set_mode : public mavlink::message
    {
      public:
        set_mode(uint8_t system_id, uint8_t component_id,  uint8_t target_system, uint8_t base_mode, uint32_t custom_mode):
          mavlink::message( mavlink::msg::set_mode_length,
                            system_id,
                            component_id,
                            mavlink::msg::set_mode_id,
                            mavlink::msg::set_mode_crc)
        {
           m_payload.push_back<uint32_t>(custom_mode); ///< The new autopilot-specific mode. This field can be ignored by an autopilot.
           m_payload.push_back<uint8_t>(target_system); ///< The system setting the mode
           m_payload.push_back<uint8_t>(base_mode); ///< The new base mode
          
        }

      	uint32_t get_custom_mode() const
          {return m_payload.get<uint32_t>(0);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(4);}
      	uint8_t get_base_mode() const
          {return m_payload.get<uint8_t>(5);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_SET_MODE_H
    