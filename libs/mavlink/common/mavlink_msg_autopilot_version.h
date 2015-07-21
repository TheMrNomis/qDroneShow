#ifndef MAVLINK_CPP_MSG_AUTOPILOT_VERSION_H
#define MAVLINK_CPP_MSG_AUTOPILOT_VERSION_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t autopilot_version_id = 148;
    const uint8_t autopilot_version_length = 60;
    const uint8_t autopilot_version_crc = 178;

    class autopilot_version : public mavlink::message
    {
      public:
        autopilot_version(uint8_t system_id, uint8_t component_id,  uint64_t capabilities, uint32_t flight_sw_version, uint32_t middleware_sw_version, uint32_t os_sw_version, uint32_t board_version, const uint8_t *flight_custom_version, const uint8_t *middleware_custom_version, const uint8_t *os_custom_version, uint16_t vendor_id, uint16_t product_id, uint64_t uid):
          mavlink::message( mavlink::msg::autopilot_version_length,
                            system_id,
                            component_id,
                            mavlink::msg::autopilot_version_id,
                            mavlink::msg::autopilot_version_crc)
        {
           m_payload.push_back<uint64_t>(capabilities); ///< bitmask of capabilities (see MAV_PROTOCOL_CAPABILITY enum)
           m_payload.push_back<uint64_t>(uid); ///< UID if provided by hardware
           m_payload.push_back<uint32_t>(flight_sw_version); ///< Firmware version number
           m_payload.push_back<uint32_t>(middleware_sw_version); ///< Middleware version number
           m_payload.push_back<uint32_t>(os_sw_version); ///< Operating system version number
           m_payload.push_back<uint32_t>(board_version); ///< HW / board version (last 8 bytes should be silicon ID, if any)
           m_payload.push_back<uint16_t>(vendor_id); ///< ID of the board vendor
           m_payload.push_back<uint16_t>(product_id); ///< ID of the product
          
        }

      	uint64_t get_capabilities() const
          {return m_payload.get<uint64_t>(0);}
      	uint64_t get_uid() const
          {return m_payload.get<uint64_t>(8);}
      	uint32_t get_flight_sw_version() const
          {return m_payload.get<uint32_t>(16);}
      	uint32_t get_middleware_sw_version() const
          {return m_payload.get<uint32_t>(20);}
      	uint32_t get_os_sw_version() const
          {return m_payload.get<uint32_t>(24);}
      	uint32_t get_board_version() const
          {return m_payload.get<uint32_t>(28);}
      	uint16_t get_vendor_id() const
          {return m_payload.get<uint16_t>(32);}
      	uint16_t get_product_id() const
          {return m_payload.get<uint16_t>(34);}
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_AUTOPILOT_VERSION_H
    