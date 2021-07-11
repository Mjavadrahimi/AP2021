#include "Menu.h"

Menu::Menu() : QGraphicsView(){
    // Create Menu Scene
    MenuScene = new QGraphicsScene();
    MenuScene->setSceneRect(0,0,1800,1000);
    setScene(MenuScene);
    // Set Menu BackGround
    setBackgroundBrush(QBrush(QImage(":/images/FirstTestLoadingScreen.png")));
    // Fix Menu Scene and disable Scrollbars
    setFixedSize(1800,1000);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
Menu::~Menu() {
    delete MenuScene;
}
