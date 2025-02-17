#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    set_toolbutton();

    ui -> toolBar -> setStyleSheet("QToolBar { spacing: 15px; }");
    ui -> toolBar->setStyleSheet(
        "QToolButton {"
        "    min-width: 100px;" // 最小宽度
        "    max-width: 100px;" // 最大宽度，确保宽度固定
        "    height: 70px;"     // 固定高度
        "    padding: 5px;"
        "    text-align: center;"
        "}"
    );

    set_listWidget();

    listWidget_addItem("C++");
    listWidget_addItem("Linux");
    listWidget_addItem("Java");
    listWidget_addItem("C");
    listWidget_addItem("数据结构与算法");
    listWidget_addItem("数据库");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAdd_clicked()
{
    QString text = ui -> lineEdit -> text();
    if (!text.isEmpty()) {
        listWidget_addItem(text);
        ui -> lineEdit -> clear();
    }
}

void MainWindow::on_actionModeIcon_triggered()
{
    ui -> listWidget -> setSpacing(30);
    ui ->listWidget -> setViewMode(QListView::IconMode);
}

void MainWindow::on_actionModeList_triggered()
{
    ui -> listWidget -> setSpacing(0);
    ui -> listWidget -> setViewMode(QListView::ListMode);
}

void MainWindow::listWidget_addItem(const QString& text) {
    QListWidgetItem* new_item = new QListWidgetItem(QIcon(":/image/class.png"), text);

    new_item -> setCheckState(Qt::Unchecked);
    new_item -> setFlags(new_item -> flags() | Qt::ItemIsUserCheckable);

    new_item -> setSizeHint(QSize(120, 120));

    ui -> listWidget -> addItem(new_item);
}

void MainWindow::set_listWidget()
{
    QFont font = ui -> listWidget -> font();
    font.setPointSize(12);
    ui -> listWidget -> setFont(font);

    ui -> listWidget -> setIconSize(QSize(80, 80));

    ui -> listWidget -> setResizeMode(QListView::Adjust);

    ui -> listWidget -> setContextMenuPolicy(Qt::CustomContextMenu);
}

void MainWindow::set_toolbutton()
{
    ui -> toolButton -> setText("Click Me!");

    QMenu* menu = new QMenu(ui -> toolButton);
    menu -> addAction(ui -> actionModeIcon);
    menu -> addAction(ui -> actionModeList);
    ui -> toolButton -> setMenu(menu);
    ui -> toolButton -> setPopupMode(QToolButton::MenuButtonPopup);


}

void MainWindow::on_actionSelectAll_triggered()
{
    for (int i = 0; i < ui -> listWidget -> count(); i++) {
        QListWidgetItem* item = ui -> listWidget -> item(i);
        if (item -> flags() & Qt::ItemIsUserCheckable) {
            item -> setCheckState(Qt::Checked);
        }
    }
}

void MainWindow::on_actionSelectReverse_triggered()
{
    for (int i = 0; i < ui -> listWidget -> count(); i++) {
        QListWidgetItem* item = ui -> listWidget -> item(i);
        if (item -> flags() & Qt::ItemIsUserCheckable) {
            item -> setCheckState(item -> checkState() == Qt::Checked ? Qt::Unchecked : Qt::Checked);
        }
    }
}

void MainWindow::on_actionDel_triggered()
{
    for (int i = ui -> listWidget -> count() - 1; i >= 0; i--) {
        QListWidgetItem* item = ui -> listWidget -> item(i);
        if (item -> checkState() == Qt::Checked) {
            delete ui -> listWidget -> takeItem(i);
        }
    }
}

void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    QMenu* tmp_menu = new QMenu(ui -> listWidget);
    tmp_menu -> addAction(ui -> actionModeIcon);
    tmp_menu -> addAction(ui -> actionModeList);
    tmp_menu -> addSeparator();
    tmp_menu -> addAction(ui -> actionSelectAll);
    tmp_menu -> addAction(ui -> actionSelectReverse);
    tmp_menu -> exec(ui -> listWidget -> mapToGlobal(pos));

    delete tmp_menu;
}
