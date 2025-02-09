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

private slots:
    void on_slider_valueChanged();

    void on_horizontalScrollBar_valueChanged(int value);

    void on_dial_valueChanged(int value);

private:
    Ui::Dialog *ui;

    void initSignalSlots();
};
#endif // DIALOG_H
