#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QObject>
#include <QTimer>
#include <QMouseEvent>
#include "Bird.h"
#include "ChickMeet.h"
#include "Chicken.h"
#include "Chick.h"
#include "SuperChick.h"
#include "Egg.h"
#include "Gift.h"



class Player : public QObject , public QGraphicsPixmapItem
{

    Q_OBJECT

private:
    int Life;
    int BulletLevel;
    QTimer *pTimer;
    QMessageBox *Message;
    bool isLive;
    int explosionTime;
    int *kills;

public:
    Player(QGraphicsItem *parent , QTimer *timer,int *kills);
    void keyPressEvent(QKeyEvent * event);
    void DecreaseLife();
    int GetLife();
    void SetBulletLevel(int BulletLevel);
    int GetBulletLevel();
    //void mousePressEvent(QGraphicsSceneMouseEvent * event);


public slots:
    void setposition();
};

#endif // PLAYER_H
