#ifndef MAVLINK_CPP_MSG_ATT_POS_MOCAP_H
#define MAVLINK_CPP_MSG_ATT_POS_MOCAP_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t att_pos_mocap_id = 138;
    const uint8_t att_pos_mocap_length = 36;
    const uint8_t att_pos_mocap_crc = 109;

    class att_pos_mocap : public mavlink::message
    {
      public:
        att_pos_mocap(uint8_t system_id, uint8_t component_id,  uint64_t  time_usec, const float * q, float  x, float  y, float  z):
          mavlink::message( mavlink::msg::att_pos_mocap_length,
                            system_id,
                            component_id,
                            mavlink::msg::att_pos_mocap_id)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (micros since boot or Unix epoch)
           m_payload.push_back<float>(x); ///< X position in meters (NED)
           m_payload.push_back<float>(y); ///< Y position in meters (NED)
           m_payload.push_back<float>(z); ///< Z position in meters (NED)
          
          	m_payload.push_back_array<float>(q, 4); ///< Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	float get_x() const
          {return m_payload.get<float>(24);}
      	float get_y() const
          {return m_payload.get<float>(28);}
      	float get_z() const
          {return m_payload.get<float>(32);}
      
       float * get_q() const
          {return m_payload.get_array<float>(8, 4);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_ATT_POS_MOCAP_H
    