#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <cstdint>
#include <iostream>

class MapWidget : public QWidget
{
  Q_OBJECT
public:
  explicit MapWidget(QWidget *parent = 0);

public slots:
  void updateLocation(int32_t lon, int32_t lat, int32_t alt);

private:


  QLayout * m_layout;

  int32_t m_lon;
  int32_t m_lat;
  int32_t m_alt;
};

#endif // MAPWIDGET_H
