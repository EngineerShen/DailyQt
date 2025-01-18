#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>

#include <QFrame>
#include <QDockWidget>
#include <QTabWidget>

#include <QLabel>
#include <QImage>
#include <QScrollArea>

#include <QVBoxLayout>
#include <QGridLayout>

#include <QPushButton>
#include <QRadioButton>
#include <QToolButton>

#include <QMenu>
#include <QAction>
#include <QStringList>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGridLayout* _layout;
    QLabel* _header;
    QFrame* _frame_dem;
    QFrame* _frame_rep;

    QDockWidget* _dock_widget;
    QToolButton* dem_people_button;
    QToolButton* rep_people_button;

private slots:
    void dock_widget_menu_triggered_dem();
    void update_dem_buttonText(const QString& option);

    void dock_widget_menu_triggered_rep();
    void update_rep_buttonText(const QString& option);

    void confirm_clicked();
signals:
    void menu_action_chosen_dem(const QString& option);
    void menu_action_chosen_rep(const QString& option);
};
#endif // MAINWINDOW_H
