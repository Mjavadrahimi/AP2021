#ifndef BIRD_H
#define BIRD_H

#include<QObject>
#include<QGraphicsPixmapItem>
#include<QTimer>


class Bird : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int hp;
    int pixelPer20MiliSec;
    int time;
public:
    Bird(const int& pixelPer20MiliSec , QTimer *bTimer , const int& hp , QGraphicsItem *parent , int bX , int bY , QGraphicsScene *bScene);

public slots:
    void damage();
    void moveDown();
};

#endif // BIRD_H
