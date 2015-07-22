#ifndef MAVLINK_CPP_MSG_RAW_IMU_H
#define MAVLINK_CPP_MSG_RAW_IMU_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t raw_imu_id = 27;
    const uint8_t raw_imu_length = 26;
    const uint8_t raw_imu_crc = 144;

    class raw_imu : public mavlink::message
    {
      public:
        raw_imu(uint8_t system_id, uint8_t component_id,  uint64_t  time_usec, int16_t  xacc, int16_t  yacc, int16_t  zacc, int16_t  xgyro, int16_t  ygyro, int16_t  zgyro, int16_t  xmag, int16_t  ymag, int16_t  zmag):
          mavlink::message( mavlink::msg::raw_imu_length,
                            system_id,
                            component_id,
                            mavlink::msg::raw_imu_id)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
           m_payload.push_back<int16_t>(xacc); ///< X acceleration (raw)
           m_payload.push_back<int16_t>(yacc); ///< Y acceleration (raw)
           m_payload.push_back<int16_t>(zacc); ///< Z acceleration (raw)
           m_payload.push_back<int16_t>(xgyro); ///< Angular speed around X axis (raw)
           m_payload.push_back<int16_t>(ygyro); ///< Angular speed around Y axis (raw)
           m_payload.push_back<int16_t>(zgyro); ///< Angular speed around Z axis (raw)
           m_payload.push_back<int16_t>(xmag); ///< X Magnetic field (raw)
           m_payload.push_back<int16_t>(ymag); ///< Y Magnetic field (raw)
           m_payload.push_back<int16_t>(zmag); ///< Z Magnetic field (raw)
          
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	int16_t get_xacc() const
          {return m_payload.get<int16_t>(8);}
      	int16_t get_yacc() const
          {return m_payload.get<int16_t>(10);}
      	int16_t get_zacc() const
          {return m_payload.get<int16_t>(12);}
      	int16_t get_xgyro() const
          {return m_payload.get<int16_t>(14);}
      	int16_t get_ygyro() const
          {return m_payload.get<int16_t>(16);}
      	int16_t get_zgyro() const
          {return m_payload.get<int16_t>(18);}
      	int16_t get_xmag() const
          {return m_payload.get<int16_t>(20);}
      	int16_t get_ymag() const
          {return m_payload.get<int16_t>(22);}
      	int16_t get_zmag() const
          {return m_payload.get<int16_t>(24);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_RAW_IMU_H
    