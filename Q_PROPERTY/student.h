#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QString>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(const QString& name, int integral = 0, int score = 0, QObject *parent = nullptr);

    // Qt属性
    Q_PROPERTY(QString s_name READ getName);
    Q_PROPERTY(int s_integral MEMBER _score);
    Q_PROPERTY(int s_score READ getScore WRITE setScore NOTIFY scoreChanged);

    // _score读写方法
    void setScore(int new_score);
    int getScore() const;

    // _name读方法
    QString getName() const;

signals:
    // _score变化时的信号
    void scoreChanged(int new_score);

public slots:
    // _score变化后的槽函数
    void afterScoreChanged(int new_score);

private:
    const QString _name;   // 只读
    int _integral;   // 最简单属性
    int _score;      // 可读可写
};

#endif // STUDENT_H
