#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _model = new QFileSystemModel();
    QString customPath = "D:\\Program Files";
    _model -> setRootPath(customPath);

    ui -> treeView -> setStyleSheet("QTreeView::item { height: 25px; }");
    ui -> treeView -> setModel(_model);
    ui -> treeView -> setRootIndex(_model -> index(customPath));

    ui -> listView -> setModel(_model);
    ui -> listView -> setRootIndex(_model -> index(customPath));

    ui -> tableView -> verticalHeader() -> hide(); // 隐藏行号
    ui -> tableView -> setModel(_model);
    ui -> tableView -> setRootIndex(_model -> index(customPath));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_expanded(const QModelIndex &index)
{
    if (_model -> isDir(index)) {
        ui -> listView -> setRootIndex(index);
        ui -> tableView -> setRootIndex(index);
    }
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString fileName = _model -> fileName(index);
    qint64 size = _model -> size(index);
    QString type = _model -> type(index);
    bool isDir = _model -> isDir(index);
    QString filePath = _model -> filePath(index);

    ui -> labelFileName -> setText(fileName);
    ui -> labelFileSize -> setText(QString::number(size));
    ui -> labelNodeType -> setText(type);
    ui -> labelFilePath -> setText(filePath);
    ui -> checkBox -> setChecked(isDir);
}
