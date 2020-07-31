#ifndef ENEMY_H
#define ENEMY_H


#include <QObject>
#include <QGraphicsItem>


class enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    enemy(QGraphicsItem *parent = nullptr);
    //enemy()=default;
    void setMovementSpeed(int speed);
    void changeLevel(int level);
    int getLevel();
public slots:
    void move();

private:
    int enemyType;
    int moveSpeed=5;
    int level;
};


#endif // ENEMY_H
