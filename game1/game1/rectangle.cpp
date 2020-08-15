#include "rectangle.h"
#include "bullet.h"
#include "game.h"
#include "enemy.h"
#include <vector>
#include <QKeyEvent>
#include <QLabel>
#include <QGraphicsScene>
//#include <QDebug>

extern Game * game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    //setPixmap()
}

void Player::keyPressEvent(QKeyEvent *event){
    //for debugging purposes
    //qDebug() << "rectangle class knows that you pressed a key";

    //using arrow keys to control player`s movement
    //can ONLY go left or right
    if (event->key() == Qt::Key_Left){
        //checking to see if it has hit the left wall yet
        if (pos().x() > 0){
            setPos(x()-10,y());
            //disp stored enemies
            //std::vector<enemy> tempStored= game->storedEnemyLevel;
            std::vector<QLabel> dispStorage;
            int size=game->storedEnemyLevel.size();
            for(int i=0;i<size;i++)
            {
                int enemyType=game->storedEnemyLevel[i];
                if(enemyType==1)
                {
                    QPixmap enemyDisp=QPixmap();  //DONT STORE ON HEAP
                    QLabel enemyStore;
                    enemyStore.setPixmap(enemyDisp);
                    enemyStore.move(x(), y());
                    enemyStore.show();
                }//add others as needed
            }
        }
    }
    else if (event->key() == Qt::Key_Right){
        //checking to see if it has hit the right wall yet
        //800 is the width of the window
        if (pos().x()+100 < 800){
            setPos(x()+10, y());
            //std::vector<enemy> tempStored= game->storedEnemyLevel;
            std::vector<QLabel> dispStorage;
            int size=game->storedEnemyLevel.size();
            for(int i=0;i<size;i++)
            {
                int enemyType=game->storedEnemyLevel[i];
                if(enemyType==1)
                {
                    QPixmap enemyDisp=QPixmap();  //DONT STORE ON HEAP
                    QLabel enemyStore;
                    enemyStore.setPixmap(enemyDisp);
                    enemyStore.move(x(), y());
                    enemyStore.show();
                }//add others as needed
            }
        }
    }

//    //spacebar is used to shoot at enemy
//    else if (event->key() == Qt::Key_Space) {
//        //creating bullet
//        //creating bullet pointer
//        bullet *b = new bullet();
//        //qDebug() << "bullet created";
//        b->setPos(x(),y());
//        scene()->addItem(b);
//    }


    //collecting the objects

}

void Player::spawn(){
    //create an enemy
    enemy *e = new enemy();
    scene()->addItem(e);


}

