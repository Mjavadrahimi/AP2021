#include "MainMenu.h"
#include "ui_MainMenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_StartButton_clicked()
{
    //hide();
    //GameEngine *game = new GameEngine();
    //game->show;
}


void MainMenu::on_SettingButton_2_clicked()
{
    hide();
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

