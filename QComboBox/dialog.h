#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void initUI();

    void set_label_text();

private slots:
    void on_comboBoxXueli_currentIndexChanged(int index);

    void on_comboBoxCity_currentIndexChanged(int index);

    void on_comboBoxLove_currentIndexChanged(int index);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
