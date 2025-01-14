#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPalette>
#include <QHash>
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGridLayout* _layout;
    QCheckBox* _pl_C_Cpp;
    QCheckBox* _pl_Java;
    QCheckBox* _pl_Python;
    QCheckBox* _pl_Golang;
    QLabel* _header;
    QLabel* _result;
    QLabel* _guess;
    QPalette* _pal;
    QHash<QString, int> _choices;
private slots:
    void display_result();
    void onStateChanged_cpp(int state);
    void onStateChanged_java(int state);
    void onStateChanged_python(int state);
    void onStateChanged_golang(int state);
};
#endif // MAINWINDOW_H
