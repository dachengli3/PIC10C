#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> //this gives us the random function

extern Game * game;

//constructor
enemy::enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //setting random positions of enemy
    int random_number = rand() % 700;
    enemyType=rand() % level + 1;
    setPos(random_number, 0);

    setPixmap(QPixmap(":/images/brick.png"));

    int chanceOfFour=rand() % 700;
    if(chanceOfFour==4)
    {
        enemyType=4;
    }
    //size of enemy
    if(enemyType==1)
    {
        //setImage here
    }
    if(enemyType==2)
    {
        //set img here
    }
    if(enemyType==3)
    {
        moveSpeed=10;
    //set image here
    }
    if(enemyType==4){
        moveSpeed=50;
    }

    //connect some stuff
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    //for every 50 milliseconds bullet will move
    timer->start(50);
}

void enemy::setMovementSpeed(int speed)
{
    moveSpeed=speed;
}

void enemy::changeLevel(int newLevel)
{
    if(newLevel>=4)
        return;
    level=newLevel;
}

int enemy::getLevel()
{
    return level;
}

void enemy::move(){
    //movement of enemy
    setPos(x(),y()+moveSpeed);

    //destroy enemy when it goes out of screen
    if (pos().y() > 600){
        //decreasing health
        //game->health->decrease();

        //cleaning up the bullet memory when it reaches the top of window
        scene()->removeItem(this);
        delete this;
    }

}
