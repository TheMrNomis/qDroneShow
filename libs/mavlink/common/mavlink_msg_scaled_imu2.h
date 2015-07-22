#ifndef MAVLINK_CPP_MSG_SCALED_IMU2_H
#define MAVLINK_CPP_MSG_SCALED_IMU2_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t scaled_imu2_id = 116;
    const uint8_t scaled_imu2_length = 22;
    const uint8_t scaled_imu2_crc = 76;

    class scaled_imu2 : public mavlink::message
    {
      public:
        scaled_imu2(uint8_t system_id, uint8_t component_id,  uint32_t  time_boot_ms, int16_t  xacc, int16_t  yacc, int16_t  zacc, int16_t  xgyro, int16_t  ygyro, int16_t  zgyro, int16_t  xmag, int16_t  ymag, int16_t  zmag):
          mavlink::message( mavlink::msg::scaled_imu2_length,
                            system_id,
                            component_id,
                            mavlink::msg::scaled_imu2_id)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot)
           m_payload.push_back<int16_t>(xacc); ///< X acceleration (mg)
           m_payload.push_back<int16_t>(yacc); ///< Y acceleration (mg)
           m_payload.push_back<int16_t>(zacc); ///< Z acceleration (mg)
           m_payload.push_back<int16_t>(xgyro); ///< Angular speed around X axis (millirad /sec)
           m_payload.push_back<int16_t>(ygyro); ///< Angular speed around Y axis (millirad /sec)
           m_payload.push_back<int16_t>(zgyro); ///< Angular speed around Z axis (millirad /sec)
           m_payload.push_back<int16_t>(xmag); ///< X Magnetic field (milli tesla)
           m_payload.push_back<int16_t>(ymag); ///< Y Magnetic field (milli tesla)
           m_payload.push_back<int16_t>(zmag); ///< Z Magnetic field (milli tesla)
          
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	int16_t get_xacc() const
          {return m_payload.get<int16_t>(4);}
      	int16_t get_yacc() const
          {return m_payload.get<int16_t>(6);}
      	int16_t get_zacc() const
          {return m_payload.get<int16_t>(8);}
      	int16_t get_xgyro() const
          {return m_payload.get<int16_t>(10);}
      	int16_t get_ygyro() const
          {return m_payload.get<int16_t>(12);}
      	int16_t get_zgyro() const
          {return m_payload.get<int16_t>(14);}
      	int16_t get_xmag() const
          {return m_payload.get<int16_t>(16);}
      	int16_t get_ymag() const
          {return m_payload.get<int16_t>(18);}
      	int16_t get_zmag() const
          {return m_payload.get<int16_t>(20);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_SCALED_IMU2_H
    