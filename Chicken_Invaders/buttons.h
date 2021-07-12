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
    bool pressButt;
private:
    QString s;
    int Xloc,Yloc;
    int ButtNumber;
    QGraphicsScene *myScene;
    // picture p = ..
};

#endif // BUTTONS_H
