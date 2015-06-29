#include "mavlink_msg_attitude.h"

MAVLink_msg_attitude::MAVLink_msg_attitude(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber, uint32_t time_boot_ms, float roll, float pitch, float yaw, float rollspeed, float pitchspeed, float yawspeed):
  MAVLinkMessage(28,sequenceNumber,systemID,componentID,MAV_MSG_ATTITUDE,true,39)
{
  m_payload << time_boot_ms;
  m_payload << roll;
  m_payload << pitch;
  m_payload << yaw;
  m_payload << rollspeed;
  m_payload << pitchspeed;
  m_payload << yawspeed;
}

uint32_t MAVLink_msg_attitude::get_time_boot_ms() const
  {return m_payload.get<uint32_t>(0);}

float MAVLink_msg_attitude::get_roll() const
  {return m_payload.get<float>(sizeof(uint32_t));}

float MAVLink_msg_attitude::get_pitch() const
  {return m_payload.get<float>(sizeof(uint32_t) + sizeof(float));}

float MAVLink_msg_attitude::get_yaw() const
  {return m_payload.get<float>(sizeof(uint32_t) + 2*sizeof(float));}

float MAVLink_msg_attitude::get_rollspeed() const
  {return m_payload.get<float>(sizeof(uint32_t) + 3*sizeof(float));}

float MAVLink_msg_attitude::get_pitchspeed() const
  {return m_payload.get<float>(sizeof(uint32_t) + 4*sizeof(float));}

float MAVLink_msg_attitude::get_yawspeed() const
  {return m_payload.get<float>(sizeof(uint32_t) + 5*sizeof(float));}
