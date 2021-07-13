QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bird.cpp \
    Buttons.cpp \
    Chick.cpp \
    Chicken.cpp \
    GameEngine.cpp \
    Menu.cpp \
    Scoreboard.cpp \
    SuperChick.cpp \
    main.cpp

HEADERS += \
    Bird.h \
    Buttons.h \
    Chick.h \
    Chicken.h \
    GameEngine.h \
    Menu.h \
    Scoreboard.h \
    SuperChick.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
