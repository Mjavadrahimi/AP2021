#include "Player.h"
#include "Bullet.h"

#include <QCursor>
#include <QObject>
#include <QWidget>
#include <QMouseEvent>



Player::Player(QGraphicsItem *parent , QTimer *timer): QObject() , QGraphicsPixmapItem(parent)
{
    explosionTime=0;
    setPixmap(QPixmap(":/images/ship.png"));
    isLive=true;
    Life = 3;
    pTimer=timer;
    // connect timer to setposition
    connect(timer,SIGNAL(timeout()),this,SLOT(setposition()));
}

void Player::keyPressEvent(QKeyEvent * event){
    //if spaceship isnt in explosion phase
    if(isLive){
        //need to change
        if (event->key() == Qt::Key_Left && pos().x() != 0 ){
            setPos(x()-20,y());
        }

        if(event->key() == Qt::Key_Right && pos().x() != 1670){
            setPos(x()+20,y());
        }

        if(event->key() == Qt::Key_Up && pos().y() != 0){
            setPos(x(),y()-20);
        }

        if(event->key() == Qt::Key_Down && pos().y() <= 880){
            setPos(x(),y()+20);
        }

        if(event->key() == Qt::Key_Space){
            //create bullet
            Bullet *bullet = new Bullet(BulletLevel,pTimer);
            bullet->setPos(x()+57,y()-20);
            scene()->addItem(bullet);
        }
    }
}

void Player::DecreaseLife()
{
    //destoroy player
    isLive=false;
    Life--;


    //check life if life < 1 player lose
    if (Life < 1)
    {
        Message = new QMessageBox;
        //message->setText(" YOU LOSE x( \n SCORE: " + QString::number(GameEngine->getPoints()) + " ");
        Message->setWindowTitle("GAME OVER!");
        Message->setIcon(QMessageBox::Information);
        int respond = Message->exec();
        if(respond == QMessageBox::Ok)
        {
            //have problem*****
            exit(0);
        }

    }
}

int Player::GetLife()
{
    return Life;
}

void Player::SetBulletLevel(int BulletLevel)
{
    this->BulletLevel=BulletLevel;
}

int Player::GetBulletLevel()
{
    return BulletLevel;
}

void Player::mousePressEvent(QMouseEvent *event)
{
    if(event->button()== Qt::LeftButton && isLive){
        //create bullet
        Bullet *bullet = new Bullet(BulletLevel,pTimer);
        bullet->setPos(x()+57,y()-20);
        scene()->addItem(bullet);
    }
}


void Player::setposition()
{
    if(isLive){
        QList <QGraphicsItem *> collidingList = collidingItems();
        for(size_t i{0} ; i<collidingList.size();i++){
            if(typeid((collidingList)[i])==typeid (Bird)){
                //Explosion and decrease hp
                this->DecreaseLife();
            }
            else if(typeid((collidingList)[i])==typeid (ChickMeet)){
                //add to meat score
            }
            else if(typeid((collidingList)[i])==typeid (Gift)){
                this->SetBulletLevel(2);
            }
        }

        this->setPos(QCursor::pos().x(),QCursor::pos().y());
    }
    else{
        explosionTime++;
        if(explosionTime==80){
            setPixmap(QPixmap(":/images/ship.png"));
            isLive=true;
            setPos(840,800);
            explosionTime=0;
        }
    }
}
