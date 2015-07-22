#ifndef MAVLINK_CPP_MSG_GLOBAL_POSITION_INT_H
#define MAVLINK_CPP_MSG_GLOBAL_POSITION_INT_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t global_position_int_id = 33;
    const uint8_t global_position_int_length = 28;
    const uint8_t global_position_int_crc = 104;

    class global_position_int : public mavlink::message
    {
      public:
        global_position_int(uint8_t system_id, uint8_t component_id,  uint32_t  time_boot_ms, int32_t  lat, int32_t  lon, int32_t  alt, int32_t  relative_alt, int16_t  vx, int16_t  vy, int16_t  vz, uint16_t  hdg):
          mavlink::message( mavlink::msg::global_position_int_length,
                            system_id,
                            component_id,
                            mavlink::msg::global_position_int_id)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot)
           m_payload.push_back<int32_t>(lat); ///< Latitude, expressed as * 1E7
           m_payload.push_back<int32_t>(lon); ///< Longitude, expressed as * 1E7
           m_payload.push_back<int32_t>(alt); ///< Altitude in meters, expressed as * 1000 (millimeters), AMSL (not WGS84 - note that virtually all GPS modules provide the AMSL as well)
           m_payload.push_back<int32_t>(relative_alt); ///< Altitude above ground in meters, expressed as * 1000 (millimeters)
           m_payload.push_back<int16_t>(vx); ///< Ground X Speed (Latitude), expressed as m/s * 100
           m_payload.push_back<int16_t>(vy); ///< Ground Y Speed (Longitude), expressed as m/s * 100
           m_payload.push_back<int16_t>(vz); ///< Ground Z Speed (Altitude), expressed as m/s * 100
           m_payload.push_back<uint16_t>(hdg); ///< Compass heading in degrees * 100, 0.0..359.99 degrees. If unknown, set to: UINT16_MAX
          
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	int32_t get_lat() const
          {return m_payload.get<int32_t>(4);}
      	int32_t get_lon() const
          {return m_payload.get<int32_t>(8);}
      	int32_t get_alt() const
          {return m_payload.get<int32_t>(12);}
      	int32_t get_relative_alt() const
          {return m_payload.get<int32_t>(16);}
      	int16_t get_vx() const
          {return m_payload.get<int16_t>(20);}
      	int16_t get_vy() const
          {return m_payload.get<int16_t>(22);}
      	int16_t get_vz() const
          {return m_payload.get<int16_t>(24);}
      	uint16_t get_hdg() const
          {return m_payload.get<uint16_t>(26);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_GLOBAL_POSITION_INT_H
    