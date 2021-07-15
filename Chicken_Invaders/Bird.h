#ifndef BIRD_H
#define BIRD_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Scoreboard.h"
#include "ChickMeet.h"
#include <QGraphicsScene>

class Bird : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int hp;
    int time;
    int point;
    bool isLive;
    ScoreBoard *bScore;
protected:
    QTimer *bTimer;
    int cTimer;
    int pixelPer8MiliSec;
public:

    Bird(const int& pixelPer8MiliSec , QTimer *bTimer , const int& hp , QGraphicsItem *parent ,
         int bX , int bY , QGraphicsScene *bScene , ScoreBoard * bScore);
     bool getIsLive();

public slots:
    void damage();
    virtual void changePic();
    virtual void moveDown();
    virtual void dropEgg();
};

#endif // BIRD_H
