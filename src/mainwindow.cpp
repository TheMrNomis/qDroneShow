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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    /*----members common to show & plan modes----*/
    m_actionQuit(new QAction("&Quit", this)),

    m_menuHelp(new QMenu("&Help", this)),
    m_actionAbout(new QAction("&About", this)),

    /*----show mode members----*/
    m_show_menuBar(new QMenuBar(0)),
      m_show_menuFile(new QMenu("&File", this)),
      m_show_menuConnect(new QMenu("&Connect", this)),
        m_show_menuSerialPort(new QMenu("Serial Port", this)),
          m_show_serialPortActionGroup(new QActionGroup(this)),
        m_show_menuBaud(new QMenu("Connexion Speed", this)),
          m_show_baudActionGroup(new QActionGroup(this)),
        m_show_actionConnect(new QAction("&Connect", this)),
        m_show_actionResearchUAVs(new QAction("&Research UAVs", this)),

    m_show_centralWidget(new QWidget(this)),

    m_show_dockUAVList(new QDockWidget(this)),
      m_show_droneList(new DroneList(this)),

    /*----plan mode members----*/
    m_plan_menuBar(new QMenuBar(0)),
      m_plan_menuFile(new QMenu("&File", this)),
        m_plan_actionNew(new QAction("&New", this)),
        m_plan_actionOpen(new QAction("&Open", this)),
        m_plan_actionSave(new QAction("&Save", this)),
        m_plan_actionSaveAs(new QAction("Save as...", this))
{
  _setupCommon();
  _setupPlanMenuBar();
  _setupShowMenuBar();
  _setShowMode();
}

MainWindow::~MainWindow()
{
  delete m_plan_menuBar;
  delete m_show_menuBar;
}

void MainWindow::_setShowMode()
{
  setMenuBar(m_show_menuBar);

  QWidget *mainZone = new QWidget;
  setCentralWidget(mainZone);

  m_show_dockUAVList->setWidget(m_show_droneList);
  m_show_dockUAVList->setFeatures(QDockWidget::NoDockWidgetFeatures);
  m_show_dockUAVList->setFloating(false);
  m_show_dockUAVList->setWindowTitle("UAV list");
  m_show_dockUAVList->setMinimumWidth(400);
  addDockWidget(Qt::LeftDockWidgetArea, m_show_dockUAVList);

  for(unsigned int i = 0; i < 8; ++i)
    m_show_baudActionGroup->addAction(m_show_arrayBaudActions[i]);

  QObject::connect(m_show_baudActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(_show_setSerialPortBaudRate(QAction *)));
  QObject::connect(m_show_serialPortActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(_show_setSerialPortName(QAction*)));
  QObject::connect(m_show_actionConnect, SIGNAL(triggered()), this, SLOT(_show_connectLink()));

  _show_updatePortNames();

  //auto-selecting the first serial port
  if(m_show_arraySerialPortActions.size() > 0)
  {
    m_show_arraySerialPortActions[0]->setChecked(true);
    _show_setSerialPortName(m_show_arraySerialPortActions[0]);
  }

  //auto-selecting 57600 bauds (telemetry default)
  m_show_arrayBaudActions[6]->setChecked(true);
  _show_setSerialPortBaudRate(m_show_arrayBaudActions[6]);
}

void MainWindow::_setPlanMode()
{
  //TODO
}

void MainWindow::_show_connectLink()
{
  if(m_show_serialPortName == "")
    QMessageBox::warning(this, "warning", "Impossible to connect\nno serial port specified");
  else
  {
    std::cout << "[MainWindow] connecting link" << std::endl;
    m_show_droneList->setConnection(new SerialLink(m_show_serialPortName, m_show_baudRate));
    QObject::disconnect(m_show_actionConnect, SIGNAL(triggered()), this, SLOT(_show_connectLink()));
    QObject::connect(m_show_actionConnect, SIGNAL(triggered()), this, SLOT(_show_disconnectLink()));
    m_show_actionConnect->setText("Disconnect");
    m_show_menuBaud->setDisabled(true);
    m_show_menuSerialPort->setDisabled(true);
  }
}

void MainWindow::_show_disconnectLink()
{
  std::cout << "[MainWindow] disconnecting link" << std::endl;
  m_show_droneList->deleteConnection();
  QObject::disconnect(m_show_actionConnect, SIGNAL(triggered()), this, SLOT(_show_disconnectLink()));
  QObject::connect(m_show_actionConnect, SIGNAL(triggered()), this, SLOT(_show_connectLink()));
  m_show_actionConnect->setText("Connect");
  m_show_menuBaud->setDisabled(false);
  m_show_menuSerialPort->setDisabled(false);
}

