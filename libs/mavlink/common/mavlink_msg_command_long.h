#ifndef MAVLINK_CPP_MSG_COMMAND_LONG_H
#define MAVLINK_CPP_MSG_COMMAND_LONG_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t command_long_id = 76;
    const uint8_t command_long_length = 33;
    const uint8_t command_long_crc = 152;

    class command_long : public mavlink::message
    {
      public:
        command_long(uint8_t system_id, uint8_t component_id,  uint8_t  target_system, uint8_t  target_component, uint16_t  command, uint8_t  confirmation, float  param1, float  param2, float  param3, float  param4, float  param5, float  param6, float  param7):
          mavlink::message( mavlink::msg::command_long_length,
                            system_id,
                            component_id,
                            mavlink::msg::command_long_id)
        {
           m_payload.push_back<float>(param1); ///< Parameter 1, as defined by MAV_CMD enum.
           m_payload.push_back<float>(param2); ///< Parameter 2, as defined by MAV_CMD enum.
           m_payload.push_back<float>(param3); ///< Parameter 3, as defined by MAV_CMD enum.
           m_payload.push_back<float>(param4); ///< Parameter 4, as defined by MAV_CMD enum.
           m_payload.push_back<float>(param5); ///< Parameter 5, as defined by MAV_CMD enum.
           m_payload.push_back<float>(param6); ///< Parameter 6, as defined by MAV_CMD enum.
           m_payload.push_back<float>(param7); ///< Parameter 7, as defined by MAV_CMD enum.
           m_payload.push_back<uint16_t>(command); ///< Command ID, as defined by MAV_CMD enum.
           m_payload.push_back<uint8_t>(target_system); ///< System which should execute the command
           m_payload.push_back<uint8_t>(target_component); ///< Component which should execute the command, 0 for all components
           m_payload.push_back<uint8_t>(confirmation); ///< 0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command)
          
          
        }

      	float get_param1() const
          {return m_payload.get<float>(0);}
      	float get_param2() const
          {return m_payload.get<float>(4);}
      	float get_param3() const
          {return m_payload.get<float>(8);}
      	float get_param4() const
          {return m_payload.get<float>(12);}
      	float get_param5() const
          {return m_payload.get<float>(16);}
      	float get_param6() const
          {return m_payload.get<float>(20);}
      	float get_param7() const
          {return m_payload.get<float>(24);}
      	uint16_t get_command() const
          {return m_payload.get<uint16_t>(28);}
      	uint8_t get_target_system() const
          {return m_payload.get<uint8_t>(30);}
      	uint8_t get_target_component() const
          {return m_payload.get<uint8_t>(31);}
      	uint8_t get_confirmation() const
          {return m_payload.get<uint8_t>(32);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_COMMAND_LONG_H
    