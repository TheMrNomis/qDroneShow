#ifndef UAVWIDGET_H
#define UAVWIDGET_H

#include <QWidget>

#include "UAV/uav.h"

class UAVWidget : public QWidget
{
  Q_OBJECT
public:
  explicit UAVWidget(QWidget *parent = 0);

signals:

public slots:

private:
  UAV * m_uav;
};

#endif // UAVWIDGET_H
