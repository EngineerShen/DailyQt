#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

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

void Dialog::on_pushButtonCalculate_clicked()
{
//    int count = ui -> lineEditCount -> text().toInt();
//    float price = ui -> lineEditPrice -> text().toFloat();
    int count = ui -> spinBoxCount -> value();
    float price = ui -> doubleSpinBoxPrice -> value();
    float totalPrice = count * price;
//    ui -> lineEditTotalPrice -> setText(QString::number(totalPrice, 'f', 2));
    ui -> doubleSpinBoxTotalPrice -> setValue(totalPrice);
}

void Dialog::on_pushButtonConvert10_clicked()
{
//    bool ok;
//    int number_10 = ui -> lineEditNumber10 -> text().toInt(&ok);
//    if (!ok) { QMessageBox::information(this, "Tip", "转换失败!"); }
//    else {
//        ui -> lineEditNumber2 -> setText(QString::number(number_10, 2));
//        ui -> lineEditNumber16 -> setText(QString::number(number_10, 16).toUpper());
//    }
    ui -> spinBox2 -> setValue(ui -> spinBox10 -> value());
    ui -> spinBox16 -> setValue(ui -> spinBox10 -> value());
}

void Dialog::on_pushButtonConvert2_clicked()
{
//    bool ok;
//    int number_2 = ui -> lineEditNumber2 -> text().toInt(&ok, 2);
//    if (!ok) { QMessageBox::information(this, "Tip", "转换失败!"); }
//    else {
//        ui -> lineEditNumber10 -> setText(QString::number(number_2, 10));
//        ui -> lineEditNumber16 -> setText(QString::number(number_2, 16).toUpper());
//    }
    ui -> spinBox10 -> setValue(ui -> spinBox2 -> value());
    ui -> spinBox16 -> setValue(ui -> spinBox2 -> value());
}

void Dialog::on_pushButtonConvert16_clicked()
{
//    bool ok;
//    int number_16 = ui -> lineEditNumber16 -> text().toInt(&ok, 16);
//    if (!ok) { QMessageBox::information(this, "Tip", "转换失败!"); }
//    else {
//        ui -> lineEditNumber10 -> setText(QString::number(number_16, 10));
//        ui -> lineEditNumber2 -> setText(QString::number(number_16, 2));
//    }
    ui -> spinBox2 -> setValue(ui -> spinBox16 -> value());
    ui -> spinBox10 -> setValue(ui -> spinBox16 -> value());
}

void Dialog::on_pushButtonClear_clicked()
{
    ui -> spinBox2 -> clear();
    ui -> spinBox10 -> clear();
    ui -> spinBox16 -> clear();
}
