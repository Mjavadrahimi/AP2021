#ifndef BIRD_H
#define BIRD_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Scoreboard.h"
#include "ChickMeet.h"
#include <QGraphicsScene>

class Bird : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int hp;
    int time;
    int point;
    ScoreBoard *bScore;
protected:
    QTimer *bTimer;
    QGraphicsScene Scene;
    int cTimer;
    int pixelPer8MiliSec;
    int xx,yy;
public:
    Bird(const int& pixelPer8MiliSec , QTimer *bTimer , const int& hp , QGraphicsItem *parent ,
         int bX , int bY , QGraphicsScene *bScene , ScoreBoard * bScore);

public slots:
    void damage();
    virtual void changePic();
    virtual void moveDown();
};

#endif // BIRD_H
