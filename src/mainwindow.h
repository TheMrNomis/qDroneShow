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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPortInfo>
#include "UAV/uav.h"
#include "UAV/seriallink.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void connectSerial();

  void updateSerialPort(int newSerial);

private:
  void _updateSerialCombobox();

  Ui::MainWindow *ui;
  UAV* m_uav;
  QString m_serialPort;
};

#endif // MAINWINDOW_H
