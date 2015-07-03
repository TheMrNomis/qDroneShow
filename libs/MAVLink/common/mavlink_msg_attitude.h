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

#ifndef MAVLINK_MSG_ATTITUDE_H
#define MAVLINK_MSG_ATTITUDE_H

#include "./mavlink.h"

class MAVLink_msg_attitude : public MAVLinkMessage
{
public:
  MAVLink_msg_attitude(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber,
                       uint32_t time_boot_ms, float roll, float pitch, float yaw, float rollspeed, float pitchspeed, float yawspeed);

  uint32_t get_time_boot_ms() const;
  float get_roll() const;
  float get_pitch() const;
  float get_yaw() const;
  float get_rollspeed() const;
  float get_pitchspeed() const;
  float get_yawspeed() const;
};

#endif // MAVLINK_MSG_ATTITUDE_H
