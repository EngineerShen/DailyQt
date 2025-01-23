#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("QListView");

    // 布局设置
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    _layout = new QVBoxLayout(centralWidget);

    // _header相关
    _header = new QLabel("Please select your favorite physicist.", centralWidget);
    _header -> setAlignment(Qt::AlignCenter);
    _layout -> addWidget(_header);

    // 物理学家列表
    QStringList physicists;
    physicists << "Isaac Newton" << "Michael Faraday" << "James Clerk Maxwell" << "Albert Einstein" << "Niels Bohr";
    physicists << "Ernest Rutherford" << "Werner Heisenberg" << "Richard Feynman" << "Stephen Hawking" << "Murray Gell-Mann";
    physicists << "Andre Geim" << "Konstantin Novoselov" << "Peter Higgs" << "David Gross" << "Frank Wilczek";

    // _model相关
    _model = new QStandardItemModel(centralWidget);
    for (const QString& name : physicists) {
        QStandardItem* item = new QStandardItem(name);
        _model->appendRow(item);
    }

    // _view相关 (视图 -- 模型)
    _view = new QListView(centralWidget);
    _view -> setModel(_model);
    _layout -> addWidget(_view);

    // _submit相关
    _submit = new QPushButton("submit", centralWidget);
    _layout ->addWidget(_submit);

    // 信号与槽
    connect(_view, SIGNAL(clicked(const QModelIndex&)), this, SLOT(showInfo(const QModelIndex&)));
    connect(_submit, &QPushButton::clicked, this, &MainWindow::submitAfter);
}

void MainWindow::showInfo(const QModelIndex& index) {
    QString info = index.data().toString();
    _choice = info;
    QMessageBox::information(this, "Item Clicked", "You choose " + info);
}

void MainWindow::submitAfter() {
    QMessageBox::information(this, "Success", "After careful selection, your favorite physicist is " + _choice);
}

MainWindow::~MainWindow()
{
}

