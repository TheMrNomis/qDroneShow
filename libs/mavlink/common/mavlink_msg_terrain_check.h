#ifndef MAVLINK_CPP_MSG_TERRAIN_CHECK_H
#define MAVLINK_CPP_MSG_TERRAIN_CHECK_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t terrain_check_id = 135;
    const uint8_t terrain_check_length = 8;
    const uint8_t terrain_check_crc = 203;

    class terrain_check : public mavlink::message
    {
      public:
        terrain_check(uint8_t system_id, uint8_t component_id,  int32_t  lat, int32_t  lon):
          mavlink::message( mavlink::msg::terrain_check_length,
                            system_id,
                            component_id,
                            mavlink::msg::terrain_check_id)
        {
           m_payload.push_back<int32_t>(lat); ///< Latitude (degrees *10^7)
           m_payload.push_back<int32_t>(lon); ///< Longitude (degrees *10^7)
          
          
        }

      	int32_t get_lat() const
          {return m_payload.get<int32_t>(0);}
      	int32_t get_lon() const
          {return m_payload.get<int32_t>(4);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_TERRAIN_CHECK_H
    