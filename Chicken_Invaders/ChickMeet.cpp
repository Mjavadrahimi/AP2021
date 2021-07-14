#include "ChickMeet.h"

ChickMeet::ChickMeet(QTimer *cTimer)
{
    setPixmap(QPixmap(":/images/chickmeat.png"));
    connect(cTimer,SIGNAL(timeout()),this,SLOT(moveDown()));
}

void ChickMeet::moveDown()
{
    if(this->pos().x()==940){
        scene()->removeItem(this);
        delete this;
    }
    this->setPos(x(),y()-+pixelPer8MiliSec);
}
