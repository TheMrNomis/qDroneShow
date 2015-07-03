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
    QMainWindow(parent)
{
  QWidget *mainZone = new QWidget;
  setCentralWidget(mainZone);

  QMenu *menuFichier = menuBar()->addMenu("&Fichier");
  //QMenu *menuEdition = menuBar()->addMenu("&Edition");

  QAction *actionQuitter = new QAction("&Quitter", this);
  actionQuitter->setIcon(QIcon(":/gui/exit"));
  QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
  menuFichier->addAction(actionQuitter);

  QToolBar *toolBar = addToolBar("toolbar");
  toolBar->setMovable(false);
  toolBar->addAction(actionQuitter);

  toolBar->addSeparator();
  QAction * actionRefreshSerial = new QAction("Refresh serial list", this);
  actionRefreshSerial->setIcon(QIcon(":/gui/refresh"));
  toolBar->addAction(actionRefreshSerial);

  DroneList * dl = new DroneList(new SerialLink("COM11", QSerialPort::Baud57600), this);
  setCentralWidget(dl);
}

MainWindow::~MainWindow()
{

}
