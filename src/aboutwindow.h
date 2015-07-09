#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class AboutWindow : public QWidget
{
  Q_OBJECT
public:
  explicit AboutWindow(QWidget *parent = 0);

};

#endif // ABOUTWINDOW_H
