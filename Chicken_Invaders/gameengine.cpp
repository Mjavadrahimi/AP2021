#include "GameEngine.h"
#include <bits/stdc++.h>
#include <vector>
#include "Bird.h"
#include "Chick.h"
#include "Chicken.h"
#include "SuperChick.h"
#include "randommaker.h"
#include <list>
#include <QTimer>
#include <iostream>
#include <QDebug>
using namespace std;
GameEngine::GameEngine(int level):level(level),QGraphicsView() {
    // QCursor
    QCursor cursor(Qt::BlankCursor);
    QApplication::setOverrideCursor(cursor);
    QApplication::changeOverrideCursor(cursor);
    // create timer
    gameTimer=new QTimer();
    gameTimer->start(8); // 125 Times in 1 second
    IntoSecond=1000/8; // = 125
    GameTime=0;
    // create scene
    myScene = new QGraphicsScene();
    myScene->setSceneRect(0,0,1800,1000);
    setScene(myScene);

    // create scene2
    myScene2 = new QGraphicsScene();
    myScene2->setSceneRect(0,0,1800,1000);
    // fix size
    setFixedSize(1800,1000);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create holder

    holder = new QGraphicsRectItem();
    holder -> setRect(0,0,1800,1000);

    myScore=new ScoreBoard(holder);
//    myBirds->append(new Chick(2,gameTimer,1,holder,150+250+6*130,100+105+6*130 - 620,myScene,myScore));
    AddBirds();
//    AddSS();
    // craete ss
    p = new Player(holder,gameTimer);
    myScene->addItem(p);
//    AddScoreBoard();

    mrChicken = new Chicken(2,gameTimer,1,holder,900,500,myScene,myScore);
    myScene->addItem(mrChicken);
    mrChicken->setPos(300,300);

    connect(gameTimer,SIGNAL(timeout()),this,SLOT(TimeSchedule()));

}
GameEngine::~GameEngine(){
//    delete [] myBirds;
//    delete mySS;
//    delete ScoreBoard

}
void GameEngine::TimeSchedule(){
    GameTime++;
    if( GameTime * 8 <= 0 ) return ; //wait 4000 ms

    // set move down for birds
    if(!connect_bird){
        for(int i=0;i<0;i++){
//            myBirds->at(i)->moveDown();
            connect(gameTimer,SIGNAL(timeout()),myBirds.at(i),SLOT(moveDown()));
        }
        connect_bird=true;
    }
    switch (level) {
        case 1:{ // level 1 = Season 1 Part 1
            // no event
            break;
        }
        case 2:{ // level 2 = Season 1 Part 2
            // no event
            break;
        }
        case 3:{ // level 3 = Season 2 Part 1
            if((GameTime * 8) % 5000 == 4000){ // T= s 9000 14000
                ChooseEggSpawn(); //choose Birds to drop an egg
                DropEgg(); //drop eggs
            }
            break;
        }
        case 4:{ // level 4 = Season 2 Part 2
            if((GameTime * 8) % 5000 == 4000){ // T= s 9000 14000
                ChooseEggSpawn(); //choose Birds to drop an egg
                DropEgg(); //drop eggs

            }
            break;
        }
        case 5:{ // level 5 = Season 3 Part 1
            if((GameTime * 8) % 6000 == 4000){ // T= s 10000 16000
                ChooseEggSpawn(); //choose Birds to drop an egg
                DropEgg(); //drop eggs
            }else if(GameTime * 8 == 9000){ // T= 9s
                //drop gift between x=(0,1740)
            }
            break;
        }
        case 6:{ // level 6 = Season 3 Part 2
            if((GameTime * 8) % 7000 == 4000){ // T= s 11000 18000
                ChooseEggSpawn(); //choose Birds to drop an egg
                DropEgg(); //drop eggs
            }else if(GameTime * 8 == 9000){ // T= 9s
                //drop gift between x=(0,1740)
            }
            break;
        }
    }
}
void GameEngine::AddBirds(){
    switch(level){
        case 1:{          // SEASON 1
//            myBirds->clear();
            for(int i=0;i<5;i++){// 5 sotoon
                for(int j=0;j<4;j++){// 4 radif
                    qInfo()<<"123ssss";
//                    myBirds.push_back(new Chicken(2,gameTimer,1,holder,150+445+i*130,100+40+j*130 - 620,myScene,myScore));
//                    myScene->addItem(myBirds.last());
//                    myBirds.last()->setPos(150+445+i*130,100+40+j*130 - 620);
//                    mrChicken = new Chicken(2,gameTimer,1,holder,900,500,myScene,myScore);
//                    mrChicken->setPos(300,300);,myScene,myScore));
//                    myBirds.push_back(new Chicken(2,gameTimer,1,holder,900,500,myScene2,myScore));
                }
            }
            break;
        }
        case 2:{
            myBirds.clear();
            for(int i=0;i<9;i++){// 9 sotoon
                for(int j=0;j<4;j++){// 4 radif
//                    myBirds->append(new Chicken(2,gameTimer,1,holder,150+145+i*130,100+40+j*130 - 620,myScene));
                }
            }
            break;
        }
        case 3:{          // SEASON 2
            myBirds.clear();
            for(int i=0;i<8;i++){// 8 sotoon
                for(int j=0;j<3;j++){// 3 radif
//                    if((i+j)%2==0)myBirds->append(new Chick(2,gameTimer,1,holder,150+250+i*130,100+105+j*130 - 620,myScene));
//                    else myBirds->append(new Chick(2,gameTimer,1,holder,150+250+i*130,100+105+j*130 - 620,myScene));

                }
            }
            break;
        }
        case 4:{
            for(int i=0;i<10;i++){// 10 sotoon
                for(int j=0;j<3;j++){// 3 radif
//                    if((i)%3==0)myBirds->append(new Chick(2,gameTimer,1,holder,150+120+i*130,100+105+j*130 - 620,myScene));
//                    else myBirds->append(new Chick(2,gameTimer,1,holder,150+120+i*130,100+105+j*130 - 620,myScene));

                }
            }
            break;
        }
        case 5:{          // SEASON 3
            for(int i=0;i<6;i++){// 6 sotoon
                for(int j=0;j<3;j++){// 3 radif
//                    if((i+j)%2==0)myBirds->append(new Chicken(2,gameTimer,1,holder,150+380+i*130,100+105+j*130 - 620,myScene));
//                    else myBirds->append(new SuperChick(2,gameTimer,1,holder,150+380+i*130,100+105+j*130 - 620,myScene));

                }
            }
            break;
        }
        case 6:{
            for(int i=0;i<9;i++){// 9 sotoon
                for(int j=0;j<3;j++){// 3 radif
//                    myBirds->append(new SuperChick(2,gameTimer,1,holder,150+145+i*130,100+105+j*130 - 620,myScene));

                }
            }
            break;
        }
    }
}
void GameEngine::ChooseEggSpawn(){
    myVector.clear();
    switch (level) {
        case 3:{
            vector <int> InputVector={1,3,5,7,9,11,13,15,17,19,21,23};
            myVector=RandomMaker().RandShuffle(InputVector);
            while(myVector.size()!=3){ // return 3 random number between {1,3,5,...,23}
                myVector.pop_back();
            }
            break;
        }
        case 4:{
            vector <int> InputVector={3,4,5,6,7,8,12,13,14,15,16,17,21,22,23,24,25,26};
            myVector=RandomMaker().RandShuffle(InputVector);
            while(myVector.size()!=4){ // return 4 random number between {3,4,5,6,7,8,12,13,14,15,16,17,21,22,23,24,25,26}
                myVector.pop_back();
            }
            break;
        }
        case 5:{
            vector <int> InputVector={1,3,5,7,9,11,13,15,17};
            myVector=RandomMaker().RandShuffle(InputVector);
            while(myVector.size()!=6){ // return 6 random number between {1,3,5,7,9,11,13,15,17}
                myVector.pop_back();
            }
            break;
        }
        case 6:{
            myVector=RandomMaker().RandShuffle(29);
            while(myVector.size()!=15){ // return 15 random number between {0,1,2,...,29}
                myVector.pop_back();
            }
            break;
        }
    }
}
void GameEngine::DropEgg(){
    for(int i=0;i<myVector.size();i++){
        //myBirds->at(i)->Drop();
    }
}
