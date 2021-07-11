#include <QApplication>
#include "Menu.h"
int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Menu *mygame = new Menu();
    mygame->show();

    return a.exec();
}
