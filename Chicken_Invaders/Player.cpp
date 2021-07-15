#include "Player.h"
#include "Bullet.h"

#include <QCursor>
#include <QObject>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>



Player::Player(QGraphicsItem *parent , QTimer *timer,int *kills): QObject() , QGraphicsPixmapItem(parent)
{
    //msound = new QMediaPlayer();
    //msound->setMedia(QUrl("qrc:/music/yum.mp3"));
    bsound = new QMediaPlayer();
    bsound->setMedia(QUrl("qrc:/music/fire.mp3"));
    explosionTime=0;
    setPixmap(QPixmap(":/images/ship.png"));
    isLive=true;
    Life = 3;
    pTimer=timer;
    this->kills=kills;
    // connect timer to setposition
    connect(timer,SIGNAL(timeout()),this,SLOT(setposition()));
    //setFocus();
}

Player::~Player()
{
    delete bsound;
}

void Player::keyPressEvent(QKeyEvent * event){
    //if spaceship isnt in explosion phase
    if(isLive){

        //need to change
//        if (event->key() == Qt::Key_Left && pos().x() != 0 ){
//            setPos(x()-20,y());
//        }

//        if(event->key() == Qt::Key_Right && pos().x() != 1670){
//            setPos(x()+20,y());
//        }

//        if(event->key() == Qt::Key_Up && pos().y() != 0){
//            setPos(x(),y()-20);
//        }

//        if(event->key() == Qt::Key_Down && pos().y() <= 880){
//            setPos(x(),y()+20);
//        }

        if(event->key() == Qt::Key_Space){
            //set sound
            bsound->play();


            //create bullet
            auto bullet = new Bullet(BulletLevel,pTimer,kills);
            scene()->addItem(bullet);
            bullet->setPos(this->pos().x()+57,this->pos().y()-20);
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

//void Player::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    qInfo()<<"pooffff";
//    if(event->button()== Qt::LeftButton && isLive){
//        //create bullet
//        Bullet *bullet = new Bullet(BulletLevel,pTimer);
//        bullet->setPos(x()+57,y()-20);
//        scene()->addItem(bullet);
//    }
//}


void Player::setposition()
{
    setFocus();
    if(isLive){
        QList <QGraphicsItem *> collidingList = collidingItems();
        for(size_t i{0} ; i<collidingList.size();i++){
            if(typeid(*(collidingList)[i])==typeid (Chicken)){
                //Explosion and decrease hp
                this->DecreaseLife();
            }
            if(typeid(*(collidingList)[i])==typeid (Chick)){
                //Explosion and decrease hp
                this->DecreaseLife();
            }
            if(typeid(*(collidingList)[i])==typeid (SuperChick)){
                //Explosion and decrease hp
                this->DecreaseLife();
            }
            if(typeid(*(collidingList)[i])==typeid (Egg)){
                //Explosion and decrease hp
                scene()->removeItem((collidingList)[i]);
                delete (collidingList)[i];
                this->DecreaseLife();
            }
            else if(typeid(*(collidingList)[i])==typeid (ChickMeet)){
                //set sound
                //msound->play();


                //add to meat score
                scene()->removeItem((collidingList)[i]);
                delete (collidingList)[i];
            }
            else if(typeid(*(collidingList)[i])==typeid (Gift)){
                this->SetBulletLevel(2);
            }
        }

        this->setPos(QCursor::pos().x(),QCursor::pos().y());
    }
    else{
        explosionTime++;
        if(explosionTime==160){
            setPixmap(QPixmap(":/images/ship.png"));
            isLive=true;
            explosionTime=0;
            QCursor::setPos(840,800);
            setPos(840,800);

        }
    }
}
