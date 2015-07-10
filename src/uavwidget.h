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

#ifndef UAVWIDGET_H
#define UAVWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "UAV/uav.h"

/**
 * @brief This class is the vue for the UAV class (MVC architecture).
 * @author Amaury Louarn <amaury.louarn@homnomnom.fr>
 */
class UAVWidget : public QWidget
{
  friend class DroneList; //DroneList use directly m_UAV
  Q_OBJECT
public:
  explicit UAVWidget(unsigned int uavListID, uint8_t uavSystemID, Link * link, QWidget *parent = 0);
  ~UAVWidget();

  uint8_t getUAVSystemID() const;

signals:
  void locationUpdated(unsigned int uavNumber,  int32_t lon, int32_t lat, int32_t alt);

private slots:
  void _setArmedState(bool isArmed);
  void _setGPS(uint8_t satelliteNumber, uint8_t fix);
  void _setConnectivity(int8_t percent);
  void _setBattery(int8_t percent);
  void _updateLocation(int32_t lon, int32_t lat, int32_t alt);

private:
  const unsigned int m_uavListID;
  uint8_t m_uavSystemID;
  UAV * m_uav;

  QVBoxLayout * m_mainLayout;

  QLabel * m_name;

  QLabel * m_armedState;
  QLabel * m_armedStateIcon;

  QLabel * m_GPS_sat;
  QLabel * m_GPS_fix;
  QLabel * m_GPSIcon;

  QLabel * m_connectionRate;
  QLabel * m_connectionRateIcon;

  QLabel * m_batteryState;
  QLabel * m_batteryStateIcon;

  QPushButton * m_buttonArm;
  QPushButton * m_buttonStop;
  QPushButton * m_buttonTakeOff;
  QPushButton * m_buttonLand;
  QPushButton * m_buttonHome;

  const QString m_style_error = "color:#bb0000; font-size:x-large; font-weight:bold;";
  const QString m_style_ok = "color:#000000; font-size:x-large";
};

#endif // UAVWIDGET_H
