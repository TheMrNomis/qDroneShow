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

#ifndef MAVLINKMESSAGE_H
#define MAVLINKMESSAGE_H

/**
 * @brief The MAVLinkMessage class represents one MAVLink message.
 *        It is the base class for other types of MAVLink messages
 */
class MAVLinkMessage
{
public:
  MAVLinkMessage();



private:
  //convenience functions

  /**
   * @brief finalize the MAVLink message
   *
   * This function calcultes the checksum and sets length and aircraft id correctly
   * It assumes that the message id and the payload are already correctly set.
   */
  uint16_t _finalize_message(uint8_t chan = MAVLINK_COMM_0);


//member variables

  //constants
  const bool MAVLINK_CRC_EXTRA;
  const uint8_t MAVLINK_STX;

  //mavlink_message struct variables
  const uint8_t m_header;
  const uint8_t m_sequenceNumber;
  const uint8_t m_systemID;
  const uint8_t m_componenentID;
  const uint8_t m_messageID;
  uint8_t m_length;
  uint16_t m_checksum;

};

#endif // MAVLINKMESSAGE_H
