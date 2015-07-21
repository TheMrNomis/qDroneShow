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
        gps_status(uint8_t system_id, uint8_t component_id,  uint8_t satellites_visible, const uint8_t *satellite_prn, const uint8_t *satellite_used, const uint8_t *satellite_elevation, const uint8_t *satellite_azimuth, const uint8_t *satellite_snr):
          mavlink::message( mavlink::msg::gps_status_length,
                            system_id,
                            component_id,
                            mavlink::msg::gps_status_id,
                            mavlink::msg::gps_status_crc)
        {
           m_payload.push_back<uint8_t>(satellites_visible); ///< Number of satellites visible
          
        }

      	uint8_t get_satellites_visible() const
          {return m_payload.get<uint8_t>(0);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_GPS_STATUS_H
    