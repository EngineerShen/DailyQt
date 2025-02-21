#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _model = new QStringListModel();
    QStringList datalist = {"北京", "上海", "广州", "深圳", "杭州", "武汉"};
    _model -> setStringList(datalist);

    ui -> listView -> setModel(_model);
    ui -> tableView -> setModel(_model);
    ui -> tableView -> horizontalHeader() -> hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAppend_clicked()
{
    int row = _model -> rowCount();
    _model -> insertRows(row, 1);
    _model -> setData(_model -> index(row), "新的城市");
}

void MainWindow::on_pushButtonInsert_clicked()
{
    _model -> insertRows(_index1.row(), 1);
    _model -> setData(_index1, "新的城市");

    ui -> listView -> setCurrentIndex(_index1);
    ui -> tableView -> setCurrentIndex(_index2);
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    _index1 = _index2 = index;
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    _index1 = _index2 = index;
}

void MainWindow::on_pushButtonClear_clicked()
{
    QStringList list;
    _model -> setStringList(list);
}

void MainWindow::on_pushButtonInit_clicked()
{
    QStringList datalist = {"北京", "上海", "广州", "深圳", "杭州", "武汉"};
    _model -> setStringList(datalist);
}

void MainWindow::on_pushButtonClearText_clicked()
{
    ui -> plainTextEdit -> clear();
}

void MainWindow::on_pushButtonDisplayModel_clicked()
{
    ui -> plainTextEdit -> clear();

    QStringList list = _model -> stringList();

    for (const QString& line : list) {
        ui -> plainTextEdit -> appendPlainText(line);
    }
}

void MainWindow::on_pushButtonDel_clicked()
{
    _model -> removeRows(_index1.row(), 1);
}
