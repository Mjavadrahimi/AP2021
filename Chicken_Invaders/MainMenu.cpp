#include "MainMenu.h"
#include "ui_MainMenu.h"
#include <QMediaPlayer>

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    PlayMusic();
    ui->setupUi(this);
    QGuiApplication *app;
    app->setOverrideCursor(QCursor(QPixmap(":/images/fork.png")));
}

MainMenu::~MainMenu()
{
    delete ui;
    delete music;

}

void MainMenu::PlayMusic()
{
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/music/music.mp3"));
    music->play();
    music->setVolume(70);

}

void MainMenu::on_StartButton_clicked()
{
    //hide();
    //GameEngine *game = new GameEngine();
    //game->show;
}


void MainMenu::on_SettingButton_2_clicked()
{
    delete this;
    SettingWindow *setting = new SettingWindow();
    setting->show();
}


void MainMenu::on_ExitButton_3_clicked()
{
    exit(0);
}


void MainMenu::on_CreatorsButton_4_clicked()
{
    auto message = new QMessageBox;
    message->setText(" Mohammad javad Rahimi \n Alireza Rezaii \n Mohammad amin Rabbanifar");
    message->setWindowTitle("Creators");
    message->setIcon(QMessageBox::Information);
    message->exec();
}

