#ifndef EGG_H
#define EGG_H

#include <Bird.h>
#include <QMediaPlayer>


class Egg : public Bird
{

private:
    int cTime;
    bool isFried;
    QMediaPlayer *fsound;


public:
    Egg(const int& pixelPer8MiliSec , QTimer *bTimer , const int& hp
        , QGraphicsItem *parent , int bX , int bY , QGraphicsScene *bScene, ScoreBoard * bScore,bool isEgg);
    ~Egg();

public slots:
    void moveDown();
};

#endif // EGG_H
