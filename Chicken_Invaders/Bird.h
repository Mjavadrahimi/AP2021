#ifndef BIRD_H
#define BIRD_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Scoreboard.h"
#include "ChickMeet.h"


class Bird : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int hp;
    int time;
    int point;
    QTimer *bTimer;
    ScoreBoard *bScore;
protected:
    int pixelPer8MiliSec;
public:
    Bird(const int& pixelPer8MiliSec , QTimer *bTimer , const int& hp , QGraphicsItem *parent ,
         int bX , int bY , QGraphicsScene *bScene , ScoreBoard * bScore);

public slots:
    void damage();
    virtual void moveDown();
};

#endif // BIRD_H
