#ifndef MAVLINK_CPP_MSG_OPTICAL_FLOW_H
#define MAVLINK_CPP_MSG_OPTICAL_FLOW_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t optical_flow_id = 100;
    const uint8_t optical_flow_length = 26;
    const uint8_t optical_flow_crc = 175;

    class optical_flow : public mavlink::message
    {
      public:
        optical_flow(uint8_t system_id, uint8_t component_id,  uint64_t time_usec, uint8_t sensor_id, int16_t flow_x, int16_t flow_y, float flow_comp_m_x, float flow_comp_m_y, uint8_t quality, float ground_distance):
          mavlink::message( mavlink::msg::optical_flow_length,
                            system_id,
                            component_id,
                            mavlink::msg::optical_flow_id,
                            mavlink::msg::optical_flow_crc)
        {
           m_payload.push_back<uint64_t>(time_usec); ///< Timestamp (UNIX)
           m_payload.push_back<float>(flow_comp_m_x); ///< Flow in meters in x-sensor direction, angular-speed compensated
           m_payload.push_back<float>(flow_comp_m_y); ///< Flow in meters in y-sensor direction, angular-speed compensated
           m_payload.push_back<float>(ground_distance); ///< Ground distance in meters. Positive value: distance known. Negative value: Unknown distance
           m_payload.push_back<int16_t>(flow_x); ///< Flow in pixels * 10 in x-sensor direction (dezi-pixels)
           m_payload.push_back<int16_t>(flow_y); ///< Flow in pixels * 10 in y-sensor direction (dezi-pixels)
           m_payload.push_back<uint8_t>(sensor_id); ///< Sensor ID
           m_payload.push_back<uint8_t>(quality); ///< Optical flow quality / confidence. 0: bad, 255: maximum quality
          
        }

      	uint64_t get_time_usec() const
          {return m_payload.get<uint64_t>(0);}
      	float get_flow_comp_m_x() const
          {return m_payload.get<float>(8);}
      	float get_flow_comp_m_y() const
          {return m_payload.get<float>(12);}
      	float get_ground_distance() const
          {return m_payload.get<float>(16);}
      	int16_t get_flow_x() const
          {return m_payload.get<int16_t>(20);}
      	int16_t get_flow_y() const
          {return m_payload.get<int16_t>(22);}
      	uint8_t get_sensor_id() const
          {return m_payload.get<uint8_t>(24);}
      	uint8_t get_quality() const
          {return m_payload.get<uint8_t>(25);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_OPTICAL_FLOW_H
    