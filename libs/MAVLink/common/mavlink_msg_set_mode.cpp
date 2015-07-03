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

#include "mavlink_msg_set_mode.h"

MAVLink_msg_set_mode::MAVLink_msg_set_mode(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber,
                                           uint8_t target_system, uint8_t base_mode, uint32_t custom_mode):

  MAVLinkMessage( mavlink_message::lengths[mavlink_message::set_mode],
                  sequenceNumber,systemID,componentID,
                  mavlink_message::set_mode,
                  mavlink_message::crcs[mavlink_message::set_mode])
{
  m_payload << custom_mode;
  m_payload << target_system;
  m_payload << base_mode;
}


uint32_t MAVLink_msg_set_mode::get_custom_mode() const
  {return m_payload.get<uint32_t>(0);}

uint8_t MAVLink_msg_set_mode::get_arget_system() const
  {return m_payload.get<uint8_t>(sizeof(uint32_t) + 0*sizeof(uint8_t));}
uint8_t MAVLink_msg_set_mode::get_base_mode() const
  {return m_payload.get<uint8_t>(sizeof(uint32_t) + 1*sizeof(uint8_t));}
