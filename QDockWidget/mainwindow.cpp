#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionTang_triggered(bool checked)
{
    ui -> dockWidgetTang -> setVisible(checked);
}

void MainWindow::on_actionSong_triggered(bool checked)
{
    ui -> dockWidgetSong -> setVisible(checked);
}

void MainWindow::on_dockWidgetSong_visibilityChanged(bool visible)
{
    ui -> actionSong -> setChecked(visible);
}

void MainWindow::on_dockWidgetTang_visibilityChanged(bool visible)
{
    ui -> actionTang -> setChecked(visible);
}
