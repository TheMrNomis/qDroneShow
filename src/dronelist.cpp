#include "dronelist.h"

DroneList::DroneList(Link* connection, QWidget *parent) :
  QGroupBox(parent),
  m_mainLayout(new QVBoxLayout),
  m_connection(connection),
  m_uavWidgets()
{
  QObject::connect(m_connection, SIGNAL(messageReceived(MAVLinkMessage)), this, SLOT(_receiveMessage(MAVLinkMessage)));

  setLayout(m_mainLayout);

  if(!m_connection->isConnected())
    if(!m_connection->connect())
      QMessageBox::critical(this, "Connection error", "Impossible to connect "+m_connection->getName());
}

DroneList::~DroneList()
{
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
  {
    UAVYoureLookingFor = new UAVWidget(static_cast<unsigned int>(m_uavWidgets.size()), systemID, m_connection, this);
    m_uavWidgets.push_back(UAVYoureLookingFor);
    m_mainLayout->addWidget(UAVYoureLookingFor);
  }

  UAVYoureLookingFor->m_uav->receiveMessage(msg);
}
