#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton* _change_color_y;
    QPushButton* _change_color_g;
    QPushButton* _change_color_b;
    QLabel* _yellow_change;
    QLabel* _green_change;
    QLabel* _blue_change;
private slots:
    void changeToYellow();
    void changeToGreen();
    void changeToBlue();
};
#endif // MAINWINDOW_H
