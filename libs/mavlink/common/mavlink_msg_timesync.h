#ifndef MAVLINK_CPP_MSG_TIMESYNC_H
#define MAVLINK_CPP_MSG_TIMESYNC_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t timesync_id = 111;
    const uint8_t timesync_length = 16;
    const uint8_t timesync_crc = 34;

    class timesync : public mavlink::message
    {
      public:
        timesync(uint8_t system_id, uint8_t component_id,  int64_t  tc1, int64_t  ts1):
          mavlink::message( mavlink::msg::timesync_length,
                            system_id,
                            component_id,
                            mavlink::msg::timesync_id)
        {
           m_payload.push_back<int64_t>(tc1); ///< Time sync timestamp 1
           m_payload.push_back<int64_t>(ts1); ///< Time sync timestamp 2
          
          
        }

      	int64_t get_tc1() const
          {return m_payload.get<int64_t>(0);}
      	int64_t get_ts1() const
          {return m_payload.get<int64_t>(8);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_TIMESYNC_H
    