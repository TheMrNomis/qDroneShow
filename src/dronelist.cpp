#include "dronelist.h"

DroneList::DroneList(QWidget *parent) :
  QGroupBox(parent),
  m_mainLayout(new QVBoxLayout),
  m_connection(nullptr),
  m_uavWidgets()
{
  m_mainLayout->setAlignment(Qt::AlignTop);
  setLayout(m_mainLayout);


}

DroneList::~DroneList()
{
  deleteConnection();
}

void DroneList::setConnection(Link * connection)
{
  std::cout << "[DroneList] adding connection" << std::endl;
  if(m_connection != nullptr)
    deleteConnection();
  m_connection = connection;
  QObject::connect(m_connection, SIGNAL(messageReceived(MAVLinkMessage)), this, SLOT(_receiveMessage(MAVLinkMessage)));

  if(!m_connection->isConnected())
    if(!m_connection->connect())
    {
      QMessageBox::critical(this, "Connection error", "Impossible to connect "+m_connection->getName());
      deleteConnection();
    }
}

void DroneList::deleteConnection()
{
  if(m_connection != nullptr)
  {
    std::cout << "[DroneList] deleting connection" << std::endl;
    QObject::disconnect(m_connection, SIGNAL(messageReceived(MAVLinkMessage)), this, SLOT(_receiveMessage(MAVLinkMessage)));
    m_connection = nullptr;
  }
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
