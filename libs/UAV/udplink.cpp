#include "udplink.h"

UDPLink::UDPLink(QString ip, unsigned int port):
  Link(),
  m_socket(),
  m_connectState(false),
  m_ip(ip),
  m_port(port)
{

}

bool UDPLink::connect()
{
  _hardwareConnect();
  return false;
}

bool UDPLink::disconnect()
{
  return false;
}

void UDPLink::_writeBytes(ByteBuffer bytes)
{
  char* data = (char *)bytes;
  size_t length = bytes.size();
  m_socket->writeDatagram(data, length, m_ip, (quint16)m_port);
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
  return m_connectState;
}

void UDPLink::_restartConnection()
{

}

void UDPLink::readBytes()
{
  //TODO
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
