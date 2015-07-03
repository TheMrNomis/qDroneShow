#ifndef DRONELIST_H
#define DRONELIST_H

#include <QGroupBox>

namespace Ui {
  class DroneList;
}

class DroneList : public QGroupBox
{
  Q_OBJECT

public:
  explicit DroneList(QWidget *parent = 0);
  ~DroneList();

private:
  Ui::DroneList *ui;
};

#endif // DRONELIST_H
