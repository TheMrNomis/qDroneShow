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

#ifndef UAV_H
#define UAV_H

#include <iostream>
#include <QObject>
#include <QDateTime>

#include "MAVLink/common/mavlink.h"

#include "link.h"

/**
 * @brief This class represents one vehicle (Unmanned Aerial Vehicle)
 * @author Amaury Louarn <amaury.louarn@homnomnom.fr>
 */
class UAV : public QObject
{
    Q_OBJECT
public:
  explicit UAV(uint8_t UAVsystemId, uint8_t GCSsystemId = 255, QObject *parent = 0);
  ~UAV();

  virtual void addLink(Link* link);

public slots:
  void connectLinks();
  void disconnectLinks();

  void initialize();

  //arming
  void armSystem();
  void disarmSystem();

  //autonomy
  void goAutonomous();
  void goManual();

  //messages
  void receiveMessage(MAVLinkMessage const& msg);
  /**
   * @brief sends a message to this UAV
   * @param msg the message to send
   * @param nb the number of time this message must be sent (1 = once, 2 = twice, etc.)
   */
  void sendMessage(MAVLinkMessage const& msg, unsigned int nb = 1);

  /**
   * @brief Sends a command to be executed on the UAV
   * @param command the commandID, as defined bu MAV_CMD enum
   * @param confirmation 0: first transmission of the command, 1->255: confirmating the transmission (for ex: the kill command)
   * @param param1-7 the params, as defined by MAV_CMD enum
   */
  void executeCommand(MAV_CMD command, int confirmation = 0, float param1 = 0.0f, float param2 = 0.0f, float param3 = 0.0f, float param4 = 0.0f, float param5 = 0.0f, float param6 = 0.0f, float param7 = 0.0f);

  /**
   * @brief sends a heartbeat to the UAV
   */
  void sendHeartbeat();

signals:
  /**
   * @brief emitted when too many packets are lost
   * @param the number of packets lost
   */
  void tooManyPacketsLost(int);

  void armingStateChanged(bool);
  void GPSChanged(uint8_t satellites, uint8_t fix);
  void connectivityChanged(int8_t);
  void batteryPercentChanged(int8_t);

  void statusText(uint8_t severity, std::string const& text);

private:
  void _updateConnectionStatus(uint8_t newSequenceNumberRX);
  uint8_t inline _sequenceNumber() {return m_UAV_sequence_number_TX++;}

private:
  //constants
  const uint64_t HEARTBEAT_TIMEOUT;

  //GCS info, not directly related to the physical UAV
  std::list<Link*> m_links;

  //basic info
  const uint8_t m_UAV_systemID;
  const uint8_t m_GCS_systemID;

  MAV_TYPE m_UAV_type;
  MAV_AUTOPILOT m_UAV_autopilot;
  uint8_t m_UAV_base_mode;
  uint32_t m_UAV_custom_mode;
  MAV_STATE m_UAV_system_status;

  //connection status
  uint8_t m_UAV_sequence_number_TX;///the sequence number to use for transmission
  uint8_t m_UAV_sequence_number_RX;///the last sequence number received
  uint8_t m_UAV_number_packet_lost;///the number of packets lost

  //heartbeat data
  bool m_heartbeat_received;///has the first heartbeat been received ?
  QDateTime m_last_heartbeat_timestamp;
};

#endif // UAV_H
