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

#include "mavlink_msg_vfr_hud.h"

MAVLink_msg_vfr_hud::MAVLink_msg_vfr_hud(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber,
                                         float airspeed, float groundspeed,
                                         int16_t heading, uint16_t throttle,
                                         float alt, float climb):

  MAVLinkMessage( mavlink_message::lengths[mavlink_message::vfr_hud],
                  sequenceNumber,systemID,componentID,
                  mavlink_message::vfr_hud,
                  mavlink_message::crcs[mavlink_message::vfr_hud])
{
  m_payload << airspeed;
  m_payload << groundspeed;
  m_payload << alt;
  m_payload << climb;
  m_payload << heading;
  m_payload << throttle;
}

float MAVLink_msg_vfr_hud::get_airspeed() const
  {return m_payload.get<float>(0*sizeof(float));}
float MAVLink_msg_vfr_hud::get_groundspeed() const
  {return m_payload.get<float>(1*sizeof(float));}

float MAVLink_msg_vfr_hud::get_alt() const
  {return m_payload.get<float>(2*sizeof(float));}
float MAVLink_msg_vfr_hud::get_climb() const
  {return m_payload.get<float>(3*sizeof(float));}

int16_t MAVLink_msg_vfr_hud::get_heading() const
  {return m_payload.get<int16_t>(4*sizeof(float));}

uint16_t MAVLink_msg_vfr_hud::get_throttle() const
  {return m_payload.get<uint16_t>(4*sizeof(float) + sizeof(int16_t));}
