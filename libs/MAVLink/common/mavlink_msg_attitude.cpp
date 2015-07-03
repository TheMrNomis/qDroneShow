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

#include "mavlink_msg_attitude.h"

MAVLink_msg_attitude::MAVLink_msg_attitude(uint8_t systemID, uint8_t componentID,
                                           uint8_t sequenceNumber, uint32_t time_boot_ms,
                                           float roll, float pitch, float yaw,
                                           float rollspeed, float pitchspeed, float yawspeed):

  MAVLinkMessage( mavlink_message::lengths[mavlink_message::attitude],
                  sequenceNumber,systemID,componentID,
                  mavlink_message::attitude,
                  mavlink_message::crcs[mavlink_message::attitude])
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
