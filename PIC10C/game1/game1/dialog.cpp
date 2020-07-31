#include "dialog.h"
#include "ui_dialog.h"
#include "game.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog){
    ui->setupUi(this);

    //adding images
    //come back to this later!!!
//    QPixmap rocket("/Users/trinh/Desktop/prac/rocket.png");
//    ui->label_pic->setPixmap(rocket);
//    ui->label_pic->setMask(rocket.mask());

    //Background image
    QPixmap backImage("/Users/trinh/Desktop/prac/Galaxy.jpeg");
    backImage = backImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, backImage);
    this->setPalette(palette);

    //Create menu widget
    QWidget *menu = new QWidget;
    QPushButton *settingPushButton = new QPushButton(tr("SETTINGS"));
    //maybe change the button color later!!!!
    settingPushButton->setStyleSheet("background-color: blue;");
    QPushButton *instructionsPushButton = new QPushButton(tr("INSTRUCTIONS"));
    instructionsPushButton->setStyleSheet("background-color: blue;");
    QPushButton *playPushButton = new QPushButton(tr("PLAY"));
    playPushButton->setStyleSheet("background-color: blue;");
    QPushButton *closePushButton = new QPushButton(tr("EXIT"));
    closePushButton->setStyleSheet("background-color: blue;");
    QHBoxLayout *menuPageLayout = new QHBoxLayout(menu);
    menuPageLayout->addWidget(settingPushButton);
    menuPageLayout->addWidget(instructionsPushButton);
    menuPageLayout->addWidget(playPushButton);
    menuPageLayout->addWidget(closePushButton);

    //Create settings widget
    QWidget *settings = new QWidget;
    QPushButton *back1 = new QPushButton(tr("back"));
    QHBoxLayout *settingsPageLayout = new QHBoxLayout(settings);
    settingsPageLayout->addWidget(back1);

    //Create the instructions widget
    QWidget *instructions = new QWidget;
    QPushButton *back2 = new QPushButton(tr("back"));
    QHBoxLayout *instructionsPageLayout = new QHBoxLayout(instructions);
    instructionsPageLayout->addWidget(back2);

    //Starting game page
//    QWidget *startGame = new QWidget;
//    Game *game = new Game();
//    QHBoxLayout *gameLayout = new QHBoxLayout(startGame);
//    gameLayout->addWidget(game);

    _stackedWidget = new QStackedWidget;
    _stackedWidget->addWidget(menu);
    _stackedWidget->addWidget(settings);
    _stackedWidget->addWidget(instructions);
//    _stackedWidget->addWidget(startGame);

    QHBoxLayout *centrallayout = new QHBoxLayout;
    centrallayout->addWidget(_stackedWidget);
    setLayout(centrallayout);

    connect(settingPushButton, SIGNAL(clicked()), this, SLOT(goToSettings()));
    connect(back1, SIGNAL(clicked()), this, SLOT(goToMenu()));
    connect(closePushButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(instructionsPushButton, SIGNAL(clicked()), this, SLOT(goToInstructions()));
    connect(back2, SIGNAL(clicked()), this, SLOT(goToMenu()));
//    connect(playPushButton, SIGNAL(clicked()), this, SLOT(playGame()));

    //Background music
    QMediaPlayer* music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/alien-spaceship_daniel_simion.mp3"));
    music->play();

}

void Dialog::goToSettings(){
   _stackedWidget->setCurrentIndex(1);
}

void Dialog::goToMenu(){
   _stackedWidget->setCurrentIndex(0);
}

void Dialog::goToInstructions(){
    _stackedWidget->setCurrentIndex(2);
}

//void Dialog::playGame(){
//    _stackedWidget->setCurrentIndex(3);
//}

Dialog::~Dialog()
{
    delete ui;
}
