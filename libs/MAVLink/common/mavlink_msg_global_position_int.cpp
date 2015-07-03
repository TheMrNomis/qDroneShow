/*======================================================================
 * qDroneShow Aerial vehicle show planification
 *
 * Copyright (C) 2015 - Amaury Louarn <amaury.louarn@homnomnom.fr>
 *
 * qDroneShow is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Feneral public license as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * qDroneShow is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without event the implied warranty of
 * MERCHANDABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with qDroneShow. If not, see <http://www.gnu.org/licenses/>
 * ======================================================================*/

/*=======================================================================
 * This file is based on the MAVLink C library, which is licensed under
 * the terms of the GNU Lesser General Public License (LGPL).
 *
 * See <https://github.com/mavlink/mavlink> for more information.
 *
 * Copyright (C) 2009-2014 Lorenz Meier <mail@qgroundcontrol.org>
 * ======================================================================*/

#include "mavlink_msg_global_position_int.h"

MAVLink_msg_global_position_int::MAVLink_msg_global_position_int(uint8_t systemID, uint8_t componentID,
                                                                 uint8_t sequenceNumber, uint32_t time_boot_ms,
                                                                 int32_t lat, int32_t lon, int32_t alt,  int32_t relative_alt,
                                                                 int16_t vx, int16_t vy, int16_t vz, uint16_t hdg):

  MAVLinkMessage( mavlink_message::lengths[mavlink_message::global_position_int],
                  sequenceNumber,systemID,componentID,
                  mavlink_message::global_position_int,
                  mavlink_message::crcs[mavlink_message::global_position_int])
{
  m_payload << time_boot_ms;
  m_payload << lat;
  m_payload << lon;
  m_payload << alt;
  m_payload << relative_alt;
  m_payload << vx;
  m_payload << vy;
  m_payload << vz;
  m_payload << hdg;
}

uint32_t MAVLink_msg_global_position_int::get_time_boot_ms() const
  {return m_payload.get<uint32_t>(0);}

int32_t MAVLink_msg_global_position_int::get_lat() const
  {return m_payload.get<int32_t>(sizeof(uint32_t) + 0*sizeof(int32_t));}
int32_t MAVLink_msg_global_position_int::get_lon() const
  {return m_payload.get<int32_t>(sizeof(uint32_t) + 1*sizeof(int32_t));}
int32_t MAVLink_msg_global_position_int::get_alt() const
  {return m_payload.get<int32_t>(sizeof(uint32_t) + 2*sizeof(int32_t));}

int32_t MAVLink_msg_global_position_int::get_relative_alt() const
  {return m_payload.get<int32_t>(sizeof(uint32_t) + 3*sizeof(int32_t));}

int16_t MAVLink_msg_global_position_int::get_vx() const
  {return m_payload.get<int16_t>(sizeof(uint32_t) + 3*sizeof(int32_t) + 0*sizeof(int16_t));}
int16_t MAVLink_msg_global_position_int::get_vy() const
  {return m_payload.get<int16_t>(sizeof(uint32_t) + 3*sizeof(int32_t) + 1*sizeof(int16_t));}
int16_t MAVLink_msg_global_position_int::get_vz() const
  {return m_payload.get<int16_t>(sizeof(uint32_t) + 3*sizeof(int32_t) + 2*sizeof(int16_t));}

uint16_t MAVLink_msg_global_position_int::get_hdg() const
  {return m_payload.get<uint16_t>(sizeof(uint32_t) + 3*sizeof(int32_t) + 3*sizeof(int16_t));}
