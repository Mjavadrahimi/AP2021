#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include "Chicken.h"
#include "SuperChick.h"
#include "Chick.h"
#include "Egg.h"
#include <QMediaPlayer>

class Bullet:public QObject ,
        public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int BulletLevel = 0;
    int pixelPer8MiliSec=4;
    int *kills;
    QMediaPlayer *dsound;
public:
    Bullet(const int& BulletLevel,QTimer *timer,int *kills);
    ~Bullet();

public slots:
    void move();

};

#endif // BULLET_H
