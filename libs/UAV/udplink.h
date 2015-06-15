#ifndef UDPLINK_H
#define UDPLINK_H

#include <QString>
#include <QUdpSocket>

class UDPLink : public Link
{
public:
  UDPLink(QString ip, unsigned int port);

  virtual bool isConnected() const;
  virtual bool connect();
  virtual bool disconnect();

signals:
  //void bytesReceived(LinkInterface* link, QByteArray data);
  void connected();
  void disconnected();
  void communicationError(const QString& title, const QString& error);

private:
  virtual void _writeBytes(ByteBuffer bytes);
  bool _hardwareConnect();
  void _restartConnection();

  QUdpSocket* m_socket;
  bool m_connectState;
  QHostAddress m_ip;
  unsigned int m_port;
};

#endif // UDPLINK_H
