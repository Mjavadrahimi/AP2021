#ifndef BUTTONS_H
#define BUTTONS_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Buttons :public QGraphicsPixmapItem
{
public:
    Buttons(int,QGraphicsScene *);
    ~Buttons();
    void mousePress(QGraphicsSceneMouseEvent *);
};

#endif // BUTTONS_H
