#ifndef QFERRERS_H
#define QFERRERS_H

#include <QWidget>
#include <QtGui>

namespace Ui {
class QFerrers;
}

class QFerrers : public QWidget
{
    Q_OBJECT

public slots:
    void move_right();

public:
    explicit QFerrers(QWidget *parent = 0);
    ~QFerrers();

    void paintEvent(QPaintEvent *);
   // void keyPressEvent(QKeyEvent *event);

private:
    Ui::QFerrers *ui;

    double x;
    double y;

};

#endif // QFERRERS_H
