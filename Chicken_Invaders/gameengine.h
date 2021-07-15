#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QList>
#include <QApplication>
#include <QTimer>
#include <vector>
#include "Scoreboard.h"
#include "Bird.h"
#include "Chick.h"
#include "Chicken.h"
#include "SuperChick.h"
#include "Player.h"
#include "Bullet.h"
#include "Gift.h"
#include <QGraphicsPixmapItem>
#include "MainMenu.h"
#include <QMessageBox>
//#include "Gift.h"
//#include "SpaceShip.h"
//#include "Scoreboard.h"
class GameEngine: public QGraphicsView
{
    Q_OBJECT
public:
    GameEngine(int);
    ~GameEngine();
    void AddBirds();
    void ChooseEggSpawn();
    void DropEgg();
private:
    int level;
    Player * p;
    int GameTime;
    std::vector<int> myVector;
    int IntoSecond; // convert QTimer repeat times to second
    bool connect_bird=false;
    QList<Bird *> myBirds;
    QTimer * gameTimer;
    QGraphicsRectItem * holder;
    QGraphicsScene * myScene;
    Bullet *b1;
    ScoreBoard * myScore;
    int *kills;
    bool isLeveled;
    ScoreBoard * lives;
    ScoreBoard *meatScore;
    QGraphicsPixmapItem *scoreBoard;
    QGraphicsPixmapItem *meatscoreBoard;
    QMessageBox *Message;
    //SpaceShip * mySS;
    //ScoreBoard * ScoreBoard
public slots:
    void TimeSchedule();

};

#endif // GAMEENGINE_H
