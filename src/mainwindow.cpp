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
        m_show_menuBaud(new QMenu("Connexion Speed", this)),
        m_show_actionConnect(new QAction("&Connect", this)),
        m_show_actionResearchUAVs(new QAction("&Research UAVs", this)),

    m_show_centralWidget(new QWidget(this)),

    m_show_dockUAVList(new QDockWidget(this)),
      m_show_droneList(new DroneList(new SerialLink("COM11", QSerialPort::Baud57600),this)),

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

}

void MainWindow::_setShowMode()
{
  setMenuBar(m_show_menuBar);

  QWidget *mainZone = new QWidget;
  setCentralWidget(mainZone);

  m_show_dockUAVList->setWidget(m_show_droneList);
  addDockWidget(Qt::LeftDockWidgetArea, m_show_dockUAVList);
}

void MainWindow::_setPlanMode()
{
  //TODO
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
  m_show_menuFile->addAction(m_actionQuit);
  m_show_menuBar->addMenu(m_show_menuFile);

  m_show_menuConnect->addMenu(m_show_menuSerialPort);
  m_show_menuConnect->addMenu(m_show_menuBaud);
  m_show_menuConnect->addAction(m_show_actionConnect);
  m_show_menuConnect->addSeparator();
  m_show_menuConnect->addAction(m_show_actionResearchUAVs);
  m_show_menuBar->addMenu(m_show_menuConnect);

  m_show_menuBar->addMenu(m_menuHelp);
}

void MainWindow::_setupPlanMenuBar()
{

}
