#ifndef MAVLINK_CPP_MSG_GLOBAL_VISION_POSITION_ESTIMATE_H
#define MAVLINK_CPP_MSG_GLOBAL_VISION_POSITION_ESTIMATE_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t global_vision_position_estimate_id = 101;
    const uint8_t global_vision_position_estimate_length = 32;
    const uint8_t global_vision_position_estimate_crc = 102;

    class global_vision_position_estimate : public mavlink::message
    {
      public:
        global_vision_position_estimate(uint8_t system_id, uint8_t component_id,  uint64_t usec, float x, float y, float z, float roll, float pitch, float yaw):
          mavlink::message( mavlink::msg::global_vision_position_estimate_length,
                            system_id,
                            component_id,
                            mavlink::msg::global_vision_position_estimate_id,
                            mavlink::msg::global_vision_position_estimate_crc)
        {
           m_payload.push_back<uint64_t>(usec); ///< Timestamp (microseconds, synced to UNIX time or since system boot)
           m_payload.push_back<float>(x); ///< Global X position
           m_payload.push_back<float>(y); ///< Global Y position
           m_payload.push_back<float>(z); ///< Global Z position
           m_payload.push_back<float>(roll); ///< Roll angle in rad
           m_payload.push_back<float>(pitch); ///< Pitch angle in rad
           m_payload.push_back<float>(yaw); ///< Yaw angle in rad
          
        }

      	uint64_t get_usec() const
          {return m_payload.get<uint64_t>(0);}
      	float get_x() const
          {return m_payload.get<float>(8);}
      	float get_y() const
          {return m_payload.get<float>(12);}
      	float get_z() const
          {return m_payload.get<float>(16);}
      	float get_roll() const
          {return m_payload.get<float>(20);}
      	float get_pitch() const
          {return m_payload.get<float>(24);}
      	float get_yaw() const
          {return m_payload.get<float>(28);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_GLOBAL_VISION_POSITION_ESTIMATE_H
    