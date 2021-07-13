#include "Chicken.h"
#include "Bird.h"

Chicken::Chicken(const int& pixelPer8MiliSec , QTimer *bTimer , const int& hp , QGraphicsItem *parent ,
                 int bX , int bY , QGraphicsScene *bScene, ScoreBoard * bScore) :
                    Bird(pixelPer8MiliSec,bTimer,hp,parent,bX,bY,bScene,bScore) ,cTime{0}
{

    setPixmap(QPixmap(":/images/babyChicken3.jpg"));

    connect(bTimer,SIGNAL(timeout()),this,SLOT(changePic()));
}

void Chicken::changePic()
{
    cTime++;
    switch (cTime%3) {
    case 0:
        setPixmap(QPixmap(":/images/babyChicken3.jpg"));
        break;
    case 1:
        setPixmap(QPixmap(":/images/babyChicken1.png"));
        break;
    default:
        setPixmap(QPixmap(":/images/babyChicken2.png"));
        break;
    }
}
