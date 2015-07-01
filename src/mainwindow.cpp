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

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_uav(new UAV(1,255, this)),
    m_serialPort()
{
  ui->setupUi(this);

  QObject::connect(ui->ButtonConnectSerial, SIGNAL(released()), this, SLOT(connectSerial()));
  QObject::connect(ui->ButtonDisconnectSerial, SIGNAL(released()), m_uav, SLOT(disconnectLinks()));

  QObject::connect(ui->comboSelectSerial, SIGNAL(activated(int)), this, SLOT(updateSerialPort(int)));
  _updateSerialCombobox();
  updateSerialPort(0);

  QObject::connect(ui->ButtonHeartbeat, SIGNAL(released()), m_uav, SLOT(sendHeartbeat()));
//  QObject::connect(ui->ButtonParameters, SIGNAL(released()), m_uav, SLOT());

  QObject::connect(ui->ButtonArm, SIGNAL(released()), m_uav, SLOT(armSystem()));
  QObject::connect(ui->ButtonDisarm, SIGNAL(released()), m_uav, SLOT(disarmSystem()));

  updateSerialPort(0);
}

MainWindow::~MainWindow()
{
  delete m_uav;
  delete ui;
}

void MainWindow::connectSerial()
{
  std::cout << "connecting Serial on port [" << m_serialPort.toStdString() << "]" << std::endl;
  //QString port(ui->comboSelectSerial->it);
  m_uav->addLink(new SerialLink(m_serialPort, QSerialPort::Baud57600));
  m_uav->connectLinks();
}

void MainWindow::updateSerialPort(int newSerial)
{
  m_serialPort = ui->comboSelectSerial->itemText(newSerial);
}

void MainWindow::_updateSerialCombobox()
{
  QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();
  for(auto it = portList.cbegin(); it != portList.cend(); ++it)
      ui->comboSelectSerial->addItem(it->portName());
}
