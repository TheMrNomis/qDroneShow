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

SerialLink::SerialLink(QString serialPort):
  Link(),
  m_serialPort(new QSerialPort)//,
//  m_port(new QSerialPort(this)),
//  m_bytesRead(0),
//  m_timeout(0),
//  m_type(""),

//  m_stopp(false),
//  m_reqReset(false)
{
  //TODO
  std::cout << "new serialLink" << std::endl;

  m_serialPort->setPortName(serialPort);
  m_serialPort->setBaudRate(QSerialPort::Baud115200);

  QObject::connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(readBytes()));
}

SerialLink::~SerialLink()
{
  _disconnect();
  delete m_serialPort;
  std::cout << "deleting serialLink" << std::endl;
}

void SerialLink::requestReset()
{
//  m_reqReset = true;
}

//bool SerialLink::connect()
//{
//  return _connect();
//}

//bool SerialLink::disconnect()
//{
//  return _disconnect();
//}

bool SerialLink::connect()
{
  bool b = m_serialPort->open(QIODevice::ReadWrite);
  if(b)
    std::cout << "successfully connected" << std::endl;
  else
    std::cout << "error in connection" << std::endl;

  //initialization of MAVLink (for pixhawk compatibility)
  const char init[] = {0x0D, 0x0D, 0x0D, 0};
  m_serialPort->write(init, sizeof(init) - 1);
  const char* cmd = "sh /etc/init.d/rc.usb\n";
  m_serialPort->write(cmd, strlen(cmd));
  m_serialPort->write(init, sizeof(init));

  return b;
}

bool SerialLink::disconnect()
{
  m_serialPort->close();
  return true;
}

void SerialLink::readBytes()
{
  //std::cout << "Data on interface !" << std::endl;
  QByteArray data = m_serialPort->readAll();
  ByteBuffer dataBuf(data.data(), data.size());
  //std::cout << dataBuf << std::endl;
  //emit(bytesReceived(dataBuf));
}

void SerialLink::_writeBytes(ByteBuffer bytes)
{
  std::cout << "sending : " << bytes << std::endl;
  m_serialPort->write((const char *)bytes, bytes.size());
}

bool SerialLink::_connect()
{
//  std::cout << "opening port :";
//  m_port->setPortName(m_serialPort);
//  m_port->setBaudRate(QSerialPort::Baud115200);
//  bool ret = m_port->open(QIODevice::ReadWrite);
//  if(ret)
//    std::cout << "[OK]" << std::endl;
//  else
//    std::cout << "[NOK]" << std::endl;
//  return ret;
  return false;
}

bool SerialLink::_disconnect()
{
//  if(m_port->isOpen())
//    m_port->close();
//  return true;
  return false;
}
