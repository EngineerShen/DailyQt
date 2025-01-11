#include <QCoreApplication>
#include <QDebug>
#include <QMap>
#include <QList>
#include <QDateTime>
#include <QHash>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    // *********  QMap  *********
    QMap<QString, int> my_scores;
    // QMap: 插入
    my_scores.insert("C/C++", 93);
    my_scores.insert("LinuxOS", 95);
    my_scores["NetWork"] = 97;
    my_scores["DataStructure"] = 99;
    my_scores["Chinese"] = 60;
    qDebug() << my_scores;
    // QMap: 删除
    my_scores.remove("Chinese");
    qDebug() << my_scores;
    // QMap: 修改
    my_scores["Java"] = 94;
    my_scores["C/C++"] = 96;
    qDebug() << my_scores;
    // QMap: 迭代器遍历
    QMap<QString, int>::const_iterator it = my_scores.constBegin();
    while (it != my_scores.constEnd()) {
        qDebug() << it.key() << ": " << it.value();
        ++it;
    }
    // QMap: 根据键查找值
    QString c_name_1 = "LinuxOS", c_name_2 = "Python";
    if (my_scores.contains(c_name_1)) { qDebug() << c_name_1 << ": " << my_scores[c_name_1]; }
    else { qDebug() << c_name_1 << ": " << "无成绩!"; }
    if (my_scores.contains(c_name_2)) { qDebug() << c_name_2 << ": " << my_scores[c_name_2]; }
    else { qDebug() << c_name_2 << ": " << "无成绩!"; }
    // QMap: 查看所有的键
    QList<QString> allKeys = my_scores.keys();
    qDebug() << allKeys;


    // *********  QMultiMap  *********
    QMultiMap<QDateTime, QString> my_schedule;
    // QMultiMap: 插入
    my_schedule.insert(QDateTime(QDate(2025, 1, 11)), "C/C++");
    my_schedule.insert(QDateTime(QDate(2025, 1, 11)), "Java");
    my_schedule.insert(QDateTime(QDate(2025, 1, 12)), "LinuxOS");
    my_schedule.insert(QDateTime(QDate(2025, 1, 12)), "NetWork");
    my_schedule.insert(QDateTime(QDate(2025, 1, 13)), "Chinese");
    my_schedule.insert(QDateTime(QDate(2025, 1, 14)), "English");
    qDebug() << my_schedule;
    // QMultiMap: 删除
    QMultiMap<QDateTime, QString>::iterator it_1 = my_schedule.find(QDateTime(QDate(2025, 1, 12)), "LinuxOS");
    if (it_1 != my_schedule.end()) { my_schedule.erase(it_1); }
    my_schedule.remove(QDateTime(QDate(2025, 1, 13)));
    qDebug() << my_schedule;
    // QMultiMap: 迭代器遍历
    QMultiMap<QDateTime, QString>::iterator it_2 = my_schedule.begin();
    while (it_2 != my_schedule.end()) {
        qDebug() << it_2.key().toString("yyyy-MM-dd") << ": " << it_2.value();
        ++it_2;
    }
    // QMultiMap: 根据键查找值
    QList<QString> classList = my_schedule.values(QDateTime(QDate(2025, 1, 11)));
    qDebug() << classList;


    // *********  QHash  *********
    QHash<QString, int> commodity;
    // QHash: 插入
    commodity.insert("Model Y", 300000);
    commodity.insert("Model S", 800000);
    commodity.insert("Model X", 1000000);
    commodity.insert("BYD Song", 150000);
    qDebug() << commodity;
    // QHash: 删除
    commodity.remove("BYD Song");
    qDebug() << commodity;
    // QHash: 修改
    commodity["Model Y"] = 240000;
    commodity.insert("Model X", 900000);
    qDebug() << commodity;
    // QHash: 迭代器遍历
    QHash<QString, int>::const_iterator it_3 = commodity.constBegin();
    while (it_3 != commodity.constEnd()) {
        qDebug() << it_3.key() << ": " << it_3.value();
        ++it_3;
    }
    // QHash: 根据键查找值
    QString car_name_1 = "Model Y", car_name_2 = "Model 3";
    if (commodity.contains(car_name_1)) { qDebug() << car_name_1 << ": " << commodity[car_name_1]; }
    else { qDebug() << car_name_1 << ": 无法找到!"; }
    if (commodity.contains(car_name_2)) { qDebug() << car_name_2 << ": " << commodity[car_name_2]; }
    else { qDebug() << car_name_2 << ": 无法找到!"; }


    // *********  QVector  *********
    QVector<QString> p_l;
    // QVector: 插入
    p_l.push_back("C/C++");
    p_l.push_back("Java");
    p_l.push_back("Python");
    p_l.push_back("HTML");
    p_l.push_back("Golang");
    p_l.push_back("Rust");
    qDebug() << p_l;
    // QVector: 删除
    p_l.remove(1);
    p_l.remove(1, 2);
    qDebug() << p_l;
    // QVector: 修改
    QString new_language = "SQL";
    p_l[2] = new_language;
    qDebug() << p_l;
    // 常规遍历
    for (int i = 0; i < p_l.size(); i++) {
        qDebug().noquote() << p_l[i];
    }

    return a.exec();
}
