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

#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>

#include <cstdint>
#include <iostream>
#include <limits>

class MapWidget : public QWidget
{
  Q_OBJECT
public:
  explicit MapWidget(QWidget *parent = 0);

signals:
  void goTo(unsigned int uavNumBer, int32_t lon, int32_t lat, int32_t alt);

public slots:
  void updateLocation(unsigned int uavNumber, int32_t lon, int32_t lat, int32_t alt);

private slots:
  void _putCurrentLocationInForm();
  void _go();
  void _updateLon(int);
  void _updateLat(int);
  void _updateAlt(int);

private:
  QVBoxLayout * m_layout;

  QLabel * m_labelLon;
  QLabel * m_labelLat;
  QLabel * m_labelAlt;

  QSpinBox * m_spinBoxLon;
  QSpinBox * m_spinBoxLat;
  QSpinBox * m_spinBoxAlt;

  QPushButton * m_buttonGo;
  QPushButton * m_buttonSetCurrent;

  int32_t m_current_lon;
  int32_t m_current_lat;
  int32_t m_current_alt;

  int32_t m_goto_lon;
  int32_t m_goto_lat;
  int32_t m_goto_alt;
};

#endif // MAPWIDGET_H
