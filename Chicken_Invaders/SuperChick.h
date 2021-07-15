#ifndef SUPERCHICK_H
#define SUPERCHICK_H
#include "Bird.h"
#include "Egg.h"
#include <QMediaPlayer>

class SuperChick : public Bird
{

private:
    int cTime;
    QTimer *timer;
    QGraphicsItem *par;
    QGraphicsScene *cScene;
    ScoreBoard *sB;
    QMediaPlayer *esound;

public:
    SuperChick(const int& pixelPer8MiliSec , QTimer *bTimer , const int& hp
          , QGraphicsItem *parent , int bX , int bY , QGraphicsScene *bScene, ScoreBoard * bScore);

    void dropEgg();

public slots:
    void changePic();

};


#endif // SUPERCHICK_H
