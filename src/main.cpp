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

#include <QApplication>
#include <iostream>
#include <bitset>

#include "MAVLink/ardupilotmega/mavlink.h"
#include "UAV/bytebuffer.h"
#include "UAV/mavlinkheartbeat.h"
#include "UAV/link.h"
#include "UAV/udplink.h"

//#include "mainwindow.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

//  bool MAVLINK_NEED_BYTE_SWAP = true;
//  ByteBuffer buf(MAVLINK_NEED_BYTE_SWAP);
//  uint64_t n(0xFFFEFDFCFBFAF9F8);
//  buf << n;

//  std::cout << "MAVLINK_NEED_BYTE_SWAP : " << MAVLINK_NEED_BYTE_SWAP << std::endl;
//  std::cout << "n = " << std::bitset<8*sizeof(n)>(n) << std::endl;

//  std::cout << "buf : " << buf << std::endl;

//  char* nb = (char*)&n;
//  std::cout << "char: ";
//  for(int i = 0; i < sizeof(n) ; ++i)
//    std::cout << "[" << std::bitset<8>(nb[i]) << "]";
//  std::cout << std::endl;

  const uint8_t systemID = 0x01;
  const uint8_t componentID = 0x3C;

  const uint8_t type = MAV_TYPE_GCS;
  const uint8_t autopilot = MAV_AUTOPILOT_INVALID;
  const uint8_t base_mode = MAV_MODE_MANUAL_ARMED;
  const uint32_t custom_mode = 0xffeeddcc;
  const uint8_t status = MAV_STATE_ACTIVE;

  MAVLinkMessage msg = MAVLinkHeartbeat(systemID,componentID,1,type,autopilot,base_mode,custom_mode,status);
  //std::cout << msg.toByteBuffer() << std::endl;


  UDPLink udp("192.168.1.14", 14552);
  udp.connect();
  udp.sendMessage(msg);

  return 0;
}
