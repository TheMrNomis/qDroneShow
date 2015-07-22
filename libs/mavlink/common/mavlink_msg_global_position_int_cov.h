#ifndef MAVLINK_CPP_MSG_GLOBAL_POSITION_INT_COV_H
#define MAVLINK_CPP_MSG_GLOBAL_POSITION_INT_COV_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t global_position_int_cov_id = 63;
    const uint8_t global_position_int_cov_length = 185;
    const uint8_t global_position_int_cov_crc = 51;

    class global_position_int_cov : public mavlink::message
    {
      public:
        global_position_int_cov(uint8_t system_id, uint8_t component_id,  uint32_t  time_boot_ms, uint64_t  time_utc, uint8_t  estimator_type, int32_t  lat, int32_t  lon, int32_t  alt, int32_t  relative_alt, float  vx, float  vy, float  vz, const float * covariance):
          mavlink::message( mavlink::msg::global_position_int_cov_length,
                            system_id,
                            component_id,
                            mavlink::msg::global_position_int_cov_id)
        {
           m_payload.push_back<uint64_t>(time_utc); ///< Timestamp (microseconds since UNIX epoch) in UTC. 0 for unknown. Commonly filled by the precision time source of a GPS receiver.
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot)
           m_payload.push_back<int32_t>(lat); ///< Latitude, expressed as degrees * 1E7
           m_payload.push_back<int32_t>(lon); ///< Longitude, expressed as degrees * 1E7
           m_payload.push_back<int32_t>(alt); ///< Altitude in meters, expressed as * 1000 (millimeters), above MSL
           m_payload.push_back<int32_t>(relative_alt); ///< Altitude above ground in meters, expressed as * 1000 (millimeters)
           m_payload.push_back<float>(vx); ///< Ground X Speed (Latitude), expressed as m/s
           m_payload.push_back<float>(vy); ///< Ground Y Speed (Longitude), expressed as m/s
           m_payload.push_back<float>(vz); ///< Ground Z Speed (Altitude), expressed as m/s
           m_payload.push_back<uint8_t>(estimator_type); ///< Class id of the estimator this estimate originated from.
          
          	m_payload.push_back_array<float>(covariance, 36); ///< Covariance matrix (first six entries are the first ROW, next six entries are the second row, etc.)
          
        }

      	uint64_t get_time_utc() const
          {return m_payload.get<uint64_t>(0);}
      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(8);}
      	int32_t get_lat() const
          {return m_payload.get<int32_t>(12);}
      	int32_t get_lon() const
          {return m_payload.get<int32_t>(16);}
      	int32_t get_alt() const
          {return m_payload.get<int32_t>(20);}
      	int32_t get_relative_alt() const
          {return m_payload.get<int32_t>(24);}
      	float get_vx() const
          {return m_payload.get<float>(28);}
      	float get_vy() const
          {return m_payload.get<float>(32);}
      	float get_vz() const
          {return m_payload.get<float>(36);}
      	uint8_t get_estimator_type() const
          {return m_payload.get<uint8_t>(184);}
      
       float * get_covariance() const
          {return m_payload.get_array<float>(40, 36);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_GLOBAL_POSITION_INT_COV_H
    