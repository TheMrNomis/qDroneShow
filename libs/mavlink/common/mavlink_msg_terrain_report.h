#ifndef MAVLINK_CPP_MSG_TERRAIN_REPORT_H
#define MAVLINK_CPP_MSG_TERRAIN_REPORT_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t terrain_report_id = 136;
    const uint8_t terrain_report_length = 22;
    const uint8_t terrain_report_crc = 1;

    class terrain_report : public mavlink::message
    {
      public:
        terrain_report(uint8_t system_id, uint8_t component_id,  int32_t  lat, int32_t  lon, uint16_t  spacing, float  terrain_height, float  current_height, uint16_t  pending, uint16_t  loaded):
          mavlink::message( mavlink::msg::terrain_report_length,
                            system_id,
                            component_id,
                            mavlink::msg::terrain_report_id)
        {
           m_payload.push_back<int32_t>(lat); ///< Latitude (degrees *10^7)
           m_payload.push_back<int32_t>(lon); ///< Longitude (degrees *10^7)
           m_payload.push_back<float>(terrain_height); ///< Terrain height in meters AMSL
           m_payload.push_back<float>(current_height); ///< Current vehicle height above lat/lon terrain height (meters)
           m_payload.push_back<uint16_t>(spacing); ///< grid spacing (zero if terrain at this location unavailable)
           m_payload.push_back<uint16_t>(pending); ///< Number of 4x4 terrain blocks waiting to be received or read from disk
           m_payload.push_back<uint16_t>(loaded); ///< Number of 4x4 terrain blocks in memory
          
          
        }

      	int32_t get_lat() const
          {return m_payload.get<int32_t>(0);}
      	int32_t get_lon() const
          {return m_payload.get<int32_t>(4);}
      	float get_terrain_height() const
          {return m_payload.get<float>(8);}
      	float get_current_height() const
          {return m_payload.get<float>(12);}
      	uint16_t get_spacing() const
          {return m_payload.get<uint16_t>(16);}
      	uint16_t get_pending() const
          {return m_payload.get<uint16_t>(18);}
      	uint16_t get_loaded() const
          {return m_payload.get<uint16_t>(20);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_TERRAIN_REPORT_H
    