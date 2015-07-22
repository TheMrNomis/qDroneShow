#ifndef MAVLINK_CPP_MSG_GPS_GLOBAL_ORIGIN_H
#define MAVLINK_CPP_MSG_GPS_GLOBAL_ORIGIN_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t gps_global_origin_id = 49;
    const uint8_t gps_global_origin_length = 12;
    const uint8_t gps_global_origin_crc = 39;

    class gps_global_origin : public mavlink::message
    {
      public:
        gps_global_origin(uint8_t system_id, uint8_t component_id,  int32_t  latitude, int32_t  longitude, int32_t  altitude):
          mavlink::message( mavlink::msg::gps_global_origin_length,
                            system_id,
                            component_id,
                            mavlink::msg::gps_global_origin_id)
        {
           m_payload.push_back<int32_t>(latitude); ///< Latitude (WGS84), in degrees * 1E7
           m_payload.push_back<int32_t>(longitude); ///< Longitude (WGS84), in degrees * 1E7
           m_payload.push_back<int32_t>(altitude); ///< Altitude (AMSL), in meters * 1000 (positive for up)
          
          
        }

      	int32_t get_latitude() const
          {return m_payload.get<int32_t>(0);}
      	int32_t get_longitude() const
          {return m_payload.get<int32_t>(4);}
      	int32_t get_altitude() const
          {return m_payload.get<int32_t>(8);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_GPS_GLOBAL_ORIGIN_H
    