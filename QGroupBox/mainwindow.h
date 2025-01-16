#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QGroupBox>
#include <QMenu>
#include <QToolButton>
#include <QString>
#include <QHash>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QGridLayout* _layout;
    QLabel* _header;
    QPushButton* _submit;
    QGroupBox* _box_1;
    QGroupBox* _box_2;
    QGroupBox* _box_3;
    QGroupBox* _box_4;
    bool _is_registry;
    QHash<QString, QToolButton*> _buttons;
private slots:
    void registry_clicked();
    void submit_clicked();
    void select_tech_company();
    void select_fina_company();
    void select_mili_company();

};
#endif // MAINWINDOW_H
