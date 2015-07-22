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

#ifndef SERIALLINK_H
#define SERIALLINK_H

#include "link.h"
#include <QString>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

class SerialLink : public Link
{
public:
  SerialLink(QString serialPort, QSerialPort::BaudRate baudRate);
  ~SerialLink();

  virtual bool connect();
  virtual bool disconnect();
  virtual void initialize();

  virtual QString getName() const;

private slots:
  virtual void _readBytes();

private:
  virtual void _writeBytes(mavlink::ByteBuffer bytes);
  /**
   * @brief extracts the MAVLink messages from m_dataBuffer
   * @emits messageReceived() when found a valid message
   * @emits badMessageReceived() when found a bad message
   */
  void _extractMAVLinkMessage();

  QString m_name;

  QSerialPort* m_serialPort;
  mavlink::ByteBuffer m_dataBuffer;
};

#endif // SERIALLINK_H
