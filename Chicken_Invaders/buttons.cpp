#include "Buttons.h"
#include <QString>
Buttons::Buttons(int ButtNumber,QGraphicsScene * myScene){
    QString s;
    int Xloc,Yloc;
    switch (ButtNumber) {
        case 1:
            s=":/images/TestButton.png";
            Xloc=750;
            Yloc=250;
            break;
        case 2:
            s=":/images/TestButton.png";
            Xloc=750;
            Yloc=400;
            break;
        case 3:
            s=":/images/TestButton.png";
            Xloc=750;
            Yloc=550;
            break;
        case 4:
            s=":/images/TestButton.png";
            Xloc=750;
            Yloc=700;
            break;
    }
    setPixmap(QPixmap(s));
    myScene->addItem(this);
    setPos(Xloc,Yloc);
}
Buttons::~Buttons(){
}
void Buttons::mousePress(QGraphicsSceneMouseEvent *press){
    delete this;
    exit(1);
}

