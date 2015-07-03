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

#include "mavlink_msg_sys_status.h"

MAVLink_msg_sys_status::MAVLink_msg_sys_status(uint8_t system_id, uint8_t component_id, uint8_t sequenceNumber,
                                               uint32_t onboard_control_sensors_present,
                                               uint32_t onboard_control_sensors_enabled,
                                               uint32_t onboard_control_sensors_health,
                                               uint16_t load, uint16_t voltage_battery,
                                               int16_t current_battery, int8_t battery_remaining,
                                               uint16_t drop_rate_comm, uint16_t errors_comm,
                                               uint16_t errors_count1, uint16_t errors_count2,
                                               uint16_t errors_count3, uint16_t errors_count4):

  MAVLinkMessage( mavlink_message::lengths[mavlink_message::sys_status],
                  sequenceNumber,system_id,component_id,
                  mavlink_message::sys_status,
                  mavlink_message::crcs[mavlink_message::sys_status])
{
  m_payload << onboard_control_sensors_present;
  m_payload << onboard_control_sensors_enabled;
  m_payload << onboard_control_sensors_health;
  m_payload << load;
  m_payload << voltage_battery;
  m_payload << current_battery;
  m_payload << drop_rate_comm;
  m_payload << errors_comm;
  m_payload << errors_count1;
  m_payload << errors_count2;
  m_payload << errors_count3;
  m_payload << errors_count4;
  m_payload << battery_remaining;

}

uint32_t MAVLink_msg_sys_status::get_onboard_control_sensors_present() const
  {return m_payload.get<uint32_t>(0*sizeof(uint32_t));}
uint32_t MAVLink_msg_sys_status::get_onboard_control_sensors_enabled() const
  {return m_payload.get<uint32_t>(1*sizeof(uint32_t));}
uint32_t MAVLink_msg_sys_status::get_onboard_control_sensors_health() const
  {return m_payload.get<uint32_t>(2*sizeof(uint32_t));}

uint16_t MAVLink_msg_sys_status::get_load() const
  {return m_payload.get<uint16_t>(3*sizeof(uint32_t) + 0*sizeof(uint16_t));}
uint16_t MAVLink_msg_sys_status::get_voltage_battery() const
  {return m_payload.get<uint16_t>(3*sizeof(uint32_t) + 1*sizeof(uint16_t));}
int16_t MAVLink_msg_sys_status::get_current_battery() const
  {return m_payload.get<uint16_t>(3*sizeof(uint32_t) + 2*sizeof(uint16_t));}
uint16_t MAVLink_msg_sys_status::get_drop_rate_comm() const
  {return m_payload.get<uint16_t>(3*sizeof(uint32_t) + 3*sizeof(uint16_t));}
uint16_t MAVLink_msg_sys_status::get_errors_comm() const
  {return m_payload.get<uint16_t>(3*sizeof(uint32_t) + 4*sizeof(uint16_t));}
uint16_t MAVLink_msg_sys_status::get_errors_count1() const
  {return m_payload.get<uint16_t>(3*sizeof(uint32_t) + 5*sizeof(uint16_t));}
uint16_t MAVLink_msg_sys_status::get_errors_count2() const
  {return m_payload.get<uint16_t>(3*sizeof(uint32_t) + 6*sizeof(uint16_t));}
uint16_t MAVLink_msg_sys_status::get_errors_count3() const
  {return m_payload.get<uint16_t>(3*sizeof(uint32_t) + 7*sizeof(uint16_t));}
uint16_t MAVLink_msg_sys_status::get_errors_count4() const
  {return m_payload.get<uint16_t>(3*sizeof(uint32_t) + 8*sizeof(uint16_t));}

int8_t MAVLink_msg_sys_status::get_battery_remaining() const
  {return m_payload.get<uint8_t>(3*sizeof(uint32_t) + 9*sizeof(uint16_t));}
