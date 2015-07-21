#ifndef MAVLINK_CPP_MSG_HEARTBEAT_H
#define MAVLINK_CPP_MSG_HEARTBEAT_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t heartbeat_id = 0;
    const uint8_t heartbeat_length = 9;
    const uint8_t heartbeat_crc = 50;

    class heartbeat : public mavlink::message
    {
      public:
        heartbeat(uint8_t system_id, uint8_t component_id,  uint8_t type, uint8_t autopilot, uint8_t base_mode, uint32_t custom_mode, uint8_t system_status):
          mavlink::message( mavlink::msg::heartbeat_length,
                            system_id,
                            component_id,
                            mavlink::msg::heartbeat_id,
                            mavlink::msg::heartbeat_crc)
        {
           m_payload.push_back<uint32_t>(custom_mode); ///< A bitfield for use for autopilot-specific flags.
           m_payload.push_back<uint8_t>(type); ///< Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
           m_payload.push_back<uint8_t>(autopilot); ///< Autopilot type / class. defined in MAV_AUTOPILOT ENUM
           m_payload.push_back<uint8_t>(base_mode); ///< System mode bitfield, see MAV_MODE_FLAG ENUM in mavlink/include/mavlink_types.h
           m_payload.push_back<uint8_t>(system_status); ///< System status flag, see MAV_STATE ENUM
           m_payload.push_back<uint8_t>(3); ///< MAVLink version, not writable by user, gets added by protocol because of magic data type: uint8_t_mavlink_version
          
        }

      	uint32_t get_custom_mode() const
          {return m_payload.get<uint32_t>(0);}
      	uint8_t get_type() const
          {return m_payload.get<uint8_t>(4);}
      	uint8_t get_autopilot() const
          {return m_payload.get<uint8_t>(5);}
      	uint8_t get_base_mode() const
          {return m_payload.get<uint8_t>(6);}
      	uint8_t get_system_status() const
          {return m_payload.get<uint8_t>(7);}
      	uint8_t get_3() const
          {return m_payload.get<uint8_t>(8);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_HEARTBEAT_H
    