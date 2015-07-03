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

#ifndef MAVLINK_MSG_VFR_HUD_H
#define MAVLINK_MSG_VFR_HUD_H

#include "./mavlink.h"

class MAVLink_msg_vfr_hud : public MAVLinkMessage
{
public:
  MAVLink_msg_vfr_hud(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber,
                      float airspeed, float groundspeed,
                      int16_t heading, uint16_t throttle,
                      float alt, float climb);

  float get_airspeed() const;
  float get_groundspeed() const;
  int16_t get_heading() const;
  uint16_t get_throttle() const;
  float get_alt() const;
  float get_climb() const;
};

#endif // MAVLINK_MSG_VFR_HUD_H
