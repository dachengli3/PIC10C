#ifndef ROCKET_H
#define ROCKET_H

#include <QWidget>
#include <QLayout>
#include <QPainter>
#include <string>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsItem>
#include <QObject>
#include <vector>


class rocket: public QGraphicsItem
{
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void advance(int step) override;
public:
    rocket(int n);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    std::vector<std::string> currentSettings;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    uint up;
    uint left;
    uint right;


private:
    double xVeocity;
    double yVelocity;
    double xAcc;
    double yAcc;
    double xPos;
    double yPos;
    double Gravity=9.8;
    double rocketFire;
    bool leftFire=false;
    bool rightFire=false;
    bool upFire=false;
    double time=0;
};

#endif // ROCKET_H
