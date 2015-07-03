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

#ifndef MAVLINK_MSG_SYS_STATUS_H
#define MAVLINK_MSG_SYS_STATUS_H

#include "./mavlink.h"

class MAVLink_msg_sys_status : public MAVLinkMessage
{
public:
  MAVLink_msg_sys_status(uint8_t system_id, uint8_t component_id, uint8_t sequenceNumber,
                         uint32_t onboard_control_sensors_present,
                         uint32_t onboard_control_sensors_enabled,
                         uint32_t onboard_control_sensors_health,
                         uint16_t load, uint16_t voltage_battery,
                         int16_t current_battery, int8_t battery_remaining,
                         uint16_t drop_rate_comm, uint16_t errors_comm,
                         uint16_t errors_count1, uint16_t errors_count2,
                         uint16_t errors_count3, uint16_t errors_count4);

   uint32_t get_onboard_control_sensors_present() const;
   uint32_t get_onboard_control_sensors_enabled() const;
   uint32_t get_onboard_control_sensors_health() const;

   uint16_t get_load() const;
   uint16_t get_voltage_battery() const;
   int16_t get_current_battery() const;
   int8_t get_battery_remaining() const;

   uint16_t get_drop_rate_comm() const;
   uint16_t get_errors_comm() const;
   uint16_t get_errors_count1() const;
   uint16_t get_errors_count2() const;
   uint16_t get_errors_count3() const;
   uint16_t get_errors_count4() const;
};

#endif // MAVLINK_MSG_SYS_STATUS_H
