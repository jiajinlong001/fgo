#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //bright[SERVANT_MAX]={1};
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    QObject::connect(deletes[1],SIGNAL(clicked()),&w,SLOT(delete1()));
    return a.exec();
}
