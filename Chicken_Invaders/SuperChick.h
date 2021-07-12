#ifndef SUPERCHICK_H
#define SUPERCHICK_H
#include "Bird.h"

class SuperChick : public Bird
{

private:
    int cTime;

public:
    SuperChick(const int& pixelPer20MiliSec , QTimer *bTimer , const int& hp
          , QGraphicsItem *parent , int bX , int bY , QGraphicsScene *bScene);

public slots:
    void changePic();

};


#endif // SUPERCHICK_H
