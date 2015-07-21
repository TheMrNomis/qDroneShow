#ifndef MAVLINK_CPP_MSG_ENCAPSULATED_DATA_H
#define MAVLINK_CPP_MSG_ENCAPSULATED_DATA_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t encapsulated_data_id = 131;
    const uint8_t encapsulated_data_length = 255;
    const uint8_t encapsulated_data_crc = 223;

    class encapsulated_data : public mavlink::message
    {
      public:
        encapsulated_data(uint8_t system_id, uint8_t component_id,  uint16_t seqnr, const uint8_t *data):
          mavlink::message( mavlink::msg::encapsulated_data_length,
                            system_id,
                            component_id,
                            mavlink::msg::encapsulated_data_id,
                            mavlink::msg::encapsulated_data_crc)
        {
           m_payload.push_back<uint16_t>(seqnr); ///< sequence number (starting with 0 on every transmission)
          
        }

      	uint16_t get_seqnr() const
          {return m_payload.get<uint16_t>(0);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_ENCAPSULATED_DATA_H
    