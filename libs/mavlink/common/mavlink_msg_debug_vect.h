#ifndef MAVLINK_CPP_MSG_DEBUG_VECT_H
#define MAVLINK_CPP_MSG_DEBUG_VECT_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t debug_vect_id = 250;
    const uint8_t debug_vect_length = 30;
    const uint8_t debug_vect_crc = 49;

    class debug_vect : public mavlink::message
    {
      public:
        debug_vect(uint8_t system_id, uint8_t component_id,  const char * name, uint64_t  time_usec, float  x, float  y, float  z):
          mavlink::message( mavlink::msg::debug_vect_length,
                            system_id,
                            component_id,
                            mavlink::msg::debug_vect_id)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp
           m_payload.push_back<float>(x); ///< x
           m_payload.push_back<float>(y); ///< y
           m_payload.push_back<float>(z); ///< z
          
          	m_payload.push_back_array<char>(name, 10); ///< Name
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	float get_x() const
          {return m_payload.get<float>(8);}
      	float get_y() const
          {return m_payload.get<float>(12);}
      	float get_z() const
          {return m_payload.get<float>(16);}
      
       char * get_name() const
          {return m_payload.get_array<char>(20, 10);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_DEBUG_VECT_H
    