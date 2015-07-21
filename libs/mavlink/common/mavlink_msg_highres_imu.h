#ifndef MAVLINK_CPP_MSG_HIGHRES_IMU_H
#define MAVLINK_CPP_MSG_HIGHRES_IMU_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t highres_imu_id = 105;
    const uint8_t highres_imu_length = 62;
    const uint8_t highres_imu_crc = 93;

    class highres_imu : public mavlink::message
    {
      public:
        highres_imu(uint8_t system_id, uint8_t component_id,  uint64_t time_usec, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro, float xmag, float ymag, float zmag, float abs_pressure, float diff_pressure, float pressure_alt, float temperature, uint16_t fields_updated):
          mavlink::message( mavlink::msg::highres_imu_length,
                            system_id,
                            component_id,
                            mavlink::msg::highres_imu_id,
                            mavlink::msg::highres_imu_crc)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (microseconds, synced to UNIX time or since system boot)
           m_payload.push_back<float>(xacc); ///< X acceleration (m/s^2)
           m_payload.push_back<float>(yacc); ///< Y acceleration (m/s^2)
           m_payload.push_back<float>(zacc); ///< Z acceleration (m/s^2)
           m_payload.push_back<float>(xgyro); ///< Angular speed around X axis (rad / sec)
           m_payload.push_back<float>(ygyro); ///< Angular speed around Y axis (rad / sec)
           m_payload.push_back<float>(zgyro); ///< Angular speed around Z axis (rad / sec)
           m_payload.push_back<float>(xmag); ///< X Magnetic field (Gauss)
           m_payload.push_back<float>(ymag); ///< Y Magnetic field (Gauss)
           m_payload.push_back<float>(zmag); ///< Z Magnetic field (Gauss)
           m_payload.push_back<float>(abs_pressure); ///< Absolute pressure in millibar
           m_payload.push_back<float>(diff_pressure); ///< Differential pressure in millibar
           m_payload.push_back<float>(pressure_alt); ///< Altitude calculated from pressure
           m_payload.push_back<float>(temperature); ///< Temperature in degrees celsius
           m_payload.push_back<uint16_t>(fields_updated); ///< Bitmask for fields that have updated since last message, bit 0 = xacc, bit 12: temperature
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	float get_xacc() const
          {return m_payload.get<float>(8);}
      	float get_yacc() const
          {return m_payload.get<float>(12);}
      	float get_zacc() const
          {return m_payload.get<float>(16);}
      	float get_xgyro() const
          {return m_payload.get<float>(20);}
      	float get_ygyro() const
          {return m_payload.get<float>(24);}
      	float get_zgyro() const
          {return m_payload.get<float>(28);}
      	float get_xmag() const
          {return m_payload.get<float>(32);}
      	float get_ymag() const
          {return m_payload.get<float>(36);}
      	float get_zmag() const
          {return m_payload.get<float>(40);}
      	float get_abs_pressure() const
          {return m_payload.get<float>(44);}
      	float get_diff_pressure() const
          {return m_payload.get<float>(48);}
      	float get_pressure_alt() const
          {return m_payload.get<float>(52);}
      	float get_temperature() const
          {return m_payload.get<float>(56);}
      	uint16_t get_fields_updated() const
          {return m_payload.get<uint16_t>(60);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_HIGHRES_IMU_H
    