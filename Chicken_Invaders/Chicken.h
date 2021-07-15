#ifndef CHICKEN_H
#define CHICKEN_H
#include "Bird.h"

class Chicken : public Bird
{

private:
    int cTime;

public:
    Chicken(const int& pixelPer8MiliSec , QTimer *bTimer , const int& hp
            , QGraphicsItem *parent , int bX , int bY , QGraphicsScene *bScene, ScoreBoard * bScore,bool isEgg);

public slots:
    void changePic();

};

#endif // CHICKEN_H
