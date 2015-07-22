#ifndef MAVLINK_CPP_MSG_RC_CHANNELS_H
#define MAVLINK_CPP_MSG_RC_CHANNELS_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t rc_channels_id = 65;
    const uint8_t rc_channels_length = 42;
    const uint8_t rc_channels_crc = 118;

    class rc_channels : public mavlink::message
    {
      public:
        rc_channels(uint8_t system_id, uint8_t component_id,  uint32_t  time_boot_ms, uint8_t  chancount, uint16_t  chan1_raw, uint16_t  chan2_raw, uint16_t  chan3_raw, uint16_t  chan4_raw, uint16_t  chan5_raw, uint16_t  chan6_raw, uint16_t  chan7_raw, uint16_t  chan8_raw, uint16_t  chan9_raw, uint16_t  chan10_raw, uint16_t  chan11_raw, uint16_t  chan12_raw, uint16_t  chan13_raw, uint16_t  chan14_raw, uint16_t  chan15_raw, uint16_t  chan16_raw, uint16_t  chan17_raw, uint16_t  chan18_raw, uint8_t  rssi):
          mavlink::message( mavlink::msg::rc_channels_length,
                            system_id,
                            component_id,
                            mavlink::msg::rc_channels_id)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot)
           m_payload.push_back<uint16_t>(chan1_raw); ///< RC channel 1 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan2_raw); ///< RC channel 2 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan3_raw); ///< RC channel 3 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan4_raw); ///< RC channel 4 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan5_raw); ///< RC channel 5 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan6_raw); ///< RC channel 6 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan7_raw); ///< RC channel 7 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan8_raw); ///< RC channel 8 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan9_raw); ///< RC channel 9 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan10_raw); ///< RC channel 10 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan11_raw); ///< RC channel 11 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan12_raw); ///< RC channel 12 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan13_raw); ///< RC channel 13 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan14_raw); ///< RC channel 14 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan15_raw); ///< RC channel 15 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan16_raw); ///< RC channel 16 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan17_raw); ///< RC channel 17 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint16_t>(chan18_raw); ///< RC channel 18 value, in microseconds. A value of UINT16_MAX implies the channel is unused.
           m_payload.push_back<uint8_t>(chancount); ///< Total number of RC channels being received. This can be larger than 18, indicating that more channels are available but not given in this message. This value should be 0 when no RC channels are available.
           m_payload.push_back<uint8_t>(rssi); ///< Receive signal strength indicator, 0: 0%, 100: 100%, 255: invalid/unknown.
          
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	uint16_t get_chan1_raw() const
          {return m_payload.get<uint16_t>(4);}
      	uint16_t get_chan2_raw() const
          {return m_payload.get<uint16_t>(6);}
      	uint16_t get_chan3_raw() const
          {return m_payload.get<uint16_t>(8);}
      	uint16_t get_chan4_raw() const
          {return m_payload.get<uint16_t>(10);}
      	uint16_t get_chan5_raw() const
          {return m_payload.get<uint16_t>(12);}
      	uint16_t get_chan6_raw() const
          {return m_payload.get<uint16_t>(14);}
      	uint16_t get_chan7_raw() const
          {return m_payload.get<uint16_t>(16);}
      	uint16_t get_chan8_raw() const
          {return m_payload.get<uint16_t>(18);}
      	uint16_t get_chan9_raw() const
          {return m_payload.get<uint16_t>(20);}
      	uint16_t get_chan10_raw() const
          {return m_payload.get<uint16_t>(22);}
      	uint16_t get_chan11_raw() const
          {return m_payload.get<uint16_t>(24);}
      	uint16_t get_chan12_raw() const
          {return m_payload.get<uint16_t>(26);}
      	uint16_t get_chan13_raw() const
          {return m_payload.get<uint16_t>(28);}
      	uint16_t get_chan14_raw() const
          {return m_payload.get<uint16_t>(30);}
      	uint16_t get_chan15_raw() const
          {return m_payload.get<uint16_t>(32);}
      	uint16_t get_chan16_raw() const
          {return m_payload.get<uint16_t>(34);}
      	uint16_t get_chan17_raw() const
          {return m_payload.get<uint16_t>(36);}
      	uint16_t get_chan18_raw() const
          {return m_payload.get<uint16_t>(38);}
      	uint8_t get_chancount() const
          {return m_payload.get<uint8_t>(40);}
      	uint8_t get_rssi() const
          {return m_payload.get<uint8_t>(41);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_RC_CHANNELS_H
    