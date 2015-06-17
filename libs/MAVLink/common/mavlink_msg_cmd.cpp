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
  MAVLinkMessage(33,sequenceNumber,systemID,componentID,76,true,152)
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
