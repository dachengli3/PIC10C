#include "settings.h"
#include "rocket.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QtWidgets>
#include <QPixmap>
#include <QGraphicsItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    Settings w;
    w.show();
    rocket *rocketTest=new rocket(0);
    rocketTest->setPos(50,50);
    rocketTest->show();
    scene.addItem(rocketTest);
    scene.setSceneRect(-300, -300, 600, 600);
    //QPixmap *test=new QPixmap("qrc:/C:/Users/dache/Downloads/rocket_Modified.png");
    //QGraphicsSimpleTextItem *test=new QGraphicsSimpleTextItem("fuck");
    //scene.addItem(test);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    //rocketTest->show();
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
//! [4] //! [5]
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
//! [5] //! [6]
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Rocket Game"));
    view.resize(1000, 1000);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.show();
    //rocketTest->show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(1000 / 33);

    return a.exec();
}
