#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("网格布局实例演示");

    // 创建中央部件
    QWidget* centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    // 创建网格布局对象并设置进中央部件中
    _gridLayout = new QGridLayout();
    centralWidget->setLayout(_gridLayout);

    // 创建水平布局对象
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


    // 网格中嵌套布局
    _gridLayout -> addLayout(_vbox_layout, 0, 0, 3, 1);
    _gridLayout -> addLayout(_hbox_layout, 0, 1, 1, 3);

    // 网格布局中其他控件的构造
    _submit = new QPushButton("submit");

    _words = new QLineEdit();
    _wd_input_info = new QLabel("A message to yourself: ");

    _name = new QLineEdit();
    _ne_input_info = new QLabel("Entet your name: ");

    // 将子控件放入网格布局中
    _gridLayout -> addWidget(_wd_input_info, 1, 1);
    _gridLayout -> addWidget(_ne_input_info, 2, 1);
    _gridLayout -> addWidget(_words, 1, 2, 1, 2);
    _gridLayout -> addWidget(_name, 2, 2);
    _gridLayout -> addWidget(_submit, 2, 3);

    // 设置布局内容与容器边界之间的边距 / 布局中控件之间的间距
    _gridLayout -> setContentsMargins(5, 5, 5, 5);
    _gridLayout -> setSpacing(5);
}

MainWindow::~MainWindow()
{
}

