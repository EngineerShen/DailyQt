#include "mainwindow.h"
#include <QDebug>
#include <QRegularExpression>
#include <QVector>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

void MainWindow::four_algorithm_test() {
    int num1 = -1;
    qDebug() << num1 << "的绝对值是: " << qAbs(num1);

    int small_num = 99;
    int big_num = 100;
    qDebug() << small_num << " vs " << big_num << ": 两者更大的是" << qMax(small_num, big_num);

    double num2 = -4.2;
    double num3 = -4.8;
    qDebug() << num2 << "最接近的整数是: " << qRound(num2);
    qDebug() << num3 << "最接近的整数是: " << qRound(num3);

    int origin_num1 = 101;
    int origin_num2 = 103;
    qDebug() << "num1(原): " << origin_num1 << "; num2(原): " << origin_num2;
    qSwap(origin_num1, origin_num2);
    qDebug() << "num1(现): " << origin_num1 << "; num2(现): " << origin_num2;
}

void MainWindow::rex_test() {
    QRegularExpression emailRegex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    QVector<QString> emails = {"engineer@x.com", "engineer.shen@x.com", "engineer_shen@x.com", "engineer_@x.com",
                               "@x.com", "_@x.com", "engineer@x", "engineer@x." , "engineer@.com" , "engineer@x.co.us",
                              "#@x.com", "^engineer^@x.com" };

    QVector<QString>::const_iterator it = emails.constBegin();

    while (it != emails.constEnd()) {
        QRegularExpressionMatch match = emailRegex.match(*it);
        if (match.hasMatch()) {
            qDebug() << *it << "  => 匹配成功!";
        }
        else {
            qDebug() << *it << "  => 匹配失败!";
        }
        ++it;
    }
}

/*
正则表达式:  (\w+)  (\.|_)?  (\w*)  @  (\w+)  (\.(\w+))+

(\w+)           匹配一个或多个单词字符
(\.|_)?         可以出现零个或者一个 '.' or '_'
(\w*)           匹配零个或多个单词字符
@               即字面意义上的@
(\w+)           匹配一个或多个单词字符
(\.(\w+))+      一个'.'再加上一个或者多个单词字符, 可以多次重复

所谓的单词字符: a-z A-Z 0-9 _(下划线)

*/

MainWindow::~MainWindow()
{
}
