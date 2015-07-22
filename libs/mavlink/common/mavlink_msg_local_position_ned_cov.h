#ifndef MAVLINK_CPP_MSG_LOCAL_POSITION_NED_COV_H
#define MAVLINK_CPP_MSG_LOCAL_POSITION_NED_COV_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t local_position_ned_cov_id = 64;
    const uint8_t local_position_ned_cov_length = 229;
    const uint8_t local_position_ned_cov_crc = 59;

    class local_position_ned_cov : public mavlink::message
    {
      public:
        local_position_ned_cov(uint8_t system_id, uint8_t component_id,  uint32_t  time_boot_ms, uint64_t  time_utc, uint8_t  estimator_type, float  x, float  y, float  z, float  vx, float  vy, float  vz, float  ax, float  ay, float  az, const float * covariance):
          mavlink::message( mavlink::msg::local_position_ned_cov_length,
                            system_id,
                            component_id,
                            mavlink::msg::local_position_ned_cov_id)
        {
           m_payload.push_back<uint64_t>(time_utc); ///< Timestamp (microseconds since UNIX epoch) in UTC. 0 for unknown. Commonly filled by the precision time source of a GPS receiver.
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp (milliseconds since system boot). 0 for system without monotonic timestamp
           m_payload.push_back<float>(x); ///< X Position
           m_payload.push_back<float>(y); ///< Y Position
           m_payload.push_back<float>(z); ///< Z Position
           m_payload.push_back<float>(vx); ///< X Speed (m/s)
           m_payload.push_back<float>(vy); ///< Y Speed (m/s)
           m_payload.push_back<float>(vz); ///< Z Speed (m/s)
           m_payload.push_back<float>(ax); ///< X Acceleration (m/s^2)
           m_payload.push_back<float>(ay); ///< Y Acceleration (m/s^2)
           m_payload.push_back<float>(az); ///< Z Acceleration (m/s^2)
           m_payload.push_back<uint8_t>(estimator_type); ///< Class id of the estimator this estimate originated from.
          
          	m_payload.push_back_array<float>(covariance, 45); ///< Covariance matrix upper right triangular (first nine entries are the first ROW, next eight entries are the second row, etc.)
          
        }

      	uint64_t get_time_utc() const
          {return m_payload.get<uint64_t>(0);}
      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(8);}
      	float get_x() const
          {return m_payload.get<float>(12);}
      	float get_y() const
          {return m_payload.get<float>(16);}
      	float get_z() const
          {return m_payload.get<float>(20);}
      	float get_vx() const
          {return m_payload.get<float>(24);}
      	float get_vy() const
          {return m_payload.get<float>(28);}
      	float get_vz() const
          {return m_payload.get<float>(32);}
      	float get_ax() const
          {return m_payload.get<float>(36);}
      	float get_ay() const
          {return m_payload.get<float>(40);}
      	float get_az() const
          {return m_payload.get<float>(44);}
      	uint8_t get_estimator_type() const
          {return m_payload.get<uint8_t>(228);}
      
       float * get_covariance() const
          {return m_payload.get_array<float>(48, 45);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_LOCAL_POSITION_NED_COV_H
    