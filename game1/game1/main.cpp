#include <QApplication>
#include "game.h"

Game *game;

/**
 * There is alot wrong with this code....
 * The backgrounf image is not fixed
 * connecting the game with the menu is hard... and not
 * doing what it is suppose to be doing...
 * when i connect the game it crashes the whole game....
 * might be a memory leak
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->show();


    return a.exec();
}
