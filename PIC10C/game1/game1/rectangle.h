#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include "enemy.h"
#include <vector>
#include <QPixmap>

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    //std::vector<enemy> currentStore;
    void stored();
public slots:
    void spawn();

private:
    int buildHeight=600;
//    QPixmap *enemy1=new QPixmap();
//    QPixmap *enemy2=new QPixmap();
//    QPixmap *enemy3=new QPixmap();
};

#endif // RECTANGLE_H
