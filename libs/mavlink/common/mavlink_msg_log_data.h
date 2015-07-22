#ifndef MAVLINK_CPP_MSG_LOG_DATA_H
#define MAVLINK_CPP_MSG_LOG_DATA_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t log_data_id = 120;
    const uint8_t log_data_length = 97;
    const uint8_t log_data_crc = 134;

    class log_data : public mavlink::message
    {
      public:
        log_data(uint8_t system_id, uint8_t component_id,  uint16_t  id, uint32_t  ofs, uint8_t  count, const uint8_t * data):
          mavlink::message( mavlink::msg::log_data_length,
                            system_id,
                            component_id,
                            mavlink::msg::log_data_id)
        {
           m_payload.push_back<uint32_t>(ofs); ///< Offset into the log
           m_payload.push_back<uint16_t>(id); ///< Log id (from LOG_ENTRY reply)
           m_payload.push_back<uint8_t>(count); ///< Number of bytes (zero for end of log)
          
          	m_payload.push_back_array<uint8_t>(data, 90); ///< log data
          
        }

      	uint32_t get_ofs() const
          {return m_payload.get<uint32_t>(0);}
      	uint16_t get_id() const
          {return m_payload.get<uint16_t>(4);}
      	uint8_t get_count() const
          {return m_payload.get<uint8_t>(6);}
      
       uint8_t * get_data() const
          {return m_payload.get_array<uint8_t>(7, 90);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_LOG_DATA_H
    