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

#include "mapwidget.h"

MapWidget::MapWidget(QWidget *parent) : QWidget(parent),
  m_layout(new QVBoxLayout(this)),

  m_labelLon(new QLabel("0",0)),
  m_labelLat(new QLabel("0",0)),
  m_labelAlt(new QLabel("0",0)),

  m_spinBoxLon(new QSpinBox),
  m_spinBoxLat(new QSpinBox),
  m_spinBoxAlt(new QSpinBox),

  m_buttonGo(new QPushButton("Go",0)),
  m_buttonSetCurrent(new QPushButton("Current Location",0))
{
  m_spinBoxLon->setRange(std::numeric_limits<int32_t>::min(),std::numeric_limits<int32_t>::max());
  m_spinBoxLat->setRange(std::numeric_limits<int32_t>::min(),std::numeric_limits<int32_t>::max());
  m_spinBoxAlt->setRange(std::numeric_limits<int32_t>::min(),std::numeric_limits<int32_t>::max());

  QFormLayout * currentForm = new QFormLayout;

  currentForm->addRow("Latitude",m_labelLat);
  currentForm->addRow("Longitude",m_labelLon);
  currentForm->addRow("Altitude",m_labelAlt);

  m_layout->addLayout(currentForm);

  QFormLayout * newForm = new QFormLayout;

  newForm->addRow("Latitude",m_spinBoxLat);
  newForm->addRow("Longitude",m_spinBoxLon);
  newForm->addRow("Altitude",m_spinBoxAlt);

  m_layout->addLayout(newForm);

  QHBoxLayout * buttonsLayout = new QHBoxLayout;

  buttonsLayout->addWidget(m_buttonSetCurrent);
  buttonsLayout->addWidget(m_buttonGo);


  m_layout->addLayout(buttonsLayout);

  setLayout(m_layout);

  updateLocation(1,0,0,0);
  _updateLon(0);
  _updateLat(0);
  _updateAlt(0);

  QObject::connect(m_buttonSetCurrent, SIGNAL(clicked()), this, SLOT(_putCurrentLocationInForm()));
  QObject::connect(m_buttonGo, SIGNAL(clicked()), this, SLOT(_go()));
  QObject::connect(m_spinBoxLon, SIGNAL(valueChanged(int)), this, SLOT(_updateLon(int)));
  QObject::connect(m_spinBoxLat, SIGNAL(valueChanged(int)), this, SLOT(_updateLat(int)));
  QObject::connect(m_spinBoxAlt, SIGNAL(valueChanged(int)), this, SLOT(_updateAlt(int)));
}

void MapWidget::updateLocation(unsigned int uavNumber, int32_t lon, int32_t lat, int32_t alt)
{
  Q_UNUSED(uavNumber);

  m_current_lon = lon;
  m_current_lat = lat;
  m_current_alt = alt;

  m_labelLon->setText(QString::number(lon));
  m_labelLat->setText(QString::number(lat));
  m_labelAlt->setText(QString::number(alt));
}


void MapWidget::_putCurrentLocationInForm()
{
  m_spinBoxLon->setValue(m_current_lon);
  m_spinBoxLat->setValue(m_current_lat);
  m_spinBoxAlt->setValue(m_current_alt);

  _updateLon(m_current_lon);
  _updateLat(m_current_lat);
  _updateAlt(m_current_alt);
}


void MapWidget::_go()
{
  emit(goTo(0,m_goto_lon,m_goto_lat,m_goto_alt));
}

void MapWidget::_updateLon(int lon)
{
  m_goto_lon = (int32_t) lon;
}

void MapWidget::_updateLat(int lat)
{
  m_goto_lat = (int32_t) lat;
}

void MapWidget::_updateAlt(int alt)
{
  m_goto_alt = (int32_t) alt;
}
