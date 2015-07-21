#ifndef MAVLINK_CPP_MSG_VISION_SPEED_ESTIMATE_H
#define MAVLINK_CPP_MSG_VISION_SPEED_ESTIMATE_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t vision_speed_estimate_id = 103;
    const uint8_t vision_speed_estimate_length = 20;
    const uint8_t vision_speed_estimate_crc = 208;

    class vision_speed_estimate : public mavlink::message
    {
      public:
        vision_speed_estimate(uint8_t system_id, uint8_t component_id,  uint64_t usec, float x, float y, float z):
          mavlink::message( mavlink::msg::vision_speed_estimate_length,
                            system_id,
                            component_id,
                            mavlink::msg::vision_speed_estimate_id,
                            mavlink::msg::vision_speed_estimate_crc)
        {
           m_payload.push_back<uint64_t>(usec); ///< Timestamp (microseconds, synced to UNIX time or since system boot)
           m_payload.push_back<float>(x); ///< Global X speed
           m_payload.push_back<float>(y); ///< Global Y speed
           m_payload.push_back<float>(z); ///< Global Z speed
          
        }

      	uint64_t get_usec() const
          {return m_payload.get<uint64_t>(0);}
      	float get_x() const
          {return m_payload.get<float>(8);}
      	float get_y() const
          {return m_payload.get<float>(12);}
      	float get_z() const
          {return m_payload.get<float>(16);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_VISION_SPEED_ESTIMATE_H
    