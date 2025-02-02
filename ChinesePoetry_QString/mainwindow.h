#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void buttonClicked();

private:
    QVBoxLayout* _layout;
    QTextEdit* _textEdit;
    QPushButton* _button;
    QLineEdit* _lineEdit;
};
#endif // MAINWINDOW_H
