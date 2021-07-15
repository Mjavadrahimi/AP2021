#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include<QGraphicsSimpleTextItem>

class ScoreBoard : public QGraphicsTextItem
{
private:
    int score;
    int typeS;
    ScoreBoard *Score;

public:

    ScoreBoard(int typeScore,QGraphicsItem *parent = 0);
    ScoreBoard(int typeScore,ScoreBoard *sb,QGraphicsItem *parent = 0);
    void addScore(int point);
    int getScore();
};

#endif // SCOREBOARD_H
