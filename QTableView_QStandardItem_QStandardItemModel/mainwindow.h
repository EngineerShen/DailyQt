#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTreeView>
#include <QTableView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>
#include <QList>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QVBoxLayout* _layout;
    QLabel* _header;
    QTreeView* _tree_view;
    QTableView* _table_view;
    QStandardItemModel* _model;
    QStandardItemModel* _syllabus;
    QPushButton* _confirm;

private slots:
    void on_confirm_clicked();
};
#endif // MAINWINDOW_H
