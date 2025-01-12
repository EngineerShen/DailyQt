#include "mainwindow.h"
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QList>
#include <QHash>
#include <iostream>
#include <QVector>
#include <QMap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

void MainWindow::test_QStringList(){
    QStringList programLanguages;

    // QStringList: 新增
    programLanguages << "C" << "C++" << "Java";
    programLanguages.append("PHP");
    programLanguages.insert(2, "Golang");
    qDebug() << programLanguages;

    // QStringList: 查看每个元素 (迭代器遍历/for循环下标遍历)
    QStringList::const_iterator it_1 = programLanguages.constBegin();
    while (it_1 != programLanguages.end()) {
        qDebug() << it_1 -> toUtf8().constData();
        ++it_1;
    }
    for (int i = 0; i < programLanguages.size(); i++) {
        qDebug() << programLanguages[i].toUtf8().constData();
    }

    // QStringList: 修改元素内容 (contains/[]下标/replaceInStrings替换部分内容)
    QString new_pl("Rust");
    if (programLanguages.contains("PHP")) {
        int index = programLanguages.indexOf("PHP");
        programLanguages[index] = new_pl;
    }
    qDebug() << programLanguages;
    programLanguages.replaceInStrings("++", "PP");
    qDebug() << programLanguages;

    // QStringList: 删除
    QString del_pl_1 = "Rust", del_pl_2 = "Java";
    programLanguages.removeOne(del_pl_1);
    qDebug() << programLanguages;
    if (programLanguages.contains(del_pl_2)) {
        programLanguages.removeAt(programLanguages.indexOf(del_pl_2));
    }
    qDebug() << programLanguages;
}

void MainWindow::test_QVariant() {
    // QVariant: 插入
    QHash<QString, QVariant> luckyItems;

    QList<int> cooper_lucky_list = {9, 8, 7, 6, 5, 4, 3 ,2 ,1, 0};
    QVector<char> Zuck_lucky_list = {'M', 'E', 'T', 'A'};
    QMap<int, QString> Tim_lucky_list = {{1, "iPhone 15"}, {2, "iPhone 16"}};
    QStringList Lee_lucky_list = {"Everything has to be experienced in practice.", "The future is very bright!"};

    luckyItems.insert("Jack", 100);
    luckyItems.insert("John", 99.99);
    luckyItems.insert("Mike", true);
    luckyItems.insert("Eric", 'E');
    luckyItems.insert("Daroem", "Software Engineer");
    luckyItems.insert("Elon", QString("SpaceX & Telsa"));
    luckyItems.insert("Cooper", QVariant::fromValue(cooper_lucky_list));
    luckyItems.insert("Zuck", QVariant::fromValue(Zuck_lucky_list));
    luckyItems.insert("Tim", QVariant::fromValue(Tim_lucky_list));
    luckyItems.insert("Lee", QVariant::fromValue(Lee_lucky_list));
    luckyItems.insert("Ben", QVariant::fromValue(computer("i9-13900HX", "RTX 4080 Laptop GPU", 1024)));

    // QVariant: 查看
    QHash<QString, QVariant>::const_iterator it_1 = luckyItems.constBegin();
    while (it_1 != luckyItems.end()) {
        if (it_1.key() == "Jack") { qDebug() << it_1.key() << ":" << it_1.value().type() << " => " << it_1.value().toInt(); }
        else if (it_1.key() == "John") { qDebug() << it_1.key() << ":" << it_1.value().type() << " => " << it_1.value().toDouble(); }
        else if (it_1.key() == "Mike") { qDebug() << it_1.key() << ":" << it_1.value().type() << " => " << it_1.value().toBool(); }
        else if (it_1.key() == "Eric") { qDebug() << it_1.key() << ":" << it_1.value().type() << " => " << it_1.value().value<char>(); }
        else if (it_1.key() == "Daroem") { qDebug() << it_1.key() << ":" << it_1.value().type() << " => " << it_1.value().toString(); }
        else if (it_1.key() == "Elon") { qDebug() << it_1.key() << ":" << it_1.value().type() << " => " << it_1.value().value<QString>(); }
        else if (it_1.key() == "Cooper") { qDebug() << it_1.key() << ":" << it_1.value().type() << " => " << it_1.value().value<QList<int>>(); }
        else if (it_1.key() == "Zuck") { qDebug() << it_1.key() << ":" << it_1.value().type() << " => " << it_1.value().value<QVector<char>>(); }
        else if (it_1.key() == "Tim") { qDebug() << it_1.key() << ":" << it_1.value().type() << " => " << it_1.value().value<QMap<int, QString>>(); }
        else if (it_1.key() == "Lee") { qDebug() << it_1.key() << ":" << it_1.value().type() << " => " << it_1.value().value<QStringList>(); }
        else if (it_1.key() == "Ben") {
            qDebug().noquote() << it_1.key() << ":" << it_1.value().type() << " => ";
            it_1.value().value<computer>().show_computer();
        }
        ++it_1;
    }

    // QVariant: canConvert 函数
    QVariant tmp = QVariant::fromValue(computer("i9-14900HX", "RTX 5090 Laptop GPU", 2048));
    if (tmp.canConvert<int>()) {
        qDebug() << "'包装袋'里的内容可以被解释成整数";
    }
    else { qDebug() << "'包装袋'里的内容不可以被解释成整数"; }
    if (tmp.canConvert<computer>()) { tmp.value<computer>().show_computer(); }
    else { qDebug() << "'包装袋'里的内容不可以被解释成自定义类:计算机"; }
}

MainWindow::~MainWindow()
{
}

