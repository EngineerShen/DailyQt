#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QLabel>

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
    void applyFormat(Qt::Alignment alignment);

private slots:
    void on_actionLoad_triggered();

    void on_actionAdd_triggered();

    void on_actionInsert_triggered();

    void on_actionDel_triggered();

    void on_actionSee_triggered();

    void on_actionLeft_triggered();

    void on_actionMid_triggered();

    void on_actionRight_triggered();

    void on_actionBold_triggered(bool checked);

    void on_selection_changed(const QItemSelection &selected, const QItemSelection &deselected);

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;

    QStandardItemModel* _model;
    QItemSelectionModel* _selectedItems;

    QLabel* _label;
};
#endif // MAINWINDOW_H
