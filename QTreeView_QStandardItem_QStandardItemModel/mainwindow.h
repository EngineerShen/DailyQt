#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QVBoxLayout* _layout;
    QLabel* _header;
    QTreeView* _view;
    QStandardItemModel* _model;
    QPushButton* _submit;
    QString _choice;

private slots:
    void onItemClicked(const QModelIndex& index);
    void submitAfter();

};
#endif // MAINWINDOW_H
