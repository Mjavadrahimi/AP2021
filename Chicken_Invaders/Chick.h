#ifndef CHICK_H
#define CHICK_H
#include "Bird.h"

class Chick : public Bird
{

private:
    int cTime;

public:
    Chick(const int& pixelPer20MiliSec , QTimer *bTimer , const int& hp
          , QGraphicsItem *parent , int bX , int bY , QGraphicsScene *bScene);

public slots:
    void changePic();

};

#endif // CHICK_H
