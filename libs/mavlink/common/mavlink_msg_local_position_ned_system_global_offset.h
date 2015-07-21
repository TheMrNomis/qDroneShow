#ifndef MAVLINK_CPP_MSG_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET_H
#define MAVLINK_CPP_MSG_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t local_position_ned_system_global_offset_id = 89;
    const uint8_t local_position_ned_system_global_offset_length = 28;
    const uint8_t local_position_ned_system_global_offset_crc = 231;

    class local_position_ned_system_global_offset : public mavlink::message
    {
      public:
        local_position_ned_system_global_offset(uint8_t system_id, uint8_t component_id,  uint32_t time_boot_ms, float x, float y, float z, float roll, float pitch, float yaw):
          mavlink::message( mavlink::msg::local_position_ned_system_global_offset_length,
                            system_id,
                            component_id,
                            mavlink::msg::local_position_ned_system_global_offset_id,
                            mavlink::msg::local_position_ned_system_global_offset_crc)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot)
           m_payload.push_back<float>(x); ///< X Position
           m_payload.push_back<float>(y); ///< Y Position
           m_payload.push_back<float>(z); ///< Z Position
           m_payload.push_back<float>(roll); ///< Roll
           m_payload.push_back<float>(pitch); ///< Pitch
           m_payload.push_back<float>(yaw); ///< Yaw
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	float get_x() const
          {return m_payload.get<float>(4);}
      	float get_y() const
          {return m_payload.get<float>(8);}
      	float get_z() const
          {return m_payload.get<float>(12);}
      	float get_roll() const
          {return m_payload.get<float>(16);}
      	float get_pitch() const
          {return m_payload.get<float>(20);}
      	float get_yaw() const
          {return m_payload.get<float>(24);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET_H
    