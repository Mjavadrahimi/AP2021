#include "SettingWindow.h"
#include "ui_settingwindow.h"
#include "MainMenu.h"

SettingWindow::SettingWindow(QWidget *parent ) :
    QMainWindow(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
    QGuiApplication *app;
    app->setOverrideCursor(QCursor(QPixmap(":/images/fork.png")));
}

SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::on_pushButton_clicked()
{
    delete this;
    MainMenu *menu = new MainMenu();
    menu->show();

}
