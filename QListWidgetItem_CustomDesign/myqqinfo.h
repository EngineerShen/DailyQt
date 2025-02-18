#ifndef MYQQINFO_H
#define MYQQINFO_H

#include <QWidget>

namespace Ui {
class MyQQInfo;
}

class MyQQInfo : public QWidget
{
    Q_OBJECT

public:
    explicit MyQQInfo(QWidget *parent = nullptr);
    ~MyQQInfo();

    void setPicture(const QString& fileName);

    void setNickName(const QString& nickName);

    void setJianJie(const QString& jianJie);

private:
    Ui::MyQQInfo *ui;
};

#endif // MYQQINFO_H
