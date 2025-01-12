#include <QCoreApplication>
#include <iostream>
#include <QList>
#include <QString>
#include <QDebug>
#include <QLinkedList>
#include <QVector>
#include <QHash>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // *******  QList  *******
    QList<QString> programLanguages;
    // QList: 插入
    programLanguages << "C" << "C++" << "C#" << "HTML" << "CSS";
    programLanguages.append("Java");
    programLanguages.prepend("Basic");
    programLanguages.insert(4, "Golang");
    qDebug() << programLanguages;
    // QList: 删除
    programLanguages.removeAt(5);
    programLanguages.removeOne("CSS");
    programLanguages.pop_back();
    programLanguages.pop_front();
    qDebug() << programLanguages;
    // QList: 迭代器遍历与修改
    QList<QString>::iterator it_1 = programLanguages.begin();
    for (int i = 0; it_1 != programLanguages.end(); i++, it_1++) {
        (*it_1) += ("  ---- No: " + QString::number(i + 1));
    }
    QList<QString>::const_iterator it_2 = programLanguages.constBegin();
    while (it_2 != programLanguages.constEnd()) {
        qDebug().noquote() << *it_2;
        ++it_2;
    }
    // QList: 下标访问
    for (int i = 0; i < programLanguages.size(); i++) {
        std::cout << programLanguages.at(i).toUtf8().constData() << std::endl;
    }
    // QList: contains / indexOf / replace函数
    QString target_1 = "C++  ---- No: 2";
    QString target_2 = "C  ---- No: 1";
    QString target_3 = "Java  ---- No: 1";
    if (programLanguages.contains(target_1)) {
        int real_index = programLanguages.indexOf(target_1);
        programLanguages.replace(real_index, "C++ is GREAT! I Love it!");
    }
    if (programLanguages.contains(target_2)) {
        int real_index = programLanguages.indexOf(target_2);
        programLanguages.replace(real_index, "C language is the basic of everything.");
    }
    if (programLanguages.contains(target_3)) {
        int real_index = programLanguages.indexOf(target_3);
        programLanguages.replace(real_index, "Java is the main technology for backend development.");
    }
    for (int i = 0; i < programLanguages.size(); i++) {
        std::cout << programLanguages.at(i).toUtf8().constData() << std::endl;
    }


    // *******  QLinkedList  *******
    QLinkedList<QString> famousPeople;
    // QLinkedList: 插入 / 迭代器遍历
    famousPeople << "Elon Musk" << "Donald Trump";
    famousPeople.append("Bill Gates");
    famousPeople.prepend("Steve Jobs");
    famousPeople.insert(famousPeople.begin() + 1, "Joe Biden");
    for (QLinkedList<QString>::const_iterator it_1 = famousPeople.constBegin(); it_1 != famousPeople.constEnd(); it_1++) {
        qDebug() << *it_1;
    }
    // QLinkedList: 删除
    famousPeople.pop_front();
    famousPeople.pop_back();
    famousPeople.erase(famousPeople.begin());
    for (QLinkedList<QString>::const_iterator it_1 = famousPeople.constBegin(); it_1 != famousPeople.constEnd(); it_1++) {
        qDebug() << *it_1;
    }
    // QLinkedList: 修改
    QLinkedList<QString>::iterator it_3 = famousPeople.begin();
    *it_3 = "Elon Reeve Musk";
    *(it_3 + 1) = "Donald John Trump";
    for (QLinkedList<QString>::const_iterator it_1 = famousPeople.constBegin(); it_1 != famousPeople.constEnd(); it_1++) {
        qDebug() << *it_1;
    }


    // QString: arg
    QHash<int, QString> my_hash;
    my_hash.insert(1, "ONE");
    my_hash.insert(2, "TWO");
    my_hash.insert(3, "THREE");
    my_hash.insert(4, "FOUR");
    my_hash.insert(5, "FIVE");
    QString templateString("Hello, this is number: %1, and its English Name is %2");
    QVector<QString> res;
    for (int i = 0; i < my_hash.size(); i++) {
        res.push_back(templateString.arg(i + 1).arg(my_hash[i + 1]));
    }
    for (int i = 0; i <res.size(); i++) {
        std::cout << res[i].toUtf8().constData() << std::endl;
    }
    return a.exec();
}
