QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bird.cpp \
    Bullet.cpp \
    Buttons.cpp \
    Chick.cpp \
    ChickMeet.cpp \
    Chicken.cpp \
    Egg.cpp \
    GameEngine.cpp \
    Gift.cpp \
    MainMenu.cpp \
    Player.cpp \
    Scoreboard.cpp \
    SettingWindow.cpp \
    SuperChick.cpp \
    main.cpp

HEADERS += \
    Bird.h \
    Bullet.h \
    Buttons.h \
    Chick.h \
    ChickMeet.h \
    Chicken.h \
    Egg.h \
    GameEngine.h \
    Gift.h \
    MainMenu.h \
    Player.h \
    Scoreboard.h \
    SettingWindow.h \
    SuperChick.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

FORMS += \
    mainmenu.ui \
    settingwindow.ui
