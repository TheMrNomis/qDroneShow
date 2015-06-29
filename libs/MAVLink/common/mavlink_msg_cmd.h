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

#include "../mavlinkmessage.h"

#ifndef MAVLINK_MSG_CMD_H
#define MAVLINK_MSG_CMD_H

class MAVLink_msg_cmd : public MAVLinkMessage
{
public:
  MAVLink_msg_cmd(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber,
                 uint8_t target_system, uint8_t target_component,
                 uint16_t command, uint8_t confirmation,
                 float param1 = 0, float param2 = 0, float param3 = 0,
                 float param4 = 0, float param5 = 0, float param6 = 0,
                 float param7 = 0);

  uint8_t get_target_system() const;
  uint8_t get_target_component() const;
  uint16_t get_command() const;
  uint8_t get_confirmation() const;
  float get_param1() const;
  float get_param2() const;
  float get_param3() const;
  float get_param4() const;
  float get_param5() const;
  float get_param6() const;
  float get_param7() const;
};

#endif // MAVLINK_MSG_CMD_H
