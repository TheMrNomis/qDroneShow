#ifndef MAVLINK_CPP_MSG_MEMORY_VECT_H
#define MAVLINK_CPP_MSG_MEMORY_VECT_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t memory_vect_id = 249;
    const uint8_t memory_vect_length = 36;
    const uint8_t memory_vect_crc = 204;

    class memory_vect : public mavlink::message
    {
      public:
        memory_vect(uint8_t system_id, uint8_t component_id,  uint16_t address, uint8_t ver, uint8_t type, const int8_t *value):
          mavlink::message( mavlink::msg::memory_vect_length,
                            system_id,
                            component_id,
                            mavlink::msg::memory_vect_id,
                            mavlink::msg::memory_vect_crc)
        {
           m_payload.push_back<uint16_t>(address); ///< Starting address of the debug variables
           m_payload.push_back<uint8_t>(ver); ///< Version code of the type variable. 0=unknown, type ignored and assumed int16_t. 1=as below
           m_payload.push_back<uint8_t>(type); ///< Type code of the memory variables. for ver = 1: 0=16 x int16_t, 1=16 x uint16_t, 2=16 x Q15, 3=16 x 1Q14
          
        }

      	uint16_t get_address() const
          {return m_payload.get<uint16_t>(0);}
      	uint8_t get_ver() const
          {return m_payload.get<uint8_t>(2);}
      	uint8_t get_type() const
          {return m_payload.get<uint8_t>(3);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_MEMORY_VECT_H
    