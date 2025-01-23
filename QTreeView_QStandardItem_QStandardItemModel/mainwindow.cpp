#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("QTreeView_QStandardItem_QStandardItemModel");

    // 布局设置
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    _layout = new QVBoxLayout(centralWidget);

    // _header相关
    _header = new QLabel("Please select an outstanding work of an engineer", centralWidget);
    _header -> setAlignment(Qt::AlignCenter);
    _layout -> addWidget(_header);

    // _model相关
    _model = new QStandardItemModel(centralWidget);

    // 设置根节点
    QStandardItem* root = _model -> invisibleRootItem();

    // 设置一级节点
    QStandardItem* node_1 = new QStandardItem("Elon Musk");
    QStandardItem* node_2 = new QStandardItem("Bill Gates");
    root -> appendRow(node_1);
    root -> appendRow(node_2);

    // 设置二级节点
    QStandardItem* node_1_1 = new QStandardItem("Telsa");
    QStandardItem* node_1_2 = new QStandardItem("SpaceX");
    QStandardItem* node_1_3 = new QStandardItem("X Crop");
    QStandardItem* node_2_1 = new QStandardItem("Stay tuned....");
    node_1 -> appendRow(node_1_1);
    node_1 -> appendRow(node_1_2);
    node_1 -> appendRow(node_1_3);
    root -> child(1) -> appendRow(node_2_1);

    // 设置三级节点
    QStandardItem* node_1_1_1 = new QStandardItem("Model X");
    QStandardItem* node_1_1_2 = new QStandardItem("Model Y");
    QStandardItem* node_1_1_3 = new QStandardItem("Model 3");
    QStandardItem* node_1_2_1 = new QStandardItem("StarShip");
    QStandardItem* node_1_2_2 = new QStandardItem("StarLink");
    QStandardItem* node_1_3_1 = new QStandardItem("X");
    QStandardItem* node_1_3_2 = new QStandardItem("xAI Grok");
    QStandardItem* node_1_3_3 = new QStandardItem("X Mail");
    node_1_1 -> appendRow(node_1_1_1);
    node_1_1 -> appendRow(node_1_1_2);
    node_1_1 -> appendRow(node_1_1_3);
    node_1_2 -> appendRow(node_1_2_1);
    node_1_2 -> appendRow(node_1_2_2);
    node_1_3 -> appendRow(node_1_3_1);
    node_1_3 -> appendRow(node_1_3_2);
    node_1_3 -> appendRow(node_1_3_3);

    // _view相关
    _view = new QTreeView(centralWidget);
    _view -> setModel(_model);
    _layout -> addWidget(_view);

    // _submit相关
    _submit = new QPushButton("submit");
    _layout -> addWidget(_submit);

    // 信号与槽
    connect(_view, &QTreeView::clicked, this, &MainWindow::onItemClicked);
    connect(_submit, &QPushButton::clicked, this, &MainWindow::submitAfter);
}

void MainWindow::onItemClicked(const QModelIndex& index) {
    const QModelIndex& parentIndex = index.parent();
    if (parentIndex.isValid()) {
        const QModelIndex& grandparentIndex = parentIndex.parent();
        if (grandparentIndex.isValid()) {
            _choice = index.data().toString();
            QMessageBox::information(this, "Select one", "You seem to like " + _choice);
        }
    }
}

void MainWindow::submitAfter() {
    QMessageBox::information(this, "Success", "Your final choice is " + _choice);
}

MainWindow::~MainWindow()
{
}

