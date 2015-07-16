#ifndef CONNECTIVITYHANDLER_H
#define CONNECTIVITYHANDLER_H

#include <iostream>
#include <cstdint>
#include <deque>
#include <cmath>

#include <QObject>
#include <QDateTime>
#include <QTimer>

class ConnectivityHandler : public QObject
{
  Q_OBJECT
public:
  explicit ConnectivityHandler(QObject *parent = 0);

signals:
  /**
   * @brief emitted when the connectivity calculation is complete
   *
   * @param percents
   * [0, 100]   normal connectivity
   * [-100, 0[  connectivity with errors (but still correct percents)
   * [-127,-100[ and ]100, 126[ no connectivity
   */
  void connectivityChanged(int8_t percents);

  /**
   * @brief emitted when the message timeout is reached
   */
  void disconnected();

public slots:
  /**
   * @brief Call this slot when you receive a message, tu update the connectivity
   * @param sequenceNumber The sequence number of the received message
   */
  void messageReceived(int sequenceNumber);

  /**
   * @brief Call this slot when you receive a corrupted message
   */
  void badMessageReceived();

  /**
   * @brief Call this slot when you receive a SYS_STATUS message
   * @param drop_rate_comm the communication drop in percent
   * @param errors_comm the communication errors
   */
  void updateTx(uint16_t drop_rate_comm, uint16_t errors_comm);

private slots:
  void _timeout();

private:
  uint8_t _connectivity() const;

  //Rx
  std::deque<std::pair<QDateTime,int> > m_RxDrops; //Rx drop rate
  std::deque<QDateTime> m_RxErrors; //Rx errors

  //Tx
  uint16_t m_TxDrops; //Tx drop rate
  uint16_t m_TxErrors;   //Tx errors

  //timeout timer
  QTimer * m_timeoutTimer;
  const int m_timeout_duration = 5000; //timeout duration (ms)
};

#endif // CONNECTIVITYHANDLER_H
