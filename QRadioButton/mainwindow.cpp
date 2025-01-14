#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("QRadioButton");
    resize(800, 75);

    // 布局管理器相关
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    _layout = new QGridLayout();
    centralWidget -> setLayout(_layout);

    // 子控件构造
    _choose_color = new QLabel("  -----     Please select your window color.     -----  ", centralWidget);
    _result_display = new QLabel(centralWidget);
    _button_green = new QRadioButton("green", centralWidget);
    _button_red = new QRadioButton("red", centralWidget);
    _button_black = new QRadioButton("black", centralWidget);
    _submit = new QPushButton("submit", centralWidget);
    _pal = new QPalette();      /* 调色板对象 */

    // 让文本在标签对象中居中显示
    _choose_color -> setAlignment(Qt::AlignCenter);
    _result_display -> setAlignment(Qt::AlignCenter);

    // 子部件放入布局中
    _layout -> addWidget(_choose_color, 0, 0, 1, 6);
    _layout -> addWidget(_button_green, 1, 0, 1, 2);
    _layout -> addWidget(_button_red, 1, 2, 1, 2);
    _layout -> addWidget(_button_black, 1, 4, 1, 2);
    _layout -> addWidget(_submit, 2, 0, 1, 2);
    _layout -> addWidget(_result_display, 2, 2, 1, 4);

    // 设置三个QRadioButton的默认设置值
    _button_black -> setChecked(true);
    _pal -> setColor(QPalette::Window, Qt::black);
    _pal -> setColor(QPalette::WindowText, Qt::white);
    this -> setPalette(*_pal);

    // 信号与槽关联
    connect(_submit, &QPushButton::clicked, this, &MainWindow::submit_after);
}

void MainWindow::submit_after() {
    // 调色与文本结果的实现
    if (_button_green -> isChecked()) {
        _pal -> setColor(QPalette::Window, Qt::green);
        _pal -> setColor(QPalette::WindowText, Qt::black);
        _result_display->setText("Green has been set successfully.");
    }
    else if (_button_red -> isChecked()) {
        _pal -> setColor(QPalette::Window, Qt::red);
        _pal -> setColor(QPalette::WindowText, Qt::yellow);
        _result_display->setText("Red has been set successfully.");
    }
    else if (_button_black -> isChecked()) {
        _pal -> setColor(QPalette::Window, Qt::black);
        _pal -> setColor(QPalette::WindowText, Qt::white);
        _result_display->setText("Black has been set successfully.");
    }
    this -> setPalette(*_pal);
}

MainWindow::~MainWindow()
{
}

