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

MAVLinkMessage::MAVLinkMessage(uint8_t length, uint8_t sequenceNumber, uint8_t systemID, uint8_t componentID, uint8_t messageID, bool crc_extra, uint8_t stx) :
  MAVLINK_CRC_EXTRA(crc_extra),
  MAVLINK_STX(stx),
  m_header(0xFE),
  m_length(length),
  m_sequenceNumber(sequenceNumber),
  m_systemID(systemID),
  m_componentID(componentID),
  m_messageID(messageID),
  m_payload()
{

}

ByteBuffer MAVLinkMessage::toByteBuffer() const
{
  return ByteBuffer();
}

/**
 * @brief finalize the MAVLink message
 *
 * This function calcultes the checksum and sets length and aircraft id correctly
 * It assumes that the message id and the payload are already correctly set.
 *
 * @return
 */
//ByteBuffer MAVLinkMessage::_finalize_message(uint8_t chan = MAVLINK_COMM_0)
//{
//  // This code part is the same for all messages;
//  msg->magic = MAVLINK_STX;
//  msg->len = m_length;
//  msg->sysid = m_systemID;
//  msg->compid = m_componentID;
//  // One sequence number per component
//  msg->seq = mavlink_get_channel_status(chan)->current_tx_seq;
//  mavlink_get_channel_status(chan)->current_tx_seq = mavlink_get_channel_status(chan)->current_tx_seq+1;
//  msg->checksum = crc_calculate(((const uint8_t*)(msg)) + 3, MAVLINK_CORE_HEADER_LEN);
//  crc_accumulate_buffer(&msg->checksum, _MAV_PAYLOAD(msg), msg->len);
//  if(MAVLINK_CRC_EXTRA)
//    crc_accumulate(crc_extra, &msg->checksum);
//  mavlink_ck_a(msg) = (uint8_t)(msg->checksum & 0xFF);
//  mavlink_ck_b(msg) = (uint8_t)(msg->checksum >> 8);

//  return length + MAVLINK_NUM_NON_PAYLOAD_BYTES;
//}
