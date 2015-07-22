#ifndef MAVLINK_CPP_MSG_SET_GPS_GLOBAL_ORIGIN_H
#define MAVLINK_CPP_MSG_SET_GPS_GLOBAL_ORIGIN_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t set_gps_global_origin_id = 48;
    const uint8_t set_gps_global_origin_length = 13;
    const uint8_t set_gps_global_origin_crc = 41;

    class set_gps_global_origin : public mavlink::message
    {
      public:
        set_gps_global_origin(uint8_t system_id, uint8_t component_id,  uint8_t  target_system, int32_t  latitude, int32_t  longitude, int32_t  altitude):
          mavlink::message( mavlink::msg::set_gps_global_origin_length,
                            system_id,
                            component_id,
                            mavlink::msg::set_gps_global_origin_id)
        {
           m_payload.push_back<int32_t>(latitude); ///< Latitude (WGS84), in degrees * 1E7
           m_payload.push_back<int32_t>(longitude); ///< Longitude (WGS84, in degrees * 1E7
           m_payload.push_back<int32_t>(altitude); ///< Altitude (AMSL), in meters * 1000 (positive for up)
           m_payload.push_back<uint8_t>(target_system); ///< System ID
          
          
        }

      	int32_t get_latitude() const
          {return m_payload.get<int32_t>(0);}
      	int32_t get_longitude() const
          {return m_payload.get<int32_t>(4);}
      	int32_t get_altitude() const
          {return m_payload.get<int32_t>(8);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(12);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_SET_GPS_GLOBAL_ORIGIN_H
    