#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <sstream>
#include <QPainter>
#include <QCoreApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <iostream>
#include <QDesktopWidget>
#include <string>
#include <QFont>
#include <vector>

SecondWindow::SecondWindow(QWidget *parent) : QWidget(parent){//,ui(new Ui::SecondWindow){
    text = new QLabel("Particles on a Board");
    text1= new QLabel("");  //setting labels
    QDesktopWidget *desktop = QApplication::desktop();
    QFont f( "Arial", 20, QFont::Cursive);
    text->setFont(f);   //putting label in the top of window
    screenWidth = desktop->width();
    layout = new QHBoxLayout();
    layout->addWidget(text);

    //std::stringstream sstr;
    this->showMaximized();  //maximizing window
    this->activateWindow();
    text->move((screenWidth-250)/2,30);
    text->setParent(this);
    text->show();   //displaying text
}


void SecondWindow::ChangeFirst(int first) {
    box1=first;
    if(box1==0) //getting 1st spinbox and storing
        text->setText(QString::fromStdString("The first box can't be 0!"));
}
void SecondWindow::ChangeSecond(int second) {
    box2=second;
    if(box2==0) //getting 2nd spinbox value and storing
        text->setText(QString::fromStdString("The second box can't be 0!"));    //conditionals if someone accidentally tries to send a 0
    text1->clear();
}

void SecondWindow::paintEvent(QPaintEvent *) {
     y=75;  //resetting dot location
     std::string message;
     QPainter painter(this);       //declaration of painter
     message="";
     text1->clear();    //clearing labels
     for(int i=0;i<box1;i++)
     {
         if(box2%2==0)  //calculating what numbers should be placed
         {
             starting=(-1*box2/2);
         }
         else{
             starting=(-1*(box2-1)/2);
         }
         x=(screenWidth+(2*starting)*60)/2; //setting x position of dots
         message="";
         for(int j=0; j<box2;j++)
         {
             holder.push_back((std::vector<QLabel*>()));    //adding new row of number labels
             // This sets the fill color and style.
                 painter.setBrush( QBrush(Qt::red) );
                 double width = 20.0;   //drawing simple black dot
                 double height = 20.0;
              QRectF rectangle(x, y, width, height);
              painter.drawEllipse(rectangle);
              if(box2%2==0)
              {
                 message=std::to_string(starting);  //setting value of label
              }
              else{
                 message=std::to_string(starting);
              }
              holder[i].push_back(new QLabel);
              holder[i][j]->setFixedWidth(50);  //declaring new label with numbers
              QFont f("Bavaria");
              f.setPointSize(10);
              f.setUnderline(TRUE);
              f.setWeight(QFont::Cursive);
              holder[i][j]->setFont(f); //playing around with font
              layout->addWidget(holder[i][j]);
              holder[i][j]->setText(QString::fromStdString(message));
              holder[i][j]->move(x,y+25);   //adjusting position
              holder[i][j]->setParent(this);
              holder[i][j]->show(); //showing label
              x+=60;
              starting++;   //incrementing number label
              message="";
         }
         y+=70; //adjust down for new line
     }
     painter.end();
}

SecondWindow::~SecondWindow()
{
    delete text;
    delete text1;
}
