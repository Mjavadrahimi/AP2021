#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include "Bird.h"
//#include "Gift.h"
//#include "SpaceShip.h"
//#include "Scoreboard.h"
class GameEngine : public QGraphicsView
{
    Q_OBJECT
public:
    GameEngine(int);
    ~GameEngine();
    void PlayGame();
    void AddBirds();
private:
    int level;
    QList<Bird *> * myBirds;
    QTimer * gameTime;
    //SpaceShip * mySS;
    //ScoreBoard * ScoreBoard
public slots:
    void TimeSchedule();

};

#endif // GAMEENGINE_H
