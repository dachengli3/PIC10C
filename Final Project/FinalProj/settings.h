#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <vector>
#include <QLayout>
#include <QPainter>
#include <QtGui>
#include <string>
#include <QSlider>
#include <QLineEdit>
#include <QPushButton>
#include <QKeyEvent>
#include <iostream>
#include <fstream>

namespace Ui {
class Settings;
}

class Settings : public QMainWindow
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();
    int screenWidth;    //calculation of size of screen (for centering)
    int save;
    QLabel* main = nullptr;
    std::vector<std::string> currentSet={"W", "A", "D", "50", "Player 1"};

protected:
    void keyPressEvent(QKeyEvent *event);
    //void keyReleaseEvent(QKeyEvent *event);

public slots:
    void setName(QString text);
    void setVolume(int value);

    void setUp();
    void setRight();
    void setLeft();
    void returnMenu();

private:
    QHBoxLayout* layout = nullptr;
    Ui::Settings *ui;

    QLabel* fieldHead=nullptr;
    QLabel* controls=nullptr;
    QLabel* leftCtrl=nullptr;
    QLabel* rightCtrl=nullptr;
    QLabel* upCtrl=nullptr;

    //creation of buttons and default controls
    QKeySequence Up=Qt::Key_W;
    QKeySequence Left=Qt::Key_A;
    QKeySequence Right=Qt::Key_D;

    QLineEdit* playerNameEdit=nullptr;

    bool upRebind=false;
    bool leftRebind=false;
    bool rightRebind=false;

    //inital values
    int vol=50;
    QString playerName="Player";

    QSlider* volCtrl=nullptr;
    QPushButton* changeUp=nullptr;
    QPushButton* changeLeft=nullptr;
    QPushButton* changeRight=nullptr;
    QPushButton* backToMenu=nullptr;
};

#endif // SETTINGS_H
