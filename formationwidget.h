#ifndef FORMATIONWIDGET_H
#define FORMATIONWIDGET_H

#include <QFrame>

namespace Ui {
  class FormationWidget;
}

class FormationWidget : public QFrame
{
  Q_OBJECT

public:
  explicit FormationWidget(QWidget *parent = 0);
  ~FormationWidget();

private:
  Ui::FormationWidget *ui;
};

#endif // FORMATIONWIDGET_H
