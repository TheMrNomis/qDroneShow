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

#ifndef UAV_H
#define UAV_H

#include <QObject>

#include "mavlinkmessage.h"

/**
 * @brief This class represents one vehicle (Unmanned Aerial Vehicle)
 * @author Amaury Louarn <amaury.louarn@homnomnom.fr>
 */
class UAV : public QObject
{
    Q_OBJECT
public:
  explicit UAV(QObject *parent = 0);
  ~UAV();

  virtual double getLocalX() const;
  virtual double getLocalY() const;
  virtual double getLocalZ() const;
  virtual bool localPositionKnown() const;

  virtual double getLatitude() const;
  virtual double getLongitude() const;
  virtual double getAltitudeAMSL() const;
  virtual double getAltitudeRelative() const;
  virtual bool globalPositionKnown() const;

  virtual double getRoll() const;
  virtual double getPitch() const;
  virtual double getYaw() const;

  virtual bool isArmed() const;

  /** @brief Get the type of the system (airplane, quadrotor, helicopter,..)*/
  virtual int getSystemType() = 0;

  /** @brief Get the type of the autopilot (PIXHAWK, APM, UDB, PPZ,..) */
  virtual int getAutopilotType() = 0;
  virtual QString getAutopilotTypeName() = 0;
  virtual void setAutopilotType(int apType) = 0;

signals:

public slots:

private:
  bool m_isArmed;
  bool m_heartBeatsEnabled;
};

#endif // UAV_H
