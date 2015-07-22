#ifndef MAVLINK_CPP_MSG_CAMERA_TRIGGER_H
#define MAVLINK_CPP_MSG_CAMERA_TRIGGER_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t camera_trigger_id = 112;
    const uint8_t camera_trigger_length = 12;
    const uint8_t camera_trigger_crc = 174;

    class camera_trigger : public mavlink::message
    {
      public:
        camera_trigger(uint8_t system_id, uint8_t component_id,  uint64_t  time_usec, uint32_t  seq):
          mavlink::message( mavlink::msg::camera_trigger_length,
                            system_id,
                            component_id,
                            mavlink::msg::camera_trigger_id)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp for the image frame in microseconds
           m_payload.push_back<uint32_t>(seq); ///< Image frame sequence
          
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	uint32_t get_seq() const
          {return m_payload.get<uint32_t>(8);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_CAMERA_TRIGGER_H
    