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

#include "UAV/bytebuffer.h"
#include "MAVLink/ardupilotmega/mavlink.h"
//#include "MAVLink/common/common.h"
#include "UAV/mavlinkheartbeat.h"

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

  const uint8_t systemID = 0xF0;
  const uint8_t componentID = 0x3C;



  const uint8_t type = MAV_TYPE_GCS;
  const uint8_t autopilot = MAV_AUTOPILOT_INVALID;
  const uint8_t base_mode = MAV_MODE_MANUAL_ARMED;
  const uint32_t custom_mode = 0xffeeddcc;
  const uint8_t status = MAV_STATE_ACTIVE;

  std::cout << "systemID : " << std::bitset<8>(systemID) << std::endl;
  std::cout << "componentID : " << std::bitset<8>(componentID) << std::endl;
  std::cout << "type : " << std::bitset<8>(type) << std::endl;
  std::cout << "autopilot : " << std::bitset<8>(autopilot) << std::endl;
  std::cout << "base_mode : " << std::bitset<8>(base_mode) << std::endl;
  std::cout << "custom_mode : " << std::bitset<32>(custom_mode) << std::endl;
  std::cout << "status : " << std::bitset<8>(status) << std::endl;

  std::cout << "----C----" << std::endl;
  mavlink_message_t message;
  mavlink_msg_heartbeat_pack(systemID,componentID,&message,type,autopilot,base_mode,custom_mode,status);

  static uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
  // Rewriting header to ensure correct link ID is set
  static uint8_t messageKeys[256] = MAVLINK_MESSAGE_CRCS;
  mavlink_finalize_message_chan(&message,systemID,componentID,MAVLINK_COMM_0,message.len, messageKeys[message.msgid]);
  // Write message into buffer, prepending start sign
  int len = mavlink_msg_to_send_buffer(buffer, &message);

  std::cout << "buffer : ";
  ByteBuffer mavbuffer;
  for(int i = 0; i < len; ++i)
  {
    mavbuffer << buffer[i];
    std::cout << "[" << std::bitset<8>(buffer[i]) << "]";
  }
  std::cout << std::endl;

  std::cout << "---POO---" << std::endl;
  MAVLinkMessage msg = MAVLinkHeartbeat(systemID,componentID,1,type,autopilot,base_mode,custom_mode,status);
  std::cout << "buffer : " << msg.toByteBuffer() << std::endl;

  std::cout << "MAVLINK_CORE_HEADER_LEN = " << MAVLINK_CORE_HEADER_LEN << std::endl;

//  std::cout << "---load--" << std::endl;
//  MAVLinkMessage mes(mavbuffer);

  return 0;
}
