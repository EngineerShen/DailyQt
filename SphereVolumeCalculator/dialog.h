#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

const double PI = 3.1415926;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void VolumeCalculating();

private:
    QLabel* _label1;
    QLabel* _label2;
    QLineEdit* _lineEdit;
    QPushButton* _pushButton;
};

#endif // DIALOG_H
