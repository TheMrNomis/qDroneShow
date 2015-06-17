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

UAV::UAV(uint8_t UAVsystemId, uint8_t GCSsystemId, uint8_t UAVcomponentId, uint8_t GCScomponentId, QObject *parent):
  QObject(parent),
  m_links(),

  //basic infos
  m_name(""),
  m_sequenceNumber(1),
  m_type(MAV_TYPE_GENERIC),
  m_airframe(),
  m_autopilot(MAV_AUTOPILOT_GENERIC),
  m_systemIsArmed(false),
  m_baseMode(0),
  m_customMode(0),
  m_status(-1),
  //m_shortModeText(),  //NOT INITIALIZED
  //m_shortStateText(), //NOT INITIALIZED

  m_UAVsystemID(UAVsystemId),
  m_GCSsystemID(GCSsystemId),
  m_UAVcomponentID(UAVcomponentId),
  m_GCScomponentID(GCScomponentId),

  //heartbeats
  m_heartbeatsEnabled(),
  m_lastHeartbeatTimestamp(),

  //battery
  startVoltage(-1.0f),
  tickVoltage(10.5f),
  lastTickVoltageValue(13.0f),
  tickLowpassVoltage(12.0f),
  warnLevelPercent(20),
  currentVoltage(12.6f),
  lpVoltage(12.0f),
  currentCurrent(0.4f),
  //batteryRemainingEstimateEnabled(),
  chargeLevel(-1),
  timeRemaining(0),
  lowBattAlarm(false),

  //time
  m_startTime(),//TODO
  m_onBoardTimeOffset(0),

  //position
  m_positionLock(false),
  m_localPositionKnown(false),
  m_globalPositionKnown(false),
  m_satelliteCount(0),
  m_globalEstimatorActive(false),

  m_localX(0.0),
  m_localY(0.0),
  m_localZ(0.0),

  m_latitude(0.0),
  m_longitude(0.0),
  m_altitudeAMSL(0.0),
  m_altitudeRelative(0.0),

  m_GPSLatitude(0.0),
  m_GPSLongitude(0.0),
  m_GPSAltitude(0.0),

  m_speedX(0.0),
  m_speedY(0.0),
  m_speedZ(0.0),

  //waypoints
  //m_distToWaypoint(),
  m_airspeed(std::numeric_limits<double>::quiet_NaN()),
  m_groundSpeed(std::numeric_limits<double>::quiet_NaN()),
  //m_bearingToWaypoint(),

  //attitude
  m_attitudeKnown(false),
  m_attitudeStamped(false),
  m_lastAttitudeTimestamp(0),

  m_roll(0.0),
  m_pitch(0.0),
  m_yaw(0.0)
{

  emit disarmed();
  emit armingChanged(false);
}

void UAV::addLink(Link* link)
{
  m_links.push_back(link);
  connect(link, SIGNAL(bytesReceived(ByteBuffer)), this, SLOT(receiveBytes(ByteBuffer)));
}

void UAV::launch()
{
  execute(MAVLink_msg_cmd(m_GCSsystemID, m_GCScomponentID, m_sequenceNumber++, m_UAVsystemID, 0, MAV_CMD_NAV_TAKEOFF, 1));
}

void UAV::home()
{
  //TODO
}

/** @brief Order the robot to land **/
void UAV::land()
{
  execute(MAVLink_msg_cmd(m_GCSsystemID, m_GCSsystemID, m_sequenceNumber++, m_UAVsystemID, MAV_COMP_ID_ALL, MAV_CMD_NAV_LAND,1,0,0,0,0,0,0,0));
}

/** @brief Order the robot to pair its receiver **/
void UAV::pairRX(int rxType, int rxSubType)
{
  execute(MAVLink_msg_cmd(m_GCSsystemID, m_GCScomponentID, m_sequenceNumber++, m_UAVsystemID, MAV_COMP_ID_ALL, MAV_CMD_START_RX_PAIR, 0, rxType, rxSubType, 0,0,0,0,0));
}

void UAV::halt()
{
  execute(MAVLink_msg_cmd(m_GCSsystemID, m_GCScomponentID, m_sequenceNumber++, m_UAVsystemID, MAV_COMP_ID_ALL, MAV_CMD_OVERRIDE_GOTO, 1, MAV_GOTO_DO_HOLD, MAV_GOTO_HOLD_AT_CURRENT_POSITION,0,0,0,0,0));
}

