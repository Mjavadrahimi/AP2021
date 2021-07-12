#include "Buttons.h"
#include <QString>
#include "GameEngine.h"
Buttons::Buttons(int ButtNumber,QGraphicsScene * myScene):ButtNumber(ButtNumber),myScene(myScene){
    pressButt=false;
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
        case 5:
            s=":/images/TestButton.png";
            Xloc=100;
            Yloc=900;
            break;
    }
    setPixmap(QPixmap(s));
    myScene->addItem(this);
    setPos(Xloc,Yloc);
}
Buttons::~Buttons(){
}
void Buttons::mousePress(QGraphicsSceneMouseEvent *press){
    pressButt=true;
    switch(ButtNumber){
        case 1:{
            //continue game
            myScene->clear();
            //GameEngine * mygame = new GameEngine();
            break;
        }
        case 2:
            //new game

            break;
        case 3:
            //game setting

            break;
        case 4:
            //game shop

            break;
        case 5:
            //directors

            break;
    }

    exit(1);
}

