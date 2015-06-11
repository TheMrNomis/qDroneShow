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

UAV::UAV(QObject *parent) : QObject(parent)
{

}

double UAV::getLocalX() const
{
  //TODO
  return 0;
}
double UAV::getLocalY() const
{
  //TODO
  return 0;
}
double UAV::getLocalZ() const
{
  //TODO
  return 0;
}
bool UAV::localPositionKnown() const
{
  //TODO
  return false;
}

double UAV::getLatitude() const
{
  //TODO
  return 0;
}
double UAV::getLongitude() const
{
  //TODO
  return 0;
}
double UAV::getAltitudeAMSL() const
{
  //TODO
  return 0;
}
double UAV::getAltitudeRelative() const
{
  //TODO
  return 0;
}
bool UAV::globalPositionKnown() const
{
  //TODO
  return 0;
}

double UAV::getRoll() const
{
  //TODO
  return 0;
}
double UAV::getPitch() const
{
  //TODO
  return 0;
}
double UAV::getYaw() const
{
  //TODO
  return 0;
}

bool UAV::isArmed() const
{
  //TODO
  return false;
}

//void UAV::executeCommand(MAV_CMD command, int confirmation = 0, float param1 = 0.0f, float param2 = 0.0f, float param3 = 0.0f, float param4 = 0.0f, float param5 = 0.0f, float param6 = 0.0f, float param7 = 0.0f, int component = 0)
//{

//}

void UAV::execute(MAVLinkMessage what)
{
  for(auto i = links.cbegin(); i != links.cend(); i++)
    (*i)->sendMessage(what);
}

