#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("QToolButton");
    setFixedSize(800, 600);

    // 创建中央部件
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 垂直布局对象构造
    _layout = new QVBoxLayout();
    setLayout(_layout);

    // ToolButton对象构造与初始化
    _my_Button = new QToolButton(this);
    _my_Button -> setText("Menu");                                         // 设置按钮的文本
    _my_Button -> setIcon(QIcon("D:\\Christopher\\Desktop\\picture.png")); // 设置按钮的图标
    _my_Button -> setToolButtonStyle(Qt::ToolButtonTextBesideIcon);        // 图标与文本并列显示
    _my_Button -> setPopupMode(QToolButton::MenuButtonPopup);              // 弹出菜单模式_1
//    _my_Button -> setPopupMode(QToolButton::DelayedPopup);                 // 弹出菜单模式_2
//    _my_Button -> setPopupMode(QToolButton::InstantPopup);                 // 弹出菜单模式_3

    // 菜单对象构造与初始化
    _my_menu = new QMenu(this);
    _my_menu -> addAction("C/C++");
    _my_menu -> addAction("Java");
    _my_menu -> addAction("Golang");

    // 将菜单设置给工具按钮
    _my_Button -> setMenu(_my_menu);

    /*  QToolButton 其设计目的是提供一种较小的、更适合工具栏或菜单的按钮  */

    // 将子控件(QToolButton按钮)放入布局管理器中
    _layout -> addWidget(_my_Button);

    // 信号与槽关联
    connect(_my_Button, &QToolButton::clicked, this, &MainWindow::toolButton_clicked);
    connect(_my_menu, &QMenu::triggered, this, &MainWindow::menu_triggered);
}

void MainWindow::toolButton_clicked() {
    QDialog* dialog = new QDialog(this);     // 小窗口对象的构造
    dialog -> setWindowTitle("Notice");     // 小窗口左上角标题显示

    // 创建垂直布局对象
    QVBoxLayout* small_layout = new QVBoxLayout(dialog);

    // 将子控件放入布局管理器中
    QLabel* notice = new QLabel("Please click the small triangle on the right.", dialog);
    small_layout -> addWidget(notice);

    // 小窗口显示
    dialog -> exec();
}

void MainWindow::menu_triggered() {
    QDialog* dialog = new QDialog(this);
    dialog -> setWindowTitle("Success");

    QHBoxLayout* small_layout = new QHBoxLayout();
    dialog -> setLayout(small_layout);

    QLabel* select_pl_success = new QLabel(dialog);
    select_pl_success -> setText("Select yout favorite programming language successfully");

    small_layout -> addWidget(select_pl_success);

    dialog -> exec();
}

MainWindow::~MainWindow()
{
}

