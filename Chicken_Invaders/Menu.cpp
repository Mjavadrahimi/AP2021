#include "Menu.h"
#include "Buttons.h"
Menu::Menu() : QGraphicsView(){
    // Create Menu Scene
    MenuScene = new QGraphicsScene();
    MenuScene->setSceneRect(0,0,1800,1000);
    setScene(MenuScene);
    // Set Menu BackGround
    setBackgroundBrush(QBrush(QImage(":/images/FirstTestLoadingScreen.png")));

    // New Button
    Buttons * B1=new Buttons(1,MenuScene);
    // Continue Button
    Buttons * B2=new Buttons(2,MenuScene);
    // Setting Button
    Buttons * B3=new Buttons(3,MenuScene);
    // Setting Button
    Buttons * B4=new Buttons(4,MenuScene);
    // Fix Menu Scene and disable Scrollbars
    setFixedSize(1800,1000);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}
Menu::~Menu(){
    delete MenuScene;
}
