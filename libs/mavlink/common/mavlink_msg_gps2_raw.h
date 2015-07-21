#ifndef MAVLINK_CPP_MSG_GPS2_RAW_H
#define MAVLINK_CPP_MSG_GPS2_RAW_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t gps2_raw_id = 124;
    const uint8_t gps2_raw_length = 35;
    const uint8_t gps2_raw_crc = 87;

    class gps2_raw : public mavlink::message
    {
      public:
        gps2_raw(uint8_t system_id, uint8_t component_id,  uint64_t time_usec, uint8_t fix_type, int32_t lat, int32_t lon, int32_t alt, uint16_t eph, uint16_t epv, uint16_t vel, uint16_t cog, uint8_t satellites_visible, uint8_t dgps_numch, uint32_t dgps_age):
          mavlink::message( mavlink::msg::gps2_raw_length,
                            system_id,
                            component_id,
                            mavlink::msg::gps2_raw_id,
                            mavlink::msg::gps2_raw_crc)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
           m_payload.push_back<int32_t>(lat); ///< Latitude (WGS84), in degrees * 1E7
           m_payload.push_back<int32_t>(lon); ///< Longitude (WGS84), in degrees * 1E7
           m_payload.push_back<int32_t>(alt); ///< Altitude (AMSL, not WGS84), in meters * 1000 (positive for up)
           m_payload.push_back<uint32_t>(dgps_age); ///< Age of DGPS info
           m_payload.push_back<uint16_t>(eph); ///< GPS HDOP horizontal dilution of position in cm (m*100). If unknown, set to: UINT16_MAX
           m_payload.push_back<uint16_t>(epv); ///< GPS VDOP vertical dilution of position in cm (m*100). If unknown, set to: UINT16_MAX
           m_payload.push_back<uint16_t>(vel); ///< GPS ground speed (m/s * 100). If unknown, set to: UINT16_MAX
           m_payload.push_back<uint16_t>(cog); ///< Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: UINT16_MAX
           m_payload.push_back<uint8_t>(fix_type); ///< 0-1: no fix, 2: 2D fix, 3: 3D fix, 4: DGPS fix, 5: RTK Fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
           m_payload.push_back<uint8_t>(satellites_visible); ///< Number of satellites visible. If unknown, set to 255
           m_payload.push_back<uint8_t>(dgps_numch); ///< Number of DGPS satellites
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	int32_t get_lat() const
          {return m_payload.get<int32_t>(8);}
      	int32_t get_lon() const
          {return m_payload.get<int32_t>(12);}
      	int32_t get_alt() const
          {return m_payload.get<int32_t>(16);}
      	uint32_t get_dgps_age() const
          {return m_payload.get<uint32_t>(20);}
      	uint16_t get_eph() const
          {return m_payload.get<uint16_t>(24);}
      	uint16_t get_epv() const
          {return m_payload.get<uint16_t>(26);}
      	uint16_t get_vel() const
          {return m_payload.get<uint16_t>(28);}
      	uint16_t get_cog() const
          {return m_payload.get<uint16_t>(30);}
      	uint8_t get_fix_type() const
          {return m_payload.get<uint8_t>(32);}
      	uint8_t get_satellites_visible() const
          {return m_payload.get<uint8_t>(33);}
      	uint8_t get_dgps_numch() const
          {return m_payload.get<uint8_t>(34);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_GPS2_RAW_H
    