void MainWindow::_show_updatePortNames()
{
  //we extract the names of the currently available serial ports
  QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();
  std::list<QString> availablePortNames;
  for(auto it = availablePorts.cbegin(); it != availablePorts.cend(); ++it)
    availablePortNames.push_back(it->portName());

  //has any serial port been closed since the last check?
  for(auto it = m_show_arraySerialPortActions.begin(); it != m_show_arraySerialPortActions.end(); ++it)
  {
    QString currentPortName = (*it)->text();
    bool found = false;
    for(auto jt = availablePortNames.begin(); !found && jt != availablePortNames.end(); ++jt)
      if((*jt) == currentPortName)
      {
        //this serial port is still available, and we already have a QAction for it, we remove it from availablePortNames
        std::cout << "found : " << currentPortName.toStdString() << std::endl;
        jt = availablePortNames.erase(jt);
        found = true;
      }
    if(!found)
    {
      //this serial port is no longer available, we delete it from the GUI.
      m_show_serialPortActionGroup->removeAction(*it);
      m_show_menuSerialPort->removeAction(*it);
      it = m_show_arraySerialPortActions.erase(it);
    }
  }

  //Now, availablePortNames only contains the names of the newly available serial ports.
  for(auto it = availablePortNames.cbegin(); it != availablePortNames.cend(); ++it)
  {
    QAction * serialPortAction = new QAction(*it, this);
    serialPortAction->setCheckable(true);
    m_show_arraySerialPortActions.push_back(serialPortAction);
    m_show_serialPortActionGroup->addAction(serialPortAction);
    m_show_menuSerialPort->addAction(serialPortAction);
  }
}

void MainWindow::_show_setSerialPortName(QAction * sender)
{
  std::cout << "serial port : " << sender->text().toStdString() << std::endl;
  m_show_serialPortName = sender->text();
}

void MainWindow::_show_setSerialPortBaudRate(QAction * baudActionSelected)
{
  if (baudActionSelected == m_show_arrayBaudActions[0])
      m_show_baudRate = QSerialPort::Baud1200;
  else if(baudActionSelected == m_show_arrayBaudActions[1])
      m_show_baudRate = QSerialPort::Baud2400;
  else if(baudActionSelected == m_show_arrayBaudActions[2])
      m_show_baudRate = QSerialPort::Baud4800;
  else if(baudActionSelected == m_show_arrayBaudActions[3])
      m_show_baudRate = QSerialPort::Baud9600;
  else if(baudActionSelected == m_show_arrayBaudActions[4])
      m_show_baudRate = QSerialPort::Baud19200;
  else if(baudActionSelected == m_show_arrayBaudActions[5])
      m_show_baudRate = QSerialPort::Baud38400;
  else if(baudActionSelected == m_show_arrayBaudActions[6])
      m_show_baudRate = QSerialPort::Baud57600;
  else if(baudActionSelected == m_show_arrayBaudActions[7])
      m_show_baudRate = QSerialPort::Baud115200;

  std::cout << "baudRate : " << (int) m_show_baudRate << std::endl;
}

void MainWindow::_setupCommon()
{
  m_actionAbout->setIcon(QIcon(":/gui/info_outline"));

  m_menuHelp->addAction(m_actionAbout);

  m_actionQuit->setIcon(QIcon(":/gui/exit"));
  QObject::connect(m_actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void MainWindow::_setupShowMenuBar()
{
  m_show_menuBar->addMenu(m_show_menuFile);
    m_show_menuFile->addAction(m_actionQuit);


  m_show_menuBar->addMenu(m_show_menuConnect);
    m_show_menuConnect->addMenu(m_show_menuSerialPort);
    m_show_menuConnect->addMenu(m_show_menuBaud);
      m_show_arrayBaudActions[0] = new QAction("1200",this);
      m_show_arrayBaudActions[1] = new QAction("2400",this);
      m_show_arrayBaudActions[2] = new QAction("4800",this);
      m_show_arrayBaudActions[3] = new QAction("9600",this);
      m_show_arrayBaudActions[4] = new QAction("19200",this);
      m_show_arrayBaudActions[5] = new QAction("38400",this);
      m_show_arrayBaudActions[6] = new QAction("57600",this);
      m_show_arrayBaudActions[7] = new QAction("115200",this);
      for(unsigned int i = 0; i < 8; ++i)
      {
        m_show_arrayBaudActions[i]->setCheckable(true);
        m_show_menuBaud->addAction(m_show_arrayBaudActions[i]);
      }
    m_show_menuConnect->addAction(m_show_actionConnect);
    m_show_menuConnect->addSeparator();
    m_show_menuConnect->addAction(m_show_actionResearchUAVs);

  m_show_menuBar->addMenu(m_menuHelp);
}

void MainWindow::_setupPlanMenuBar()
{

}
