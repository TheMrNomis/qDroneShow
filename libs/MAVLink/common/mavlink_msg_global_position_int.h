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

#ifndef MAVLINK_MSG_GLOBAL_POSITION_INT_H
#define MAVLINK_MSG_GLOBAL_POSITION_INT_H

#include "./mavlink.h"

class MAVLink_msg_global_position_int : public MAVLinkMessage
{
public:
  MAVLink_msg_global_position_int(uint8_t systemID, uint8_t componentID,
                                  uint8_t sequenceNumber, uint32_t time_boot_ms,
                                  int32_t lat, int32_t lon, int32_t alt,  int32_t relative_alt,
                                  int16_t vx, int16_t vy, int16_t vz, uint16_t hdg);

  uint32_t get_time_boot_ms() const;
  int32_t get_lat() const;
  int32_t get_lon() const;
  int32_t get_alt() const;
  int32_t get_relative_alt() const;
  int16_t get_vx() const;
  int16_t get_vy() const;
  int16_t get_vz() const;
  uint16_t get_hdg() const;
};

#endif // MAVLINK_MSG_GLOBAL_POSITION_INT_H
