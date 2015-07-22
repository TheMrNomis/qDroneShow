#ifndef MAVLINK_CPP_MSG_NAV_CONTROLLER_OUTPUT_H
#define MAVLINK_CPP_MSG_NAV_CONTROLLER_OUTPUT_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t nav_controller_output_id = 62;
    const uint8_t nav_controller_output_length = 26;
    const uint8_t nav_controller_output_crc = 183;

    class nav_controller_output : public mavlink::message
    {
      public:
        nav_controller_output(uint8_t system_id, uint8_t component_id,  float  nav_roll, float  nav_pitch, int16_t  nav_bearing, int16_t  target_bearing, uint16_t  wp_dist, float  alt_error, float  aspd_error, float  xtrack_error):
          mavlink::message( mavlink::msg::nav_controller_output_length,
                            system_id,
                            component_id,
                            mavlink::msg::nav_controller_output_id)
        {
           m_payload.push_back<float>(nav_roll); ///< Current desired roll in degrees
           m_payload.push_back<float>(nav_pitch); ///< Current desired pitch in degrees
           m_payload.push_back<float>(alt_error); ///< Current altitude error in meters
           m_payload.push_back<float>(aspd_error); ///< Current airspeed error in meters/second
           m_payload.push_back<float>(xtrack_error); ///< Current crosstrack error on x-y plane in meters
           m_payload.push_back<int16_t>(nav_bearing); ///< Current desired heading in degrees
           m_payload.push_back<int16_t>(target_bearing); ///< Bearing to current MISSION/target in degrees
           m_payload.push_back<uint16_t>(wp_dist); ///< Distance to active MISSION in meters
          
          
        }

      	float get_nav_roll() const
          {return m_payload.get<float>(0);}
      	float get_nav_pitch() const
          {return m_payload.get<float>(4);}
      	float get_alt_error() const
          {return m_payload.get<float>(8);}
      	float get_aspd_error() const
          {return m_payload.get<float>(12);}
      	float get_xtrack_error() const
          {return m_payload.get<float>(16);}
      	int16_t get_nav_bearing() const
          {return m_payload.get<int16_t>(20);}
      	int16_t get_target_bearing() const
          {return m_payload.get<int16_t>(22);}
      	uint16_t get_wp_dist() const
          {return m_payload.get<uint16_t>(24);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_NAV_CONTROLLER_OUTPUT_H
    