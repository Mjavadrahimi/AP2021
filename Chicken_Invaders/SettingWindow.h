#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QMainWindow>
#include "MainMenu.h"

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = nullptr );
    ~SettingWindow();

private slots:
    void on_pushButton_clicked();


    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::SettingWindow *ui;
};

#endif // SETTINGWINDOW_H
