#include "formationwidget.h"
#include "ui_formationwidget.h"

FormationWidget::FormationWidget(QWidget *parent) :
  QFrame(parent),
  ui(new Ui::FormationWidget)
{
  ui->setupUi(this);
}

FormationWidget::~FormationWidget()
{
  delete ui;
}
