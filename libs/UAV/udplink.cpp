#include "udplink.h"

UDPLink::UDPLink(QString ip, unsigned int port):
  m_socket(this),
  m_connectState(false),
  m_ip(ip),
  m_port(port)
{

}

virtual void UDPLink::_writeBytes(ByteBuffer bytes)
{

}

bool UDPLink::_hardwareConnect()
{
  //TODO
  m_socket = new QUdpSocket();
  m_socket->setProxy(QNetworkProxy::NoProxy);
  m_connectState = m_socket->bind(m_ip, m_port, QAbstractSocket::ReuseAddressHint);
  if (m_connectState) {
      QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(readBytes()));
      emit connected();
  } else {
      emit communicationError("UDP Link Error", "Error binding UDP port");
  }
  return _connectState;
}

void UDPLink::_restartConnection()
{

}

ByteBuffer UDPLink::readBytes()
{
  //TODO
  while (_socket->hasPendingDatagrams())
  {
      QByteArray datagram;
      datagram.resize(_socket->pendingDatagramSize());

      QHostAddress sender;
      quint16 senderPort;
      _socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

      // FIXME TODO Check if this method is better than retrieving the data by individual processes
      emit bytesReceived(this, datagram);
  }
}
