#include "qferrers.h"
#include "ui_qferrers.h"
#include <QPainter>
#include<QKeyEvent>

QFerrers::QFerrers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QFerrers)
{
    ui->setupUi(this);

    x = 20.0;
    y = 20.0;

}

void QFerrers::move_right() {

    x += 10.0;
    repaint();
    QCoreApplication::processEvents();
}



void QFerrers::paintEvent(QPaintEvent *) {

    QPainter painter(this);

        // This sets the fill color and style.
        painter.setBrush( QBrush(Qt::black) );


        // Let’s just draw a simple circular dot.  It will be inscribed in a rectangle.
        double width = 20.0;
        double height = 20.0;
        QRectF rectangle(x, y, width, height);
        painter.drawEllipse(rectangle);

}

//void QFerrers::keyPressEvent(QKeyEvent *event){
//    switch (event->key()) {
//    case Qt::Key_Left:
//        x -= 10.0; break;
//    case Qt::Key_Right:
//        x += 10.0; break;
//    case Qt::Key_Up:
//        y -= 10.0; break;
//    case Qt::Key_Down:
//        y += 10.0; break;
//    default:
//        QWidget::keyPressEvent(event);
//    }
//     repaint();
//     QCoreApplication::processEvents();

//     return; }




QFerrers::~QFerrers()
{
    delete ui;
}
