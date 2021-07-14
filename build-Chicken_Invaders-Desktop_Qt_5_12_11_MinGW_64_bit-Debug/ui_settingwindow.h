/********************************************************************************
** Form generated from reading UI file 'settingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINDOW_H
#define UI_SETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QSlider *volume;
    QSlider *sens;
    QGraphicsView *volumePic;
    QGraphicsView *volumePic_2;

    void setupUi(QMainWindow *SettingWindow)
    {
        if (SettingWindow->objectName().isEmpty())
            SettingWindow->setObjectName(QString::fromUtf8("SettingWindow"));
        SettingWindow->resize(1800, 1000);
        SettingWindow->setMinimumSize(QSize(1800, 1000));
        SettingWindow->setMaximumSize(QSize(1800, 1000));
        SettingWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/images/FirstTestLoadingScreen.png);"));
        centralwidget = new QWidget(SettingWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(825, 780, 151, 61));
        QFont font;
        font.setPointSize(14);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.166 rgba(255, 255, 0, 255), stop:0.333 rgba(0, 255, 0, 255), stop:0.5 rgba(0, 255, 255, 255), stop:0.666 rgba(0, 0, 255, 255), stop:0.833 rgba(255, 0, 255, 255), stop:1 rgba(255, 0, 0, 255));\n"
"color: rgb(170, 170, 0);"));
        volume = new QSlider(centralwidget);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setGeometry(QRect(820, 440, 160, 31));
        volume->setOrientation(Qt::Horizontal);
        sens = new QSlider(centralwidget);
        sens->setObjectName(QString::fromUtf8("sens"));
        sens->setGeometry(QRect(820, 600, 160, 31));
        sens->setOrientation(Qt::Horizontal);
        volumePic = new QGraphicsView(centralwidget);
        volumePic->setObjectName(QString::fromUtf8("volumePic"));
        volumePic->setGeometry(QRect(740, 430, 50, 50));
        volumePic->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-image: url(:/images/volumeasli.png);\n"
"font: 14pt \"MS Shell Dlg 2\";"));
        volumePic_2 = new QGraphicsView(centralwidget);
        volumePic_2->setObjectName(QString::fromUtf8("volumePic_2"));
        volumePic_2->setGeometry(QRect(740, 590, 50, 50));
        volumePic_2->setStyleSheet(QString::fromUtf8("background-image: url(:/images/mouse1.png);\n"
"border:none;"));
        SettingWindow->setCentralWidget(centralwidget);

        retranslateUi(SettingWindow);

        QMetaObject::connectSlotsByName(SettingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SettingWindow)
    {
        SettingWindow->setWindowTitle(QApplication::translate("SettingWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("SettingWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingWindow: public Ui_SettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
