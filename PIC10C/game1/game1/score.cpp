#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem (parent){
    //start score at 0
    score = 0;

    //drawing score
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",20));
}

void Score::increase(int amt){
    score+=amt;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}

