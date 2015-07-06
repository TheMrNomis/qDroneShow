#ifndef DRONELIST_H
#define DRONELIST_H

#include <QGroupBox>
#include <QMessageBox>
#include <vector>
#include "UAV/link.h"
#include "uavwidget.h"

/**
 * @brief This class is GroupBox containing UAVWidgets. It is used as an interface that creates UAVs as it receive MAVLink messages.
 * @author Amaury Louarn <amaury.louarn@homnomnom.fr>
 */
class DroneList : public QGroupBox
{
  Q_OBJECT

public:
  explicit DroneList(QWidget *parent = 0);
  ~DroneList();

public slots:
  /**
   * @brief sets the Link used to communicate with UAVs
   * @param connection the new Link to be used
   * @warning if a current connection is set, this function WILL delete() it.
   * @warning this function WILL take ownership of the Link*.
   */
  void setConnection(Link * connection);
  /**
   * @brief removes the Link used to communicate with UAVs
   * @warning this function WILL delete() the current Link
   */
  void deleteConnection();

private slots:
  void _receiveMessage(MAVLinkMessage const& msg);

private:
  Link * m_connection;
  std::vector<UAVWidget *> m_uavWidgets;
  QVBoxLayout * m_mainLayout;
};

#endif // DRONELIST_H
