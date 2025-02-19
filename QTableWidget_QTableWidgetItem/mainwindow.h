#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QLineEdit>
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

private slots:
    void on_actionInsert_triggered();

    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_actionDel_triggered();

    void on_actionEdit_triggered(bool checked);

    void itemChanged_later(QTableWidgetItem *item);

    void on_pushButton_clicked();

    void on_tableWidget_itemSelectionChanged();

private:
    void initTableWidget();

    void initStatusBar();

    QTableWidgetItem* addNewRow(int row, const QString& name, const QString& gender, const QString& birthday, const QString& job, const QString& married);

private:
    Ui::MainWindow *ui;
    int _currentRow;

    QLineEdit* _lineEdit;
    QPushButton* _button;
    QLabel* _label;
};
#endif // MAINWINDOW_H
