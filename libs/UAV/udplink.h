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

#ifndef UDPLINK_H
#define UDPLINK_H

#include <QString>
#include <QUdpSocket>
#include <QNetworkProxy>
#include "link.h"

#if defined(ZEROCONF_ENABLED)
  #include <dns_sd.h>
#endif
//TODO : ZeroConf !

class UDPLink : public Link
{
public:
  UDPLink(QString ip, unsigned int port);
  ~UDPLink();

  virtual void requestReset();

  virtual bool connect();
  virtual bool disconnect();

public slots:
  virtual void readBytes();

private:
  virtual void _writeBytes(ByteBuffer bytes);
  virtual bool _connect();
  virtual bool _disconnect();

  bool _hardwareConnect();
  void _restartConnection();

  void _registerZeroconf(uint16_t port, std::string const& regType);
  void _deregisterZeroconf();

#if defined(ZEROCONF_ENABLED)
  DNSServiceRef m_dnssServiceRed;
#endif

  QUdpSocket* m_socket;
  QHostAddress m_ip;
  unsigned int m_port;
};

#endif // UDPLINK_H
