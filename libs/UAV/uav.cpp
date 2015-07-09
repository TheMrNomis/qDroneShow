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
  HEARTBEAT_TIMEOUT(5*1000), //5 seconds
  m_links(),
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
  emit armingStateChanged(false);
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

bool UAV::isArmed() const
{
  return m_UAV_base_mode & MAV_MODE_FLAG_SAFETY_ARMED;
}

void UAV::initialize()
{
  sendMessage(MAVLink_msg_request_rata_stream(m_GCS_systemID,0,_sequenceNumber(),
                                              m_UAV_systemID,1,
                                              MAV_DATA_STREAM_EXTENDED_STATUS,
                                              2,1),
              2);
  sendMessage(MAVLink_msg_request_rata_stream(m_GCS_systemID,0,_sequenceNumber(),
                                              m_UAV_systemID,1,
                                              MAV_DATA_STREAM_POSITION,
                                              3,1),
              2);
  sendMessage(MAVLink_msg_request_rata_stream(m_GCS_systemID,0,_sequenceNumber(),
                                              m_UAV_systemID,1,
                                              MAV_DATA_STREAM_EXTRA1,
                                              10,1),
              2);
  sendMessage(MAVLink_msg_request_rata_stream(m_GCS_systemID,0,_sequenceNumber(),
                                              m_UAV_systemID,1,
                                              MAV_DATA_STREAM_EXTRA2,
                                              10,1),
              2);
  sendMessage(MAVLink_msg_request_rata_stream(m_GCS_systemID,0,_sequenceNumber(),
                                              m_UAV_systemID,1,
                                              MAV_DATA_STREAM_EXTRA3,
                                              2,1),
              2);
  sendMessage(MAVLink_msg_request_rata_stream(m_GCS_systemID,0,_sequenceNumber(),
                                              m_UAV_systemID,1,
                                              MAV_DATA_STREAM_RAW_SENSORS,
                                              2,1),
              2);
  sendMessage(MAVLink_msg_request_rata_stream(m_GCS_systemID,0,_sequenceNumber(),
                                              m_UAV_systemID,1,
                                              MAV_DATA_STREAM_RC_CHANNELS,
                                              2,1),
              2);
}

void UAV::stop()
{
  std::cout << "stopping" << std::endl;
}

//arming
void UAV::armSystem()
{
  executeCommand(MAV_CMD_COMPONENT_ARM_DISARM,0,1);
}

void UAV::disarmSystem()
{
  executeCommand(MAV_CMD_COMPONENT_ARM_DISARM,0,0);
}

