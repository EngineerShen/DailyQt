#include "mainwindow.h"
#include <QMessageBox>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Chinese Poetry");

    // 布局设置
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    _layout = new QVBoxLayout(centralWidget);

    // _textEdit相关
    _textEdit = new QTextEdit(centralWidget);
    _layout -> addWidget(_textEdit);
    _textEdit -> setFixedSize(200, 100);

    // _button相关
    _button = new QPushButton("go on ....", centralWidget);
    _layout -> addWidget(_button);

    // _lineEdit相关
    _lineEdit = new QLineEdit(centralWidget);
    _lineEdit -> setReadOnly(true);
    _layout -> addWidget(_lineEdit);

    // 信号与槽
    connect(_button, &QPushButton::clicked, this, &MainWindow::buttonClicked);
}

MainWindow::~MainWindow()
{
}

void MainWindow::buttonClicked() {
    QString fulltext = _textEdit -> toPlainText();
    if (fulltext.isEmpty()) {
        QMessageBox::information(this, "Failed", "Please enter text content first!");
    }
    else {
        QString ret;
        QStringList qList = fulltext.split("\n");
        for (auto& str : qList) {
            ret += str[0];
        }
        _lineEdit -> setText(ret);
    }
}

