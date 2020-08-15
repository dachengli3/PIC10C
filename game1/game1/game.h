#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QFont>
#include "rectangle.h" //player
#include "score.h"
#include <vector>
#include "enemy.h"
#include "health.h"

class Game: public QGraphicsView{
public:
    Game(QWidget *parent = nullptr);

    QGraphicsScene *scene;
    Player *player;
    Score *score;
    std::vector<int> storedEnemyLevel;
    //Health *health;

public slots:
    void start();
    int playerX;
    int playerY;

private:

};

#endif // GAME_H
