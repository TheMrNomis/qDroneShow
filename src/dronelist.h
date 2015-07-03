#ifndef DRONELIST_H
#define DRONELIST_H

#include <QGroupBox>
#include <QMessageBox>
#include <vector>
#include "UAV/link.h"
#include "uavwidget.h"

/**
 * @brief This class is GroupBox containing UAVWidgets. It is used as an interface that creates UAVs as it receive MAVLink messages through the Link "connection"
 * @author Amaury Louarn <amaury.louarn@homnomnom.fr>
 */
class DroneList : public QGroupBox
{
  Q_OBJECT

public:
  explicit DroneList(Link * connection, QWidget *parent = 0);
  ~DroneList();

private slots:
  void _receiveMessage(MAVLinkMessage const& msg);

private:
  Link * m_connection;
  std::vector<UAVWidget *> m_uavWidgets;
  QVBoxLayout * m_mainLayout;
};

#endif // DRONELIST_H
