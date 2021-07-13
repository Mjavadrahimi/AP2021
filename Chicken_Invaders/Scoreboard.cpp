#include "Scoreboard.h"
#include <QFont>
ScoreBoard::ScoreBoard(QGraphicsItem *parent) : QGraphicsTextItem(parent) , score{0}
{
    setPlainText(QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",25));
}

void ScoreBoard::addScore(int point)
{
    score+=point;
    setPlainText(QString::number(score));
}
