#include "uavwidget.h"

UAVWidget::UAVWidget(unsigned int uavListID, uint8_t uavSystemID, Link* link, QWidget *parent) :
  QWidget(parent),
  m_uavSystemID(uavSystemID),
  m_uav(new UAV(uavSystemID)),

  m_mainLayout(new QVBoxLayout(this)),
  m_name(new QLabel(this)),

  m_armedState(new QLabel(this)),
  m_armedStateIcon(new QLabel(this)),

  m_GPS(new QLabel(this)),
  m_GPSIcon(new QLabel(this)),

  m_connectionRate(new QLabel(this)),
  m_connectionRateIcon(new QLabel(this)),

  m_batteryState(new QLabel(this)),
  m_batteryStateIcon(new QLabel(this))
{
  QHBoxLayout * firstLine = new QHBoxLayout(m_mainLayout->widget());
  m_name->setText("<h1>UAV "+QString::number(uavListID)+"</h1>");
  _setArmedState(false);
  firstLine->addWidget(m_name);
  firstLine->addSpacing(50);
  firstLine->addWidget(m_armedStateIcon);
  firstLine->addWidget(m_armedState);

  QHBoxLayout * secondLine = new QHBoxLayout(m_mainLayout->widget());
  _setGPS(-1);
  _setConnectivity(-101);
  _setBattery(-1);
  secondLine->addWidget(m_GPSIcon);
  secondLine->addWidget(m_GPS);
  firstLine->addSpacing(50);
  secondLine->addWidget(m_connectionRateIcon);
  secondLine->addWidget(m_connectionRate);
  firstLine->addSpacing(50);
  secondLine->addWidget(m_batteryStateIcon);
  secondLine->addWidget(m_batteryState);

  m_mainLayout->addLayout(firstLine);
  m_mainLayout->addLayout(secondLine);
  setLayout(m_mainLayout);

  QObject::connect(m_uav, SIGNAL(armingStateChanged(bool)), this, SLOT(_setArmedState(bool)));
  QObject::connect(m_uav, SIGNAL(numberOfGPSChanged(int8_t)), this, SLOT(_setGPS(int8_t)));
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

void UAVWidget::_setGPS(int8_t satelliteNumber)
{
  if(satelliteNumber < 0)
  {
    m_GPSIcon->setPixmap(QPixmap(":/gps/off"));
    m_GPS->setText("<span style='"+m_style_error+"'>ERROR</span>");
  }
  else if(satelliteNumber == 0)
  {
    m_GPSIcon->setPixmap(QPixmap(":/gps/not_fixed"));
    m_GPS->setText("<span style='"+m_style_error+"'>"+QString::number(satelliteNumber)+"</span>");
  }
  else
  {
    m_GPSIcon->setPixmap(QPixmap(":/gps/fixed"));
    m_GPS->setText("<span style='"+m_style_ok+"'>"+QString::number(satelliteNumber)+"</span>");
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