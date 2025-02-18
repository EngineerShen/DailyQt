#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionTang_triggered(bool checked);

    void on_actionSong_triggered(bool checked);

    void on_dockWidgetSong_visibilityChanged(bool visible);

    void on_dockWidgetTang_visibilityChanged(bool visible);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
