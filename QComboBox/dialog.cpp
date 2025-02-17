#include "dialog.h"
#include "ui_dialog.h"
#include <QIcon>
#include <QStringList>
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

void Dialog::initUI()
{
    QIcon image1(":/images/basketball.png");
    QIcon image2(":/images/baseball.png");
    ui -> comboBoxLove -> addItem(image1, "篮球");
    ui -> comboBoxLove -> addItem(image2, "排球");

    QStringList list;
    list << "大学" << "中学" << "大学";
    ui -> comboBoxXueli -> addItems(list);

    ui -> comboBoxCity -> addItem("北京", "010");
    ui -> comboBoxCity -> addItem("上海", "021");
    ui -> comboBoxCity -> addItem("杭州", "0571");
}

void Dialog::set_label_text()
{
    QString xueli = ui -> comboBoxXueli -> currentText();
    QString city = ui -> comboBoxCity -> currentText();
    QString number = ui -> comboBoxCity -> currentData().toString();
    QString like = ui -> comboBoxLove -> currentText();
    QString label_text = "学历是:" + xueli + " 所在城市:" + city + " 区号:" + number + " 个人喜好:" + like;
    ui -> label_4 -> setText(label_text);
}


void Dialog::on_comboBoxXueli_currentIndexChanged(int index)
{
    set_label_text();
}

void Dialog::on_comboBoxCity_currentIndexChanged(int index)
{
    set_label_text();
}

void Dialog::on_comboBoxLove_currentIndexChanged(int index)
{
    set_label_text();
}
