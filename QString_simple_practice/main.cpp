#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <iostream>
#include <QByteArray>
#include <QVector>
#include <QVariant>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QString: +
    qDebug() << "*****   QString: +   *****";
    QString str1 = "Hello";
    QString str2 = "World";
    QString str_1 = str1 + " " + str2;
    qDebug() << str_1;
    qDebug() << "";

    // QString: +=
    qDebug() << "*****   QString: +=   *****";
    QString str3 = "Software";
    QString str_2 = str3 += "Engineer";
    qDebug() << str_2;
    qDebug() << "";

    // QString: append函数
    qDebug() << "*****   QString: append   *****";
    QString str_3 = "C";
    str_3.append("++");
    qDebug() << str_3;
    qDebug() << "";

    // QString: asprintf函数
    qDebug() << "*****   QString: asprintf   *****";
    QString str4 = "Daroem_1";
    int age_1 = 21;
    double CombatValue_1 = 99.99;
    QString str_4 = QString::asprintf("YourName: %s, YourAge: %d, Combat Value: %.2f", str4.toUtf8().constData(), age_1, CombatValue_1);
    qDebug() << str_4;
    qDebug() << "";

    // QString: arg函数
    qDebug() << "*****   QString: arg   *****";
    QString str5 = "Daroem_2";
    int age_2 = 22;
    double CombatValue_2 = 100;
    QString str_5 = QString ("YourName: %1, YourAge: %2, Combat Value: %3").arg(str5).arg(age_2).arg(CombatValue_2, 0, 'f', 2);
    qDebug() << str_5;
    qDebug() << "";

    // QString: startsWith & endsWith函数
    qDebug() << "*****   QString: startsWith & endsWith   *****";
    QString str6 = "ElonReeveMusk";
    if (str6.startsWith("Elon")) { std::cout << "Elon"; }
    if (str6.endsWith("Musk")) { std::cout << "Musk" << std::endl; }
    qDebug() << "";

    // QString: toInt函数
    qDebug() << "*****   QString: toInt   *****";
    QString str7 = "420";
    int number = str7.toInt();
    qDebug() << number;
    qDebug() << "";

    // QString: compare函数
    qDebug() << "*****   QString: compare   *****";
    QString str8("StarShip");
    QString str9("StarShip");
    QString str10("STARSHIP");
    QString str11("SpaceX");
    int res_1 = str8.compare(str9, Qt::CaseSensitive);
    int res_2 = str8.compare(str10, Qt::CaseSensitive);
    int res_3 = str8.compare(str11, Qt::CaseSensitive);
    qDebug() << res_1 << " " << res_2 << " " << res_3;
    qDebug() << "";

    // QByteArray初识
    qDebug() << "*****   QByteArray   *****";
    QString first_str("Hello Qt!");
    QByteArray byteArray(first_str.toUtf8());
    qDebug() << "原始字符数组: " << byteArray;

    byteArray.append("Hello C++!");
    qDebug() << "追加之后: " << byteArray;

    QString second_str(byteArray);
    qDebug() << "转换为QString: " << second_str;
    qDebug() << "";

    // QVector初识
    qDebug() << "*****   QVector   *****";
    QVector<QString> fruits;
    fruits.push_back("Apple");
    fruits.push_back("Banana");
    fruits.push_back("Cherry");

    std::cout << "当前水果列表: ";
    for (auto& val : fruits) { std::cout << val.toUtf8().constData() << " "; }
    qDebug() << "";

    fruits.insert(1, "Blueberry");
    std::cout << "插入Blueberry之后的列表: ";
    for (auto& val : fruits) { std::cout << val.toUtf8().constData() << " "; }
    qDebug() << "";

    fruits.remove(0);
    std::cout << "插入Apple之后的列表: ";
    for (auto& val : fruits) { std::cout << val.toUtf8().constData() << " "; }
    std::cout << std::endl << std::endl;

    // QVariant初识
    qDebug() << "*****   QVariant   *****";
    QVector<QVariant> test_vector;
    test_vector.push_back(1);
    test_vector.push_back(1.1);
    test_vector.push_back(true);
    test_vector.push_back('C');
    test_vector.push_back("C++");
    test_vector.push_back(QString("Hello Engineer!"));
    for (const auto& val : test_vector) {
        qDebug().noquote() << val << " ";
    }
    qDebug() << "";

    // QDatetime初识
    qDebug() << "*****   QDatetime   *****";
    QDateTime now = QDateTime::currentDateTime();
    qDebug() << "当前的日期与时间(非格式化): " << now.toString();
    qDebug() << "当前的日期与时间(格式化): " << now.toString("yyyy--MM--dd  hh:mm:ss");
    QDateTime specificTime(QDate(2003, 5, 22), QTime(0, 0, 0));
    qDebug() << "特定的日期与时间: " << specificTime.toString();
    qDebug() << "";
    return a.exec();
}
