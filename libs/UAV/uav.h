/*=======================================================================
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

/*=======================================================================
 * This file contains fragments of code from the QGroundControl project,
 * which is released under the terms of the GNU General Public License,
 * version 3.
 *
 * Copyright (C) 2009 - 2015 QGROUNDCONTROL PROJECT
 * <http://www.qgroundcontrol.org>
 * ======================================================================*/

#ifndef UAV_H
#define UAV_H

#include <iostream>
#include <QObject>
#include <QDateTime>

#include "MAVLink/common/mavlink.h"

#include "link.h"

/**
 * @brief This class represents one vehicle (Unmanned Aerial Vehicle)
 * @author Amaury Louarn <amaury.louarn@homnomnom.fr>
 */
class UAV : public QObject
{
    Q_OBJECT
public:
  explicit UAV(uint8_t UAVsystemId, uint8_t GCSsystemId = 255, uint8_t UAVcomponentId = 0, uint8_t GCScomponentId = 0, QObject *parent = 0);
  ~UAV();

  virtual void addLink(Link* link);

public slots:
  void connectLinks();
  void disconnectLinks();

  /** @brief Launches the system **/
  void launch();
  /** @brief Write this waypoint to the list of waypoints */
  //void setWaypoint(Waypoint* wp); FIXME tbd
  /** @brief Set currently active waypoint */
  //void setWaypointActive(int id); FIXME tbd
  /** @brief Order the robot to return home **/
  void home();
  /** @brief Order the robot to land **/
  void land();
  /** @brief Order the robot to pair its receiver **/
  void pairRX(int rxType, int rxSubType);

  void halt();
  void go();

  /** @brief Stops the robot system. If it is an MAV, the robot starts the emergency landing procedure **/
  void emergencySTOP();

  /** @brief Kills the robot. All systems are immediately shut down (e.g. the main power line is cut). This might lead to a crash **/
  bool emergencyKILL();

  /** @brief Shut the system cleanly down. Will shut down any onboard computers **/
  void shutdown();

  /** @brief Set the target position for the robot to navigate to. */
  void setTargetPosition(float x, float y, float z, float yaw);

  //low battery alarm
  void startLowBattAlarm();
  void stopLowBattAlarm();

  //arming
  void armSystem();
  void disarmSystem();
  void toggleArmedState();

  //autonomy
  void goAutonomous();
  void goManual();
  void toggleAutonomy();

  //messages
  void receiveMessage(MAVLinkMessage const& msg);
  void receiveMessage(ByteBuffer const& msg);
  void sendMessage(MAVLinkMessage const& msg);

  //mode & state
  void setMode(uint8_t baseMode, uint32_t customMode);
  void updateState();

  //positionning
  void setLocalOriginAtCurrentGPSPosition();
  void setHomePosition(double latitude, double longitude, double altitude);

signals:
  /**
   * @brief signal sent immediatly after a change of the arming state
   * @param a boolean to indicate the new value of the armind : true if the UAV is now armed, false otherwise
   */
  void armingStateChanged(bool);

  void localXChanged(double val,QString name);
  void localYChanged(double val,QString name);
  void localZChanged(double val,QString name);
  void longitudeChanged(double val,QString name);
  void latitudeChanged(double val,QString name);
  void altitudeAMSLChanged(double val,QString name);
  void altitudeAMSLFTChanged(double val,QString name);
  void altitudeWGS84Changed(double val,QString name);
  void altitudeRelativeChanged(double val,QString name);
  void rollChanged(double val,QString name);
  void pitchChanged(double val,QString name);
  void yawChanged(double val,QString name);
  void satelliteCountChanged(double val,QString name);
  void distToWaypointChanged(double val,QString name);
  void groundSpeedChanged(double val, QString name);
  void airSpeedChanged(double val, QString name);
  void bearingToWaypointChanged(double val,QString name);

public slots:

  /**
   * @brief Sends a command to be executed on the UAV
   * @param command the commandID, as defined bu MAV_CMD enum
   * @param confirmation 0: first transmission of the command, 1->255: confirmating the transmission (for ex: the kill command)
   * @param param1-7 the params, as defined by MAV_CMD enum
   */
  void executeCommand(MAV_CMD command, int confirmation = 0, float param1 = 0.0f, float param2 = 0.0f, float param3 = 0.0f, float param4 = 0.0f, float param5 = 0.0f, float param6 = 0.0f, float param7 = 0.0f);

  void executeCommandAck(int num, bool success);

  /**
   * @brief get the UAV to execute the MAVLink order
   * @param what The MAVLinkMessage to execute
   */
  void execute(MAVLinkMessage what);

