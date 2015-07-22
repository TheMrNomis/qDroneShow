#ifndef MAVLINK_CPP_MSG_GPS_STATUS_H
#define MAVLINK_CPP_MSG_GPS_STATUS_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t gps_status_id = 25;
    const uint8_t gps_status_length = 101;
    const uint8_t gps_status_crc = 23;

    class gps_status : public mavlink::message
    {
      public:
        gps_status(uint8_t system_id, uint8_t component_id,  uint8_t  satellites_visible, const uint8_t * satellite_prn, const uint8_t * satellite_used, const uint8_t * satellite_elevation, const uint8_t * satellite_azimuth, const uint8_t * satellite_snr):
          mavlink::message( mavlink::msg::gps_status_length,
                            system_id,
                            component_id,
                            mavlink::msg::gps_status_id)
        {
           m_payload.push_back<uint8_t>(satellites_visible); ///< Number of satellites visible
          
          	m_payload.push_back_array<uint8_t>(satellite_prn, 20); ///< Global satellite ID
          	m_payload.push_back_array<uint8_t>(satellite_used, 20); ///< 0: Satellite not used, 1: used for localization
          	m_payload.push_back_array<uint8_t>(satellite_elevation, 20); ///< Elevation (0: right on top of receiver, 90: on the horizon) of satellite
          	m_payload.push_back_array<uint8_t>(satellite_azimuth, 20); ///< Direction of satellite, 0: 0 deg, 255: 360 deg.
          	m_payload.push_back_array<uint8_t>(satellite_snr, 20); ///< Signal to noise ratio of satellite
          
        }

      	uint8_t get_satellites_visible() const
          {return m_payload.get<uint8_t>(0);}
      
       uint8_t * get_satellite_prn() const
          {return m_payload.get_array<uint8_t>(1, 20);}
       uint8_t * get_satellite_used() const
          {return m_payload.get_array<uint8_t>(21, 20);}
       uint8_t * get_satellite_elevation() const
          {return m_payload.get_array<uint8_t>(41, 20);}
       uint8_t * get_satellite_azimuth() const
          {return m_payload.get_array<uint8_t>(61, 20);}
       uint8_t * get_satellite_snr() const
          {return m_payload.get_array<uint8_t>(81, 20);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_GPS_STATUS_H
    