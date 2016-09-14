#include <QtGui/QApplication>
#include "mainwindow.h"
#include<QTime>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QTime::currentTime().msec());
    MainWindow w;
    w.show();
    return a.exec();
}
