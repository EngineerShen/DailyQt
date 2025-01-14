#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QButtonGroup>
#include <QPalette>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGridLayout* _layout;
    QLabel* _choose_color;
    QRadioButton* _button_green;
    QRadioButton* _button_red;
    QRadioButton* _button_black;
    QPushButton* _submit;
    QLabel* _result_display;
    QPalette* _pal;
private slots:
    void submit_after();

};
#endif // MAINWINDOW_H
