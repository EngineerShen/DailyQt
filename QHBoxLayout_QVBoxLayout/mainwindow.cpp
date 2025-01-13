#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置主窗口左上角的title
    setWindowTitle("各种布局控件测试");

    //创建中央部件
    QWidget* centralWidget = new QWidget;
    setCentralWidget(centralWidget);
    /* 注: 一个QWidget（包括中央部件）只能有一个布局直接设置给它 */

    // 构造水平布局对象
    _hbox_layout = new QHBoxLayout();

    // 构造水平布局子控件对象
    _pl_1 = new QRadioButton("C/C++");
    _pl_2 = new QRadioButton("Java");
    _pl_3 = new QRadioButton("Golang");
    _pl_4 = new QRadioButton("Rust");
    _pl_select_info = new QLabel("Choose your best programming language: ");
    _pl_select_ok = new QPushButton("confirm");

    // 将子控件放入水平布局当中
    _hbox_layout -> addWidget(_pl_select_info);
    _hbox_layout -> addWidget(_pl_1);
    _hbox_layout -> addWidget(_pl_2);
    _hbox_layout -> addWidget(_pl_3);
    _hbox_layout -> addWidget(_pl_4);
    _hbox_layout -> addWidget(_pl_select_ok);


    // 构造垂直布局对象
    _vbox_layout = new QVBoxLayout();

    // 构造垂直布局子控件对象
    _class_1 = new QCheckBox("Linux OS");
    _class_2 = new QCheckBox("Windows OS");
    _class_3 = new QCheckBox("NetWork");
    _class_4 = new QCheckBox("Data Structure");
    _class_5 = new QCheckBox("MySQL");
    _cl_select_info = new QLabel("Choose your classes: ");
    _cl_select_ok = new QPushButton("confirm");

    // 将子控件放入垂直布局当中
    _vbox_layout -> addWidget(_cl_select_info);
    _vbox_layout -> addWidget(_class_1);
    _vbox_layout -> addWidget(_class_2);
    _vbox_layout -> addWidget(_class_3);
    _vbox_layout -> addWidget(_class_4);
    _vbox_layout -> addWidget(_class_5);
    _vbox_layout -> addWidget(_cl_select_ok);

    centralWidget -> setLayout(_hbox_layout);
    // centralWidget -> setLayout(_vbox_layout);
}

MainWindow::~MainWindow()
{
}

