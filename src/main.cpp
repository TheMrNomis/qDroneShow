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

#include "UAV/bytebuffer.h"

//#include "mainwindow.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

  bool MAVLINK_NEED_BYTE_SWAP = true;
  ByteBuffer buf(MAVLINK_NEED_BYTE_SWAP);
  uint64_t n(0xFFFEFDFCFBFAF9F8);
  buf << n;

  std::cout << "MAVLINK_NEED_BYTE_SWAP : " << MAVLINK_NEED_BYTE_SWAP << std::endl;
  std::cout << "n = " << std::bitset<8*sizeof(n)>(n) << std::endl;

  std::cout << "buf : " << buf << std::endl;

  char* nb = (char*)&n;
  std::cout << "char: ";
  for(int i = 0; i < sizeof(n) ; ++i)
    std::cout << "[" << std::bitset<8>(nb[i]) << "]";
  std::cout << std::endl;

  return 0;
}
