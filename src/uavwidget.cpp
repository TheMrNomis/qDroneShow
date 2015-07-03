#include "uavwidget.h"

UAVWidget::UAVWidget(unsigned int uavListID, uint8_t uavSystemID, Link* link, QWidget *parent) :
  QWidget(parent),
  m_uavSystemID(uavSystemID),
  m_uav(new UAV(uavSystemID)),

  m_mainLayout(new QVBoxLayout(this)),
  m_name(new QLabel(this)),

  m_armedState(new QLabel(this)),
  m_armedStateIcon(new QLabel(this)),

  m_GPS_sat(new QLabel(this)),
  m_GPS_fix(new QLabel(this)),
  m_GPSIcon(new QLabel(this)),

  m_connectionRate(new QLabel(this)),
  m_connectionRateIcon(new QLabel(this)),

  m_batteryState(new QLabel(this)),
  m_batteryStateIcon(new QLabel(this))
{
  setFixedSize(400, 150);

  QHBoxLayout * firstLine = new QHBoxLayout(m_mainLayout->widget());
  m_name->setText("<h1>UAV "+QString::number(uavListID)+"</h1>");
  _setArmedState(false);
  firstLine->addWidget(m_name);
  firstLine->addSpacing(50);
  firstLine->addWidget(m_armedStateIcon);
  firstLine->addWidget(m_armedState);

  QHBoxLayout * secondLine = new QHBoxLayout(m_mainLayout->widget());
  _setGPS(255,0);
  _setConnectivity(-101);
  _setBattery(-1);
  secondLine->addWidget(m_GPSIcon);

  QVBoxLayout * GPSLayout = new QVBoxLayout(secondLine->widget());
  GPSLayout->addWidget(m_GPS_fix);
  GPSLayout->addWidget(m_GPS_sat);

  secondLine->addLayout(GPSLayout);

  secondLine->addSpacing(50);
  secondLine->addWidget(m_connectionRateIcon);
  secondLine->addWidget(m_connectionRate);
  secondLine->addSpacing(50);
  secondLine->addWidget(m_batteryStateIcon);
  secondLine->addWidget(m_batteryState);

  m_mainLayout->addLayout(firstLine);
  m_mainLayout->addLayout(secondLine);
  setLayout(m_mainLayout);

  QObject::connect(m_uav, SIGNAL(armingStateChanged(bool)), this, SLOT(_setArmedState(bool)));
  QObject::connect(m_uav, SIGNAL(GPSChanged(uint8_t,uint8_t)), this, SLOT(_setGPS(uint8_t, uint8_t)));
  QObject::connect(m_uav, SIGNAL(connectivityChanged(int8_t)), this, SLOT(_setConnectivity(int8_t)));
  QObject::connect(m_uav, SIGNAL(batteryPercentChanged(int8_t)), this, SLOT(_setBattery(int8_t)));

  //UAV connection
  m_uav->addLink(link);
  m_uav->initialize();
}

UAVWidget::~UAVWidget()
{
    delete m_uav;
}

uint8_t UAVWidget::getUAVSystemID() const{return m_uavSystemID;}

void UAVWidget::_setArmedState(bool isArmed)
{
  if(isArmed)
  {
    m_armedStateIcon->setPixmap(QPixmap(":/state/armed"));
    m_armedState->setText("<span style='"+m_style_error+"'>Armed</span>");
  }
  else
  {
    m_armedStateIcon->setPixmap(QPixmap(":/state/disarmed"));
    m_armedState->setText("<span style='"+m_style_ok+"'>Disarmed</span>");
  }
}

