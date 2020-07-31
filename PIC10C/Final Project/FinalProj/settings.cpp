#include "settings.h"
#include "ui_settings.h"
#include <sstream>
#include <QPainter>
#include <QCoreApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <iostream>
#include <QDesktopWidget>
#include <string>
#include <QFont>
#include <vector>
#include <QKeyEvent>
#include <QSlider>
#include <QLineEdit>
#include <QPushButton>
#include <conio.h>
#include <iostream>
#include <QFile>
#include <fstream>
#include <QString>
#include <QTextStream>
#include <QDebug>



//void Settings::keyReleaseEvent(QKeyEvent *ev)
//{
//    main->setText("You Release Key " + ev->text());
//}
//for rocket ctrl

Settings::Settings(QWidget *parent) :QMainWindow(parent),
    ui(new Ui::Settings)
{
    //window settings
    ui->setupUi(this);
    main = new QLabel("Settings");
    QDesktopWidget *desktop = QApplication::desktop();
    QFont header( "Arial", 20);
    main->setFont(header);   //putting label in the top of window
    screenWidth = desktop->width();
    layout = new QHBoxLayout();
    //layout->addWidget(main);
    this->showMaximized();  //maximizing window
    this->activateWindow();
    main->move((screenWidth-200)/2,-150);
    main->setParent(this);
    main->show();

    //subheadings
    QFont subhead("Arial", 15);
    fieldHead= new QLabel("Field controls");  //setting labels
    controls=new QLabel("Rocket and player settings");
    controls->move(100,100);
    controls->setFont(subhead);
    controls->setParent(this);
    controls->show();
    fieldHead->move(100,500);
    fieldHead->setFont(subhead);
    fieldHead->setParent(this);
    fieldHead->show();
    leftCtrl=new QLabel(Left.toString());
    leftCtrl->setParent(this);
    leftCtrl->move(1000,400);
    leftCtrl->show();
    rightCtrl=new QLabel(Right.toString());
    rightCtrl->setParent(this);
    rightCtrl->move(1000,300);
    rightCtrl->show();
    upCtrl=new QLabel(Up.toString());
    upCtrl->setParent(this);
    upCtrl->move(1000,200);
    upCtrl->show();

    volCtrl=new QSlider();
    volCtrl->setOrientation(Qt::Horizontal);
    volCtrl->setFixedHeight(50);
    volCtrl->move((screenWidth-300)/2,700);
    volCtrl->setRange(0,100);
    volCtrl->setParent(this);
    volCtrl->show();

    changeUp=new QPushButton("Change Up Keybind");
    changeUp->setParent(this);
    changeUp->setFixedSize(150,50);
    changeUp->move(1000,250);
    changeUp->show();


    changeLeft=new QPushButton("Change Left Keybind");
    changeLeft->setFixedSize(150,50);
    changeLeft->move(800,320);
    changeLeft->setParent(this);
    changeLeft->show();


    changeRight=new QPushButton("Change Right Keybind");
    changeRight->setFixedSize(150,50);
    changeRight->move(1200,320);
    changeRight->setParent(this);
    changeRight->show();

    playerNameEdit=new QLineEdit;
    playerNameEdit->setParent(this);
    playerNameEdit->move(screenWidth/2, 800);
    playerNameEdit->setFixedSize(50, 100);
    playerNameEdit->show();

    backToMenu=new QPushButton("Return to Menu");
    backToMenu->setParent(this);
    backToMenu->move(screenWidth/2, 900);
    backToMenu->setFixedSize(50, 100);
    backToMenu->show();

    //connect functions
    connect(changeUp, SIGNAL(clicked()), this, SLOT(setUp()));
    connect(changeLeft, SIGNAL(clicked()), this, SLOT(setLeft()));
    connect(changeRight, SIGNAL(clicked()), this, SLOT(setRight()));
    connect(playerNameEdit, SIGNAL(textChanged(QString)), this, SLOT(setName(QString)));
    connect(volCtrl, SIGNAL(valueChanged(int)), this, SLOT(setVolume(int)));
    connect(backToMenu, SIGNAL(clicked()), this, SLOT(returnMenu()));
}

void Settings::setName(QString text){
    std::string holder=text.toStdString();
    currentSet[4]=holder;
};
void Settings::setVolume(int value){
    std::string hold=std::to_string(value);
    currentSet[3]=hold;
};

void Settings::returnMenu()
{
    //opening the file
    QString outFile = "Settings.txt";
    QFile outFile2(outFile);
    outFile2.open(QIODevice::WriteOnly);
    for(int i=0;i<currentSet.size();i++)
    {
        QByteArray byteArray(currentSet[i].c_str(), currentSet[i].length());
        outFile2.write(byteArray);
        outFile2.write("\n");
    }
    outFile2.close();
};


//rebinding controls
void Settings::setUp(){
    upRebind=true;
    main->setText("Press any Key to rebind up control");
};

void Settings::setRight(){
    rightRebind=true;
    main->setText("Press any Key to rebind right control");
};

void Settings::setLeft(){
    leftRebind=true;
    main->setText("Press any Key to rebind left control");
};

void Settings::keyPressEvent(QKeyEvent *ev)
{
    if (leftRebind) {
            leftRebind= false;
            Left = ev->key();
            QString holder=Left.toString();
            std::string hold="Left Keybind has been reset to: ";
            QString combined= QString::fromStdString(hold)+ev->key();
            main->setText(combined);
            leftCtrl->setText(Left.toString());
            QString temp=Left.toString();
            std::string tempString=temp.toStdString();
            currentSet[1]=tempString;
        }
    if (upRebind) {
            upRebind= false;
            Up = ev->key();
            QString holder=Up.toString();
            std::string hold="Up Keybind has been reset to: ";
            QString combined= QString::fromStdString(hold)+holder;
            main->setText(combined);
            upCtrl->setText(Up.toString());
            QString temp=Up.toString();
            std::string tempString=temp.toStdString();
            currentSet[0]=tempString;
        }
    if (rightRebind) {
            rightRebind= false;
            Right = ev->key();
            QString holder=Right.toString();
            std::string hold="Right Keybind has been reset to: ";
            QString combined= QString::fromStdString(hold)+holder;
            main->setText(combined);
            rightCtrl->setText(Right.toString());
            QString temp=Right.toString();
            std::string tempString=temp.toStdString();
            currentSet[2]=tempString;
        }
}
Settings::~Settings()
{
    delete ui;
}



