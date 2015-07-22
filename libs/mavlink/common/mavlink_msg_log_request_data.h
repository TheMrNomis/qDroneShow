#ifndef MAVLINK_CPP_MSG_LOG_REQUEST_DATA_H
#define MAVLINK_CPP_MSG_LOG_REQUEST_DATA_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t log_request_data_id = 119;
    const uint8_t log_request_data_length = 12;
    const uint8_t log_request_data_crc = 116;

    class log_request_data : public mavlink::message
    {
      public:
        log_request_data(uint8_t system_id, uint8_t component_id,  uint8_t  target_system, uint8_t  target_component, uint16_t  id, uint32_t  ofs, uint32_t  count):
          mavlink::message( mavlink::msg::log_request_data_length,
                            system_id,
                            component_id,
                            mavlink::msg::log_request_data_id)
        {
           m_payload.push_back<uint32_t>(ofs); ///< Offset into the log
           m_payload.push_back<uint32_t>(count); ///< Number of bytes
           m_payload.push_back<uint16_t>(id); ///< Log id (from LOG_ENTRY reply)
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
          
          
        }

      	uint32_t get_ofs() const
          {return m_payload.get<uint32_t>(0);}
      	uint32_t get_count() const
          {return m_payload.get<uint32_t>(4);}
      	uint16_t get_id() const
          {return m_payload.get<uint16_t>(8);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(10);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(11);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_LOG_REQUEST_DATA_H
    