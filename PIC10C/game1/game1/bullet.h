#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>


class bullet: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    bullet(QGraphicsItem *parent = nullptr);

public slots:
    void move();
};

#endif // BULLET_H
