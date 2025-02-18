#include "myqqinfo.h"
#include "ui_myqqinfo.h"

MyQQInfo::MyQQInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyQQInfo)
{
    ui->setupUi(this);
}

MyQQInfo::~MyQQInfo()
{
    delete ui;
}

void MyQQInfo::setPicture(const QString &fileName)
{
    QPixmap pixmap(fileName);
    ui -> label -> setPixmap(pixmap);
    ui -> label -> setScaledContents(true);
}

void MyQQInfo::setNickName(const QString &nickName)
{
    ui -> labelNickName ->setText(nickName);
}

void MyQQInfo::setJianJie(const QString &jianJie)
{
    ui -> labelJianJie -> setText(jianJie);
}
