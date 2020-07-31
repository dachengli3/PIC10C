#include "storeditems.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <vector>

extern Game * game;


StoredItems::StoredItems(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    std::vector<enemy> tempStored= game->storedEnemyLevel;
    playerPosX=game->player->x();
    playerPosY=game->player->y();
    for(int i=0;i<tempStored.size();i++)
    {
        int enemyType=tempStored[i].getLevel();
        if(enemyType==1)
        {
            QPixmap enemyDisp=QPixmap();  //DONT STORE ON HEAP
            //enemyDisp.
        }//add others as needed
    }
}

void StoredItems::move(){
    //movement of enemy
    setPos(playerPosX, playerPosY);
}

