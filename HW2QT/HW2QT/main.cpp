#include "mainwindow.h"
#include "secondwindow.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <QObject>
#include <vector>
#include <QMainWindow>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);      //declaration of main and second windows
   SecondWindow* second=new SecondWindow;
   // QWidget* wid = new QWidget;
   second->show();
   MainWindow w;
   (w).show();
   w.setWindowTitle("Set number of boxes");

   second->setWindowTitle("Number of boxes display");   //assn of names
   QObject::connect(&w, SIGNAL(TransmitValueOfFirstBox(int)), second, SLOT(ChangeFirst(int)));
   QObject::connect(&w, SIGNAL(TransmitValueOfSecondBox(int)), second, SLOT(ChangeSecond(int)));    //function to set spinboxes across classes
   return a.exec();
}
