#include "Menu.h"
#include "Buttons.h"

Menu::Menu() : QGraphicsView(){
    // Create Menu Scene
    MenuScene = new QGraphicsScene();
    MenuScene->setSceneRect(0,0,1800,1000);
    setScene(MenuScene);
    // Set Menu BackGround
    setBackgroundBrush(QBrush(QImage(":/images/FirstTestLoadingScreen.png")));
    // Continue Button
    B1=new Buttons(1,MenuScene);
    // New Button
    B2=new Buttons(2,MenuScene);
    // Setting Button
    B3=new Buttons(3,MenuScene);
    // Store Button
    B4=new Buttons(4,MenuScene);
    // Directors Button
    B5=new Buttons(5,MenuScene);
    // Fix Menu Scene and disable Scrollbars
    setFixedSize(1800,1000);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
Menu::~Menu(){
    delete MenuScene;
    delete myTimer;
    delete B1;
    delete B2;
    delete B3;
    delete B4;
    delete B5;
}
