#ifndef MAVLINK_CPP_MSG_GPS_INJECT_DATA_H
#define MAVLINK_CPP_MSG_GPS_INJECT_DATA_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t gps_inject_data_id = 123;
    const uint8_t gps_inject_data_length = 113;
    const uint8_t gps_inject_data_crc = 250;

    class gps_inject_data : public mavlink::message
    {
      public:
        gps_inject_data(uint8_t system_id, uint8_t component_id,  uint8_t target_system, uint8_t target_component, uint8_t len, const uint8_t *data):
          mavlink::message( mavlink::msg::gps_inject_data_length,
                            system_id,
                            component_id,
                            mavlink::msg::gps_inject_data_id,
                            mavlink::msg::gps_inject_data_crc)
        {
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
           m_payload.push_back<uint8_t>(len); ///< data length
          
        }

      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(0);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(1);}
      	uint8_t get_len() const
          {return m_payload.get<uint8_t>(2);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_GPS_INJECT_DATA_H
    