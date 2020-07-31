#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <vector>

extern Game * game;

//constructor
bullet::bullet(QGraphicsItem *parent): QObject (), QGraphicsRectItem (parent){
    //size of the bullet/ drawing bullet
    setRect(0,0,10,50);

    //connecting a timer to move() so bullet shoots every so often
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    //for every 50 milliseconds bullet will move
    timer->start(50);
}

void bullet::move(){
    //checking if it hits enemy
   QList<QGraphicsItem *> colliding_items = collidingItems();
   foreach(QGraphicsItem * i , colliding_items)
   {
       enemy * item= dynamic_cast<enemy *>(i);
       game->storedEnemyLevel.push_back(item->getLevel());
       int size=game->storedEnemyLevel.size();
           if((game->storedEnemyLevel[size-1]==4))
           {
               for(int i=0;i<size;i++)
               {
                    int level=game->storedEnemyLevel[size-1];
                    game->score->increase(10*(5-level));
                    game->storedEnemyLevel.clear();
               }
           }

           if(size>2)
           {
               int level=(game->storedEnemyLevel[size-1]);
               if(level==(game->storedEnemyLevel[size-1]))
               {
                   if(level==(game->storedEnemyLevel[size-2]))
                   {
                       std::vector<int>::iterator it1;
                       it1=game->storedEnemyLevel.end();
                       it1--;
                       it1--;
                       game->storedEnemyLevel.erase(it1,game->storedEnemyLevel.end());
                       game->score->increase(10*(5-level));
                   }
               }
           }
       }

   //if one of colliding items is an enemy, destroy bullet and enemy
   for (int i=0, n = colliding_items.size(); i<n; i++){
    //remove them both (still on heap)
    scene()->removeItem(colliding_items[i]);
    scene()->removeItem(this);

    //delete them both from the heap
    delete colliding_items[i];
    delete this;
   }

    //just want to move bullet up, aka "shooting
    setPos(x(),y()-10);
    if (pos().y() + rect().height()< 0){
        //cleaning up the bullet memory when it reaches the top of window
        scene()->removeItem(this);
        delete this;
    }
}
