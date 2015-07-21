#ifndef MAVLINK_CPP_MSG_TERRAIN_DATA_H
#define MAVLINK_CPP_MSG_TERRAIN_DATA_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t terrain_data_id = 134;
    const uint8_t terrain_data_length = 43;
    const uint8_t terrain_data_crc = 229;

    class terrain_data : public mavlink::message
    {
      public:
        terrain_data(uint8_t system_id, uint8_t component_id,  int32_t lat, int32_t lon, uint16_t grid_spacing, uint8_t gridbit, const int16_t *data):
          mavlink::message( mavlink::msg::terrain_data_length,
                            system_id,
                            component_id,
                            mavlink::msg::terrain_data_id,
                            mavlink::msg::terrain_data_crc)
        {
           m_payload.push_back<int32_t>(lat); ///< Latitude of SW corner of first grid (degrees *10^7)
           m_payload.push_back<int32_t>(lon); ///< Longitude of SW corner of first grid (in degrees *10^7)
           m_payload.push_back<uint16_t>(grid_spacing); ///< Grid spacing in meters
           m_payload.push_back<uint8_t>(gridbit); ///< bit within the terrain request mask
          
        }

      	int32_t get_lat() const
          {return m_payload.get<int32_t>(0);}
      	int32_t get_lon() const
          {return m_payload.get<int32_t>(4);}
      	uint16_t get_grid_spacing() const
          {return m_payload.get<uint16_t>(8);}
      	uint8_t get_gridbit() const
          {return m_payload.get<uint8_t>(42);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_TERRAIN_DATA_H
    