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
    Chicken * mrChicken;
    Player * p;
    int GameTime;
    std::vector<int> myVector;
    int IntoSecond; // convert QTimer repeat times to second
    bool connect_bird=false;
    QList<Bird *> myBirds;
    QTimer * gameTimer;
    QGraphicsRectItem * holder;
    QGraphicsScene * myScene;
    QGraphicsScene * myScene2;
    ScoreBoard * myScore;
    //SpaceShip * mySS;
    //ScoreBoard * ScoreBoard
public slots:
    void TimeSchedule();

};

#endif // GAMEENGINE_H
