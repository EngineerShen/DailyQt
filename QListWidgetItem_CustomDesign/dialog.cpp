#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    initUI();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::initUI() {
    page1_addItems(33);
    page2_addItems(40);
    page3_addItems(7);
    page4_addItems(3);
}

void Dialog::page1_addItems(int count)
{
    for (int i = 0; i < count; i++) {

        QListWidgetItem* new_item = new QListWidgetItem();
        new_item -> setSizeHint(QSize(400, 150));
        ui -> listWidget1 -> addItem(new_item);

        MyQQInfo* new_info = new MyQQInfo(this);
        new_info -> setPicture(":/images/qq.png");
        new_info -> setNickName("挚友" + QString::number(i + 1));
        new_info ->setJianJie("好好学习, 天天向上!");

        ui -> listWidget1 -> setItemWidget(new_item, new_info);
    }
}

void Dialog::page2_addItems(int count)
{
    for (int i = 0; i < count; i++) {

        QListWidgetItem* new_item = new QListWidgetItem();
        new_item -> setSizeHint(QSize(400, 150));
        ui -> listWidget2 -> addItem(new_item);

        MyQQInfo* new_info = new MyQQInfo(this);
        new_info -> setPicture(":/images/qq.png");
        new_info -> setNickName("好友" + QString::number(i + 1));
        new_info ->setJianJie("加油干!");

        ui -> listWidget2 -> setItemWidget(new_item, new_info);
    }
}

void Dialog::page3_addItems(int count)
{
    for (int i = 0; i < count; i++) {

        QListWidgetItem* new_item = new QListWidgetItem();
        new_item -> setSizeHint(QSize(400, 150));
        ui -> listWidget3 -> addItem(new_item);

        MyQQInfo* new_info = new MyQQInfo(this);
        new_info -> setPicture(":/images/qq.png");
        new_info -> setNickName("同学" + QString::number(i + 1));
        new_info ->setJianJie("怀念往昔!");

        ui -> listWidget3 -> setItemWidget(new_item, new_info);
    }
}

void Dialog::page4_addItems(int count)
{
    for (int i = 0; i < count; i++) {

        QListWidgetItem* new_item = new QListWidgetItem();
        new_item -> setSizeHint(QSize(400, 150));
        ui -> listWidget4 -> addItem(new_item);

        MyQQInfo* new_info = new MyQQInfo(this);
        new_info -> setPicture(":/images/qq.png");
        new_info -> setNickName("死敌" + QString::number(i + 1));
        new_info ->setJianJie("有种来干一架!");

        ui -> listWidget4 -> setItemWidget(new_item, new_info);
    }
}

