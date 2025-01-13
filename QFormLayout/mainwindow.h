#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QFormLayout* _formLayout;

    QLineEdit* _name_input;

    QLineEdit* _college_input;

    QLineEdit* _email_input;

    QLineEdit* _tele_input;

    QPushButton* _submit;
};
#endif // MAINWINDOW_H
