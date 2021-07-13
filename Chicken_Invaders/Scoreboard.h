#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include<QGraphicsSimpleTextItem>

class ScoreBoard : public QGraphicsTextItem
{
private:
    int score;

public:
    ScoreBoard(QGraphicsItem *parent = 0);
    void addScore(int point);

};

#endif // SCOREBOARD_H
