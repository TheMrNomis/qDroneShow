#ifndef MAVLINK_CPP_MSG_POSITION_TARGET_LOCAL_NED_H
#define MAVLINK_CPP_MSG_POSITION_TARGET_LOCAL_NED_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t position_target_local_ned_id = 85;
    const uint8_t position_target_local_ned_length = 51;
    const uint8_t position_target_local_ned_crc = 140;

    class position_target_local_ned : public mavlink::message
    {
      public:
        position_target_local_ned(uint8_t system_id, uint8_t component_id,  uint32_t  time_boot_ms, uint8_t  coordinate_frame, uint16_t  type_mask, float  x, float  y, float  z, float  vx, float  vy, float  vz, float  afx, float  afy, float  afz, float  yaw, float  yaw_rate):
          mavlink::message( mavlink::msg::position_target_local_ned_length,
                            system_id,
                            component_id,
                            mavlink::msg::position_target_local_ned_id)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp in milliseconds since system boot
           m_payload.push_back<float>(x); ///< X Position in NED frame in meters
           m_payload.push_back<float>(y); ///< Y Position in NED frame in meters
           m_payload.push_back<float>(z); ///< Z Position in NED frame in meters (note, altitude is negative in NED)
           m_payload.push_back<float>(vx); ///< X velocity in NED frame in meter / s
           m_payload.push_back<float>(vy); ///< Y velocity in NED frame in meter / s
           m_payload.push_back<float>(vz); ///< Z velocity in NED frame in meter / s
           m_payload.push_back<float>(afx); ///< X acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
           m_payload.push_back<float>(afy); ///< Y acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
           m_payload.push_back<float>(afz); ///< Z acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
           m_payload.push_back<float>(yaw); ///< yaw setpoint in rad
           m_payload.push_back<float>(yaw_rate); ///< yaw rate setpoint in rad/s
           m_payload.push_back<uint16_t>(type_mask); ///< Bitmask to indicate which dimensions should be ignored by the vehicle: a value of 0b0000000000000000 or 0b0000001000000000 indicates that none of the setpoint dimensions should be ignored. If bit 10 is set the floats afx afy afz should be interpreted as force instead of acceleration. Mapping: bit 1: x, bit 2: y, bit 3: z, bit 4: vx, bit 5: vy, bit 6: vz, bit 7: ax, bit 8: ay, bit 9: az, bit 10: is force setpoint, bit 11: yaw, bit 12: yaw rate
           m_payload.push_back<uint8_t>(coordinate_frame); ///< Valid options are: MAV_FRAME_LOCAL_NED = 1, MAV_FRAME_LOCAL_OFFSET_NED = 7, MAV_FRAME_BODY_NED = 8, MAV_FRAME_BODY_OFFSET_NED = 9
          
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	float get_x() const
          {return m_payload.get<float>(4);}
      	float get_y() const
          {return m_payload.get<float>(8);}
      	float get_z() const
          {return m_payload.get<float>(12);}
      	float get_vx() const
          {return m_payload.get<float>(16);}
      	float get_vy() const
          {return m_payload.get<float>(20);}
      	float get_vz() const
          {return m_payload.get<float>(24);}
      	float get_afx() const
          {return m_payload.get<float>(28);}
      	float get_afy() const
          {return m_payload.get<float>(32);}
      	float get_afz() const
          {return m_payload.get<float>(36);}
      	float get_yaw() const
          {return m_payload.get<float>(40);}
      	float get_yaw_rate() const
          {return m_payload.get<float>(44);}
      	uint16_t get_type_mask() const
          {return m_payload.get<uint16_t>(48);}
      	uint8_t get_coordinate_frame() const
          {return m_payload.get<uint8_t>(50);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_POSITION_TARGET_LOCAL_NED_H
    