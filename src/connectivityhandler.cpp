#include "connectivityhandler.h"

ConnectivityHandler::ConnectivityHandler(QObject *parent) :
  QObject(parent),
  m_RxDrops(),
  m_RxErrors(),

  m_TxDrops(0),
  m_TxErrors(0),

  m_timeoutTimer(new QTimer(this))
{
  m_timeoutTimer->setSingleShot(true);
  QObject::connect(m_timeoutTimer, SIGNAL(timeout()), this, SLOT(_timeout()));
  m_timeoutTimer->start(m_timeout_duration);
}

void ConnectivityHandler::messageReceived(int sequenceNumber)
{
  m_timeoutTimer->start(m_timeout_duration);
  QDateTime t = QDateTime::currentDateTime();

  while(m_RxDrops.size() > 0 && m_RxDrops.front().first.msecsTo(t) > 1000)
    m_RxDrops.pop_front();

  m_RxDrops.push_back(std::pair<QDateTime,int>(t,sequenceNumber));

  emit(connectivityChanged(_connectivity()));
}

void ConnectivityHandler::badMessageReceived()
{
  QDateTime t = QDateTime::currentDateTime();

  //remove data that is too old
  while(m_RxErrors.size() > 0 && m_RxErrors.front().msecsTo(t) > 1000)
    m_RxErrors.pop_front();

  m_RxErrors.push_back(t);

  emit(connectivityChanged(_connectivity()));
}

void ConnectivityHandler::updateTx(uint16_t drop_rate_comm, uint16_t errors_comm)
{
  m_TxDrops = drop_rate_comm;
  m_TxErrors = errors_comm;

  emit(connectivityChanged(_connectivity()));
}

void ConnectivityHandler::_timeout()
{
  emit(disconnected());
  emit(connectivityChanged(-101));
}

uint8_t ConnectivityHandler::_connectivity() const
{
  /*----Rx----*/
  int RxDrop = 0;
  for(auto it = m_RxDrops.cbegin(); it != m_RxDrops.cend(); ++it)
    RxDrop += (*it).second;

  int RxError = (int)m_RxErrors.size();

  //we use the log10 to have a huge drop (30%) at the first drop, and a little drop (5/10%) after multiple loss
  int RxPercent = 100 - 100*log(1+RxDrop+RxError);
  RxPercent = (RxPercent > 0)? RxPercent : 0;

  /*----Tx----*/
  int TxPercent = 100 - 100*log(1+m_TxDrops+m_TxErrors);
  TxPercent = (TxPercent > 0)? TxPercent : 0;

  /*----------*/
  return (RxPercent + TxPercent)/2;
}