void UAV::go()
{
  execute(MAVLink_msg_cmd(m_GCSsystemID, m_GCScomponentID, m_sequenceNumber++, m_UAVsystemID, MAV_COMP_ID_ALL, MAV_CMD_OVERRIDE_GOTO, 1, MAV_GOTO_DO_CONTINUE, MAV_GOTO_HOLD_AT_CURRENT_POSITION,0,0,0,0,0));
}

/** @brief Stops the robot system. If it is an MAV, the robot starts the emergency landing procedure **/
void UAV::emergencySTOP()
{
  //TODO
  halt();
}

/** @brief Kills the robot. All systems are immediately shut down (e.g. the main power line is cut). This might lead to a crash **/
bool UAV::emergencyKILL()
{
  //TODO
  halt();
}

/** @brief Shut the system cleanly down. Will shut down any onboard computers **/
void UAV::shutdown()
{
  execute(MAVLink_msg_cmd(m_GCSsystemID, m_GCScomponentID, m_sequenceNumber++, m_UAVsystemID, MAV_COMP_ID_ALL, MAV_CMD_PREFLIGHT_REBOOT_SHUTDOWN, 1,0,2,0,0,0,0,0));
}

/** @brief Set the target position for the robot to navigate to. */
void UAV::setTargetPosition(float x, float y, float z, float yaw)
{
  execute(MAVLink_msg_cmd(m_GCSsystemID, m_GCScomponentID, m_sequenceNumber++, m_UAVsystemID, MAV_COMP_ID_ALL, MAV_CMD_NAV_PATHPLANNING, 1,1,1,0,yaw,x,y,z));
}

//low battery alarm
void UAV::startLowBattAlarm()
{
  //TODO
}

void UAV::stopLowBattAlarm()
{
  //TODO
}

//arming
void UAV::armSystem()
{
  setMode(m_baseMode | MAV_MODE_FLAG_SAFETY_ARMED, m_customMode);
}

void UAV::disarmSystem()
{
  setMode(m_baseMode & ~(MAV_MODE_FLAG_SAFETY_ARMED), m_customMode);
}

void UAV::toggleArmedState()
{
  setMode(m_baseMode ^ MAV_MODE_FLAG_SAFETY_ARMED, m_customMode);
}

//autonomy
void UAV::goAutonomous()
{
  setMode((m_baseMode & ~(MAV_MODE_FLAG_MANUAL_INPUT_ENABLED)) | (MAV_MODE_FLAG_AUTO_ENABLED | MAV_MODE_FLAG_STABILIZE_ENABLED | MAV_MODE_FLAG_GUIDED_ENABLED), 0);
}

void UAV::goManual()
{setMode((m_baseMode & ~(MAV_MODE_FLAG_AUTO_ENABLED | MAV_MODE_FLAG_STABILIZE_ENABLED | MAV_MODE_FLAG_GUIDED_ENABLED))  | MAV_MODE_FLAG_MANUAL_INPUT_ENABLED, 0);
}

void UAV::toggleAutonomy()
{
  setMode(m_baseMode ^ MAV_MODE_FLAG_AUTO_ENABLED ^ MAV_MODE_FLAG_MANUAL_INPUT_ENABLED ^ MAV_MODE_FLAG_GUIDED_ENABLED ^ MAV_MODE_FLAG_STABILIZE_ENABLED, 0);
}

//messages
void UAV::receiveMessage(MAVLinkMessage const& msg)
{
  //TODO
}

void UAV::receiveMessage(ByteBuffer const& msg)
{
  ByteBuffer buf(msg);
  receiveMessage(MAVLinkMessage(buf));
}

void UAV::sendMessage(MAVLinkMessage const& msg)
{
  execute(msg);
}

//mode & state
void UAV::setMode(MAV_MODE baseMode, uint32_t customMode)
{
  if(receivedMode)
  {
    execute(MAVLink_msg_set_mode(m_GCSsystemID, m_GCScomponentID, m_sequenceNumber++, m_UAVsystemID, baseMode, customMode));
  }
}

void UAV::updateState()
{
  //TODO : emit heartBeatTimeout
  uint64_t heartbeatInterval = QDateTime::toTime_t() - m_lastHeartbeatTimestamp;
  if((heartbeatInterval > HEARTBEAT_TIMEOUT))
    m_connectionLost = true;
  else
    m_connectionLost = false;
}


