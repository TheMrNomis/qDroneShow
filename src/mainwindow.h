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

#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QDockWidget>
#include <QSignalMapper>

#include <QtSerialPort/QSerialPortInfo>

#include "UAV/uav.h"
#include "UAV/seriallink.h"

#include "dronelist.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void _setShowMode();
  void _setPlanMode();

  void _show_connectLink();
  void _show_disconnectLink();

  void _show_droneListConnected(bool isConnected);

  void _show_updatePortNames();

  void _show_setSerialPortName(QAction* sender);
  void _show_setSerialPortBaudRate(QAction* baudActionSelected);

private:
  /*----members common to show & plan modes----*/
  void _setupCommon();
  QAction * m_actionQuit;

  QMenu * m_menuHelp;
    QAction * m_actionAbout;

  /*----show mode members----*/
  void _setupShowMenuBar();
  QMenuBar * m_show_menuBar;
    QMenu * m_show_menuFile;
    QMenu * m_show_menuConnect;
      QMenu * m_show_menuSerialPort;
        QActionGroup * m_show_serialPortActionGroup;
        std::vector<QAction *> m_show_arraySerialPortActions;
      QMenu * m_show_menuBaud;
        QActionGroup * m_show_baudActionGroup;
        QAction * m_show_arrayBaudActions[8];
      QAction * m_show_actionConnect;
      QAction * m_show_actionResearchUAVs;

  QWidget * m_show_centralWidget;

  QDockWidget * m_show_dockUAVList;
    DroneList * m_show_droneList;

  QString m_show_serialPortName;
  QSerialPort::BaudRate m_show_baudRate;

  /*----plan mode members----*/
  void _setupPlanMenuBar();
  QMenuBar * m_plan_menuBar;
    QMenu * m_plan_menuFile;
      QAction * m_plan_actionNew;
      QAction * m_plan_actionOpen;
      QAction * m_plan_actionSave;
      QAction * m_plan_actionSaveAs;
};

#endif // MAINWINDOW_H
