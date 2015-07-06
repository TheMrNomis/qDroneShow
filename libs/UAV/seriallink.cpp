/*=======================================================================
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
 * This file contains fragments of code from the QGroundControl project,
 * which is released under the terms of the GNU General Public License,
 * version 3.
 *
 * Copyright (C) 2009 - 2015 QGROUNDCONTROL PROJECT
 * <http://www.qgroundcontrol.org>
 * ======================================================================*/

#include "seriallink.h"
#include <limits>

SerialLink::SerialLink(QString serialPort, QSerialPort::BaudRate baudRate):
  Link(),
  m_name("["+serialPort+"]"),
  m_serialPort(new QSerialPort)
{
  m_serialPort->setPortName(serialPort);
  m_serialPort->setBaudRate(baudRate);

  QObject::connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(_readBytes()));
}

SerialLink::~SerialLink()
{
  disconnect();
  delete m_serialPort;
}

bool SerialLink::connect()
{
  if(!m_serialPort->open(QIODevice::ReadWrite))
  {
    emit(connectionError());
    return false;
  }

  initialize();

  emit connected();
  return true;
}

void SerialLink::initialize()
{
  //initialization of MAVLink (for pixhawk compatibility)
  const char init[] = {0x0D, 0x0D, 0x0D, 0};
  m_serialPort->write(init, sizeof(init) - 1);
  const char* cmd = "sh /etc/init.d/rc.usb\n";
  m_serialPort->write(cmd, strlen(cmd));
  m_serialPort->write(init, sizeof(init));
}

bool SerialLink::disconnect()
{
  m_serialPort->close();
  emit(disconnected());
  return true;
}

QString SerialLink::getName() const {return m_name;}

void SerialLink::_readBytes()
{
  //we get the data from the serial port
  QByteArray data = m_serialPort->readAll();
  ByteBuffer dataBuf(data.data(), data.size());
  //put it on the data buffer
  m_dataBuffer << dataBuf;
  //and extract (if any) the messages on the data buffer
  _extractMAVLinkMessage();
}

void SerialLink::_extractMAVLinkMessage()
{
  //MAVLink messages always start by a 0xFE byte
  while(m_dataBuffer.size() > 0 && (uint8_t) m_dataBuffer[0] != (uint8_t) 0xFE)
    m_dataBuffer.pop_front();


  //MAVLink messages are at least 8 bytes long (6 bytes header + 2 bytes CRC)
  if(m_dataBuffer.size() >= 8)
  {
    uint8_t msgLength = m_dataBuffer.get<uint8_t>(1);

    if(msgLength > (0xff - 8)) //messages are at most 0xff in length, therefore the payload is at most (0xff - 8) in length
    {
      m_dataBuffer.pop_front();
      return;
    }

    msgLength += 8; //msg length = (payload += (header + CRC))

    //check if we have the whole message
    if(m_dataBuffer.size() >= msgLength)
    {
      //dump the whole message onto a ByteBuffer
      ByteBuffer messageBuffer;
      for(unsigned int i = 0; i < msgLength; ++i)
        m_dataBuffer >> messageBuffer;

      //cast the Buffer to a MAVLink message
      MAVLinkMessage msg(messageBuffer);
      if(msg.isValid(mavlink_message::crcs[msg.get_messageID()]))
        emit(messageReceived(msg));
      else
        emit(badMessageReceived(msg));

      //then, check again if there is another message
      _extractMAVLinkMessage();

    }
  }
}

void SerialLink::_writeBytes(ByteBuffer bytes)
{
  //std::cout << "sending : " << bytes << std::endl;
  m_serialPort->write((const char *)bytes, bytes.size());
}
