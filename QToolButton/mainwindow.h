#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMenu>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QLabel>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QVBoxLayout* _layout;
    QToolButton* _my_Button;
    QMenu* _my_menu;

private slots:
    void toolButton_clicked();

    void menu_triggered();
};
#endif // MAINWINDOW_H
