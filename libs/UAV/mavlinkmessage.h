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

#include <iostream>
#include "bytebuffer.h"

/**
 * @brief The MAVLinkMessage class represents one MAVLink message.
 *        It is the base class for other types of MAVLink messages
 */
class MAVLinkMessage
{
public:
  MAVLinkMessage(ByteBuffer & buffer, bool crc_extra = true, uint8_t crc_extra_value = 0);
  /**
   * @brief transforms the MAVLinkMessage into a ByteBuffer
   *
   * The ByteBuffer that is generated can then be sent over a telemetry,
   * or whatever link you have between the GCS and the MAV.
   */
  ByteBuffer toByteBuffer() const;

protected:
  MAVLinkMessage(uint8_t length, uint8_t sequenceNumber, uint8_t systemID, uint8_t componentID, uint8_t messageID, bool crc_extra = true, uint8_t crc_extra_value = 0);

  ByteBuffer m_payload;

private:
  ByteBuffer _calculateChecksum(ByteBuffer const& buffer) const;

  class Checksum
  {
  public:
    Checksum();
    void accumulate(uint8_t data);
    void accumulate(ByteBuffer data);

    operator uint16_t() const;

  private:

    uint16_t m_crc;

    const uint16_t m_X25_INIT_CRC;
    const uint16_t m_X25_VALIDATE_CRC;
  };

  //constants
  const bool m_MAVLINK_CRC_EXTRA;
  const uint8_t m_CRC_EXTRA;

  //mavlink_message struct variables
  uint8_t m_header;         ///< 0xFE (MAVLink header)
  uint8_t m_length;         ///< message payload length
  uint8_t m_sequenceNumber; ///< sequence number. Rolls between 0x00 and 0xFF
  uint8_t m_systemID;       ///< system ID
  uint8_t m_componentID;    ///< component ID
  uint8_t m_messageID;      ///< message ID
  //ByteBuffer m_checksum;          ///< checksum for error detection

};

#endif // MAVLINKMESSAGE_H
