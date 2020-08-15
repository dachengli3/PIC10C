#include "mainwindow.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{

   QApplication myapp(argc,argv);
  // QLabel *label = new QLabel("Hello, World... from Qt!");
  QLabel *label = new QLabel("<h2><i>Hello</i> " "<font color=red>Qt!</font></h2>");
  label->show();
  return myapp.exec();

}
