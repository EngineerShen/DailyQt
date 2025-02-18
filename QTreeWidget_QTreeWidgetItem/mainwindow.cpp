#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    ui -> treeWidget -> setSelectionMode(QAbstractItemView::ExtendedSelection);

    QStringList list;
    list << "技术栈" << "要求";
    ui -> treeWidget -> setHeaderLabels(list);

    QStringList list_1;
    list_1 << "C++" << "Linux" << "计算机网络" << "数据结构";
    for (int i = 0; i < list_1.count(); i++) {
        QIcon img(":/images/fold.png");
        QTreeWidgetItem* new_item = new QTreeWidgetItem(ui -> treeWidget);

        new_item -> setFlags(new_item -> flags() | Qt::ItemIsEditable);

        new_item -> setIcon(0, img);
        new_item -> setText(0, list_1[i]);
        new_item -> setText(1, "必备技能");
    }

    // C++
    QStringList cpp;
    QTreeWidgetItem* top_item_cpp = ui -> treeWidget ->topLevelItem(0);
    cpp << "类与对象" << "继承与多态" << "STL容器" << "智能指针";
    for (int i = 0; i < cpp.count(); i++) {
        QTreeWidgetItem* child_item = new QTreeWidgetItem(top_item_cpp);
        child_item -> setFlags(child_item -> flags() | Qt::ItemIsEditable);

        child_item -> setText(0, cpp[i]);
        child_item -> setText(1, "熟练掌握");
    }

    // Linux
    QStringList linux;
    QTreeWidgetItem* top_item_linux = ui -> treeWidget -> topLevelItem(1);
    linux << "进程" << "线程" << "信号" << "文件";
    for (int i = 0; i < linux.count(); i++) {
        QTreeWidgetItem* child_item = new QTreeWidgetItem(top_item_linux);
        child_item -> setFlags(child_item -> flags() | Qt::ItemIsEditable);

        child_item -> setText(0, linux[i]);
        child_item -> setText(1, "深入了解");
    }

    // Linux..
    QTreeWidgetItem* item = ui -> treeWidget -> topLevelItem(1);
    for (int i = 0; i < item -> childCount(); i++) {
        QTreeWidgetItem* child = item -> child(i);
        if (child -> text(0) == "线程") {
            QStringList thread;
            thread << "线程本质" << "多线程互斥" << "多线程同步";
            for (int j = 0; j < thread.count(); j++) {
                QTreeWidgetItem* child_item = new QTreeWidgetItem(child);
                child_item -> setFlags(child_item -> flags() | Qt::ItemIsEditable);

                child_item -> setText(0, thread[j]);
                child_item -> setText(1, "了解");
            }
        }
    }
}

void MainWindow::on_actionAdd_triggered()
{
    QTreeWidgetItem* new_item = new QTreeWidgetItem();
    new_item -> setText(0, "Unknown");
    new_item -> setText(1, "Unknown");
    new_item -> setFlags(new_item -> flags() | Qt::ItemIsEditable);

    QTreeWidgetItem* now_item = ui -> treeWidget -> currentItem();
    if (now_item) {
        QTreeWidgetItem* parent = now_item -> parent();
        if (parent) {
            int index = parent -> indexOfChild(now_item);
            parent -> insertChild(index + 1, new_item);
        }
        else {
            int index = ui -> treeWidget -> indexOfTopLevelItem(now_item);
            ui -> treeWidget -> insertTopLevelItem(index + 1, new_item);
        }
    }
    else {
        ui -> treeWidget -> addTopLevelItem(new_item);
    }
}

void MainWindow::on_actionDel_triggered()
{
    QList<QTreeWidgetItem*> selectedItems = ui -> treeWidget -> selectedItems();

    for (QTreeWidgetItem* item : selectedItems) {
        QTreeWidgetItem* parent = item->parent();
        if (parent) {
            parent->removeChild(item);
        } else {
            int index = ui->treeWidget->indexOfTopLevelItem(item);
            ui->treeWidget->takeTopLevelItem(index);
        }
    }
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    QString text = item -> text(column);
    ui -> textEdit -> append(text);
}

