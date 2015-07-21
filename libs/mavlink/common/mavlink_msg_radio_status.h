#ifndef MAVLINK_CPP_MSG_RADIO_STATUS_H
#define MAVLINK_CPP_MSG_RADIO_STATUS_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t radio_status_id = 109;
    const uint8_t radio_status_length = 9;
    const uint8_t radio_status_crc = 185;

    class radio_status : public mavlink::message
    {
      public:
        radio_status(uint8_t system_id, uint8_t component_id,  uint8_t rssi, uint8_t remrssi, uint8_t txbuf, uint8_t noise, uint8_t remnoise, uint16_t rxerrors, uint16_t fixed):
          mavlink::message( mavlink::msg::radio_status_length,
                            system_id,
                            component_id,
                            mavlink::msg::radio_status_id,
                            mavlink::msg::radio_status_crc)
        {
           m_payload.push_back<uint16_t>(rxerrors); ///< Receive errors
           m_payload.push_back<uint16_t>(fixed); ///< Count of error corrected packets
           m_payload.push_back<uint8_t>(rssi); ///< Local signal strength
           m_payload.push_back<uint8_t>(remrssi); ///< Remote signal strength
           m_payload.push_back<uint8_t>(txbuf); ///< Remaining free buffer space in percent.
           m_payload.push_back<uint8_t>(noise); ///< Background noise level
           m_payload.push_back<uint8_t>(remnoise); ///< Remote background noise level
          
        }

      	uint16_t get_rxerrors() const
          {return m_payload.get<uint16_t>(0);}
      	uint16_t get_fixed() const
          {return m_payload.get<uint16_t>(2);}
      	uint8_t get_rssi() const
          {return m_payload.get<uint8_t>(4);}
      	uint8_t get_remrssi() const
          {return m_payload.get<uint8_t>(5);}
      	uint8_t get_txbuf() const
          {return m_payload.get<uint8_t>(6);}
      	uint8_t get_noise() const
          {return m_payload.get<uint8_t>(7);}
      	uint8_t get_remnoise() const
          {return m_payload.get<uint8_t>(8);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_RADIO_STATUS_H
    