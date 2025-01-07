#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(800, 600);
    w.setWindowTitle("我的应用程序");

    w.setMyLabel();

    w.show();
    return a.exec();
}
