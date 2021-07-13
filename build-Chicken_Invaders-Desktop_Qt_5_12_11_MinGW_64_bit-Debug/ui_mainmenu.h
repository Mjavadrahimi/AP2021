/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QPushButton *StartButton;
    QPushButton *SettingButton_2;
    QPushButton *ExitButton_3;
    QPushButton *CreatorsButton_4;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(1800, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainMenu->sizePolicy().hasHeightForWidth());
        MainMenu->setSizePolicy(sizePolicy);
        MainMenu->setMinimumSize(QSize(1800, 1000));
        MainMenu->setMaximumSize(QSize(1800, 1000));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe MDL2 Assets"));
        font.setPointSize(10);
        MainMenu->setFont(font);
        MainMenu->setCursor(QCursor(Qt::PointingHandCursor));
        MainMenu->setMouseTracking(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainMenu->setWindowIcon(icon);
        MainMenu->setStyleSheet(QString::fromUtf8("background-image: url(:/images/FirstTestLoadingScreen.png);"));
        MainMenu->setDocumentMode(false);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        StartButton = new QPushButton(centralwidget);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));
        StartButton->setGeometry(QRect(825, 560, 151, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(14);
        font1.setItalic(false);
        StartButton->setFont(font1);
        StartButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.166 rgba(255, 255, 0, 255), stop:0.333 rgba(0, 255, 0, 255), stop:0.5 rgba(0, 255, 255, 255), stop:0.666 rgba(0, 0, 255, 255), stop:0.833 rgba(255, 0, 255, 255), stop:1 rgba(255, 0, 0, 255));\n"
"color: rgb(170, 170, 0);"));
        StartButton->setIconSize(QSize(700, 700));
        SettingButton_2 = new QPushButton(centralwidget);
        SettingButton_2->setObjectName(QString::fromUtf8("SettingButton_2"));
        SettingButton_2->setGeometry(QRect(825, 670, 151, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font2.setPointSize(14);
        SettingButton_2->setFont(font2);
        SettingButton_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.166 rgba(255, 255, 0, 255), stop:0.333 rgba(0, 255, 0, 255), stop:0.5 rgba(0, 255, 255, 255), stop:0.666 rgba(0, 0, 255, 255), stop:0.833 rgba(255, 0, 255, 255), stop:1 rgba(255, 0, 0, 255));\n"
"color: rgb(170, 170, 0);"));
        ExitButton_3 = new QPushButton(centralwidget);
        ExitButton_3->setObjectName(QString::fromUtf8("ExitButton_3"));
        ExitButton_3->setGeometry(QRect(825, 780, 151, 61));
        ExitButton_3->setFont(font2);
        ExitButton_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.166 rgba(255, 255, 0, 255), stop:0.333 rgba(0, 255, 0, 255), stop:0.5 rgba(0, 255, 255, 255), stop:0.666 rgba(0, 0, 255, 255), stop:0.833 rgba(255, 0, 255, 255), stop:1 rgba(255, 0, 0, 255));\n"
"color: rgb(170, 170, 0);"));
        CreatorsButton_4 = new QPushButton(centralwidget);
        CreatorsButton_4->setObjectName(QString::fromUtf8("CreatorsButton_4"));
        CreatorsButton_4->setGeometry(QRect(60, 870, 40, 40));
        CreatorsButton_4->setCursor(QCursor(Qt::ArrowCursor));
        CreatorsButton_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.166 rgba(255, 255, 0, 255), stop:0.333 rgba(0, 255, 0, 255), stop:0.5 rgba(0, 255, 255, 255), stop:0.666 rgba(0, 0, 255, 255), stop:0.833 rgba(255, 0, 255, 255), stop:1 rgba(255, 0, 0, 255));"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../Downloads/infoo.png"), QSize(), QIcon::Normal, QIcon::Off);
        CreatorsButton_4->setIcon(icon1);
        CreatorsButton_4->setIconSize(QSize(40, 40));
        MainMenu->setCentralWidget(centralwidget);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "Chicken Invaders", nullptr));
        StartButton->setText(QApplication::translate("MainMenu", "Start", nullptr));
        SettingButton_2->setText(QApplication::translate("MainMenu", "Setting", nullptr));
        ExitButton_3->setText(QApplication::translate("MainMenu", "Exit", nullptr));
        CreatorsButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
