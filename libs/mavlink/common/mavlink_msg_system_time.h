#ifndef MAVLINK_CPP_MSG_SYSTEM_TIME_H
#define MAVLINK_CPP_MSG_SYSTEM_TIME_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t system_time_id = 2;
    const uint8_t system_time_length = 12;
    const uint8_t system_time_crc = 137;

    class system_time : public mavlink::message
    {
      public:
        system_time(uint8_t system_id, uint8_t component_id,  uint64_t time_unix_usec, uint32_t time_boot_ms):
          mavlink::message( mavlink::msg::system_time_length,
                            system_id,
                            component_id,
                            mavlink::msg::system_time_id,
                            mavlink::msg::system_time_crc)
        {
           m_payload.push_back<uint64_t>(time_unix_usec); ///< Timestamp of the master clock in microseconds since UNIX epoch.
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp of the component clock since boot time in milliseconds.
          
        }

      	uint64_t get_time_unix_usec() const
          {return m_payload.get<uint64_t>(0);}
      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(8);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_SYSTEM_TIME_H
    