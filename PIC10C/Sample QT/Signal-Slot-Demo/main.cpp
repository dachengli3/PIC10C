#include "mainwindow.h"
#include "secondwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    SecondWindow second_win;
    second_win.show();

    // This is where the connect statement should go.
    QObject::connect(&w, SIGNAL(TransmitValueOfSpinBox(int)), &second_win, SLOT(ChangeText(int)));

    return a.exec();
}
