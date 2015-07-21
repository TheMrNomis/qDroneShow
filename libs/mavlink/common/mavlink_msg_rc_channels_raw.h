#ifndef MAVLINK_CPP_MSG_RC_CHANNELS_RAW_H
#define MAVLINK_CPP_MSG_RC_CHANNELS_RAW_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t rc_channels_raw_id = 35;
    const uint8_t rc_channels_raw_length = 22;
    const uint8_t rc_channels_raw_crc = 244;

    class rc_channels_raw : public mavlink::message
    {
      public:
        rc_channels_raw(uint8_t system_id, uint8_t component_id,  uint32_t time_boot_ms, uint8_t port, uint16_t chan1_raw, uint16_t chan2_raw, uint16_t chan3_raw, uint16_t chan4_raw, uint16_t chan5_raw, uint16_t chan6_raw, uint16_t chan7_raw, uint16_t chan8_raw, uint8_t rssi):
          mavlink::message( mavlink::msg::rc_channels_raw_length,
                            system_id,
                            component_id,
                            mavlink::msg::rc_channels_raw_id,
                            mavlink::msg::rc_channels_raw_crc)
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
           m_payload.push_back<uint8_t>(port); ///< Servo output port (set of 8 outputs = 1 port). Most MAVs will just use one, but this allows for more than 8 servos.
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
      	uint8_t get_port() const
          {return m_payload.get<uint8_t>(20);}
      	uint8_t get_rssi() const
          {return m_payload.get<uint8_t>(21);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_RC_CHANNELS_RAW_H
    