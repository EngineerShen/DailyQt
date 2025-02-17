#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void listWidget_addItem(const QString& text);

    void set_listWidget();

    void set_toolbutton();

private slots:
    void on_pushButtonAdd_clicked();

    void on_actionModeIcon_triggered();

    void on_actionModeList_triggered();

    void on_actionSelectAll_triggered();

    void on_actionSelectReverse_triggered();

    void on_actionDel_triggered();

    void on_listWidget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
