#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>

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
    void on_calendarWidget_selectionChanged();

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

    void timer_time_out();

private:
    Ui::Dialog *ui;
    QTimer* _timer;
};
#endif // DIALOG_H
