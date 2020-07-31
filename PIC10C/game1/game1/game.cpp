#include "game.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
//#include "storeditems.h"

Game::Game(QWidget *parent){
    //creating the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,700);//size of window of game
    //make the newly created scene the scene to visualize
    setScene(scene);
    //this just hides the scroll bar from the side, not best way
    //to deal with the bullets because they are still continuously
    //moving upwards and not stopping
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,700);

    //creating player
    player = new Player();
    //player->setRect(0,0,100,100);
    player->setPos(400,600);
    //StoredItems *objectHolder=new StoredItems;
//    objectHolder->setPos(400,550);
//    scene->addItem(objectHolder);
    //making rectangle more focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    //adding player to the scene
    scene->addItem(player);

    //creating the score board
    score = new Score();
    scene->addItem(score);
    //health = new Health();
    //health->setPos(health->x(), health->y()+25);
    //scene->addItem(health);

    //spawn enemies, shooting at enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

}

void Game::start(){
    scene->clear();
}


