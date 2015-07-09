#include "mapwidget.h"

MapWidget::MapWidget(QWidget *parent) : QWidget(parent),
  m_layout(new QHBoxLayout(this))
{
}

void MapWidget::updateLocation(int32_t lon, int32_t lat, int32_t alt)
{
  m_lon = lon;
  m_lat = lat;
  m_alt = alt;
}
