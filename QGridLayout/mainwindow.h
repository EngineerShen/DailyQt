#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGridLayout* _gridLayout;           // 网格布局对象指针

    QHBoxLayout* _hbox_layout;          // 水平布局对象指针
    QRadioButton* _pl_1;                // 水平布局中的子控件对象指针
    QRadioButton* _pl_2;
    QRadioButton* _pl_3;
    QRadioButton* _pl_4;
    QLabel* _pl_select_info;
    QPushButton* _pl_select_ok;

    QVBoxLayout* _vbox_layout;          // 垂直布局对象指针
    QCheckBox* _class_1;                // 垂直布局中的子控件对象指针
    QCheckBox* _class_2;
    QCheckBox* _class_3;
    QCheckBox* _class_4;
    QCheckBox* _class_5;
    QLabel* _cl_select_info;
    QPushButton* _cl_select_ok;

    QLineEdit* _words;                  // 寄语输入框对象指针
    QLabel* _wd_input_info;             // 输入提示标签

    QLineEdit* _name;                   // 姓名输入框对象指针
    QLabel* _ne_input_info;             // 输入提示标签

    QPushButton* _submit;               // 提交按钮对象指针
};
#endif // MAINWINDOW_H
