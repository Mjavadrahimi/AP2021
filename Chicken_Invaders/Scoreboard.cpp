#include "Scoreboard.h"
#include <QFont>
ScoreBoard::ScoreBoard(int typeScore , QGraphicsItem *parent) : QGraphicsTextItem(parent) , score{0}
{
    if(typeScore==3) score=3;
    typeS=typeScore;
    setPlainText(QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",25));
}

ScoreBoard::ScoreBoard(int typeScore, ScoreBoard *sb, QGraphicsItem *parent): QGraphicsTextItem(parent) , score{0}
{
    Score=sb;
    typeS=typeScore;
    setPlainText(QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",25));
}

void ScoreBoard::addScore(int point)
{
    score+=point;
    if(typeS==2 && score==30){
        score=0;
        Score->addScore(50);
    }

    setPlainText(QString::number(score));
}

int ScoreBoard::getScore()
{
    return score;
}
