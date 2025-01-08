#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;

    w.setWindowTitle("我的计算求体积的程序");

    w.show();
    return a.exec();
}
