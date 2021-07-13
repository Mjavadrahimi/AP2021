#include "Bird.h"
#include<QGraphicsScene>
Bird::Bird(const int& pixelPer20MiliSec , QTimer *bTimer , const int& hp , QGraphicsItem *parent,int bX,int bY ,QGraphicsScene *bScene)
    : QObject() , QGraphicsPixmapItem(parent), pixelPer20MiliSec{pixelPer20MiliSec} , hp{hp} , time{0}
{
    bScene->addItem(this);
    setPos(bX,bY);
    connect(bTimer,SIGNAL(timeout()),this,SLOT(movedown()));
}

void Bird::damage()
{
    --hp;
    if(hp==0){
        scene()->removeItem(this);
    }
}

void Bird::moveDown()
{
    if(time<124){
        this->setPos(x() , y()+pixelPer20MiliSec);
    }
    ++time;
}
