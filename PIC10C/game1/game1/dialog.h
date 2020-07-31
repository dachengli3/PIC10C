#ifndef DIALOG_H
#define DIALOG_H

#include"game.h"

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QAbstractButton>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QStackedWidget>
#include <QPalette>
#include <QPixmap>
#include <QMediaPlayer>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void goToSettings();
    void goToMenu();
    void goToInstructions();
//    void playGame();

private:
    Ui::Dialog *ui;
    QStackedWidget *_stackedWidget;
};

#endif // DIALOG_H
