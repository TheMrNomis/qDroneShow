#ifndef MAVLINK_CPP_MSG_POWER_STATUS_H
#define MAVLINK_CPP_MSG_POWER_STATUS_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t power_status_id = 125;
    const uint8_t power_status_length = 6;
    const uint8_t power_status_crc = 203;

    class power_status : public mavlink::message
    {
      public:
        power_status(uint8_t system_id, uint8_t component_id,  uint16_t  Vcc, uint16_t  Vservo, uint16_t  flags):
          mavlink::message( mavlink::msg::power_status_length,
                            system_id,
                            component_id,
                            mavlink::msg::power_status_id)
        {
           m_payload.push_back<uint16_t>(Vcc); ///< 5V rail voltage in millivolts
           m_payload.push_back<uint16_t>(Vservo); ///< servo rail voltage in millivolts
           m_payload.push_back<uint16_t>(flags); ///< power supply status flags (see MAV_POWER_STATUS enum)
          
          
        }

      	uint16_t get_Vcc() const
          {return m_payload.get<uint16_t>(0);}
      	uint16_t get_Vservo() const
          {return m_payload.get<uint16_t>(2);}
      	uint16_t get_flags() const
          {return m_payload.get<uint16_t>(4);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_POWER_STATUS_H
    