void UAVWidget::_setGPS(uint8_t satelliteNumber, uint8_t fix)
{
  if(satelliteNumber == 255)
  {
    m_GPSIcon->setPixmap(QPixmap(":/gps/off"));
    m_GPS_sat->setText("<span style='"+m_style_error+"'>ERROR</span>");
    m_GPS_fix->setText("<span style='"+m_style_error+"'>ERROR</span>");
  }
  else
  {
    m_GPS_sat->setText("<span style='"+m_style_ok+"'>"+QString::number(satelliteNumber)+"</span>");
    if(fix < 2)
    {
      m_GPSIcon->setPixmap(QPixmap(":/gps/not_fixed"));
      m_GPS_fix->setText("<span style='"+m_style_error+"'>no fix</span>");
    }
    else if(fix <= 5)
    {
      m_GPSIcon->setPixmap(QPixmap(":/gps/fixed"));
      if(fix == 2)
        m_GPS_fix->setText("<span style='"+m_style_ok+"'>2D fix</span>");
      else if(fix == 3)
        m_GPS_fix->setText("<span style='"+m_style_ok+"'>3D fix</span>");
      else if(fix == 4)
        m_GPS_fix->setText("<span style='"+m_style_ok+"'>DGPS</span>");
      else if(fix == 5)
        m_GPS_fix->setText("<span style='"+m_style_ok+"'>RTK</span>");
    }
    else
    {
      m_GPSIcon->setPixmap(QPixmap(":/gps/off"));
      m_GPS_fix->setText("<span style='"+m_style_error+"'>ERROR</span>");
    }
  }
}

void UAVWidget::_setConnectivity(int8_t percent)
{
  if(percent < 0 || percent > 100)
    m_connectionRate->setText("<span style='"+m_style_error+"'>ERROR</span>");
  else
    m_connectionRate->setText("<span style='"+m_style_ok+"'>"+QString::number(percent)+"%</span>");


  if(percent < -100 || percent > 100)
    m_connectionRateIcon->setPixmap(QPixmap(":/signal/off"));
  else if(percent < -80)
    m_connectionRateIcon->setPixmap(QPixmap(":/signal/error_4"));
  else if(percent < -60)
    m_connectionRateIcon->setPixmap(QPixmap(":/signal/error_3"));
  else if(percent < -40)
    m_connectionRateIcon->setPixmap(QPixmap(":/signal/error_2"));
  else if(percent < -20)
    m_connectionRateIcon->setPixmap(QPixmap(":/signal/error_1"));
  else if(percent < 0)
    m_connectionRateIcon->setPixmap(QPixmap(":/signal/error_0"));
  else if(percent < 20)
    m_connectionRateIcon->setPixmap(QPixmap(":/signal/0"));
  else if(percent < 40)
    m_connectionRateIcon->setPixmap(QPixmap(":/signal/1"));
  else if(percent < 60)
    m_connectionRateIcon->setPixmap(QPixmap(":/signal/2"));
  else if(percent < 80)
    m_connectionRateIcon->setPixmap(QPixmap(":/signal/3"));
  else if(percent <= 100)
    m_connectionRateIcon->setPixmap(QPixmap(":/signal/4"));
}

void UAVWidget::_setBattery(int8_t percent)
{
  if(percent < 0 || percent > 100)
  {
    m_batteryStateIcon->setPixmap(QPixmap(":/battery/unknown"));
    m_batteryState->setText("<span style='"+m_style_error+"'>ERROR</span>");
  }
  else
  {
    m_batteryState->setText("<span style='"+m_style_ok+"'>"+QString::number(percent)+"%</span>");
    if(percent <= 10)
      m_batteryStateIcon->setPixmap(QPixmap(":/battery/10"));
    else if(percent <= 20)
      m_batteryStateIcon->setPixmap(QPixmap(":/battery/20"));
    else if(percent <= 30)
      m_batteryStateIcon->setPixmap(QPixmap(":/battery/30"));
    else if(percent <= 50)
      m_batteryStateIcon->setPixmap(QPixmap(":/battery/50"));
    else if(percent <= 60)
      m_batteryStateIcon->setPixmap(QPixmap(":/battery/60"));
    else if(percent <= 80)
      m_batteryStateIcon->setPixmap(QPixmap(":/battery/80"));
    else if(percent <= 90)
      m_batteryStateIcon->setPixmap(QPixmap(":/battery/90"));
    else
      m_batteryStateIcon->setPixmap(QPixmap(":/battery/100"));
  }
}
