#ifndef MAVLINK_CPP_MSG_SERVO_OUTPUT_RAW_H
#define MAVLINK_CPP_MSG_SERVO_OUTPUT_RAW_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t servo_output_raw_id = 36;
    const uint8_t servo_output_raw_length = 21;
    const uint8_t servo_output_raw_crc = 222;

    class servo_output_raw : public mavlink::message
    {
      public:
        servo_output_raw(uint8_t system_id, uint8_t component_id,  uint32_t  time_usec, uint8_t  port, uint16_t  servo1_raw, uint16_t  servo2_raw, uint16_t  servo3_raw, uint16_t  servo4_raw, uint16_t  servo5_raw, uint16_t  servo6_raw, uint16_t  servo7_raw, uint16_t  servo8_raw):
          mavlink::message( mavlink::msg::servo_output_raw_length,
                            system_id,
                            component_id,
                            mavlink::msg::servo_output_raw_id)
        {
           m_payload.push_back<uint32_t>(time_usec); ///< Timestamp (microseconds since system boot)
           m_payload.push_back<uint16_t>(servo1_raw); ///< Servo output 1 value, in microseconds
           m_payload.push_back<uint16_t>(servo2_raw); ///< Servo output 2 value, in microseconds
           m_payload.push_back<uint16_t>(servo3_raw); ///< Servo output 3 value, in microseconds
           m_payload.push_back<uint16_t>(servo4_raw); ///< Servo output 4 value, in microseconds
           m_payload.push_back<uint16_t>(servo5_raw); ///< Servo output 5 value, in microseconds
           m_payload.push_back<uint16_t>(servo6_raw); ///< Servo output 6 value, in microseconds
           m_payload.push_back<uint16_t>(servo7_raw); ///< Servo output 7 value, in microseconds
           m_payload.push_back<uint16_t>(servo8_raw); ///< Servo output 8 value, in microseconds
           m_payload.push_back<uint8_t>(port); ///< Servo output port (set of 8 outputs = 1 port). Most MAVs will just use one, but this allows to encode more than 8 servos.
          
          
        }

      	uint32_t get_time_usec() const
          {return m_payload.get<uint32_t>(0);}
      	uint16_t get_servo1_raw() const
          {return m_payload.get<uint16_t>(4);}
      	uint16_t get_servo2_raw() const
          {return m_payload.get<uint16_t>(6);}
      	uint16_t get_servo3_raw() const
          {return m_payload.get<uint16_t>(8);}
      	uint16_t get_servo4_raw() const
          {return m_payload.get<uint16_t>(10);}
      	uint16_t get_servo5_raw() const
          {return m_payload.get<uint16_t>(12);}
      	uint16_t get_servo6_raw() const
          {return m_payload.get<uint16_t>(14);}
      	uint16_t get_servo7_raw() const
          {return m_payload.get<uint16_t>(16);}
      	uint16_t get_servo8_raw() const
          {return m_payload.get<uint16_t>(18);}
      	uint8_t get_port() const
          {return m_payload.get<uint8_t>(20);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_SERVO_OUTPUT_RAW_H
    