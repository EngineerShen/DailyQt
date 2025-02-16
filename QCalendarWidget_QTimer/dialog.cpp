#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    _timer = new QTimer(this);

    connect(_timer, &QTimer::timeout, this, &Dialog::timer_time_out);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_calendarWidget_selectionChanged()
{
    QDate date = ui -> calendarWidget -> selectedDate();
    ui -> dateEdit -> setDate(date);

    QString date_str = date.toString("yyyy年MM月dd日");
    ui -> label -> setText(date_str);
}

void Dialog::on_dateEdit_userDateChanged(const QDate &date)
{
    QString date_str = date.toString("yyyy年MM月dd日");
    ui -> label -> setText(date_str);

    ui -> calendarWidget -> setSelectedDate(date);
}

void Dialog::on_pushButtonStart_clicked()
{
    _timer -> start(50);
}

void Dialog::on_pushButtonStop_clicked()
{
    _timer -> stop();
}

void Dialog::timer_time_out() {
    int value = ui -> progressBar -> value() + 1;
    if (value == 101) { value = 0; }
    ui -> progressBar -> setValue(value);
}
