#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet:public QObject ,
        public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int BulletLevel = 0;
    int pixelPer8MiliSec=4;
public:
    Bullet(const int& BulletLevel,QTimer *timer);

public slots:
    void move();

};

#endif // BULLET_H
