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
    void on_pushButtonCalculate_clicked();

    void on_pushButtonConvert10_clicked();

    void on_pushButtonConvert2_clicked();

    void on_pushButtonConvert16_clicked();

    void on_pushButtonClear_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
