#include "dialog.h"
#include <QGridLayout>
#include <QString>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    // 构造出来四个窗口控件对象
    _label1 = new QLabel("请输入圆球的半径", this);
    _label2 = new QLabel("", this);
    _lineEdit = new QLineEdit(this);
    _pushButton = new QPushButton("点击计算", this);

    // 对这四个窗口控件进行表格布局的形式排列
    QGridLayout* gridlayout = new QGridLayout;
    gridlayout -> addWidget(_label1, 0, 0);
    gridlayout -> addWidget(_label2, 1, 0);
    gridlayout -> addWidget(_lineEdit, 0, 1);
    gridlayout -> addWidget(_pushButton, 1, 1);
    setLayout(gridlayout);

    // 信号与槽的关联
    connect(_pushButton, &QPushButton::clicked, this, &Dialog::VolumeCalculating);
}

void Dialog::VolumeCalculating() {
    QString inputtext = _lineEdit -> text();
    int R = inputtext.toInt();
    double volume = 4 / 3.0 * PI * R * R * R;
    QString result = QString::number(volume, 'f', 4);
    _label2 ->setText(result);
}

Dialog::~Dialog()
{
}