void UAV::toggleArmingState()
{
  if(this->isArmed())
    disarmSystem();
  else
    armSystem();
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

void UAV::goHome()
{
  //TODO
  std::cout << "going home" << std::endl;
}

void UAV::takeoff()
{
  //TODO
  float x_pos = 0;  ///X-axis position (m)
  float y_pos = 0;  ///X-axis position (m)
  float z_pos = 1;  ///X-axis position (m)

  float pitch = 0;  ///pitch (rad)
  float yaw = 0;    ///yaw angle (rad)
  float takeoff_ascent_rate = 5; ///ascent rate (m/s)

  std::cout << "taking off" << std::endl;
  executeCommand(MAV_CMD_NAV_TAKEOFF_LOCAL, 0,pitch,0/*(empty param)*/,takeoff_ascent_rate,yaw,y_pos,x_pos,z_pos);
}

void UAV::land()
{
  //TODO
  float target_number = 0;  ///landing target number (if available)
  float offset = 1;         ///maximum offset from desired landing position (m)
  float descent_rate = 5;   ///descent rate (m/s)
  float yaw = 0;            ///yaw angle

  float x_pos = 0;          ///X-axis position (m)
  float y_pos = 0;          ///Y-axis position (m)
  float z_pos = 0;          ///Z-axis position (m)

  std::cout << "landing" << std::endl;
  executeCommand(MAV_CMD_NAV_LAND_LOCAL,0,target_number,offset,descent_rate,yaw,y_pos,x_pos,z_pos);
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
    case mavlink_message::heartbeat:
    {
      const MAVLink_msg_heartbeat * message = static_cast<MAVLink_msg_heartbeat const*>(&msg);
      //first hearbeat not received, data update
      if(!m_heartbeat_received)
      {
        m_heartbeat_received = true;
        m_UAV_type = static_cast<MAV_TYPE>(message->get_type());
        m_UAV_autopilot = static_cast<MAV_AUTOPILOT>(message->get_autopilot());
        m_UAV_sequence_number_RX = message->get_sequenceNumber();
      }
      _updateMode(message->get_baseMode(), message->get_customMode());
      m_last_heartbeat_timestamp = QDateTime::currentDateTime();
      break;
    }
    case mavlink_message::sys_status:
    {
      const MAVLink_msg_sys_status * message = static_cast<MAVLink_msg_sys_status const*>(&msg);
      emit(batteryPercentChanged(message->get_battery_remaining()));
      break;
    }
    case mavlink_message::system_time:
      //TODO
    break;
    case mavlink_message::attitude:
      //TODO
      //std::cout << "MAV_MSG_ATTITUDE received" << std::endl;
    break;
    case mavlink_message::global_position_int:
      //TODO
      //std::cout << "MAV_MSG_GLOBAL_POSITION_INT received" << std::endl;
    break;
    case mavlink_message::vfr_hud:
      //TODO
      //std::cout << "MAV_MSG_VFR_HUD received" << std::endl;
    break;
    case mavlink_message::gps_raw_int:
    {
      //TODO
      const MAVLink_msg_gps_raw_int * message = static_cast<MAVLink_msg_gps_raw_int const*>(&msg);
      emit(GPSChanged(message->get_satellites_visible(),message->get_fix_type()));
      if(message->get_fix_type() > 1)
      {
        std::cout << "GPS : lon=" << message->get_lon() << " lat=" << message->get_lat() << " alt=" << message->get_alt() << std::endl;
        emit(locationUpdate(message->get_lon(),message->get_lat(),message->get_alt()));
      }
      break;
    }
    case mavlink_message::statustext:
    {
      //TODO
      const MAVLink_msg_statustext * message = static_cast<MAVLink_msg_statustext const*>(&msg);
      emit(statusText(message->get_severity(), message->get_text()));
      break;
    }
      //deliberately ignored messages
    case mavlink_message::rc_channels_raw:
    case mavlink_message::raw_imu:
    case mavlink_message::scaled_pressure:
    case mavlink_message::servo_output_raw:
    case mavlink_message::mission_current:
    case mavlink_message::nav_controller_output:
    break;
    default:
      //unrecognized messages
    break;
  }
}

void UAV::sendMessage(MAVLinkMessage const& msg, unsigned int nb)
{
  for(auto i = m_links.cbegin(); i != m_links.cend(); i++)
    for(unsigned int n = 0; n < nb; ++n)
      (*i)->sendMessage(msg);
}

void UAV::executeCommand(MAV_CMD command, int confirmation, float param1, float param2, float param3, float param4, float param5, float param6, float param7)
{
  sendMessage(MAVLink_msg_cmd(m_GCS_systemID,MAV_COMP_ID_ALL,_sequenceNumber(),m_UAV_systemID,MAV_COMP_ID_ALL,command,confirmation,param1,param2,param3,param4,param5,param6,param7));
}

void UAV::sendHeartbeat()
{
  sendMessage(MAVLink_msg_heartbeat(m_GCS_systemID, 1, _sequenceNumber(), MAV_TYPE_GCS, MAV_AUTOPILOT_INVALID, MAV_MODE_PREFLIGHT, 0, MAV_STATE_ACTIVE));
}

void UAV::setMode(uint8_t baseMode, uint32_t customMode)
{
  sendMessage(MAVLink_msg_set_mode(m_GCS_systemID,MAV_COMP_ID_MISSIONPLANNER,_sequenceNumber(),m_UAV_systemID,baseMode,customMode));
}

void UAV::_updateConnectionStatus(uint8_t newSequenceNumberRX)
{
  //TODO
  m_UAV_number_packet_lost = (uint8_t) newSequenceNumberRX - m_UAV_sequence_number_RX - 1;
  m_UAV_sequence_number_RX = newSequenceNumberRX;
  emit connectivityChanged((int8_t)((255 - m_UAV_number_packet_lost)*100.0/0xff));
}

void UAV::_updateMode(uint8_t baseMode, uint32_t customMode)
{
  bool safety_armed_new = MAV_MODE_FLAG_SAFETY_ARMED & baseMode;
  bool safety_armed_old = MAV_MODE_FLAG_SAFETY_ARMED & m_UAV_base_mode;

  if(safety_armed_new && !safety_armed_old)
    emit(armingStateChanged(true));
  else if(!safety_armed_new && safety_armed_old)
    emit(armingStateChanged(false));

  m_UAV_base_mode = baseMode;
  m_UAV_custom_mode = customMode;
}
