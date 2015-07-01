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

#include "uav.h"

UAV::UAV(uint8_t UAVsystemId, uint8_t GCSsystemId, QObject *parent):
  QObject(parent),
  m_links(),
  HEARTBEAT_TIMEOUT(5*1000), //5 seconds
  m_UAV_systemID(UAVsystemId),
  m_GCS_systemID(GCSsystemId),

  m_UAV_type(),
  m_UAV_autopilot(),
  m_UAV_base_mode(),
  m_UAV_custom_mode(),
  m_UAV_system_status(),

  m_UAV_sequence_number_TX(0),
  m_UAV_sequence_number_RX(0),
  m_UAV_number_packet_lost(0),

   m_heartbeat_received(),
  m_last_heartbeat_timestamp()
{

  //emit disarmed();
  //emit armingChanged(false);
}

UAV::~UAV()
{
  for(auto it = m_links.begin(); it != m_links.end(); ++it)
    delete *it;
}

void UAV::connectLinks()
{
  for(auto it = m_links.begin(); it != m_links.end(); ++it)
  {
    (*it)->connect();
    QObject::connect(*it, SIGNAL(messageReceived(MAVLinkMessage)), this, SLOT(receiveMessage(MAVLinkMessage)));
  }
}

void UAV::disconnectLinks()
{
  for(auto it = m_links.begin(); it != m_links.end(); ++it)
    (*it)->disconnect();
}

void UAV::addLink(Link* link)
{
  m_links.push_back(link);
//  connect(link, SIGNAL(bytesReceived(ByteBuffer)), this, SLOT(receiveBytes(ByteBuffer)));
}

//arming
void UAV::armSystem()
{
  std::cout << "arming" << std::endl;
  //setMode(m_baseMode | MAV_MODE_FLAG_SAFETY_ARMED, m_customMode);
}

void UAV::disarmSystem()
{
  std::cout << "disarming" << std::endl;
  //setMode(m_baseMode & ~(MAV_MODE_FLAG_SAFETY_ARMED), m_customMode);
}

//autonomy
void UAV::goAutonomous()
{
  std::cout << "going autonomous" << std::endl;
  //setMode((m_baseMode & ~(MAV_MODE_FLAG_MANUAL_INPUT_ENABLED)) | (MAV_MODE_FLAG_AUTO_ENABLED | MAV_MODE_FLAG_STABILIZE_ENABLED | MAV_MODE_FLAG_GUIDED_ENABLED), 0);
}

void UAV::goManual()
{
  std::cout << "going manual" << std::endl;
  //setMode((m_baseMode & ~(MAV_MODE_FLAG_AUTO_ENABLED | MAV_MODE_FLAG_STABILIZE_ENABLED | MAV_MODE_FLAG_GUIDED_ENABLED))  | MAV_MODE_FLAG_MANUAL_INPUT_ENABLED, 0);
}

//messages
void UAV::receiveMessage(MAVLinkMessage const& msg)
{
  if(msg.get_systemID() != m_UAV_systemID)
    return;

  //updating connection data
  if(m_heartbeat_received)
    _updateConnectionStatus(msg.get_sequenceNumber());

  switch(msg.get_messageID())
    {
    case MAV_MSG_HEARTBEAT:
    {
      const MAVLink_msg_heartbeat * message = static_cast<MAVLink_msg_heartbeat const*>(&msg);
      //first hearbeat not received, data update
      if(!m_heartbeat_received)
      {
        m_heartbeat_received = true;

        m_UAV_type = static_cast<MAV_TYPE>(message->get_type());
        m_UAV_autopilot = static_cast<MAV_AUTOPILOT>(message->get_autopilot());
        m_UAV_base_mode = message->get_baseMode();
        m_UAV_custom_mode = message->get_customMode();
        m_UAV_system_status = static_cast<MAV_STATE>(message->get_systemStatus());
        m_UAV_sequence_number_RX = message->get_sequenceNumber();
      }
      m_last_heartbeat_timestamp = QDateTime::currentDateTime();
      break;
    }
    case MAV_MSG_SYS_STATUS:
    {
      //TODO
      break;
    }
    case MAV_MSG_ATTITUDE:
      //TODO
      //std::cout << "MAV_MSG_ATTITUDE received" << std::endl;
      break;
    case MAV_MSG_GLOBAL_POSITION_INT:
      //TODO
      //std::cout << "MAV_MSG_GLOBAL_POSITION_INT received" << std::endl;
      break;
    case MAV_MSG_VFR_HUD:
      //TODO
      //std::cout << "MAV_MSG_VFR_HUD received" << std::endl;
      break;
    case MAV_MSG_GPS_RAW_INT:
      //TODO
      break;
    //deliberately ignored messages
    case MAV_MSG_RC_CHANNELS_RAW:
    case MAV_MSG_RAW_IMU:
    case MAV_MSG_SCALED_PRESSURE:
    case MAV_MSG_SERVO_OUTPUT_RAW:
    case MAV_MSG_MISSION_CURRENT:
    case MAV_MSG_NAV_CONTROLLER_OUTPUT:
      break;
    default:
      std::cout << "unrecognized message received : " << (int)msg.get_messageID() << std::endl;
      break;
    }
}

void UAV::sendMessage(MAVLinkMessage const& msg)
{
  std::cout << "Sending message " << msg.toByteBuffer() << std::endl;
  for(auto i = m_links.cbegin(); i != m_links.cend(); i++)
    (*i)->sendMessage(msg);
}

void UAV::executeCommand(MAV_CMD command, int confirmation, float param1, float param2, float param3, float param4, float param5, float param6, float param7)
{
  sendMessage(MAVLink_msg_cmd(m_GCS_systemID,MAV_COMP_ID_ALL,_sequenceNumber(),m_UAV_systemID,MAV_COMP_ID_ALL,command,confirmation,param1,param2,param3,param4,param5,param6,param7));
}

void UAV::sendHeartbeat()
{
  sendMessage(MAVLink_msg_heartbeat(m_UAV_systemID, 1, _sequenceNumber(), MAV_TYPE_GCS, MAV_AUTOPILOT_INVALID, MAV_MODE_PREFLIGHT, 0, MAV_STATE_ACTIVE));
}

void UAV::_updateConnectionStatus(uint8_t newSequenceNumberRX)
{
  m_UAV_number_packet_lost = (uint8_t) newSequenceNumberRX - m_UAV_sequence_number_RX - 1;
  m_UAV_sequence_number_RX = newSequenceNumberRX;
  std::cout << "connexion : " << (int)(255 - m_UAV_number_packet_lost)*100.0/0xff << "%" << std::endl;
}
