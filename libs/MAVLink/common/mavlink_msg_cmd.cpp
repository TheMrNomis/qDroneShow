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

#include "mavlink_msg_cmd.h"

MAVLink_msg_cmd::MAVLink_msg_cmd(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber,
               uint8_t target_system, uint8_t target_component,
               uint16_t command, uint8_t confirmation,
               float param1, float param2, float param3,
               float param4, float param5, float param6,
               float param7):

  MAVLinkMessage( mavlink_message::lengths[mavlink_message::command_long],
                  sequenceNumber,systemID,componentID,
                  mavlink_message::command_long,
                  mavlink_message::crcs[mavlink_message::command_long])
{
  m_payload << param1;
  m_payload << param2;
  m_payload << param3;
  m_payload << param4;
  m_payload << param5;
  m_payload << param6;
  m_payload << param7;
  m_payload << command;
  m_payload << target_system;
  m_payload << target_component;
  m_payload << confirmation;
}

float MAVLink_msg_cmd::get_param1() const
  {return m_payload.get<float>(0);}
float MAVLink_msg_cmd::get_param2() const
  {return m_payload.get<float>(1*sizeof(float));}
float MAVLink_msg_cmd::get_param3() const
  {return m_payload.get<float>(2*sizeof(float));}
float MAVLink_msg_cmd::get_param4() const
  {return m_payload.get<float>(3*sizeof(float));}
float MAVLink_msg_cmd::get_param5() const
  {return m_payload.get<float>(4*sizeof(float));}
float MAVLink_msg_cmd::get_param6() const
  {return m_payload.get<float>(5*sizeof(float));}
float MAVLink_msg_cmd::get_param7() const
  {return m_payload.get<float>(6*sizeof(float));}

uint16_t MAVLink_msg_cmd::get_command() const
  {return m_payload.get<uint16_t>(7*sizeof(float));}

uint8_t MAVLink_msg_cmd::get_target_system() const
  {return m_payload.get<uint8_t>(7*sizeof(float) + sizeof(uint16_t));}
uint8_t MAVLink_msg_cmd::get_target_component() const
  {return m_payload.get<uint8_t>(7*sizeof(float) + sizeof(uint16_t) + 1*sizeof(uint8_t));}
uint8_t MAVLink_msg_cmd::get_confirmation() const
  {return m_payload.get<uint8_t>(7*sizeof(float) + sizeof(uint16_t) + 2*sizeof(uint8_t));}

