#ifndef MAVLINK_CPP_MSG_VFR_HUD_H
#define MAVLINK_CPP_MSG_VFR_HUD_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t vfr_hud_id = 74;
    const uint8_t vfr_hud_length = 20;
    const uint8_t vfr_hud_crc = 20;

    class vfr_hud : public mavlink::message
    {
      public:
        vfr_hud(uint8_t system_id, uint8_t component_id,  float airspeed, float groundspeed, int16_t heading, uint16_t throttle, float alt, float climb):
          mavlink::message( mavlink::msg::vfr_hud_length,
                            system_id,
                            component_id,
                            mavlink::msg::vfr_hud_id,
                            mavlink::msg::vfr_hud_crc)
        {
           m_payload.push_back<float>(airspeed); ///< Current airspeed in m/s
           m_payload.push_back<float>(groundspeed); ///< Current ground speed in m/s
           m_payload.push_back<float>(alt); ///< Current altitude (MSL), in meters
           m_payload.push_back<float>(climb); ///< Current climb rate in meters/second
           m_payload.push_back<int16_t>(heading); ///< Current heading in degrees, in compass units (0..360, 0=north)
           m_payload.push_back<uint16_t>(throttle); ///< Current throttle setting in integer percent, 0 to 100
          
        }

      	float get_airspeed() const
          {return m_payload.get<float>(0);}
      	float get_groundspeed() const
          {return m_payload.get<float>(4);}
      	float get_alt() const
          {return m_payload.get<float>(8);}
      	float get_climb() const
          {return m_payload.get<float>(12);}
      	int16_t get_heading() const
          {return m_payload.get<int16_t>(16);}
      	uint16_t get_throttle() const
          {return m_payload.get<uint16_t>(18);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_VFR_HUD_H
    