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

MAVLinkMessage::MAVLinkMessage(uint8_t length, uint8_t sequenceNumber, uint8_t systemID, uint8_t componentID, uint8_t messageID, bool crc_extra, uint8_t crc_extra_value) :
  m_MAVLINK_CRC_EXTRA(crc_extra),
  m_CRC_EXTRA(crc_extra_value),
  m_header(0xFE),
  m_length(length),
  m_sequenceNumber(sequenceNumber),
  m_systemID(systemID),
  m_componentID(componentID),
  m_messageID(messageID),
  m_payload()
{

}

MAVLinkMessage::MAVLinkMessage(ByteBuffer & buffer, bool crc_extra, uint8_t crc_extra_value):
  m_MAVLINK_CRC_EXTRA(crc_extra),
  m_CRC_EXTRA(crc_extra_value),
  m_header(0),
  m_length(0),
  m_sequenceNumber(0),
  m_systemID(),
  m_componentID(0),
  m_messageID(0),
  m_payload()
{
  buffer >> m_header;
  buffer >> m_length;
  buffer >> m_sequenceNumber;
  buffer >> m_systemID;
  buffer >> m_componentID;
  buffer >> m_messageID;
  for(int i = 0; i < m_length; ++i)
    buffer >> m_payload;
  for(int i = 0; i < 2; ++i)
    buffer >> m_checksum;
}

uint8_t MAVLinkMessage::get_header() const
  {return m_header;}
uint8_t MAVLinkMessage::get_length() const
  {return m_length;}
uint8_t MAVLinkMessage::get_sequenceNumber() const
  {return m_sequenceNumber;}
uint8_t MAVLinkMessage::get_systemID() const
  {return m_systemID;}
uint8_t MAVLinkMessage::get_componentID() const
  {return m_componentID;}
uint8_t MAVLinkMessage::get_messageID() const
  {return m_messageID;}
ByteBuffer MAVLinkMessage::get_payload() const
  {return ByteBuffer(m_payload);}

bool MAVLinkMessage::isValid() const
{
  if(m_checksum.size() == 0)
    return true;
  else
  {
    ByteBuffer buffer;

    buffer << m_header;
    buffer << m_length;
    buffer << m_sequenceNumber;
    buffer << m_systemID;
    buffer << m_componentID;
    buffer << m_messageID;
    buffer << m_payload;
    return m_checksum == _calculateChecksum(buffer);
  }
}

ByteBuffer MAVLinkMessage::toByteBuffer() const
{
  ByteBuffer buffer;

  buffer << m_header;
  buffer << m_length;
  buffer << m_sequenceNumber;
  buffer << m_systemID;
  buffer << m_componentID;
  buffer << m_messageID;
  buffer << m_payload;
  buffer << _calculateChecksum(buffer);

  return buffer;
}

ByteBuffer MAVLinkMessage::_calculateChecksum(ByteBuffer const& buffer) const
{
  Checksum cs/*(buffer)*/;
  ByteBuffer retBuffer;

  for(int i = 1; i < 6; ++i)
    cs.accumulate(buffer[i]);

  cs.accumulate(m_payload);

  if(m_MAVLINK_CRC_EXTRA)
    cs.accumulate(m_CRC_EXTRA);

  uint16_t checksum = (uint16_t)cs;

  retBuffer << (uint8_t)(checksum & 0xFF);
  retBuffer << (uint8_t)(checksum >> 8);

  return retBuffer;
}

MAVLinkMessage::Checksum::Checksum():
  m_X25_INIT_CRC(0xffff),
  m_X25_VALIDATE_CRC(0xf0b8)
{
  m_crc = m_X25_INIT_CRC;
}

void MAVLinkMessage::Checksum::accumulate(uint8_t data)
{
  uint8_t tmp;
  uint8_t tmp2 = (uint8_t)(m_crc &0xff);
  tmp = data ^ tmp2;
  tmp ^= (tmp<<4);
  m_crc = (m_crc >>8) ^ (tmp<<8) ^ (tmp <<3) ^ (tmp>>4);
}

void MAVLinkMessage::Checksum::accumulate(ByteBuffer data)
{
  for(auto it = data.cbegin(); it != data.cend(); ++it)
    accumulate((uint8_t)*it);
}

MAVLinkMessage::Checksum::operator uint16_t() const
{
  return m_crc;
}
