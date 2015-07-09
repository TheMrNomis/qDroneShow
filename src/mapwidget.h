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
#include <QHBoxLayout>
#include <cstdint>
#include <iostream>

class MapWidget : public QWidget
{
  Q_OBJECT
public:
  explicit MapWidget(QWidget *parent = 0);

public slots:
  void updateLocation(unsigned int uavNumber, int32_t lon, int32_t lat, int32_t alt);

private:
  QLayout * m_layout;

  int32_t m_lon;
  int32_t m_lat;
  int32_t m_alt;
};

#endif // MAPWIDGET_H
