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

#include "dronelist.h"

DroneList::DroneList(QWidget *parent) :
  QGroupBox(parent),
  m_mainLayout(new QVBoxLayout),
  m_connection(nullptr),
  m_uavWidgets()
{
  m_mainLayout->setAlignment(Qt::AlignTop);
  setLayout(m_mainLayout);

  emit(connected(false));
}

DroneList::~DroneList()
{
  deleteConnection();
}

void DroneList::setConnection(Link * connection)
{
  if(m_connection != nullptr)
    deleteConnection();
  m_connection = connection;
  QObject::connect(m_connection, SIGNAL(messageReceived(MAVLinkMessage)), this, SLOT(_receiveMessage(MAVLinkMessage)));

  if(!m_connection->isConnected())
  {
    if(m_connection->connect())
      emit(connected(true));
    else
    {
      QMessageBox::critical(this, "Connection error", "Impossible to connect "+m_connection->getName());
      deleteConnection();
    }
  }
}

void DroneList::deleteConnection()
{
  if(m_connection != nullptr)
  {
    QObject::disconnect(m_connection, SIGNAL(messageReceived(MAVLinkMessage)), this, SLOT(_receiveMessage(MAVLinkMessage)));
    m_connection = nullptr;
    emit(connected(false));

    //removing all the UAVWidgets from the GUI
    for(auto it = m_uavWidgets.cbegin(); it != m_uavWidgets.cend(); ++it)
      delete *it;
    m_uavWidgets.clear();
  }
}

void DroneList::searchUAVs()
{
  //initializing the connection (useful for setting pixhawk in MAVLink mode)
  m_connection->initialize();
}

void DroneList::moveUAVTo(unsigned int uavNumber, int32_t lon, int32_t lat, int32_t alt)
{
  m_uavWidgets[uavNumber]->m_uav->goTo(lon,lat,alt);
}

void DroneList::_receiveMessage(MAVLinkMessage const& msg)
{
  UAVWidget * UAVYoureLookingFor = nullptr;
  const uint8_t systemID = msg.get_systemID();

  //checking if we have a UAV with this system id
  for(auto it = m_uavWidgets.begin(); UAVYoureLookingFor == nullptr && it != m_uavWidgets.end(); ++it)
    if((*it)->getUAVSystemID() == systemID)
      UAVYoureLookingFor = *it;

  //if we don't, we create a new one
  if(UAVYoureLookingFor == nullptr)
    UAVYoureLookingFor = _createUAV(systemID);

  UAVYoureLookingFor->m_uav->receiveMessage(msg);
}

UAVWidget * DroneList::_createUAV(uint8_t systemID)
{
  UAVWidget * uav = new UAVWidget(static_cast<unsigned int>(m_uavWidgets.size()), systemID, m_connection, this);

  m_uavWidgets.push_back(uav);
  m_mainLayout->addWidget(uav);

  QObject::connect(uav, SIGNAL(locationUpdated(int,int32_t,int32_t,int32_t)), this, SIGNAL(locationUpdated(int,int32_t,int32_t,int32_t)));

  return uav;
}
