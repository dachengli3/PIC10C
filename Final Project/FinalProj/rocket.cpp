#include "rocket.h"
#include <sstream>
#include <QCoreApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <string>
#include <QFont>
#include <vector>
#include <algorithm>
#include <QKeySequence>
#include <QKeyEvent>
#include <QLineEdit>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QtWidgets>
#include <chrono>
#include <QPainter>
#include <QPixmap>
#include <QWidget>
#include <QDesktopWidget>
#include <conio.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>


void rocket::keyPressEvent(QKeyEvent *event)
{
        switch (event->key()) {
        case Qt::Key_0:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_1:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_2:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_3:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_4:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_5:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_6:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_7:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_8:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_9:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_A:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_B:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_C:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_D:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_E:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_F:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_G:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;
        case Qt::Key_H:
            if(event->key()==up)
                upFire=true;
            if(event->key()==left)
                leftFire=true;
            if(event->key()==right)
                rightFire=true;
            break;

        }
}

void rocket::keyReleaseEvent(QKeyEvent *event)
{
        switch (event->key()) {
        case Qt::Key_Left:
            leftFire=FALSE;
            break;
        case Qt::Key_Right:
            rightFire=FALSE;
            break;
        case Qt::Key_Up:
            upFire=FALSE;
            break;
        }
}

rocket::rocket(int level)
{
    level=5;//level choice
    // Draw the enemy
    //setRect(0, 0, 50, 50);

    // connect
    //scene=new QGraphicsScene();
    //scene.setSceneRect(-300, -300, 600, 600);
    //scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    //scene->addItem(this);//add collision here
    //QGraphicsView view(&scene);
    //view.setRenderHint(QPainter::Antialiasing);

    QString inFile = "Settings.txt";
    QFile inFile2(inFile);
    inFile2.open(QIODevice::ReadOnly);
    for(int i=0;i<5;i++)
    {
        QByteArray byteArray=inFile2.readLine();
        std::string hold=byteArray.toStdString();
        hold.erase(std::remove(hold.begin(), hold.end(), '\n'), hold.end());
        currentSettings.push_back(hold);
    }
    inFile2.close();
    QKeySequence sequence = QKeySequence(QString::fromStdString(currentSettings[0]));
    uint keyCode=sequence[0];
    up=keyCode;

    sequence=QKeySequence(QString::fromStdString(currentSettings[1]));
    keyCode=sequence[0];
    left=keyCode;

    sequence=QKeySequence(QString::fromStdString(currentSettings[2]));
    keyCode=sequence[0];
    right=keyCode;

    qDebug()<<up<<left<<right;

    QPixmap upFireImg("qrc:/C:/Users/dache/Downloads/rocket_Modified.png");
    QPainter *paint=new QPainter;
    paint->drawPixmap(100,100,100,100, upFireImg);
}

QRectF rocket::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}

QPainterPath rocket::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}

void rocket::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap upFireImg("qrc:/C:/Users/dache/Downloads/rocket_Modified.png");
    QPixmap leftFireImg("/Users/trinh/Desktop/prac/rocket.png");
    QPixmap rightFireImg("/Users/trinh/Desktop/prac/rocket.png");
    //QPainter painter(this);
    painter->drawPixmap(10,70,50,50, upFireImg);
}

void rocket::advance(int step)
{
    if(!step)
        return;
    auto MainTimerStart = std::chrono::system_clock::now();
    if(upFire)
    {
        MainTimerStart=std::chrono::system_clock::now();
        auto start = std::chrono::system_clock::now();
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        double time=elapsed_seconds.count();
        this->setPos(xPos, yPos+5*time*time);
        qDebug("Fuck this shit");
    }
    if(leftFire)
    {
        MainTimerStart=std::chrono::system_clock::now();
        auto start = std::chrono::system_clock::now();
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        double time=elapsed_seconds.count();
        this->setPos(xPos+5*time*time, yPos);
    }
    if(rightFire)
    {
        MainTimerStart=std::chrono::system_clock::now();
        auto start = std::chrono::system_clock::now();
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        double time=elapsed_seconds.count();
        this->setPos(xPos+5*time*time, yPos);
    }
    auto MainTimerEnd=std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = MainTimerEnd-MainTimerStart;
    double MainTime=elapsed_seconds.count();
    this->setPos(xPos, yPos-Gravity*MainTime*MainTime);
    //insert collision here
}


