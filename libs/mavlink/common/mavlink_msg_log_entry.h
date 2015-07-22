#ifndef MAVLINK_CPP_MSG_LOG_ENTRY_H
#define MAVLINK_CPP_MSG_LOG_ENTRY_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t log_entry_id = 118;
    const uint8_t log_entry_length = 14;
    const uint8_t log_entry_crc = 56;

    class log_entry : public mavlink::message
    {
      public:
        log_entry(uint8_t system_id, uint8_t component_id,  uint16_t  id, uint16_t  num_logs, uint16_t  last_log_num, uint32_t  time_utc, uint32_t  size):
          mavlink::message( mavlink::msg::log_entry_length,
                            system_id,
                            component_id,
                            mavlink::msg::log_entry_id)
        {
           m_payload.push_back<uint32_t>(time_utc); ///< UTC timestamp of log in seconds since 1970, or 0 if not available
           m_payload.push_back<uint32_t>(size); ///< Size of the log (may be approximate) in bytes
           m_payload.push_back<uint16_t>(id); ///< Log id
           m_payload.push_back<uint16_t>(num_logs); ///< Total number of logs
           m_payload.push_back<uint16_t>(last_log_num); ///< High log number
          
          
        }

      	uint32_t get_time_utc() const
          {return m_payload.get<uint32_t>(0);}
      	uint32_t get_size() const
          {return m_payload.get<uint32_t>(4);}
      	uint16_t get_id() const
          {return m_payload.get<uint16_t>(8);}
      	uint16_t get_num_logs() const
          {return m_payload.get<uint16_t>(10);}
      	uint16_t get_last_log_num() const
          {return m_payload.get<uint16_t>(12);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_LOG_ENTRY_H
    