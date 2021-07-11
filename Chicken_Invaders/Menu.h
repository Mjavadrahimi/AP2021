#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

class Menu : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene * MenuScene;
public:
    Menu();
    ~Menu();
public slots:

};

#endif // MENU_H
