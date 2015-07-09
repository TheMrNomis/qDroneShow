/*======================================================================
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

#ifndef DRONELIST_H
#define DRONELIST_H

#include <QGroupBox>
#include <QMessageBox>
#include <vector>
#include "UAV/link.h"
#include "uavwidget.h"

/**
 * @brief This class is GroupBox containing UAVWidgets. It is used as an interface that creates UAVs as it receive MAVLink messages.
 * @author Amaury Louarn <amaury.louarn@homnomnom.fr>
 */
class DroneList : public QGroupBox
{
  Q_OBJECT

public:
  explicit DroneList(QWidget *parent = 0);
  ~DroneList();

signals:
  /**
   * @brief signal emitted when the connexion has just been connected or disconnected
   * @param isConnected true if the signal is connected, false otherwise
   */
  void connected(bool isConnected);

public slots:
  /**
   * @brief sets the Link used to communicate with UAVs
   * @param connection the new Link to be used
   * @warning if a current connection is set, this function WILL delete() it.
   * @warning this function WILL take ownership of the Link*.
   */
  void setConnection(Link * connection);

  /**
   * @brief removes the Link used to communicate with UAVs
   * @warning this function WILL delete() the current Link
   */
  void deleteConnection();

  /**
   * @brief searches the UAVs connected (and reachable)
   */
  void searchUAVs();

private slots:
  void _receiveMessage(MAVLinkMessage const& msg);

private:
  Link * m_connection;
  std::vector<UAVWidget *> m_uavWidgets;
  QVBoxLayout * m_mainLayout;
};

#endif // DRONELIST_H
