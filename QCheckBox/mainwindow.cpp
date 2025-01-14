#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("QCheckBox");

    // 哈希表初始化
    _choices.insert("C/C++", 0);
    _choices.insert("Java", 0);
    _choices.insert("Python", 0);
    _choices.insert("Golang", 0);

    // 布局构造
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    _layout = new QGridLayout(centralWidget);

    // 子部件构造
    _pl_C_Cpp = new QCheckBox("C/C++", centralWidget);
    _pl_Java = new QCheckBox("Java", centralWidget);
    _pl_Python = new QCheckBox("Pyhton", centralWidget);
    _pl_Golang = new QCheckBox("Golang", centralWidget);
    _header = new QLabel("Please select your favorite programming language.", centralWidget);
    _result = new QLabel(centralWidget);
    _guess = new QLabel(centralWidget);
    _pal = new QPalette();

    // 设置窗口背景与字体颜色
    _pal -> setColor(QPalette::Window, Qt::black);
    _pal -> setColor(QPalette::WindowText, Qt::white);
    setPalette(*_pal);

    // 将子部件放入布局中
    _layout -> addWidget(_header, 0, 0, 1, 4);
    _layout -> addWidget(_pl_C_Cpp, 1, 0);
    _layout -> addWidget(_pl_Java, 1, 1);
    _layout -> addWidget(_pl_Python, 1, 2);
    _layout -> addWidget(_pl_Golang, 1, 3);
    _layout -> addWidget(_result, 2, 0, 1, 4);
    _layout -> addWidget(_guess, 3, 0, 1, 4);

    // 设置复选框三态
    _pl_C_Cpp -> setTristate(true);
    _pl_Java -> setTristate(true);
    _pl_Python -> setTristate(true);
    _pl_Golang -> setTristate(true);

    // 信号与槽
    connect(_pl_C_Cpp, SIGNAL(stateChanged(int)), this, SLOT(onStateChanged_cpp(int)));
    connect(_pl_Java, SIGNAL(stateChanged(int)), this, SLOT(onStateChanged_java(int)));
    connect(_pl_Python, SIGNAL(stateChanged(int)), this, SLOT(onStateChanged_python(int)));
    connect(_pl_Golang, SIGNAL(stateChanged(int)), this, SLOT(onStateChanged_golang(int)));
}

void MainWindow::display_result() {
    QHash<QString, int>::iterator it = _choices.begin();
    QString result_str = "You totally like ";
    QString guess_str = "You might like ";
    int count_res = 0, count_gus = 0;
    while (it != _choices.end()) {
        if (it.value() == 1) {
            guess_str += it.key();
            guess_str += " ";
            count_gus++;
        }
        else if (it.value() == 2) {
            result_str += it.key();
            result_str += " ";
            count_res++;
        }
        ++it;
    }
    if (count_gus > 0) { _guess -> setText(guess_str); }
    else { _guess -> clear(); }
    if (count_res > 0) { _result -> setText(result_str); }
    else { _result -> clear(); }
}

void MainWindow::onStateChanged_cpp(int state) {
    switch (state) {
        case Qt::Unchecked:
            _choices["C/C++"] = 0;
            break;
        case Qt::PartiallyChecked:
            _choices["C/C++"] = 1;
            break;
        case Qt::Checked:
            _choices["C/C++"] = 2;
            break;
    }
    display_result();
}

void MainWindow::onStateChanged_java(int state) {
    switch (state) {
        case Qt::Unchecked:
            _choices["Java"] = 0;
            break;
        case Qt::PartiallyChecked:
            _choices["Java"] = 1;
            break;
        case Qt::Checked:
            _choices["Java"] = 2;
            break;
    }
    display_result();
}

void MainWindow::onStateChanged_python(int state) {
    switch (state) {
        case Qt::Unchecked:
            _choices["Python"] = 0;
            break;
        case Qt::PartiallyChecked:
            _choices["Python"] = 1;
            break;
        case Qt::Checked:
            _choices["Python"] = 2;
            break;
    }
    display_result();
}

void MainWindow::onStateChanged_golang(int state) {
    switch (state) {
        case Qt::Unchecked:
            _choices["Golang"] = 0;
            break;
        case Qt::PartiallyChecked:
            _choices["Golang"] = 1;
            break;
        case Qt::Checked:
            _choices["Golang"] = 2;
            break;
    }
    display_result();
}

MainWindow::~MainWindow()
{
}

