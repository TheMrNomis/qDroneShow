#include "aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) : QWidget(parent)
{
  this->setFixedWidth(400);
  QVBoxLayout * layout = new QVBoxLayout(this);
  layout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
  layout->addWidget(new QLabel("<h1>QDroneShow</h1>", this));
  layout->addWidget(new QLabel("<a href='https://github.com/TheMrNomis/qDroneShow'>https://github.com/TheMrNomis/qDroneShow</a>",this));

  layout->addSpacing(10);

  layout->addWidget(new QLabel("Built on "+QString(__DATE__)+", "+QString(__TIME__), this));

  layout->addSpacing(10);

  layout->addWidget(new QLabel("Copyright © 2015 - Amaury Louarn"));

  layout->addSpacing(10);

  layout->addWidget(new QLabel("<h2>License (GNU GPL v3)</h2>"));

  layout->addWidget(new QLabel("QDroneShow is free software; you can redistribute it and/or modify\r\nit under the terms of the GNU Feneral public license as published by\r\nthe Free Software Foundation; either version 3 of the License, or\n(at your option) any later version.\r\n\r\nqDroneShow is distributed in the hope that it will be useful,\nbut WITHOUT ANY WARRANTY; without event the implied warranty of\nMERCHANDABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\nGNU General Public License for more details.\n\nYou should have received a copy of the GNU General Public License\nalong with qDroneShow. If not, see <http://www.gnu.org/licenses/>",this));

  layout->addSpacing(10);

  layout->addWidget(new QLabel("<h2>Credits</h2>"));

  layout->addWidget(new QLabel("<h3>MAVLink C Library</h3>",this));
  layout->addWidget(new QLabel("Licensed under the GNU Lesser General Public License version 3",this));
  layout->addWidget(new QLabel("Copyright © 2009-2014 Lorenz Meier",this));
  layout->addWidget(new QLabel("<a href='https://github.com/mavlink/mavlink'>https://github.com/mavlink/mavlink</a>",this));

  layout->addWidget(new QLabel("<h3>QGroundControl</h3>",this));
  layout->addWidget(new QLabel("Licensed under the GNU General Public License version 3",this));
  layout->addWidget(new QLabel("Copyright © 2009 - 2015 QGroundControl project",this));
  layout->addWidget(new QLabel("<a href='http://www.qgroundcontrol.org/'>http://www.qgroundcontrol.org/</a>",this));

  layout->addWidget(new QLabel("<h3>Material design icons</h3>",this));
  layout->addWidget(new QLabel("Licensed under the Creative Common Attribution 4.0 International License",this));
  layout->addWidget(new QLabel("<a href='https://github.com/google/material-design-icons'>https://github.com/google/material-design-icons</a>",this));

  this->setLayout(layout);
  this->setWindowTitle("About");
}

