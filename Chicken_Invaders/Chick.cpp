#include "Chick.h"
#include <QDebug>
Chick::Chick(const int& pixelPer8MiliSec , QTimer *bTimer , const int& hp
             , QGraphicsItem *parent , int bX , int bY , QGraphicsScene *bScene, ScoreBoard * bScore,bool isEgg)
                : Bird(pixelPer8MiliSec,bTimer,hp,parent,bX,bY,bScene,bScore,isEgg) ,cTime{0}
{

    timer = bTimer;
    par=parent;
    cScene=bScene;
    sB=bScore;
    connect(bTimer,SIGNAL(timeout()),this,SLOT(changePic()));
    setPixmap(QPixmap(":/images/chicken3.png"));

}

void Chick::dropEgg()
{
    Egg *cE = new Egg(1,timer,1,par,this->pos().x()+15,this->pos().y()+90,cScene,sB,true);
    scene()->addItem(cE);

    //esound->play();
}

void Chick::changePic()
{
    cTime++;
    switch ((cTime%39)/13) {
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
