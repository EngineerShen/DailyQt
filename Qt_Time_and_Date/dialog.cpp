#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QDateTime now = QDateTime::currentDateTime();
    ui -> timeEdit1 -> setTime(now.time());
    ui -> dateEdit1 -> setDate(now.date());
    ui -> dateTimeEdit1 -> setDateTime(now);
}

void Dialog::on_spinBox1_valueChanged(int arg1)
{
    QTime time = ui -> timeEdit1 -> time();
    QTime newtime = time.addSecs(arg1 * 3600);
    ui -> timeEdit2 -> setTime(newtime);
}

void Dialog::on_spinBox2_valueChanged(int arg1)
{
    QDate date = ui -> dateEdit1 -> date();
    QDate newdate = date.addDays(arg1);
    ui -> dateEdit2 -> setDate(newdate);
}

void Dialog::on_spinBox3_valueChanged(int arg1)
{
    QDateTime datetime = ui -> dateTimeEdit1 -> dateTime();
    QDateTime newDateTime = datetime.addDays(arg1);
    ui -> dateTimeEdit2 -> setDateTime(newDateTime);
}
