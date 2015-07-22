#ifndef MAVLINK_CPP_MSG_OPTICAL_FLOW_RAD_H
#define MAVLINK_CPP_MSG_OPTICAL_FLOW_RAD_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t optical_flow_rad_id = 106;
    const uint8_t optical_flow_rad_length = 44;
    const uint8_t optical_flow_rad_crc = 138;

    class optical_flow_rad : public mavlink::message
    {
      public:
        optical_flow_rad(uint8_t system_id, uint8_t component_id,  uint64_t  time_usec, uint8_t  sensor_id, uint32_t  integration_time_us, float  integrated_x, float  integrated_y, float  integrated_xgyro, float  integrated_ygyro, float  integrated_zgyro, int16_t  temperature, uint8_t  quality, uint32_t  time_delta_distance_us, float  distance):
          mavlink::message( mavlink::msg::optical_flow_rad_length,
                            system_id,
                            component_id,
                            mavlink::msg::optical_flow_rad_id)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (microseconds, synced to UNIX time or since system boot)
           m_payload.push_back<uint32_t>(integration_time_us); ///< Integration time in microseconds. Divide integrated_x and integrated_y by the integration time to obtain average flow. The integration time also indicates the.
           m_payload.push_back<float>(integrated_x); ///< Flow in radians around X axis (Sensor RH rotation about the X axis induces a positive flow. Sensor linear motion along the positive Y axis induces a negative flow.)
           m_payload.push_back<float>(integrated_y); ///< Flow in radians around Y axis (Sensor RH rotation about the Y axis induces a positive flow. Sensor linear motion along the positive X axis induces a positive flow.)
           m_payload.push_back<float>(integrated_xgyro); ///< RH rotation around X axis (rad)
           m_payload.push_back<float>(integrated_ygyro); ///< RH rotation around Y axis (rad)
           m_payload.push_back<float>(integrated_zgyro); ///< RH rotation around Z axis (rad)
           m_payload.push_back<uint32_t>(time_delta_distance_us); ///< Time in microseconds since the distance was sampled.
           m_payload.push_back<float>(distance); ///< Distance to the center of the flow field in meters. Positive value (including zero): distance known. Negative value: Unknown distance.
           m_payload.push_back<int16_t>(temperature); ///< Temperature * 100 in centi-degrees Celsius
           m_payload.push_back<uint8_t>(sensor_id); ///< Sensor ID
           m_payload.push_back<uint8_t>(quality); ///< Optical flow quality / confidence. 0: no valid flow, 255: maximum quality
          
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	uint32_t get_integration_time_us() const
          {return m_payload.get<uint32_t>(8);}
      	float get_integrated_x() const
          {return m_payload.get<float>(12);}
      	float get_integrated_y() const
          {return m_payload.get<float>(16);}
      	float get_integrated_xgyro() const
          {return m_payload.get<float>(20);}
      	float get_integrated_ygyro() const
          {return m_payload.get<float>(24);}
      	float get_integrated_zgyro() const
          {return m_payload.get<float>(28);}
      	uint32_t get_time_delta_distance_us() const
          {return m_payload.get<uint32_t>(32);}
      	float get_distance() const
          {return m_payload.get<float>(36);}
      	int16_t get_temperature() const
          {return m_payload.get<int16_t>(40);}
      	uint8_t get_sensor_id() const
          {return m_payload.get<uint8_t>(42);}
      	uint8_t get_quality() const
          {return m_payload.get<uint8_t>(43);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_OPTICAL_FLOW_RAD_H
    