#ifndef MAVLINK_CPP_MSG_HIL_GPS_H
#define MAVLINK_CPP_MSG_HIL_GPS_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t hil_gps_id = 113;
    const uint8_t hil_gps_length = 36;
    const uint8_t hil_gps_crc = 124;

    class hil_gps : public mavlink::message
    {
      public:
        hil_gps(uint8_t system_id, uint8_t component_id,  uint64_t time_usec, uint8_t fix_type, int32_t lat, int32_t lon, int32_t alt, uint16_t eph, uint16_t epv, uint16_t vel, int16_t vn, int16_t ve, int16_t vd, uint16_t cog, uint8_t satellites_visible):
          mavlink::message( mavlink::msg::hil_gps_length,
                            system_id,
                            component_id,
                            mavlink::msg::hil_gps_id,
                            mavlink::msg::hil_gps_crc)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
           m_payload.push_back<int32_t>(lat); ///< Latitude (WGS84), in degrees * 1E7
           m_payload.push_back<int32_t>(lon); ///< Longitude (WGS84), in degrees * 1E7
           m_payload.push_back<int32_t>(alt); ///< Altitude (AMSL, not WGS84), in meters * 1000 (positive for up)
           m_payload.push_back<uint16_t>(eph); ///< GPS HDOP horizontal dilution of position in cm (m*100). If unknown, set to: 65535
           m_payload.push_back<uint16_t>(epv); ///< GPS VDOP vertical dilution of position in cm (m*100). If unknown, set to: 65535
           m_payload.push_back<uint16_t>(vel); ///< GPS ground speed (m/s * 100). If unknown, set to: 65535
           m_payload.push_back<int16_t>(vn); ///< GPS velocity in cm/s in NORTH direction in earth-fixed NED frame
           m_payload.push_back<int16_t>(ve); ///< GPS velocity in cm/s in EAST direction in earth-fixed NED frame
           m_payload.push_back<int16_t>(vd); ///< GPS velocity in cm/s in DOWN direction in earth-fixed NED frame
           m_payload.push_back<uint16_t>(cog); ///< Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: 65535
           m_payload.push_back<uint8_t>(fix_type); ///< 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
           m_payload.push_back<uint8_t>(satellites_visible); ///< Number of satellites visible. If unknown, set to 255
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	int32_t get_lat() const
          {return m_payload.get<int32_t>(8);}
      	int32_t get_lon() const
          {return m_payload.get<int32_t>(12);}
      	int32_t get_alt() const
          {return m_payload.get<int32_t>(16);}
      	uint16_t get_eph() const
          {return m_payload.get<uint16_t>(20);}
      	uint16_t get_epv() const
          {return m_payload.get<uint16_t>(22);}
      	uint16_t get_vel() const
          {return m_payload.get<uint16_t>(24);}
      	int16_t get_vn() const
          {return m_payload.get<int16_t>(26);}
      	int16_t get_ve() const
          {return m_payload.get<int16_t>(28);}
      	int16_t get_vd() const
          {return m_payload.get<int16_t>(30);}
      	uint16_t get_cog() const
          {return m_payload.get<uint16_t>(32);}
      	uint8_t get_fix_type() const
          {return m_payload.get<uint8_t>(34);}
      	uint8_t get_satellites_visible() const
          {return m_payload.get<uint8_t>(35);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_HIL_GPS_H
    