#include "mainwindow.h"

/* nothing */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _label = new QLabel("C/C++/Qt工程师 CooperShen", this);
}

void MainWindow::setMyLabel() {
    // 设置标签字体颜色
    QPalette palette = _label -> palette();
    palette.setColor(_label -> foregroundRole(), Qt::green);
    _label -> setPalette(palette);

    // 设置背景颜色
    palette.setColor(_label -> backgroundRole(), Qt::yellow);
    _label -> setPalette(palette);
    _label -> setAutoFillBackground(true);

    // 设置字体类型与大小
    QFont font = _label -> font();
    font.setFamily("KaiTi");
    font.setPointSize(15);
    _label -> setFont(font);

    // 根据标签内的内容自动适配标签本身大小
    _label -> setFixedWidth(380);
    _label -> setWordWrap(true);
    _label -> adjustSize();

    // 设置标签位置
    int x = (this -> width() - _label -> width()) / 2;
    int y = (this -> height() - _label -> height()) / 2;
    _label -> move(x, y);
}

MainWindow::~MainWindow()
{
}