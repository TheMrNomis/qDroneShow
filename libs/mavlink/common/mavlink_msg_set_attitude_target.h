#ifndef MAVLINK_CPP_MSG_SET_ATTITUDE_TARGET_H
#define MAVLINK_CPP_MSG_SET_ATTITUDE_TARGET_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t set_attitude_target_id = 82;
    const uint8_t set_attitude_target_length = 39;
    const uint8_t set_attitude_target_crc = 49;

    class set_attitude_target : public mavlink::message
    {
      public:
        set_attitude_target(uint8_t system_id, uint8_t component_id,  uint32_t time_boot_ms, uint8_t target_system, uint8_t target_component, uint8_t type_mask, const float *q, float body_roll_rate, float body_pitch_rate, float body_yaw_rate, float thrust):
          mavlink::message( mavlink::msg::set_attitude_target_length,
                            system_id,
                            component_id,
                            mavlink::msg::set_attitude_target_id,
                            mavlink::msg::set_attitude_target_crc)
        {
           m_payload.push_back<uint32_t>(time_boot_ms); ///< Timestamp in milliseconds since system boot
           m_payload.push_back<float>(body_roll_rate); ///< Body roll rate in radians per second
           m_payload.push_back<float>(body_pitch_rate); ///< Body roll rate in radians per second
           m_payload.push_back<float>(body_yaw_rate); ///< Body roll rate in radians per second
           m_payload.push_back<float>(thrust); ///< Collective thrust, normalized to 0 .. 1 (-1 .. 1 for vehicles capable of reverse trust)
           m_payload.push_back<uint8_t>(target_system); ///< System ID
           m_payload.push_back<uint8_t>(target_component); ///< Component ID
           m_payload.push_back<uint8_t>(type_mask); ///< Mappings: If any of these bits are set, the corresponding input should be ignored: bit 1: body roll rate, bit 2: body pitch rate, bit 3: body yaw rate. bit 4-bit 6: reserved, bit 7: throttle, bit 8: attitude
          
        }

      	uint32_t get_time_boot_ms() const
          {return m_payload.get<uint32_t>(0);}
      	float get_body_roll_rate() const
          {return m_payload.get<float>(20);}
      	float get_body_pitch_rate() const
          {return m_payload.get<float>(24);}
      	float get_body_yaw_rate() const
          {return m_payload.get<float>(28);}
      	float get_thrust() const
          {return m_payload.get<float>(32);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(36);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(37);}
      	uint8_t get_type_mask() const
          {return m_payload.get<uint8_t>(38);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_SET_ATTITUDE_TARGET_H
    