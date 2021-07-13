#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QMessageBox>
#include "gameengine.h"
#include "SettingWindow.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:

    void on_StartButton_clicked();

    void on_SettingButton_2_clicked();

    void on_ExitButton_3_clicked();

    void on_CreatorsButton_4_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