//positionning
void UAV::setLocalOriginAtCurrentGPSPosition()
{
  executeCommand(MAV_CMD_DO_SET_HOME,1,1,0,0,0,0,0,0);
}

void UAV::setHomePosition(double latitude, double longitude, double altitude)
{
  //TODO
}

void UAV::executeCommand(MAV_CMD command, int confirmation = 0, float param1 = 0.0f, float param2 = 0.0f, float param3 = 0.0f, float param4 = 0.0f, float param5 = 0.0f, float param6 = 0.0f, float param7 = 0.0f)
{
  execute(MAVLink_msg_cmd(m_GCSsystemID,m_GCScomponentID,m_sequenceNumber++,m_UAVsystemID,m_UAVcomponentID,command,confirmation,param1,param2,param3,param4,param5,param6,param7));
}

void UAV::executeCommandAck(int num, bool success)
{
  execute(MAVLink_msg_cmd_ack(m_GCSsystemID,m_GCSsystemID,m_sequenceNumber++,num, success? 0:1));
}

void UAV::execute(MAVLinkMessage what)
{
  for(auto i = m_links.cbegin(); i != m_links.cend(); i++)
    (*i)->sendMessage(what);
}

void UAV::sendHeartbeat()
{
  //TODO : check if params are OK
  execute(MAVLink_msg_heartbeat(m_UAVsystemID, 1, m_sequenceNumber++,m_type,m_autopilot,m_baseMode,m_customMode,m_status));
}

//getters & setters
QString UAV::getName() const{return m_name;}
uint8_t UAV::getSystemID() const{return m_systemID;}
uint8_t UAV::getSequenceNumber() const{return m_sequenceNumber;}
MAV_TYPE UAV::getType() const{return m_type;}
MAV_FRAME UAV::getAirframe() const{return m_airframe;}
MAV_AUTOPILOT UAV::getAutopilot() const{return m_autopilot;}
MAV_MODE UAV::getBaseMode() const{return m_baseMode;}
uint32_t UAV::getCustomMode() const{return m_customMode;}
MAV_STATE UAV::getStatus() const{return m_status;}
QString UAV::getShortModeText() const{return m_shortModeText;}
QString UAV::getShortStateText() const{return m_shortStateText;}

bool UAV::isArmed() const{return m_systemIsArmed;}

uint64_t UAV::getStartTime() const{return m_startTime;}
uint64_t UAV::getOnBoardTimeOffset() const{return m_onBoardTimeOffset;}

bool UAV::isPositionLock() const{return m_positionLock;}
bool UAV::isLocalPositionKnown() const{return m_localPositionKnown;}
bool UAV::isGlobalPositionKnown() const{return m_globalPositionKnown;}
double UAV::getSatelliteCount() const{return m_satelliteCount;}
bool UAV::isGlobalEstimatorActive() const{return m_globalEstimatorActive;}

double UAV::getLocalX() const{return m_localX;}
double UAV::getLocalY() const{return m_localY;}
double UAV::getLocalZ() const{return m_localZ;}

double UAV::getLatitude() const{return m_latitude;}
double UAV::getLongitude() const{return m_longitude;}
double UAV::getAltitudeAMSL() const{return m_altitudeAMSL;}
double UAV::getAltitudeRelative() const{return m_altitudeRelative;}

double UAV::getGPSLatitude() const{return m_GPSAltitude;}
double UAV::getGPSLongitude() const{return m_GPSLatitude;}
double UAV::getGPSAltitude() const{return m_GPSLongitude;}

double UAV::getSpeedX() const{return m_speedX;}
double UAV::getSpeedY() const{return m_speedY;}
double UAV::getSpeedZ() const{return m_speedZ;}

double UAV::getDistToWaypoint() const{return m_distToWaypoint;}
double UAV::getAirspeed() const{return m_airspeed;}
double UAV::getGroundSpeed() const{return m_groundSpeed;}
double UAV::getBearingToWaypoint() const{return m_bearingToWaypoint;}

bool UAV::isAttitudeKnown() const{return m_attitudeKnown;}
bool UAV::isAttitudeStamped() const{return m_attitudeStamped;}
uint64_t UAV::getLastAttitudeTimestamp() const{return m_lastAttitudeTimestamp;}

double UAV::getRoll() const{return m_roll;}
double UAV::getPitch() const{return m_pitch;}
double UAV::getYaw() const{return m_yaw;}
