#include "mainwindow.h"
#include <QLabel>
#include <QLayout>
#include <QSpinBox>
#include <QDebug>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <QPainter>
#include<QKeyEvent>


MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {

    button = new QPushButton("Generate Particles");     //setup of labels
    label = new QLabel("Generate Particles- try the arrow keys!");
    spin_box = new QSpinBox;    //declaration of spinboxes
    second_box=new QSpinBox;
    layout = new QVBoxLayout;
    layout->addWidget(button);
    layout->addWidget(label);   //addition of widgets to layout
    layout->addWidget(spin_box);
    layout->addWidget(second_box);
    setLayout(layout);
    this->setFocus();   //bringing this class to the head every run cycle

    SetUpConnections(); //establishment of connections
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Left:
        spin_box->setValue(spin_box->value()+1); break;
    case Qt::Key_Right:
        spin_box->setValue(spin_box->value()-1); break;
    case Qt::Key_Up:
        second_box->setValue(second_box->value()+1); break;
    case Qt::Key_Down:
        second_box->setValue(second_box->value()-1); break;
    default:
        QWidget::keyPressEvent(event);
    }
  //   QCoreApplication::processEvents();
     return;
}
//playing around with the arrow key functions

void MainWindow::SetUpConnections() {
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(HandleButtonPush()));
    QObject::disconnect(this);  //helper function to establish middleman between functions in secondwindow and main
}

void MainWindow::HandleButtonPush() {
    std::stringstream sstr;
    sstr << "Generate Particles";   //labels
    std::string message = sstr.str();
    label->setText(QString::fromStdString(message));

   // This is where the spin_box value should be sent
   emit (TransmitValueOfFirstBox(spin_box->value()));   //transmission of values through middleman to secondwindow
   emit (TransmitValueOfSecondBox(second_box->value()));
}
