#include "Gift.h"

Gift::Gift(QTimer *bTimer , const int& x, QGraphicsScene *scene)
{
    setPixmap(QPixmap(":/images/gift.png"));
    scene->addItem(this);
    setPos(x,-60);
    connect(bTimer,SIGNAL(timeout()),this,SLOT(moveDown()));

}

void Gift::moveDown()
{
    if(this->pos().x()==940){
        scene()->removeItem(this);
        delete this;
    }
    this->setPos(x(),y()+pixelPer8MiliSec);
}
