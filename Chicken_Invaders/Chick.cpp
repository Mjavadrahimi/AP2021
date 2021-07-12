#include "Chick.h"

Chick::Chick(const int& pixelPer20MiliSec , QTimer *bTimer , const int& hp
             , QGraphicsItem *parent , int bX , int bY , QGraphicsScene *bScene): Bird(pixelPer20MiliSec,bTimer,hp,parent,bX,bY,bScene) ,cTime{0}
{

    setPixmap(QPixmap(":/images/chicken3.png"));

    connect(bTimer,SIGNAL(timeout()),this,SLOT(changePic()));
}

void Chick::changePic()
{
    cTime++;
    switch (cTime%3) {
    case 0:
        setPixmap(QPixmap(":/images/chicken3.png"));
        break;
    case 1:
        setPixmap(QPixmap(":/images/chicken1.png"));
        break;
    default:
        setPixmap(QPixmap(":/images/chicken2.png"));
        break;
    }
}
