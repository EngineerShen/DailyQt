#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include "myqqinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    void initUI();

    void page1_addItems(int count);
    void page2_addItems(int count);
    void page3_addItems(int count);
    void page4_addItems(int count);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
