#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet:public QObject ,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();
    int BulletLevel = 0;
public slots:
    void move();

};

#endif // BULLET_H
