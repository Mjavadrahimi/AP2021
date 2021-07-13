#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Bird.h"

Bullet::Bullet(const int& BulletLevel , QTimer *timer): BulletLevel{BulletLevel}
{
    //set picture for each level
    if(BulletLevel == 1)
        setPixmap(QPixmap(":/images/laser 1.png"));
    if(BulletLevel == 2)
        setPixmap(QPixmap(":/images/laser 2.png"));



    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

}


void Bullet::move()
{
    QList <QGraphicsItem *> collidingList = collidingItems();
    for(size_t i{0} ; i<collidingList.size();i++){
        if(typeid(*(collidingList)[i])==typeid (Bird)){
            //decrease hp
            (dynamic_cast<Bird *>(collidingList[i]))->damage();

            //remove bullet
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    //move up
    setPos(x(),y()-pixelPer8MiliSec);

    //check pos
    if(pos().y() + 20 < 0){
        scene()->removeItem(this);
        delete this;
    }
}
