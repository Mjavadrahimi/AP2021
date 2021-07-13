#ifndef GIFT_H
#define GIFT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>

class Gift : public QObject , public QGraphicsPixmapItem
{

    Q_OBJECT

private:
    int pixelPer8MiliSec=4;

public:
    Gift(QTimer *bTimer , const int& x, QGraphicsScene *scene);

public slots:
    void moveDown();
};

#endif // GIFT_H
