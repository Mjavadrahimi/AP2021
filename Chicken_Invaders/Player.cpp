#include "Player.h"
#include "Bullet.h"


Player::Player()
{
    setPixmap(QPixmap(":/images/ship.png"));
     Life = 3;

}

void Player::keyPressEvent(QKeyEvent * event){
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
        Bullet *bullet = new Bullet();
        bullet->setPos(x()+57,y()-20);
        scene()->addItem(bullet);
    }

}

void Player::DecreaseLife()
{
    //destoroy player

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
