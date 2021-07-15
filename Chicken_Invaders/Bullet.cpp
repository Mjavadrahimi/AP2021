#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Bird.h"
#include <QDebug>

Bullet::Bullet(const int& BulletLevel , QTimer *timer, int *kills): BulletLevel{BulletLevel}, kills{kills}
{

    dsound = new QMediaPlayer();
    //set picture for each level

        setPixmap(QPixmap(":/images/laser 1.png"));
    if(BulletLevel == 2)
        setPixmap(QPixmap(":/images/laser 2.png"));



    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

}

Bullet::~Bullet()
{
    delete dsound;

}


void Bullet::move()
{

    QList <QGraphicsItem *> collidingList = collidingItems();
    for(size_t i{0} ; i<collidingList.size();i++){
        if(typeid(*(collidingList)[i])==typeid (Chicken)){
           dsound->setMedia(QUrl("qrc:/music/deadchick.mp3"));
           dsound->play();

            //decrease hp
           (dynamic_cast<Bird *>(collidingList[i]))->damage();
            *kills+=4;
            scene()->removeItem(this);
            delete this;
            return;
        }
        if(typeid(*(collidingList)[i])==typeid (SuperChick)){
            dsound->setMedia(QUrl("qrc:/music/deadmorgh.mp3"));
            dsound->play();

            //decrease hp
            (dynamic_cast<Bird *>(collidingList[i]))->damage();
            *kills+=1;
            scene()->removeItem(this);
            delete this;
            return;
        }
        if(typeid(*(collidingList)[i])==typeid (Chick)){
            dsound->setMedia(QUrl("qrc:/music/deadmorgh.mp3"));
            dsound->play();

            //decrease hp
            (dynamic_cast<Bird *>(collidingList[i]))->damage();
            *kills+=2;
            scene()->removeItem(this);
            delete this;
            return;
        }
        if(typeid(*(collidingList)[i])==typeid (Egg)){
            //decrease hp
            (dynamic_cast<Bird *>(collidingList[i]))->damage();
            scene()->removeItem(this);
            delete this;
            return;
        }

            //remove bullet


    }
    //move up
    setPos(x(),y()-pixelPer8MiliSec);

    //check pos
    if(pos().y() + 20 < 0){
        scene()->removeItem(this);
        delete this;
    }
}
