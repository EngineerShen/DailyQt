#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("表单布局");

    // 创建中间部件
    QWidget* centralWidget = new QWidget();
    setCentralWidget(centralWidget);

    // 表单布局对象构造
    _formLayout = new QFormLayout(centralWidget);

    // 表单布局内子控件构造
    _name_input = new QLineEdit();
    _college_input = new QLineEdit();
    _email_input = new QLineEdit();
    _tele_input = new QLineEdit();
    _submit = new QPushButton("submit");

    // 将子控件放入表单布局中
    _formLayout -> addRow("name: ", _name_input);
    _formLayout -> addRow("college: ", _college_input);
    _formLayout -> addRow("email: ", _email_input);
    _formLayout -> addRow("tele: ", _tele_input);
    _formLayout -> addWidget(_submit);

    // 设置布局有关间距
    _formLayout -> setContentsMargins(20, 20, 20, 20);
    _formLayout -> setSpacing(10);

    // 表单布局中处理行包装(即当标签和控件的宽度超过父窗口的宽度时如何处理)
//    _formLayout -> setRowWrapPolicy(QFormLayout::WrapAllRows);
    _formLayout -> setRowWrapPolicy(QFormLayout::WrapLongRows);

    // 表单布局设置标签对齐方式
    _formLayout -> setLabelAlignment(Qt::AlignRight);
}

MainWindow::~MainWindow()
{
}

