#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet()
{
    //set picture for each level
    if(BulletLevel == 0)
        setPixmap(QPixmap(":/images/laser 1.png"));
    if(BulletLevel == 1)
        setPixmap(QPixmap(":/images/laser 2.png"));


    //connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //start timer
    timer->start(25);
}

void Bullet::move()
{
    //move up
    setPos(x(),y()-125);

    //check pos
    if(pos().y() + 20 < 0){
        scene()->removeItem(this);
        delete this;
    }
}
