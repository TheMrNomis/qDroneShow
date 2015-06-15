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

#include "mavlinkmessage.h"

#ifndef MAVLINKHEARTBEAT_H
#define MAVLINKHEARTBEAT_H


class MAVLinkHeartbeat : public MAVLinkMessage
{
public:
  /**
   * @brief creates a MAVLinkHeartbeat
   * @param systemID The identifier of the receiving system
   * @param componentID The identifier of the component on the receiving system
   * @param sequenceNumber The number of the message in the sequence (0 -> 254)
   * @param type Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
   * @param autopilot Autopilot type / class. defined in MAV_AUTOPILOT ENUM
   * @param baseMode System mode bitfield, see MAV_MODE_FLAG ENUM
   * @param customMode A bitfield for use for autopilot-specific flags.
   * @param systemStatus System status flag, see MAV_STATE ENUM
   */
  MAVLinkHeartbeat(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber,uint8_t type, uint8_t autopilot,
                   uint8_t baseMode, uint32_t customMode, uint8_t systemStatus);
};

#endif // MAVLINKHEARTBEAT_H
