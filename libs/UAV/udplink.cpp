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

#include "udplink.h"

UDPLink::UDPLink(QString ip, unsigned int port):
  Link(),
  m_socket(),
  m_ip(ip),
  m_port(port)
{
  //TODO
}

UDPLink::~UDPLink()
{
  _disconnect();
}

void UDPLink::requestReset()
{
  //TODO
}

bool UDPLink::connect()
{
  //TODO
  _hardwareConnect();
  return false;
}

bool UDPLink::disconnect()
{
  //TODO
  return false;
}


void UDPLink::readBytes()
{
  //TODO : check if working
  while (m_socket->hasPendingDatagrams())
  {
      QByteArray datagram;
      datagram.resize(m_socket->pendingDatagramSize());

      QHostAddress sender;
      quint16 senderPort;
      m_socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

      ByteBuffer buffer(datagram.data(), datagram.size());
      emit bytesReceived(buffer);
  }
}

void UDPLink::_writeBytes(ByteBuffer bytes)
{
  //TODO : check if it's working ^_^ (should be)
  char* data = (char *)bytes;
  size_t length = bytes.size();
  m_socket->writeDatagram(data, length, m_ip, (quint16)m_port);
}

bool UDPLink::_hardwareConnect()
{
  //TODO
  if(m_socket != nullptr)
  {
    delete m_socket;
    m_socket = nullptr;
  }

  m_socket = new QUdpSocket();
  m_socket->setProxy(QNetworkProxy::NoProxy);
  m_isConnected = m_socket->bind(QHostAddress::Any, m_port, QAbstractSocket::ReuseAddressHint);
  if (m_isConnected) {
      QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(readBytes()));
      emit connected();
  } else {
      emit communicationError("UDP Link Error", "Error binding UDP port");
  }
  return m_isConnected;
}

void UDPLink::_restartConnection()
{
  if(isConnected())
  {
    _disconnect();
    _connect();
  }
}

bool UDPLink::_connect()
{
  _hardwareConnect();
  return true;
}

bool UDPLink::_disconnect()
{
  if(m_socket != nullptr)
  {
    m_socket->deleteLater();
    m_socket = nullptr;
    emit disconnected();
  }
  return true;
}

void _registerZeroconf(uint16_t port, std::string const& regType)
{
#if defined(ZEROCONF_ENABLED)
  DNSServiceErrorType result = DNSServiceRegister(&m_dnssServiceRef,0,0,0,
          regType.c_str(),
          NULL,
          NULL,
          htons(port),
          0,
          NULL,
          NULL,
          NULL);
  if(result != kDNSServiceErr_NoError)
  {
    emit communicationError("UDP Link Error", "Error registering Zeroconf");
    m_dnssServiceRef = NULL;
  }
#else
  Q_UNUSED(port);
  Q_UNUSED(regType);
#endif
}

void _deregisterZeroconf()
{
#if defined(ZEROCONF_ENABLED)
  if (_dnssServiceRef)
  {
    DNSServiceRefDeallocate(_dnssServiceRef);
    m_dnssServiceRef = NULL;
  }
  #endif
}
