#include "student.h"
#include <QDebug>

Student::Student(const QString& name, int integral, int score, QObject *parent)
    : QObject(parent)
    , _name(name)
    , _integral(integral)
    , _score(score)
{}

// _score读写方法
void Student::setScore(int new_score) {
    _score = new_score;
    emit scoreChanged(new_score);
}

int Student::getScore() const {
    return _score;
}

// _name读方法
QString Student::getName() const {
    return _name;
}

// _score变化后的槽函数
void Student::afterScoreChanged(int new_score) {
    qDebug() << "槽函数: " << _name.toUtf8().data() << "的成绩修改为: " << new_score;
}
