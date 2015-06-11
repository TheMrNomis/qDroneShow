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

#ifndef LINK_H
#define LINK_H

#include <QObject>

#include "mavlinkmessage.h"

/**
 * @brief The Link class is an abstract class used as an interface for the
 *        differents links that can be used for MAVLink (UDP, serial...)
 */
class Link : public QObject
{
  Q_OBJECT
public:
  explicit Link(QObject *parent = 0);

  /**
   * @brief Determine the connection status
   *
   * @return True if the connection is established, false otherwise
   **/
  virtual bool isConnected() const = 0;

  /**
   * @brief connect this link
   * @return true if successfully connected, false otherwise
   */
  virtual bool connect() = 0;

  /**
   * @brief disconnects this link
   * @return true if sucessfully disconnected, false otherwise
   */
  virtual bool disconnect() = 0;

  /**
   * @brief write a MAVLinkMessage to this link
   * @param msg the message to transmit
   */
  void operator<<(MAVLinkMessage const& msg);

signals:
  /**
   * @brief New data arrived
   *
   * The new data is contained in the QByteArray data. The data is copied for each
   * receiving protocol. For high-speed links like image transmission this might
   * affect performance, for control links it is however desirable to directly
   * forward the link data.
   *
   * @param data the new bytes
   */
  //void bytesReceived(LinkInterface* link, QByteArray data);

  /**
   * @brief This signal is emitted instantly when the link is connected
   **/
  void connected();

  /**
   * @brief This signal is emitted instantly when the link is disconnected
   **/
  void disconnected();

  /**
   * @brief Communication error occured
   **/
  void communicationError(const QString& title, const QString& error);

public slots:
  /**
   * @brief Sends a MAVLinkMessage through this link
   * @param message the message to transmit
   */
  virtual void sendMessage(MAVLinkMessage const& message);

protected:
  /**
   * @brief This method allows to write bytes to the interface.
   *
   * @param bytes The buffer of bytes to be written on the interface
   **/
  virtual void _writeBytes(ByteBuffer bytes) = 0;

  bool m_isConnected;


};

#endif // LINK_H
