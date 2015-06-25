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

#include "mavlink_msg_heartbeat.h"

MAVLink_msg_heartbeat::MAVLink_msg_heartbeat(uint8_t systemID, uint8_t componentID,
				uint8_t sequenceNumber,uint8_t type, uint8_t autopilot,
                uint8_t baseMode, uint32_t customMode, uint8_t systemStatus):
  MAVLinkMessage(9,sequenceNumber,systemID,componentID,0,true,0x32)
{
  m_payload << customMode;
  m_payload << type;
  m_payload << autopilot;
  m_payload << baseMode;
  m_payload << systemStatus;
  m_payload << (uint8_t)3; //protocol version
}