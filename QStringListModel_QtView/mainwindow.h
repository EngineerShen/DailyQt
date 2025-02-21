#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QModelIndex>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAppend_clicked();

    void on_pushButtonInsert_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButtonClear_clicked();

    void on_pushButtonInit_clicked();

    void on_pushButtonClearText_clicked();

    void on_pushButtonDisplayModel_clicked();

    void on_pushButtonDel_clicked();

private:
    Ui::MainWindow *ui;

    QStringListModel* _model;

    QModelIndex _index1;
    QModelIndex _index2;
};
#endif // MAINWINDOW_H
