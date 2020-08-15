#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>
#include <QLabel>
#include <vector>
#include <QLayout>
#include<QPainter>
#include <QtGui>


class SecondWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SecondWindow(QWidget *parent = nullptr);
    int screenWidth;    //calculation of size of screen (for centering)
    int save;
    ~SecondWindow();

signals:

public slots:
    void ChangeFirst(int first);    //functions for changes of spinboxes
    void ChangeSecond(int second);
    void paintEvent(QPaintEvent *); //actual function that paints stuff
private:
    QLabel* text = nullptr;
    QLabel* text1 = nullptr;    //declaration of labels
    std::vector<std::vector<QLabel*>>holder;    //a vector to store the numbers beneath the dots
    QHBoxLayout* layout = nullptr;  //layout
    int x=20;   //default values for spinboxes and draw positions
    int y=20;
    int box1=0;
    int box2=0;
    int starting=0;
};

#endif // SECONDWINDOW_H
