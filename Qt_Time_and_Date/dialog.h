#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_spinBox1_valueChanged(int arg1);

    void on_spinBox2_valueChanged(int arg1);

    void on_spinBox3_valueChanged(int arg1);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
