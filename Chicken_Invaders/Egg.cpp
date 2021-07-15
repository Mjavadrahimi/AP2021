#include "Egg.h"

#include<QGraphicsScene>

Egg::Egg(const int& pixelPer8MiliSec , QTimer *bTimer , const int& hp
         , QGraphicsItem *parent , int bX , int bY , QGraphicsScene *bScene, ScoreBoard * bScore,bool isEgg) :
    Bird(pixelPer8MiliSec,bTimer,hp,parent,bX,bY,bScene,bScore,isEgg) , cTime{0}
{
    fsound = new QMediaPlayer();
    fsound->setMedia(QUrl("qrc:/music/eggboom.mp3"));
    isFried=false;
    setPixmap(QPixmap(":/images/egg1.png"));
     //connecting timer for moving egg down
    connect(bTimer,SIGNAL(timeout()),this,SLOT(moveDown()));
}

Egg::~Egg()
{
    delete fsound;
}

void Egg::moveDown()
{
    if(this->pos().y() >= 960){


        if(!isFried){
            isFried=true;
            setPixmap(QPixmap(":/images/egg2.png"));
            fsound->play();

        }
    }
    this->setPos(x(),y()+pixelPer8MiliSec);
    if(isFried){
        this->setPos(x(),y()-pixelPer8MiliSec);
    }
    if(isFried){
       cTime++;
       if(cTime==125){
           scene()->removeItem(this);
           delete this;
       }

    }
}
