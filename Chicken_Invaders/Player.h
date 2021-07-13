#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMessageBox>

class Player : public QGraphicsPixmapItem
{
public:
    Player();
    void keyPressEvent(QKeyEvent * event);
    void DecreaseLife();
    int Life;
    int GetLife();
    QMessageBox *Message;


};

#endif // PLAYER_H
