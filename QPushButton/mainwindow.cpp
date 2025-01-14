#include "mainwindow.h"
#include <QPalette>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("QPushButton");
    setFixedSize(800, 600);

    // 初始化MainWindow中的各个小部件
    _change_color_y = new QPushButton("change", this);
    _change_color_g = new QPushButton("change", this);
    _change_color_b = new QPushButton("change", this);
    _yellow_change = new QLabel("Set the screen color to yellow:", this);
    _green_change = new QLabel("Set the screen color to green:", this);
    _blue_change = new QLabel("Set the screen color to blue:", this);

    // 由于不使用布局管理器，使用setGeometry显式设置一个控件的位置与大小
    _yellow_change -> setGeometry(QRect(50, 50, 300, 40));
    _green_change -> setGeometry(QRect(50, 130, 300, 40));
    _blue_change -> setGeometry(QRect(50, 210, 300, 40));
    _change_color_y -> setGeometry(QRect(450, 50, 150, 40));
    _change_color_g -> setGeometry(QRect(450, 130, 150, 40));
    _change_color_b -> setGeometry(QRect(450, 210, 150, 40));

    // 连接信号与槽
    connect(_change_color_y, &QPushButton::clicked, this, &MainWindow::changeToYellow);
    connect(_change_color_g, &QPushButton::clicked, this, &MainWindow::changeToGreen);
    connect(_change_color_b, &QPushButton::clicked, this, &MainWindow::changeToBlue);
}


void MainWindow::changeToYellow() {
    QPalette pal = palette();                        // 创建一个调色板
    pal.setColor(QPalette::Background, Qt::yellow);  // 设置背景颜色为黄色
    setPalette(pal);                                 // 将调色板应用到窗口
    setAutoFillBackground(true);                     // 确保背景颜色是可见的
}

void MainWindow::changeToGreen() {
    QPalette pal = palette();                        // 创建一个调色板
    pal.setColor(QPalette::Background, Qt::green);   // 设置背景颜色为绿色
    setPalette(pal);                                 // 将调色板应用到窗口
    setAutoFillBackground(true);                     // 确保背景颜色是可见的
}

void MainWindow::changeToBlue() {
    QPalette pal = palette();                        // 创建一个调色板
    pal.setColor(QPalette::Background, Qt::blue);    // 设置背景颜色为蓝色
    setPalette(pal);                                 // 将调色板应用到窗口
    setAutoFillBackground(true);                     // 确保背景颜色是可见的
}

MainWindow::~MainWindow()
{
}

