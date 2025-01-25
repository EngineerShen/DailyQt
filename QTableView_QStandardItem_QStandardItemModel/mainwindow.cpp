#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("QTableView_QStandardItem_QStandardItemModel");

    // 布局设置
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    _layout = new QVBoxLayout(centralWidget);

    // _header相关
    _header = new QLabel(" -- Physics test scores -- ", centralWidget);
    _header -> setAlignment(Qt::AlignCenter);
    _layout -> addWidget(_header);

    // _table_view视图与其模型相关
    _model = new QStandardItemModel();
    _model -> setHorizontalHeaderItem(0, new QStandardItem("Name"));
    _model -> setHorizontalHeaderItem(1, new QStandardItem("Gender"));
    _model -> setHorizontalHeaderItem(2, new QStandardItem("Class"));
    _model -> setHorizontalHeaderItem(3, new QStandardItem("Score"));

    _model -> setItem(0, 0, new QStandardItem("Jack"));
    _model -> setItem(0, 1, new QStandardItem("Male"));
    _model -> setItem(0, 2, new QStandardItem("101"));
    _model -> setItem(0, 3, new QStandardItem("98"));

    _model -> setItem(1, 0, new QStandardItem("Eric"));
    _model -> setItem(1, 1, new QStandardItem("Male"));
    _model -> setItem(1, 2, new QStandardItem("102"));
    _model -> setItem(1, 3, new QStandardItem("90"));

    _model -> setItem(2, 0, new QStandardItem("Elon"));
    _model -> setItem(2, 1, new QStandardItem("Male"));
    _model -> setItem(2, 2, new QStandardItem("42"));
    _model -> setItem(2, 3, new QStandardItem("100"));

    _table_view = new QTableView(centralWidget);
    _table_view -> setModel(_model);
    _table_view -> setFixedSize(650, 200);
    _table_view -> setEditTriggers(QAbstractItemView::NoEditTriggers);

    QList<QStandardItem*> rowItems;
    rowItems << new QStandardItem("Ivana") << new QStandardItem("Female") << new QStandardItem("103") << new QStandardItem("60");
    _model -> appendRow(rowItems);

    _layout -> addWidget(_table_view);

    // _tree_view视图与其模型相关
    _syllabus = new QStandardItemModel();
    _syllabus -> setHorizontalHeaderItem(0, new QStandardItem("Score Layout"));
    _syllabus -> setHorizontalHeaderItem(1, new QStandardItem("Lecturer"));
    _syllabus -> setHorizontalHeaderItem(2, new QStandardItem("Examiner"));

    QStandardItem* _total = new QStandardItem("Physics [100]");
    QStandardItem* _ClassicalMechanics = new QStandardItem("ClassicalMechanics [20]");
    QStandardItem* _Electromagnetism = new QStandardItem("Electromagnetism [30]");
    QStandardItem* _Thermodynamics = new QStandardItem("Thermodynamics [40]");
    QStandardItem* _StatisticalMechanics = new QStandardItem("StatisticalMechanics [10]");

    _total -> appendRow(_ClassicalMechanics);
    _total -> appendRow(_Electromagnetism);
    _total -> appendRow(_Thermodynamics);
    _total -> appendRow(_StatisticalMechanics);

    _ClassicalMechanics -> appendRow(new QStandardItem("1. [10]"));
    _ClassicalMechanics -> appendRow(new QStandardItem("2. [10]"));
    _Electromagnetism -> appendRow(new QStandardItem("3. [10]"));
    _Electromagnetism -> appendRow(new QStandardItem("4. [20]"));
    _Thermodynamics -> appendRow(new QStandardItem("5. [25]"));
    _Thermodynamics -> appendRow(new QStandardItem("6. [15]"));
    _StatisticalMechanics -> appendRow(new QStandardItem("7. [5]"));
    _StatisticalMechanics -> appendRow(new QStandardItem("8. [5]"));

    QStandardItem* _lecturer = new QStandardItem("Matthew");
    QStandardItem* _examiner = new QStandardItem("Brown");

    _syllabus -> setItem(0, 0, _total);
    _syllabus -> setItem(0, 1, _lecturer);
    _syllabus -> setItem(0, 2, _examiner);

    _tree_view = new QTreeView(centralWidget);
    _tree_view ->setModel(_syllabus);
    _tree_view -> setFixedSize(650, 100);

    _layout -> addWidget(_tree_view);

    // _confirm相关
    _confirm = new QPushButton("I already know", centralWidget);
    _layout -> addWidget(_confirm);

    // 信号与槽
    connect(_confirm, &QPushButton::clicked, this, &MainWindow::on_confirm_clicked);
}

void MainWindow::on_confirm_clicked() {
    QMessageBox::information(this, "physics", "Thank you for your attention.");
}

MainWindow::~MainWindow()
{
}

