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
  SerialLink(QString serialPort);
  ~SerialLink();


  virtual void requestReset();

  virtual bool connect();
  virtual bool disconnect();

//signals:
//  void updateLink();

public slots:
  virtual void readBytes();

private:
  virtual void _writeBytes(ByteBuffer bytes);
  virtual bool _connect();
  virtual bool _disconnect();

//  void _emitLinkError(const QString& errorMsg);
//  bool _hardwareConnect(QString &_type);
//  bool _isBootloader();
//  void _resetConfiguration();

  QSerialPort* m_serialPort;

//  QString m_serialPort;
//  QSerialPort* m_port;
//  quint64 m_bytesRead;
//  int m_timeout;
//  QString m_type;

//  bool m_stopp;
//  bool m_reqReset;

//  ByteBuffer m_transmitBuffer;

//private slots:
//  void _rerouteDisconnected();
};

#endif // SERIALLINK_H
