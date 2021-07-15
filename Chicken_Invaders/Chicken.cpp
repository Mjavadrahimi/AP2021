#include "Chicken.h"
#include "Bird.h"

Chicken::Chicken(const int& pixelPer8MiliSec , QTimer *bTimer , const int& hp , QGraphicsItem *parent ,
                 int bX , int bY , QGraphicsScene *bScene, ScoreBoard * bScore) :
                    Bird(pixelPer8MiliSec,bTimer,hp,parent,bX,bY,bScene,bScore) ,cTime{0}
{
    connect(bTimer,SIGNAL(timeout()),this,SLOT(changePic()));
    setPixmap(QPixmap(":/images/babyChicken1.png"));
}

void Chicken::changePic()
{


    cTime++;
    switch ((cTime%39) /13) {
    case 0:
        setPixmap(QPixmap(":/images/babyChicken3.png"));
        break;
    case 1:
        setPixmap(QPixmap(":/images/babyChicken1.png"));
        break;
    default:
        setPixmap(QPixmap(":/images/babyChicken2.png"));
        break;
    }
}
