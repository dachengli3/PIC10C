#include "mainwindow.h"
#include <QLabel>
#include <QLayout>
#include <QSpinBox>
#include <QDebug>
#include <iostream>
#include <string>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    button = new QPushButton("Push Me!");
    label = new QLabel("You have not pushed the button");
    spin_box = new QSpinBox;
    layout = new QVBoxLayout;
    layout->addWidget(button);
    layout->addWidget(label);
    layout->addWidget(spin_box);
    setLayout(layout);

    SetUpConnections();
}

void MainWindow::SetUpConnections() {
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(HandleButtonPush()));
}

void MainWindow::HandleButtonPush() {
    std::stringstream sstr;
    sstr << "You have pushed the button: " << ++times_button_was_pushed << " times!";
    std::string message = sstr.str();
   label->setText(QString::fromStdString(message));

   // This is where the spin_box value should be sent
   emit TransmitValueOfSpinBox(spin_box->value());
    //label->setText("You have pushed the button!");
}
