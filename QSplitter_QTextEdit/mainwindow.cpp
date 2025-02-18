#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

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

void MainWindow::on_actionInsertPic_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "选择图片");
    QPixmap pixmap(fileName);

//    QTextCursor cursor = ui -> textEdit -> textCursor();
//    QTextDocument* document = ui ->textEdit -> document();
//    document -> addResource(QTextDocument::ImageResource, QUrl("image"), pixmap);
//    cursor.insertImage("image");

    QString html = QString("<img src=\"file:///%1\" />").arg(fileName);
    ui -> textEdit -> insertHtml(html);
}
