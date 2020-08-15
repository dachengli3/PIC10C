#ifndef STOREDITEMS_H
#define STOREDITEMS_H

#include <QObject>
#include <QGraphicsItem>

class StoredItems: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    StoredItems(QGraphicsItem *parent = nullptr);
    void setMovementSpeed(int speed);
    void changeLevel(int level);
    int getLevel();
public slots:
    void move();

private:
    int playerPosX;
    int playerPosY;
};

#endif


