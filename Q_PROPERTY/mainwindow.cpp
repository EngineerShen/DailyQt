#include "mainwindow.h"
#include "student.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::test_1() {
    Student* s1 = new Student("Junyang Shen");
    connect(s1, &Student::scoreChanged, s1, &Student::afterScoreChanged);

    qDebug() << s1 -> property("s_name").toString();

    s1 -> setProperty("s_integral", 20000);
    qDebug() << s1 -> property("s_integral").toInt();

    s1 -> setProperty("s_score", 99);
    qDebug() << s1 -> property("s_score").toInt();

    // 动态属性
    s1 -> setProperty("s_age", 21);
    qDebug() << s1 -> property("s_age").toInt();

    s1 -> setProperty("s_addr", "Hangzhou China");
    qDebug() << s1 -> property("s_addr").toString();
}