  /**
   * @brief sends a heartbeat to the UAV
   */
  void sendHeartbeat();

  void receiveBytes(ByteBuffer);

public:
  //getters
  QString getName() const;
  uint8_t getSystemID() const;
  uint8_t getSequenceNumber() const;
  MAV_TYPE getType() const;
  MAV_FRAME getAirframe() const;
  MAV_AUTOPILOT getAutopilot() const;
  MAV_MODE getBaseMode() const;
  uint32_t getCustomMode() const;
  MAV_STATE getStatus() const;
  QString getShortModeText() const;
  QString getShortStateText() const;

  virtual bool isArmed() const;

  //time
  uint64_t getStartTime() const;
  uint64_t getOnBoardTimeOffset() const;

  //position
  bool isPositionLock() const;
  bool isLocalPositionKnown() const;
  bool isGlobalPositionKnown() const;
  double getSatelliteCount() const;
  bool isGlobalEstimatorActive() const;

  double getLocalX() const;
  double getLocalY() const;
  double getLocalZ() const;

  double getLatitude() const;
  double getLongitude() const;
  double getAltitudeAMSL() const;
  double getAltitudeRelative() const;

  double getGPSLatitude() const;
  double getGPSLongitude() const;
  double getGPSAltitude() const;

  double getSpeedX() const;
  double getSpeedY() const;
  double getSpeedZ() const;

  //waypoints
  double getDistToWaypoint() const;
  double getAirspeed() const;
  double getGroundSpeed() const;
  double getBearingToWaypoint() const;

  //attitude
  bool isAttitudeKnown() const;
  bool isAttitudeStamped() const;
  uint64_t getLastAttitudeTimestamp() const;

  double getRoll() const;
  double getPitch() const;
  double getYaw() const;

private:
  //constants
  const uint64_t HEARTBEAT_TIMEOUT;

  std::list<Link*> m_links;

  //basic infos
  QString m_name;
  uint8_t m_sequenceNumber;
  MAV_TYPE m_type;
  MAV_FRAME m_airframe;
  MAV_AUTOPILOT m_autopilot;
  bool m_systemIsArmed;
  MAV_MODE m_baseMode;
  uint32_t m_customMode;
  MAV_STATE m_status;
  QString m_shortModeText;
  QString m_shortStateText;

  //IDs
  uint8_t m_UAVsystemID;
  uint8_t m_GCSsystemID;
  uint8_t m_UAVcomponentID;
  uint8_t m_GCScomponentID;

  //heartbeats
  bool m_heartbeatsEnabled;
  bool m_connectionLost;
  uint64_t m_lastHeartbeatTimestamp;

  //battery
  float startVoltage;         ///< Voltage at system start
  float tickVoltage;          ///< Voltage where 0.1 V ticks are told
  float lastTickVoltageValue; ///< The last voltage where a tick was announced
  float tickLowpassVoltage;   ///< Lowpass-filtered voltage for the tick announcement
  float warnLevelPercent;     ///< Warning level, in percent
  double currentVoltage;      ///< Voltage currently measured
  float lpVoltage;            ///< Low-pass filtered voltage
  double currentCurrent;      ///< Battery current currently measured
  bool batteryRemainingEstimateEnabled; ///< If the estimate is enabled, QGC will try to estimate the remaining battery life
  float chargeLevel;          ///< Charge level of battery, in percent
  int timeRemaining;          ///< Remaining time calculated based on previous and current
  bool lowBattAlarm;          ///< Switch if battery is low

  //time
  uint64_t m_startTime;
  uint64_t m_onBoardTimeOffset;

  //position
  bool m_positionLock;
  bool m_localPositionKnown;
  bool m_globalPositionKnown;
  double m_satelliteCount;
  bool m_globalEstimatorActive;

  double m_localX;
  double m_localY;
  double m_localZ;

  double m_latitude;
  double m_longitude;
  double m_altitudeAMSL;
  double m_altitudeRelative;

  double m_GPSLatitude;
  double m_GPSLongitude;
  double m_GPSAltitude;

  double m_speedX;
  double m_speedY;
  double m_speedZ;

  //waypoints
  double m_distToWaypoint;
  double m_airspeed;
  double m_groundSpeed;
  double m_bearingToWaypoint;

  //attitude
  bool m_attitudeKnown;
  bool m_attitudeStamped;
  uint64_t m_lastAttitudeTimestamp;

  double m_roll;
  double m_pitch;
  double m_yaw;

  //parameters
  bool blockHomePositionChanges;   ///< Block changes to the home position
  bool receivedMode;          ///< True if mode was retrieved from current connection to UAS

};

#endif // UAV_H
