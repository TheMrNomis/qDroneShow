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

using namespace mavlink;

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
    QObject::connect(*it, SIGNAL(badMessageReceived()), this, SIGNAL(badMessageReceived()));
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
  sendMessage(mavlink::msg::request_data_stream(m_GCS_systemID,0,
                                                m_UAV_systemID,1,
                                                MAV_DATA_STREAM_EXTENDED_STATUS,
                                                2,1),
              2);
  sendMessage(mavlink::msg::request_data_stream(m_GCS_systemID,0,
                                                m_UAV_systemID,1,
                                                MAV_DATA_STREAM_POSITION,
                                                3,1),
              2);
  sendMessage(mavlink::msg::request_data_stream(m_GCS_systemID,0,
                                                m_UAV_systemID,1,
                                                MAV_DATA_STREAM_EXTRA1,
                                                10,1),
              2);
  sendMessage(mavlink::msg::request_data_stream(m_GCS_systemID,0,
                                                m_UAV_systemID,1,
                                                MAV_DATA_STREAM_EXTRA2,
                                                10,1),
              2);
  sendMessage(mavlink::msg::request_data_stream(m_GCS_systemID,0,
                                                m_UAV_systemID,1,
                                                MAV_DATA_STREAM_EXTRA3,
                                                2,1),
              2);
  sendMessage(mavlink::msg::request_data_stream(m_GCS_systemID,0,
                                                m_UAV_systemID,1,
                                                MAV_DATA_STREAM_RAW_SENSORS,
                                                2,1),
              2);
  sendMessage(mavlink::msg::request_data_stream(m_GCS_systemID,0,
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
//  float x_pos = 0;  ///X-axis position (m)
//  float y_pos = 0;  ///X-axis position (m)
//  float z_pos = 1;  ///X-axis position (m)

  float pitch = 0;  ///pitch (rad)
//  float yaw = 0;    ///yaw angle (rad)
//  float takeoff_ascent_rate = 5; ///ascent rate (m/s)

  std::cout << "taking off" << std::endl;
  if(m_fix > 1)
    std::cout << "takeoff" << std::endl;
    //executeCommand(MAV_CMD_NAV_TAKEOFF, 0,pitch,0/*(empty param)*/,0,yaw,m_latitude,m_longitude,m_altitude+1);

  executeCommand(MAV_CMD_NAV_TAKEOFF,1,0,0,0,0,0,0,0);
}

void UAV::land()
{
  //TODO
//  float target_number = 0;  ///landing target number (if available)
//  float offset = 1;         ///maximum offset from desired landing position (m)
//  float descent_rate = 5;   ///descent rate (m/s)
//  float yaw = 0;            ///yaw angle

//  float x_pos = 0;          ///X-axis position (m)
//  float y_pos = 0;          ///Y-axis position (m)
//  float z_pos = 0;          ///Z-axis position (m)

  std::cout << "landing" << std::endl;
//  executeCommand(MAV_CMD_NAV_LAND_LOCAL,0,target_number,offset,descent_rate,yaw,y_pos,x_pos,z_pos);
  executeCommand(MAV_CMD_NAV_LAND,1,0,0,0,0,0,0,0);
}


void UAV::goTo(int32_t lon, int32_t lat, int32_t alt)
{
  float holdTime = 0;             ///s
  float acceptanceRadius = 0.1f;  ///m
  float yaw = 0;
  float longitude = (float)lon;
  float latitude = (float)lat;
  float altitude = (float)alt;

  executeCommand(MAV_CMD_NAV_WAYPOINT, 0, holdTime, acceptanceRadius, 0/*pass through*/, yaw, latitude, longitude, altitude);
}

//messages
void UAV::receiveMessage(mavlink::message const& msg)
{
  if(msg.get_system_id() != m_UAV_systemID)
    return;

  //updating connection data
  _updateConnectionStatus(msg.get_sequence_number());

  switch(msg.get_message_id())
  {
    case mavlink::msg::heartbeat_id:
    {
      const mavlink::msg::heartbeat * message = static_cast<mavlink::msg::heartbeat const*>(&msg);
      //first hearbeat not received, data update
      if(!m_heartbeat_received)
      {
        m_heartbeat_received = true;
        m_UAV_type = static_cast<MAV_TYPE>(message->get_type());
        m_UAV_autopilot = static_cast<MAV_AUTOPILOT>(message->get_autopilot());
        m_UAV_sequence_number_RX = message->get_sequence_number();
      }
      _updateMode(message->get_base_mode(), message->get_custom_mode());
      std::cout << "mode = " << std::bitset<8>(message->get_base_mode()) << std::endl;
      m_last_heartbeat_timestamp = QDateTime::currentDateTime();
      break;
    }
    case mavlink::msg::sys_status_id:
    {
      const mavlink::msg::sys_status * message = static_cast<mavlink::msg::sys_status const*>(&msg);
      emit(batteryPercentChanged(message->get_battery_remaining()));

      emit(txConnectivityUpdate(message->get_drop_rate_comm(), message->get_errors_comm()));
      break;
    }
    case mavlink::msg::system_time_id:
      //TODO
    break;
    case mavlink::msg::attitude_id:
      //TODO
      //std::cout << "MAV_MSG_ATTITUDE received" << std::endl;
    break;
    case mavlink::msg::global_position_int_id:
    {
      //TODO
      //std::cout << "MAV_MSG_GLOBAL_POSITION_INT received" << std::endl;
      const mavlink::msg::global_position_int * message = static_cast<mavlink::msg::global_position_int const*>(&msg);
      std::cout << "GPS : lon=" << message->get_lon() << " lat=" << message->get_lat() << " alt=" << message->get_alt() << std::endl;
      emit(locationUpdate(message->get_lon(), message->get_lat(), message->get_alt()));
      _updateLocation(message->get_lon(), message->get_lat(), message->get_alt());
      break;
    }
    case mavlink::msg::vfr_hud_id:
    {
      //TODO
      std::cout << "vfr hud" << std::endl;
      const mavlink::msg::vfr_hud * message = static_cast<mavlink::msg::vfr_hud const*>(&msg);
      std::cout << "alt : " << message->get_alt() << std::endl;
      break;
    }
    case mavlink::msg::command_ack_id:
    {
      std::cout << "command ack" << std::endl;
      const mavlink::msg::command_ack * message = static_cast<mavlink::msg::command_ack const*>(&msg);
      std::cout << "command ack : cmd=" << (int)message->get_command() << ", result = " << (int)message->get_result() << std::endl;
      break;
    }
    case mavlink::msg::gps_raw_int_id:
    {
      //TODO
      const mavlink::msg::gps_raw_int * message = static_cast<mavlink::msg::gps_raw_int const*>(&msg);
      emit(GPSChanged(message->get_satellites_visible(),message->get_fix_type()));
      _updateGPS(message->get_satellites_visible(),message->get_fix_type());
      break;
    }
    case mavlink::msg::statustext_id:
    {
      //TODO
      const mavlink::msg::statustext * message = static_cast<mavlink::msg::statustext const*>(&msg);
      emit(statusText(message->get_severity(), message->get_text()));
      break;
    }
      //deliberately ignored messages
    case mavlink::msg::rc_channels_raw_id:
      std::cout << "rc_channels_raw" << std::endl;
    break;
    case mavlink::msg::raw_imu_id:
      std::cout << "raw imu" << std::endl;
    break;
    case mavlink::msg::scaled_pressure_id:
      std::cout << "scaled pressure" << std::endl;
    break;
    case mavlink::msg::servo_output_raw_id:
      std::cout << "servo output raw" << std::endl;
    break;
    case mavlink::msg::mission_current_id:
      std::cout << "mission current" << std::endl;
    break;
    case mavlink::msg::nav_controller_output_id:
      std::cout << "controller output" << std::endl;
    break;
    default:
      //unrecognized messages
      std::cout << "unrecognized message : " << (int) msg.get_message_id() << std::endl;
    break;
  }
}

void UAV::sendMessage(mavlink::message const& msg, unsigned int nb)
{
  for(auto i = m_links.cbegin(); i != m_links.cend(); i++)
    for(unsigned int n = 0; n < nb; ++n)
      (*i)->sendMessage(msg);
}

void UAV::executeCommand(MAV_CMD command, int confirmation, float param1, float param2, float param3, float param4, float param5, float param6, float param7)
{
  sendMessage(mavlink::msg::command_long(m_GCS_systemID,MAV_COMP_ID_ALL,m_UAV_systemID,MAV_COMP_ID_ALL,command,confirmation,param1,param2,param3,param4,param5,param6,param7));
}

void UAV::sendHeartbeat()
{
  sendMessage(mavlink::msg::heartbeat(m_GCS_systemID, 1,MAV_TYPE_GCS, MAV_AUTOPILOT_INVALID, MAV_MODE_PREFLIGHT, 0, MAV_STATE_ACTIVE));
}

void UAV::setMode(uint8_t baseMode, uint32_t customMode)
{
  sendMessage(mavlink::msg::set_mode(m_GCS_systemID,MAV_COMP_ID_MISSIONPLANNER,m_UAV_systemID,baseMode,customMode));
}

void UAV::_updateConnectionStatus(uint8_t newSequenceNumberRX)
{
  //TODO
  m_UAV_number_packet_lost = (uint8_t) newSequenceNumberRX - m_UAV_sequence_number_RX - 1;
  m_UAV_sequence_number_RX = newSequenceNumberRX;
  emit messageReceived(m_UAV_number_packet_lost);
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

void UAV::_updateLocation(int32_t lon, int32_t lat, int32_t alt)
{
  m_longitude = lon;
  m_latitude = lat;
  m_altitude = alt;
}


void UAV::_updateGPS(uint8_t satellites, uint8_t fix)
{
  m_satellites = satellites;
  m_fix = fix;
}
