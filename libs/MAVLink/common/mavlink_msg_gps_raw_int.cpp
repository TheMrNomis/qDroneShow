#include "mavlink_msg_gps_raw_int.h"

MAVLink_msg_gps_raw_int::MAVLink_msg_gps_raw_int(
    uint8_t system_id, uint8_t component_id, uint8_t sequenceNumber,
    uint64_t time_usec, uint8_t fix_type,
    int32_t lat, int32_t lon, int32_t alt,
    uint16_t eph, uint16_t epv, uint16_t vel, uint16_t cog,
    uint8_t satellites_visible):

  MAVLinkMessage( mavlink_message::lengths[mavlink_message::gps_raw_int],
                  sequenceNumber, system_id, component_id,
                  mavlink_message::gps_raw_int,
                  mavlink_message::crcs[mavlink_message::gps_raw_int])
{
  m_payload << time_usec;
  m_payload << lat;
  m_payload << lon;
  m_payload << alt;
  m_payload << eph;
  m_payload << epv;
  m_payload << vel;
  m_payload << cog;
  m_payload << fix_type;
  m_payload << satellites_visible;
}

uint64_t MAVLink_msg_gps_raw_int::get_time_usec() const
  {return m_payload.get<uint64_t>(0);}

int32_t MAVLink_msg_gps_raw_int::get_lat() const
  {return m_payload.get<int32_t>(sizeof(uint64_t) + 0*sizeof(int32_t));}
int32_t MAVLink_msg_gps_raw_int::get_lon() const
  {return m_payload.get<int32_t>(sizeof(uint64_t) + 1*sizeof(int32_t));}
int32_t MAVLink_msg_gps_raw_int::get_alt() const
  {return m_payload.get<int32_t>(sizeof(uint64_t) + 2*sizeof(int32_t));}

uint16_t MAVLink_msg_gps_raw_int::get_eph() const
  {return m_payload.get<int16_t>(sizeof(uint64_t) + 3*sizeof(int32_t) + 0*sizeof(uint16_t));}
uint16_t MAVLink_msg_gps_raw_int::get_epv() const
  {return m_payload.get<int16_t>(sizeof(uint64_t) + 3*sizeof(int32_t) + 1*sizeof(uint16_t));}
uint16_t MAVLink_msg_gps_raw_int::get_vel() const
  {return m_payload.get<int16_t>(sizeof(uint64_t) + 3*sizeof(int32_t) + 2*sizeof(uint16_t));}
uint16_t MAVLink_msg_gps_raw_int::get_cog() const
  {return m_payload.get<int16_t>(sizeof(uint64_t) + 3*sizeof(int32_t) + 3*sizeof(uint16_t));}

uint8_t MAVLink_msg_gps_raw_int::get_fix_type() const
  {return m_payload.get<int16_t>(sizeof(uint64_t) + 3*sizeof(int32_t) + 4*sizeof(uint16_t) + 0*sizeof(uint8_t));}
uint8_t MAVLink_msg_gps_raw_int::get_satellites_visible() const
  {return m_payload.get<int16_t>(sizeof(uint64_t) + 3*sizeof(int32_t) + 4*sizeof(uint16_t) + 0*sizeof(uint8_t));}
