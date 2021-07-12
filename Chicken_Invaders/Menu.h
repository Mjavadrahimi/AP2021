#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "Buttons.h"
class Menu : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene * MenuScene;
    QTimer *myTimer;
    Buttons * B1;
    Buttons * B2;
    Buttons * B3;
    Buttons * B4;
    Buttons * B5;
public:
    Menu();
    ~Menu();
};

#endif // MENU_H
