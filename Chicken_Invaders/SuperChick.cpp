#include "SuperChick.h"

SuperChick::SuperChick(const int& pixelPer20MiliSec , QTimer *bTimer , const int& hp
             , QGraphicsItem *parent , int bX , int bY , QGraphicsScene *bScene): Bird(pixelPer20MiliSec,bTimer,hp,parent,bX,bY,bScene) ,cTime{0}
{

    setPixmap(QPixmap(":/images/superchicken6.png"));

    connect(bTimer,SIGNAL(timeout()),this,SLOT(changePic()));
}

void SuperChick::changePic()
{
    cTime++;
    switch (cTime%3) {
    case 0:
        setPixmap(QPixmap(":/images/superchicken6.png"));
        break;
    case 1:
        setPixmap(QPixmap(":/images/superchicken1.png"));
        break;
    case 2:
        setPixmap(QPixmap(":/images/superchicken2.png"));
        break;
    case 3:
        setPixmap(QPixmap(":/images/superchicken3.png"));
        break;
    case 4:
        setPixmap(QPixmap(":/images/superchicken4.png"));
        break;
    default:
        setPixmap(QPixmap(":/images/superchicken5.png"));
        break;
    }
}
