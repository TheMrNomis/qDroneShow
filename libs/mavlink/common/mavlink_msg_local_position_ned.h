#ifndef MAVLINK_CPP_MSG_LOCAL_POSITION_NED_H
#define MAVLINK_CPP_MSG_LOCAL_POSITION_NED_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t local_position_ned_id = 32;
    const uint8_t local_position_ned_length = 28;
    const uint8_t local_position_ned_crc = 185;

    class local_position_ned : public mavlink::message
    {
      public:
        local_position_ned(uint8_t system_id, uint8_t component_id,  uint32_t time_boot_ms, float x, float y, float z, float vx, float vy, float vz):
          mavlink::message( mavlink::msg::local_position_ned_length,
                            system_id,
                            component_id,
                            mavlink::msg::local_position_ned_id,
                            mavlink::msg::local_position_ned_crc)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot)
           m_payload.push_back<float>(x); ///< X Position
           m_payload.push_back<float>(y); ///< Y Position
           m_payload.push_back<float>(z); ///< Z Position
           m_payload.push_back<float>(vx); ///< X Speed
           m_payload.push_back<float>(vy); ///< Y Speed
           m_payload.push_back<float>(vz); ///< Z Speed
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	float get_x() const
          {return m_payload.get<float>(4);}
      	float get_y() const
          {return m_payload.get<float>(8);}
      	float get_z() const
          {return m_payload.get<float>(12);}
      	float get_vx() const
          {return m_payload.get<float>(16);}
      	float get_vy() const
          {return m_payload.get<float>(20);}
      	float get_vz() const
          {return m_payload.get<float>(24);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_LOCAL_POSITION_NED_H
    