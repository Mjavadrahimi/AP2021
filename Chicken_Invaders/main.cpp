#include <QApplication>
#include "MainMenu.h"
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainMenu *main = new MainMenu();
    main->show();


    return a.exec();
}
