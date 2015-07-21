#ifndef MAVLINK_CPP_MSG_LANDING_TARGET_H
#define MAVLINK_CPP_MSG_LANDING_TARGET_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t landing_target_id = 149;
    const uint8_t landing_target_length = 30;
    const uint8_t landing_target_crc = 200;

    class landing_target : public mavlink::message
    {
      public:
        landing_target(uint8_t system_id, uint8_t component_id,  uint64_t time_usec, uint8_t target_num, uint8_t frame, float angle_x, float angle_y, float distance, float size_x, float size_y):
          mavlink::message( mavlink::msg::landing_target_length,
                            system_id,
                            component_id,
                            mavlink::msg::landing_target_id,
                            mavlink::msg::landing_target_crc)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (micros since boot or Unix epoch)
           m_payload.push_back<float>(angle_x); ///< X-axis angular offset (in radians) of the target from the center of the image
           m_payload.push_back<float>(angle_y); ///< Y-axis angular offset (in radians) of the target from the center of the image
           m_payload.push_back<float>(distance); ///< Distance to the target from the vehicle in meters
           m_payload.push_back<float>(size_x); ///< Size in radians of target along x-axis
           m_payload.push_back<float>(size_y); ///< Size in radians of target along y-axis
           m_payload.push_back<uint8_t>(target_num); ///< The ID of the target if multiple targets are present
           m_payload.push_back<uint8_t>(frame); ///< MAV_FRAME enum specifying the whether the following feilds are earth-frame, body-frame, etc.
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	float get_angle_x() const
          {return m_payload.get<float>(8);}
      	float get_angle_y() const
          {return m_payload.get<float>(12);}
      	float get_distance() const
          {return m_payload.get<float>(16);}
      	float get_size_x() const
          {return m_payload.get<float>(20);}
      	float get_size_y() const
          {return m_payload.get<float>(24);}
      	uint8_t get_target_num() const
          {return m_payload.get<uint8_t>(28);}
      	uint8_t get_frame() const
          {return m_payload.get<uint8_t>(29);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_LANDING_TARGET_H
    