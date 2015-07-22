#ifndef MAVLINK_CPP_MSG_RC_CHANNELS_SCALED_H
#define MAVLINK_CPP_MSG_RC_CHANNELS_SCALED_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t rc_channels_scaled_id = 34;
    const uint8_t rc_channels_scaled_length = 22;
    const uint8_t rc_channels_scaled_crc = 237;

    class rc_channels_scaled : public mavlink::message
    {
      public:
        rc_channels_scaled(uint8_t system_id, uint8_t component_id,  uint32_t  time_boot_ms, uint8_t  port, int16_t  chan1_scaled, int16_t  chan2_scaled, int16_t  chan3_scaled, int16_t  chan4_scaled, int16_t  chan5_scaled, int16_t  chan6_scaled, int16_t  chan7_scaled, int16_t  chan8_scaled, uint8_t  rssi):
          mavlink::message( mavlink::msg::rc_channels_scaled_length,
                            system_id,
                            component_id,
                            mavlink::msg::rc_channels_scaled_id)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot)
           m_payload.push_back<int16_t>(chan1_scaled); ///< RC channel 1 value scaled, (-100%) -10000, (0%) 0, (100%) 10000, (invalid) INT16_MAX.
           m_payload.push_back<int16_t>(chan2_scaled); ///< RC channel 2 value scaled, (-100%) -10000, (0%) 0, (100%) 10000, (invalid) INT16_MAX.
           m_payload.push_back<int16_t>(chan3_scaled); ///< RC channel 3 value scaled, (-100%) -10000, (0%) 0, (100%) 10000, (invalid) INT16_MAX.
           m_payload.push_back<int16_t>(chan4_scaled); ///< RC channel 4 value scaled, (-100%) -10000, (0%) 0, (100%) 10000, (invalid) INT16_MAX.
           m_payload.push_back<int16_t>(chan5_scaled); ///< RC channel 5 value scaled, (-100%) -10000, (0%) 0, (100%) 10000, (invalid) INT16_MAX.
           m_payload.push_back<int16_t>(chan6_scaled); ///< RC channel 6 value scaled, (-100%) -10000, (0%) 0, (100%) 10000, (invalid) INT16_MAX.
           m_payload.push_back<int16_t>(chan7_scaled); ///< RC channel 7 value scaled, (-100%) -10000, (0%) 0, (100%) 10000, (invalid) INT16_MAX.
           m_payload.push_back<int16_t>(chan8_scaled); ///< RC channel 8 value scaled, (-100%) -10000, (0%) 0, (100%) 10000, (invalid) INT16_MAX.
           m_payload.push_back<uint8_t>(port); ///< Servo output port (set of 8 outputs = 1 port). Most MAVs will just use one, but this allows for more than 8 servos.
           m_payload.push_back<uint8_t>(rssi); ///< Receive signal strength indicator, 0: 0%, 100: 100%, 255: invalid/unknown.
          
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	int16_t get_chan1_scaled() const
          {return m_payload.get<int16_t>(4);}
      	int16_t get_chan2_scaled() const
          {return m_payload.get<int16_t>(6);}
      	int16_t get_chan3_scaled() const
          {return m_payload.get<int16_t>(8);}
      	int16_t get_chan4_scaled() const
          {return m_payload.get<int16_t>(10);}
      	int16_t get_chan5_scaled() const
          {return m_payload.get<int16_t>(12);}
      	int16_t get_chan6_scaled() const
          {return m_payload.get<int16_t>(14);}
      	int16_t get_chan7_scaled() const
          {return m_payload.get<int16_t>(16);}
      	int16_t get_chan8_scaled() const
          {return m_payload.get<int16_t>(18);}
      	uint8_t get_port() const
          {return m_payload.get<uint8_t>(20);}
      	uint8_t get_rssi() const
          {return m_payload.get<uint8_t>(21);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_RC_CHANNELS_SCALED_H
    