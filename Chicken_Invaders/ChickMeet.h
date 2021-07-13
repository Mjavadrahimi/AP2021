#ifndef CHICKMEET_H
#define CHICKMEET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>


class ChickMeet : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int pixelPer8MiliSec=4;

public:
    ChickMeet(QTimer *bTimer);

public slots:
    void moveDown();
};

#endif // CHICKMEET_H
