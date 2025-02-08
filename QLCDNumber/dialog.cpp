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

void Dialog::on_dial_valueChanged(int value)
{
    ui -> lcdNumber -> display(value);
}

void Dialog::on_radioButton10_clicked()
{
    ui -> lcdNumber -> setDigitCount(3);
    ui -> lcdNumber -> setMode(QLCDNumber::Dec);
}

void Dialog::on_radioButton2_clicked()
{
    ui -> lcdNumber -> setDigitCount(8);
    ui -> lcdNumber -> setMode(QLCDNumber::Bin);
}

void Dialog::on_radioButton8_clicked()
{
    ui -> lcdNumber -> setDigitCount(3);
    ui -> lcdNumber -> setMode(QLCDNumber::Oct);
}

void Dialog::on_radioButton16_clicked()
{
    ui -> lcdNumber -> setDigitCount(2);
    ui -> lcdNumber -> setMode(QLCDNumber::Hex);
}
