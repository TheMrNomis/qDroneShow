#ifndef MAVLINK_CPP_MSG_SAFETY_ALLOWED_AREA_H
#define MAVLINK_CPP_MSG_SAFETY_ALLOWED_AREA_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t safety_allowed_area_id = 55;
    const uint8_t safety_allowed_area_length = 25;
    const uint8_t safety_allowed_area_crc = 3;

    class safety_allowed_area : public mavlink::message
    {
      public:
        safety_allowed_area(uint8_t system_id, uint8_t component_id,  uint8_t  frame, float  p1x, float  p1y, float  p1z, float  p2x, float  p2y, float  p2z):
          mavlink::message( mavlink::msg::safety_allowed_area_length,
                            system_id,
                            component_id,
                            mavlink::msg::safety_allowed_area_id)
        {
           m_payload.push_back<float>(p1x); ///< x position 1 / Latitude 1
           m_payload.push_back<float>(p1y); ///< y position 1 / Longitude 1
           m_payload.push_back<float>(p1z); ///< z position 1 / Altitude 1
           m_payload.push_back<float>(p2x); ///< x position 2 / Latitude 2
           m_payload.push_back<float>(p2y); ///< y position 2 / Longitude 2
           m_payload.push_back<float>(p2z); ///< z position 2 / Altitude 2
           m_payload.push_back<uint8_t>(frame); ///< Coordinate frame, as defined by MAV_FRAME enum in mavlink_types.h. Can be either global, GPS, right-handed with Z axis up or local, right handed, Z axis down.
          
          
        }

      	float get_p1x() const
          {return m_payload.get<float>(0);}
      	float get_p1y() const
          {return m_payload.get<float>(4);}
      	float get_p1z() const
          {return m_payload.get<float>(8);}
      	float get_p2x() const
          {return m_payload.get<float>(12);}
      	float get_p2y() const
          {return m_payload.get<float>(16);}
      	float get_p2z() const
          {return m_payload.get<float>(20);}
      	uint8_t get_frame() const
          {return m_payload.get<uint8_t>(24);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_SAFETY_ALLOWED_AREA_H
    