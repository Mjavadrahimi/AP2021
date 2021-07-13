#include "Bird.h"
#include <QGraphicsScene>
Bird::Bird(const int& pixelPer8MiliSec , QTimer *bTimer , const int& hp , QGraphicsItem *parent,int bX,int bY ,QGraphicsScene *bScene
           ,  ScoreBoard * bScore) : QObject() , QGraphicsPixmapItem(parent), hp{hp} , pixelPer8MiliSec{pixelPer8MiliSec} , time{0}
{
    this->bTimer=bTimer;
    this->bScore=bScore;
    if(hp == 1 )
        point =5;
    else
        point =10;
    bScene->addItem(this);
    setPos(bX,bY);
}

void Bird::damage()
{
    --hp;
    if(hp==0){
        // add points to scoreboard
        bScore->addScore(point);
        if(point==10){
            ChickMeet *cM=new ChickMeet(bTimer);
            cM->setPos(x()+45,y()+45);
            scene()->addItem(cM);
        }
        scene()->removeItem(this);
    }
}

void Bird::moveDown()
{
    if(time<310){
        this->setPos(x() , y()+pixelPer8MiliSec);
    }
    ++time;
}
