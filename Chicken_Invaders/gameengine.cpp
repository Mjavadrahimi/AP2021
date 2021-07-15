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
    kills=new int();
    *kills=0;
    isLeveled=false;
    this->level=4;

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
    setBackgroundBrush(QBrush(QImage(":/images/BackGround.png")));

    // fix size
    setFixedSize(1800,1000);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create holder

    holder = new QGraphicsRectItem();
    holder -> setRect(0,0,1800,1000);

    myScore=new ScoreBoard(holder);
//    myBirds->append(new Chick(2,gameTimer,1,holder,150+250+6*130,100+105+6*130 - 620,myScene,myScore));


    //    AddSS();
    // craete ss
    p = new Player(holder,gameTimer,kills);
    myScene->addItem(p);
//    AddScoreBoard();

//    b1 = new Bullet(1,gameTimer);
//    myScene->addItem(b1);
//    b1->setPos(800,840);

    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();

    connect(gameTimer,SIGNAL(timeout()),this,SLOT(TimeSchedule()));


}
GameEngine::~GameEngine(){
//    delete [] myBirds;
//    delete mySS;
//    delete ScoreBoard

}
void GameEngine::TimeSchedule(){
    GameTime++;

    if(isLeveled){
        qInfo()<<"lvl done2";
        level++;
        GameTime=0;
        isLeveled=false;
        connect_bird=false;
    }

    if( GameTime * 8 <= 4000) return ; //wait 4000 ms




    // set move down for birds
    if(!connect_bird){
        AddBirds();
        for(int i=0;i<myBirds.size();i++){
//            myBirds->at(i)->moveDown();

            connect(gameTimer,SIGNAL(timeout()),myBirds.at(i),SLOT(moveDown()));
        }
        connect_bird=true;
    }
    switch (level) {
        case 1:{ if(*kills==80) {
            qInfo()<<"lvl done";
            isLeveled=true;
            *kills=0;
        }
            break;
        }
        case 2:{
        if(*kills==144) {
                    qInfo()<<"lvl done";
                    isLeveled=true;
                    *kills=0;
                }
            break;
        }
        case 3:{ // level 3 = Season 2 Part 1
                if(*kills==96) {
                    qInfo()<<"lvl done";
                    isLeveled=true;
                    *kills=0;
                }
            if((GameTime * 8) % 5000 == 4000){ // T= s 9000 14000
                ChooseEggSpawn(); //choose Birds to drop an egg
                DropEgg(); //drop eggs
            }
            break;
        }
        case 4:{ // level 4 = Season 2 Part 2
           if(*kills==120) {
               qInfo()<<"lvl done";
               isLeveled=true;
               *kills=0;
           }
            if((GameTime * 8) % 5000 == 4000){ // T= s 9000 14000
                ChooseEggSpawn(); //choose Birds to drop an egg
                DropEgg(); //drop eggs

            }
            break;
        }
        case 5:{ // level 5 = Season 3 Part 1
            if(*kills==72) {
                qInfo()<<"lvl done";
                isLeveled=true;
                *kills=0;
            }
            if((GameTime * 8) % 6000 == 4000){ // T= s 10000 16000
                ChooseEggSpawn(); //choose Birds to drop an egg
                DropEgg(); //drop eggs
            }else if(GameTime * 8 == 9000){ // T= 9s
                //drop gift between x=(0,1740)
            }
            break;
        }
        case 6:{ // level 6 = Season 3 Part 2
            if(*kills==108) {
                qInfo()<<"lvl done";
                isLeveled=true;
                *kills=0;
            }
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
            myBirds.clear();
            for(int i=0;i<5;i++){// 5 sotoon
                for(int j=0;j<4;j++){// 4 radif
                    myBirds.push_back(new Chicken(2,gameTimer,1,holder,150+445+i*130,100+40+j*130 - 620,myScene,myScore));
                }
            }
            break;
        }
        case 2:{
            myBirds.clear();
            for(int i=0;i<9;i++){// 9 sotoon
                for(int j=0;j<4;j++){// 4 radif
                    myBirds.push_back(new Chicken(2,gameTimer,1,holder,150+145+i*130,100+40+j*130 - 620,myScene,myScore));
                }
            }
            break;
        }
        case 3:{          // SEASON 2
            myBirds.clear();
            for(int i=0;i<8;i++){// 8 sotoon
                for(int j=0;j<3;j++){// 3 radif
                    if((i+j)%2==0)myBirds.push_back(new Chicken(2,gameTimer,1,holder,150+250+i*130,100+105+j*130 - 620,myScene,myScore));
                    else myBirds.push_back(new Chick(2,gameTimer,2,holder,150+250+i*130,100+105+j*130 - 620,myScene,myScore));

                }
            }
            break;
        }
        case 4:{
            myBirds.clear();
            for(int i=0;i<10;i++){// 10 sotoon
                for(int j=0;j<3;j++){// 3 radif
                    if((i)%3==0)myBirds.push_back(new Chicken(2,gameTimer,1,holder,150+120+i*130,100+105+j*130 - 620,myScene,myScore));
                    else myBirds.push_back(new Chick(2,gameTimer,2,holder,150+120+i*130,100+105+j*130 - 620,myScene,myScore));

                }
            }
            break;
        }
        case 5:{          // SEASON 3
            myBirds.clear();
            for(int i=0;i<6;i++){// 6 sotoon
                for(int j=0;j<3;j++){// 3 radif
                    if((i+j)%2==0)myBirds.push_back(new Chick(2,gameTimer,2,holder,150+380+i*130,100+105+j*130 - 620,myScene,myScore));
                    else myBirds.push_back(new SuperChick(2,gameTimer,4,holder,150+380+i*130,100+105+j*130 - 620,myScene,myScore));

                }
            }
            break;
        }
        case 6:{
            myBirds.clear();
            for(int i=0;i<9;i++){// 9 sotoon
                for(int j=0;j<3;j++){// 3 radif
                    myBirds.push_back(new SuperChick(2,gameTimer,4,holder,150+145+i*130,100+105+j*130 - 620,myScene,myScore));

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
            myVector=RandomMaker().RandShuffle(26);
            while(myVector.size()!=15){ // return 15 random number between {0,1,2,...,26}
                myVector.pop_back();
            }
            break;
        }
    }
}
void GameEngine::DropEgg(){
    for(int i=0;i<myVector.size();i++){
        if((dynamic_cast<Bird *>(myBirds.at(myVector.at(i))))->getIsLive())
        (dynamic_cast<Bird *>(myBirds.at(myVector.at(i))))->dropEgg();
    }
}
