#include "Egg.h"

#include<QGraphicsScene>

Egg::Egg(const int& pixelPer8MiliSec , QTimer *bTimer , const int& hp
         , QGraphicsItem *parent , int bX , int bY , QGraphicsScene *bScene, ScoreBoard * bScore) :
    Bird(pixelPer8MiliSec,bTimer,hp,parent,bX,bY,bScene,bScore) , cTime{0}
{
    isFried=false;
    setPixmap(QPixmap(":/images/egg1.png"));
    // connecting timer for moving egg down
    connect(bTimer,SIGNAL(timeout()),this,SLOT(moveDown()));
}

void Egg::moveDown()
{
    if(this->pos().x()==940){
        setPixmap(QPixmap(":/images/egg2.png"));
        isFried=true;
    }
    this->setPos(x(),y()+pixelPer8MiliSec);

    if(isFried){
       cTime++;
       if(cTime==125){
           scene()->removeItem(this);
       }

    }
}
