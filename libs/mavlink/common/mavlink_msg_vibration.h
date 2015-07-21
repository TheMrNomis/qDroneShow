#ifndef MAVLINK_CPP_MSG_VIBRATION_H
#define MAVLINK_CPP_MSG_VIBRATION_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t vibration_id = 241;
    const uint8_t vibration_length = 32;
    const uint8_t vibration_crc = 90;

    class vibration : public mavlink::message
    {
      public:
        vibration(uint8_t system_id, uint8_t component_id,  uint64_t time_usec, float vibration_x, float vibration_y, float vibration_z, uint32_t clipping_0, uint32_t clipping_1, uint32_t clipping_2):
          mavlink::message( mavlink::msg::vibration_length,
                            system_id,
                            component_id,
                            mavlink::msg::vibration_id,
                            mavlink::msg::vibration_crc)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (micros since boot or Unix epoch)
           m_payload.push_back<float>(vibration_x); ///< Vibration levels on X-axis
           m_payload.push_back<float>(vibration_y); ///< Vibration levels on Y-axis
           m_payload.push_back<float>(vibration_z); ///< Vibration levels on Z-axis
           m_payload.push_back<uint32_t>(clipping_0); ///< first accelerometer clipping count
           m_payload.push_back<uint32_t>(clipping_1); ///< second accelerometer clipping count
           m_payload.push_back<uint32_t>(clipping_2); ///< third accelerometer clipping count
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	float get_vibration_x() const
          {return m_payload.get<float>(8);}
      	float get_vibration_y() const
          {return m_payload.get<float>(12);}
      	float get_vibration_z() const
          {return m_payload.get<float>(16);}
      	uint32_t get_clipping_0() const
          {return m_payload.get<uint32_t>(20);}
      	uint32_t get_clipping_1() const
          {return m_payload.get<uint32_t>(24);}
      	uint32_t get_clipping_2() const
          {return m_payload.get<uint32_t>(28);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_VIBRATION_H
    