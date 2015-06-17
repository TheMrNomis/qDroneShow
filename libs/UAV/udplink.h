#ifndef UDPLINK_H
#define UDPLINK_H

#include <QString>
#include <QUdpSocket>
#include <QNetworkProxy>
#include "link.h"

class UDPLink : public Link
{
public:
  UDPLink(QString ip, unsigned int port);

  virtual bool connect();
  virtual bool disconnect();

public slots:
  virtual void readBytes();

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
