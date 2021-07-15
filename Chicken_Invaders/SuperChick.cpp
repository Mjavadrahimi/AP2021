#include "SuperChick.h"

SuperChick::SuperChick(const int& pixelPer8MiliSec , QTimer *bTimer , const int& hp
             , QGraphicsItem *parent , int bX , int bY , QGraphicsScene *bScene, ScoreBoard * bScore)
             : Bird(pixelPer8MiliSec,bTimer,hp,parent,bX,bY,bScene,bScore) ,cTime{0}
{

    timer = bTimer;
    par=parent;
    cScene=bScene;
    sB=bScore;
    connect(bTimer,SIGNAL(timeout()),this,SLOT(changePic()));
    setPixmap(QPixmap(":/images/superchicken6.png"));

//    connect(bTimer,SIGNAL(timeout()),this,SLOT(changePic()));
}

void SuperChick::dropEgg()
{
    Egg *cE = new Egg(1,timer,1,par,this->pos().x()+15,this->pos().y()+90,cScene,sB);
    scene()->addItem(cE);
}

void SuperChick::changePic()
{
    cTime++;
    switch ((cTime%36)/6) {
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
