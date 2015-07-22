#ifndef MAVLINK_CPP_MSG_TERRAIN_REQUEST_H
#define MAVLINK_CPP_MSG_TERRAIN_REQUEST_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t terrain_request_id = 133;
    const uint8_t terrain_request_length = 18;
    const uint8_t terrain_request_crc = 6;

    class terrain_request : public mavlink::message
    {
      public:
        terrain_request(uint8_t system_id, uint8_t component_id,  int32_t  lat, int32_t  lon, uint16_t  grid_spacing, uint64_t  mask):
          mavlink::message( mavlink::msg::terrain_request_length,
                            system_id,
                            component_id,
                            mavlink::msg::terrain_request_id)
        {
           m_payload.push_back<uint64_t>(mask); ///< Bitmask of requested 4x4 grids (row major 8x7 array of grids, 56 bits)
           m_payload.push_back<int32_t>(lat); ///< Latitude of SW corner of first grid (degrees *10^7)
           m_payload.push_back<int32_t>(lon); ///< Longitude of SW corner of first grid (in degrees *10^7)
           m_payload.push_back<uint16_t>(grid_spacing); ///< Grid spacing in meters
          
          
        }

      	uint64_t get_mask() const
          {return m_payload.get<uint64_t>(0);}
      	int32_t get_lat() const
          {return m_payload.get<int32_t>(8);}
      	int32_t get_lon() const
          {return m_payload.get<int32_t>(12);}
      	uint16_t get_grid_spacing() const
          {return m_payload.get<uint16_t>(16);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_TERRAIN_REQUEST_H
    