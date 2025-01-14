#include "mainwindow.h"

QHash<QString, QString> ConfirmationDialog::_real_sites = {
    {"Telsa", "www.Telsa.com"}, {"SpaceX", "www.spacex.com"}, {"Boring", "www.boringcompany.com"}, {"X", "www.x.com"}
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Website Link Collector");

    // 设置布局
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    _layout = new QGridLayout(centralWidget);

    // 小部件构造
    _header = new QLabel("Choose your website", centralWidget);
    _website_1 = new QCommandLinkButton("visit the Telsa", centralWidget);
    _website_1 -> setDescription("model 3, model Y ...");
    _website_2 = new QCommandLinkButton("visit the SpaceX", centralWidget);
    _website_2 -> setDescription("StarShip, Falcon 9 ...");
    _website_3 = new QCommandLinkButton("visit the Borning", centralWidget);
    _website_3 -> setDescription("Underground tunnel transportation ...");
    _website_4 = new QCommandLinkButton("visit the X", centralWidget);
    _website_4 -> setDescription("Free Speech ...");

    // 设置窗口背景与字体颜色
    _pal = new QPalette();
    _pal -> setColor(QPalette::Window, Qt::yellow);
    _pal -> setColor(QPalette::WindowText, Qt::red);
    setPalette(*_pal);

    // 设置header标签字体样式与居中排布
    QFont font = _header -> font();
    font.setPointSize(20);
    _header -> setFont(font);
    _header->setAlignment(Qt::AlignCenter);

    // 将小部件放入布局中
    _layout -> addWidget(_header, 0, 0, 1, 4);
    _layout -> addWidget(_website_1, 1, 0, 1, 2);
    _layout -> addWidget(_website_2, 1, 2, 1, 2);
    _layout -> addWidget(_website_3, 2, 0, 1, 2);
    _layout -> addWidget(_website_4, 2, 2, 1, 2);

    // 信号与槽
    connect(_website_1, &QCommandLinkButton::clicked, this, &MainWindow::choose_site_1);
    connect(_website_2, &QCommandLinkButton::clicked, this, &MainWindow::choose_site_2);
    connect(_website_3, &QCommandLinkButton::clicked, this, &MainWindow::choose_site_3);
    connect(_website_4, &QCommandLinkButton::clicked, this, &MainWindow::choose_site_4);
}

void MainWindow::choose_site_1() {
    ConfirmationDialog conf("Telsa", this);
    conf.exec();              // 进入对话框事件循环即可, 对话框的关闭不关你这边的事情，不用操心
}
void MainWindow::choose_site_2() {
    ConfirmationDialog conf("SpaceX", this);
    conf.exec();
}
void MainWindow::choose_site_3() {
    ConfirmationDialog conf("Boring", this);
    conf.exec();
}
void MainWindow::choose_site_4() {
    ConfirmationDialog conf("X", this);
    conf.exec();
}

MainWindow::~MainWindow()
{
}

