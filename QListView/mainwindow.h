#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QListView>
#include <QLabel>
#include <QStringList>
#include <QStandardItemModel>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showInfo(const QModelIndex& index);
    void submitAfter();

private:
    QVBoxLayout* _layout;
    QLabel* _header;
    QListView* _view;
    QStandardItemModel* _model;
    QPushButton* _submit;

    QString _choice;
};
#endif // MAINWINDOW_H
