#include "SettingWindow.h"
#include "ui_SettingWindow.h"

SettingWindow::SettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
}

SettingWindow::~SettingWindow()
{
    delete ui;
}




void SettingWindow::on_BackButton_clicked()
{
    hide();
    delete ui;
    MainMenu *menu = new MainMenu();
    menu->show();
}



