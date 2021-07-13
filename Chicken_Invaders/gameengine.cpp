#include "GameEngine.h"
#include "Bird.h"
#include "Chick.h"
#include "Chicken.h"
#include "SuperChick.h"
#include <list>
#include <QTimer>
GameEngine::GameEngine(int level):level(level) {
    gameTime=new QTimer();
    gameTime->start(50);
    AddBirds();
//    AddSS();
//    AddScoreBoard();
    connect(gameTime,SIGNAL(timeout()),this,SLOT(GameTimerSchedule()));

}
GameEngine::~GameEngine(){
    delete [] myBirds;
//    delete mySS;
//    delete ScoreBoard

}

void GameEngine::PlayGame(){
}
void GameEngine::TimeSchedule(){
//    AddScoreBoard();
//    GameTimerSchedule();
}
void GameEngine::AddBirds(){
    switch(level){
        case 1:{
            myBirds->clear();
            for(int i=0;i<5;i++){// 5 sotoon
                for(int j=0;j<4;j++){// 4 radif
                    myBirds->append(new Chick(5,new QTimer(),1,new QGraphicsItem(),150+445+i*130,100+40+j*130));
                }
            }
            break;
        }
        case 2:{
            myBirds->clear();
            for(int i=0;i<5;i++){// 9 sotoon
                for(int j=0;j<4;j++){// 4 radif
                    myBirds->append(new Chick(5,new QTimer(),1,new QGraphicsItem(),150+145+i*130,100+40+j*130));
                }
            }
            break;
        }
        case 3:{
            myBirds->clear();
            for(int i=0;i<5;i++){// 8 sotoon
                for(int j=0;j<4;j++){// 3 radif
                    myBirds->append(new Chick(5,new QTimer(),1,new QGraphicsItem(),150+250+i*130,100+105+j*130));

                }
            }
            break;
        }
        case 4:{
            for(int i=0;i<5;i++){// 10 sotoon
                for(int j=0;j<4;j++){// 3 radif
                    myBirds->append(new Chick(5,new QTimer(),1,new QGraphicsItem(),150+120+i*130,100+105+j*130));

                }
            }
            break;
        }
        case 5:{
            for(int i=0;i<5;i++){// 6 sotoon
                for(int j=0;j<4;j++){// 3 radif
                    myBirds->append(new Chick(5,new QTimer(),1,new QGraphicsItem(),150+380+i*130,100+105+j*130));

                }
            }
            break;
        }
        case 6:{
            for(int i=0;i<5;i++){// 9 sotoon
                for(int j=0;j<4;j++){// 3 radif
                    myBirds->append(new Chick(5,new QTimer(),1,new QGraphicsItem(),150+145+i*130,100+105+j*130));

                }
            }
            break;
        }
    }
}

