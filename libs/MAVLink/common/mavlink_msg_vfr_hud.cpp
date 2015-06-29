#include "mavlink_msg_vfr_hud.h"

MAVLink_msg_vfr_hud::MAVLink_msg_vfr_hud(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber,float airspeed, float groundspeed, int16_t heading, uint16_t throttle, float alt, float climb):
  MAVLinkMessage(20,sequenceNumber,systemID,componentID,MAV_MSG_VFR_HUD,true,20)
{
  m_payload << airspeed;
  m_payload << groundspeed;
  m_payload << alt;
  m_payload << climb;
  m_payload << heading;
  m_payload << throttle;
}

float get_airspeed() const
  {return m_payload.get<float>(0*sizeof(float));}
float get_groundspeed() const
  {return m_payload.get<float>(1*sizeof(float));}

float get_alt() const
  {return m_payload.get<float>(2*sizeof(float));}
float get_climb() const
  {return m_payload.get<float>(3*sizeof(float));}

int16_t get_heading() const
  {return m_payload.get<int16_t>(4*sizeof(float));}

uint16_t get_throttle() const
  {return m_payload.get<uint16_t>(4*sizeof(float) + sizeof(int16_t));}
