#ifndef MAVLINK_CPP_MSG_DISTANCE_SENSOR_H
#define MAVLINK_CPP_MSG_DISTANCE_SENSOR_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t distance_sensor_id = 132;
    const uint8_t distance_sensor_length = 14;
    const uint8_t distance_sensor_crc = 85;

    class distance_sensor : public mavlink::message
    {
      public:
        distance_sensor(uint8_t system_id, uint8_t component_id,  uint32_t time_boot_ms, uint16_t min_distance, uint16_t max_distance, uint16_t current_distance, uint8_t type, uint8_t id, uint8_t orientation, uint8_t covariance):
          mavlink::message( mavlink::msg::distance_sensor_length,
                            system_id,
                            component_id,
                            mavlink::msg::distance_sensor_id,
                            mavlink::msg::distance_sensor_crc)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Time since system boot
           m_payload.push_back<uint16_t>(min_distance); ///< Minimum distance the sensor can measure in centimeters
           m_payload.push_back<uint16_t>(max_distance); ///< Maximum distance the sensor can measure in centimeters
           m_payload.push_back<uint16_t>(current_distance); ///< Current distance reading
           m_payload.push_back<uint8_t>(type); ///< Type from MAV_DISTANCE_SENSOR enum.
           m_payload.push_back<uint8_t>(id); ///< Onboard ID of the sensor
           m_payload.push_back<uint8_t>(orientation); ///< Direction the sensor faces from MAV_SENSOR_ORIENTATION enum.
           m_payload.push_back<uint8_t>(covariance); ///< Measurement covariance in centimeters, 0 for unknown / invalid readings
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	uint16_t get_min_distance() const
          {return m_payload.get<uint16_t>(4);}
      	uint16_t get_max_distance() const
          {return m_payload.get<uint16_t>(6);}
      	uint16_t get_current_distance() const
          {return m_payload.get<uint16_t>(8);}
      	uint8_t get_type() const
          {return m_payload.get<uint8_t>(10);}
      	uint8_t get_id() const
          {return m_payload.get<uint8_t>(11);}
      	uint8_t get_orientation() const
          {return m_payload.get<uint8_t>(12);}
      	uint8_t get_covariance() const
          {return m_payload.get<uint8_t>(13);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_DISTANCE_SENSOR_H
    