#include "mainwindow.h"
#include <QApplication>
#include "qferrers.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QFerrers* ferr = new QFerrers;


    QWidget* wid = new QWidget;

   QPushButton* left = new QPushButton("Left");
   QPushButton* right = new QPushButton("Right");

   QHBoxLayout* layout = new QHBoxLayout;

   layout->addWidget(left);
   layout->addWidget(right);


    QVBoxLayout* topbottom = new QVBoxLayout;

    topbottom->addWidget(ferr);
    topbottom->addLayout(layout);

    wid->setLayout(topbottom);

    w.setCentralWidget(wid);

  QObject::connect(right, SIGNAL(clicked()), ferr, SLOT(move_right()));



    return a.exec();
}
