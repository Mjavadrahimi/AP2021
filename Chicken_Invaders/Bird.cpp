#include "Bird.h"
#include <QGraphicsScene>
#include <QDebug>
Bird::Bird(const int& pixelPer8MiliSec , QTimer *bTimer , const int& hp , QGraphicsItem *parent,int bX,int bY ,QGraphicsScene *bScene
           ,  ScoreBoard * bScore,bool isEgg) : QObject() , QGraphicsPixmapItem(parent), hp{hp} , time{0} ,isEgg{isEgg}
{
    this->pixelPer8MiliSec=pixelPer8MiliSec;
    this->bTimer=bTimer;
    this->bScore=bScore;
    isLive=true;
    if(hp == 1 )
        point =5;
    else
        point =10;
    bScene->addItem(this);
//    connect(p1,SIGNAL(timeout()),this,SLOT(changePic()));
    setPos(bX,bY);

}

bool Bird::getIsLive()
{
    return isLive;
}

void Bird::damage(int dmg)
{
    if(dmg==1){
        hp--;
    }else{
        hp-=2;
    }

    qInfo()<<hp;
    if(hp<=0){
        qInfo()<<"12333";
        // add points to scoreboard
        bScore->addScore(point);
        if(point==10){
            ChickMeet *cM=new ChickMeet(bTimer);
            cM->setPos(x()+45,y()+45);
            scene()->addItem(cM);
        }
        scene()->removeItem(this);
        if(isEgg){
            delete this;
            return;
        }


        isLive=false;
    }
}

void Bird::changePic()
{

}

void Bird::moveDown()
{
    if(time<310){
        this->setPos(x() , y()+pixelPer8MiliSec);
    }

    ++time;
}

void Bird::dropEgg()
{

}
