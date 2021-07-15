#ifndef CHICK_H
#define CHICK_H
#include "Bird.h"
#include "Egg.h"
#include <QMediaPlayer>

class Chick : public Bird
{

private:
    int cTime;
    QTimer *timer;
    QGraphicsItem *par;
    QGraphicsScene *cScene;
    ScoreBoard *sB;
    int a;
    QMediaPlayer *esound;
public:
    Chick(const int& pixelPer8MiliSec , QTimer *bTimer , const int& hp
          , QGraphicsItem *parent , int bX , int bY , QGraphicsScene *bScene, ScoreBoard * bScore);

    void dropEgg();

public slots:
    void changePic();

};

#endif // CHICK_H
