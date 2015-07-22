#ifndef MAVLINK_CPP_MSG_RC_CHANNELS_OVERRIDE_H
#define MAVLINK_CPP_MSG_RC_CHANNELS_OVERRIDE_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t rc_channels_override_id = 70;
    const uint8_t rc_channels_override_length = 18;
    const uint8_t rc_channels_override_crc = 124;

    class rc_channels_override : public mavlink::message
    {
      public:
        rc_channels_override(uint8_t system_id, uint8_t component_id,  uint8_t  target_system, uint8_t  target_component, uint16_t  chan1_raw, uint16_t  chan2_raw, uint16_t  chan3_raw, uint16_t  chan4_raw, uint16_t  chan5_raw, uint16_t  chan6_raw, uint16_t  chan7_raw, uint16_t  chan8_raw):
          mavlink::message( mavlink::msg::rc_channels_override_length,
                            system_id,
                            component_id,
                            mavlink::msg::rc_channels_override_id)
        {
           m_payload.push_back<uint16_t>(chan1_raw); ///< RC channel 1 value, in microseconds. A value of UINT16_MAX means to ignore this field.
           m_payload.push_back<uint16_t>(chan2_raw); ///< RC channel 2 value, in microseconds. A value of UINT16_MAX means to ignore this field.
           m_payload.push_back<uint16_t>(chan3_raw); ///< RC channel 3 value, in microseconds. A value of UINT16_MAX means to ignore this field.
           m_payload.push_back<uint16_t>(chan4_raw); ///< RC channel 4 value, in microseconds. A value of UINT16_MAX means to ignore this field.
           m_payload.push_back<uint16_t>(chan5_raw); ///< RC channel 5 value, in microseconds. A value of UINT16_MAX means to ignore this field.
           m_payload.push_back<uint16_t>(chan6_raw); ///< RC channel 6 value, in microseconds. A value of UINT16_MAX means to ignore this field.
           m_payload.push_back<uint16_t>(chan7_raw); ///< RC channel 7 value, in microseconds. A value of UINT16_MAX means to ignore this field.
           m_payload.push_back<uint16_t>(chan8_raw); ///< RC channel 8 value, in microseconds. A value of UINT16_MAX means to ignore this field.
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
          
          
        }

      	uint16_t get_chan1_raw() const
          {return m_payload.get<uint16_t>(0);}
      	uint16_t get_chan2_raw() const
          {return m_payload.get<uint16_t>(2);}
      	uint16_t get_chan3_raw() const
          {return m_payload.get<uint16_t>(4);}
      	uint16_t get_chan4_raw() const
          {return m_payload.get<uint16_t>(6);}
      	uint16_t get_chan5_raw() const
          {return m_payload.get<uint16_t>(8);}
      	uint16_t get_chan6_raw() const
          {return m_payload.get<uint16_t>(10);}
      	uint16_t get_chan7_raw() const
          {return m_payload.get<uint16_t>(12);}
      	uint16_t get_chan8_raw() const
          {return m_payload.get<uint16_t>(14);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(16);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(17);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_RC_CHANNELS_OVERRIDE_H
    