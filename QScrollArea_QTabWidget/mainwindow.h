#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTabWidget>
#include <QGridLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QGridLayout* _layout;
    QLabel* _header;
    QTabWidget* _widgets;

private slots:
    void after_submit();
};
#endif // MAINWINDOW_H
