#ifndef UAVWIDGET_H
#define UAVWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

#include "UAV/uav.h"
//#include "dronelist.h"

/**
 * @brief This class is the vue for the UAV class (MVC architecture).
 * @author Amaury Louarn <amaury.louarn@homnomnom.fr>
 */
class UAVWidget : public QWidget
{
  friend class DroneList; //DroneList use directly m_UAV
  Q_OBJECT
public:
  explicit UAVWidget(unsigned int uavListID, uint8_t uavSystemID, Link * link, QWidget *parent = 0);
  ~UAVWidget();

  uint8_t getUAVSystemID() const;

signals:

private slots:
  void _setArmedState(bool isArmed);
  void _setGPS(uint8_t satelliteNumber, uint8_t fix);
  void _setConnectivity(int8_t percent);
  void _setBattery(int8_t percent);

private:
  uint8_t m_uavSystemID;
  UAV * m_uav;

  QVBoxLayout * m_mainLayout;

  QLabel * m_name;

  QLabel * m_armedState;
  QLabel * m_armedStateIcon;

  QLabel * m_GPS_sat;
  QLabel * m_GPS_fix;
  QLabel * m_GPSIcon;

  QLabel * m_connectionRate;
  QLabel * m_connectionRateIcon;

  QLabel * m_batteryState;
  QLabel * m_batteryStateIcon;

  const QString m_style_error = "color:#bb0000; font-size:x-large; font-weight:bold;";
  const QString m_style_ok = "color:#000000; font-size:x-large";
};

#endif // UAVWIDGET_H
