#ifndef MAVLINK_CPP_MSG_HIL_RC_INPUTS_RAW_H
#define MAVLINK_CPP_MSG_HIL_RC_INPUTS_RAW_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t hil_rc_inputs_raw_id = 92;
    const uint8_t hil_rc_inputs_raw_length = 33;
    const uint8_t hil_rc_inputs_raw_crc = 54;

    class hil_rc_inputs_raw : public mavlink::message
    {
      public:
        hil_rc_inputs_raw(uint8_t system_id, uint8_t component_id,  uint64_t  time_usec, uint16_t  chan1_raw, uint16_t  chan2_raw, uint16_t  chan3_raw, uint16_t  chan4_raw, uint16_t  chan5_raw, uint16_t  chan6_raw, uint16_t  chan7_raw, uint16_t  chan8_raw, uint16_t  chan9_raw, uint16_t  chan10_raw, uint16_t  chan11_raw, uint16_t  chan12_raw, uint8_t  rssi):
          mavlink::message( mavlink::msg::hil_rc_inputs_raw_length,
                            system_id,
                            component_id,
                            mavlink::msg::hil_rc_inputs_raw_id)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
           m_payload.push_back<uint16_t>(chan1_raw); ///< RC channel 1 value, in microseconds
           m_payload.push_back<uint16_t>(chan2_raw); ///< RC channel 2 value, in microseconds
           m_payload.push_back<uint16_t>(chan3_raw); ///< RC channel 3 value, in microseconds
           m_payload.push_back<uint16_t>(chan4_raw); ///< RC channel 4 value, in microseconds
           m_payload.push_back<uint16_t>(chan5_raw); ///< RC channel 5 value, in microseconds
           m_payload.push_back<uint16_t>(chan6_raw); ///< RC channel 6 value, in microseconds
           m_payload.push_back<uint16_t>(chan7_raw); ///< RC channel 7 value, in microseconds
           m_payload.push_back<uint16_t>(chan8_raw); ///< RC channel 8 value, in microseconds
           m_payload.push_back<uint16_t>(chan9_raw); ///< RC channel 9 value, in microseconds
           m_payload.push_back<uint16_t>(chan10_raw); ///< RC channel 10 value, in microseconds
           m_payload.push_back<uint16_t>(chan11_raw); ///< RC channel 11 value, in microseconds
           m_payload.push_back<uint16_t>(chan12_raw); ///< RC channel 12 value, in microseconds
           m_payload.push_back<uint8_t>(rssi); ///< Receive signal strength indicator, 0: 0%, 255: 100%
          
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	uint16_t get_chan1_raw() const
          {return m_payload.get<uint16_t>(8);}
      	uint16_t get_chan2_raw() const
          {return m_payload.get<uint16_t>(10);}
      	uint16_t get_chan3_raw() const
          {return m_payload.get<uint16_t>(12);}
      	uint16_t get_chan4_raw() const
          {return m_payload.get<uint16_t>(14);}
      	uint16_t get_chan5_raw() const
          {return m_payload.get<uint16_t>(16);}
      	uint16_t get_chan6_raw() const
          {return m_payload.get<uint16_t>(18);}
      	uint16_t get_chan7_raw() const
          {return m_payload.get<uint16_t>(20);}
      	uint16_t get_chan8_raw() const
          {return m_payload.get<uint16_t>(22);}
      	uint16_t get_chan9_raw() const
          {return m_payload.get<uint16_t>(24);}
      	uint16_t get_chan10_raw() const
          {return m_payload.get<uint16_t>(26);}
      	uint16_t get_chan11_raw() const
          {return m_payload.get<uint16_t>(28);}
      	uint16_t get_chan12_raw() const
          {return m_payload.get<uint16_t>(30);}
      	uint8_t get_rssi() const
          {return m_payload.get<uint8_t>(32);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_HIL_RC_INPUTS_RAW_H
    