#include "mainwindow.h"
#include <QMessageBox>
#include <QStringList>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("QGroupBox");
    resize(800, 300);

    // 设置主窗口布局
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    _layout = new QGridLayout();
    centralWidget -> setLayout(_layout);

    // 初始化_is_registry
    _is_registry = false;

    // _header标签构造、设置、放入布局
    _header = new QLabel("   *****  Do you want to be a hardcore engineer?  *****   ", centralWidget);
    _header -> setAlignment(Qt::AlignCenter);
    _layout -> addWidget(_header, 0, 0, 1, 4);

    // 组合1 有关
    _box_1 = new QGroupBox("Please register first..", centralWidget);
    QGridLayout* box1_layout = new QGridLayout();
    _box_1 -> setLayout(box1_layout);

    QLabel* name = new QLabel("name: ", _box_1);
    QLabel* college = new QLabel("college: ", _box_1);
    QLineEdit* name_input = new QLineEdit(_box_1);
    QLineEdit* college_input = new QLineEdit(_box_1);
    QPushButton* register_info = new QPushButton("register", _box_1);

    box1_layout -> addWidget(name, 0, 0);
    box1_layout -> addWidget(name_input, 0, 1);
    box1_layout -> addWidget(college, 1, 0);
    box1_layout -> addWidget(college_input, 1, 1);
    box1_layout -> addWidget(register_info, 2, 0, 1, 2);

    _layout -> addWidget(_box_1, 1, 0, 2, 2);

    // 组合2 有关
    _box_2 = new QGroupBox("step 1: ", centralWidget);
    QVBoxLayout* box2_layout = new QVBoxLayout();
    _box_2 -> setLayout(box2_layout);

    QLabel* box_2_info = new QLabel("Are you willing to take on hardcore work of absolute intensity?", _box_2);
    QRadioButton* yes_hardwork = new QRadioButton("yes", _box_2);
    QRadioButton* no_hardwork = new QRadioButton("no", _box_2);
    QRadioButton* maybe_hardwork = new QRadioButton("maybe", _box_2);

    yes_hardwork->setChecked(true);

    box2_layout -> addWidget(box_2_info);
    box2_layout -> addWidget(yes_hardwork);
    box2_layout -> addWidget(no_hardwork);
    box2_layout -> addWidget(maybe_hardwork);

    _box_2 -> setCheckable(true);
    _box_2 ->setChecked(false);

    _layout -> addWidget(_box_2, 1, 2, 2, 2);

    // 组合3 有关
    _box_3 = new QGroupBox("step 2: ", centralWidget);
    QVBoxLayout* box3_layout = new QVBoxLayout();
    _box_3 -> setLayout(box3_layout);

    QLabel* box_3_info = new QLabel("Who is your idol?", _box_3);
    QCheckBox* people_1 = new QCheckBox("Elon Musk", _box_3);
    QCheckBox* people_2 = new QCheckBox("Bill Gates", _box_3);
    QCheckBox* people_3 = new QCheckBox("Jeff Bezos", _box_3);
    QCheckBox* people_4 = new QCheckBox("Mark Zuckerberg", _box_3);

    people_1 -> setChecked(true);
    people_2 -> setChecked(true);

    box3_layout -> addWidget(box_3_info);
    box3_layout -> addWidget(people_1);
    box3_layout -> addWidget(people_2);
    box3_layout -> addWidget(people_3);
    box3_layout -> addWidget(people_4);

    _box_3 -> setCheckable(true);
    _box_3 ->setChecked(false);

    _layout -> addWidget(_box_3, 3, 0, 2, 2);

    // 组合4 有关
    _box_4 = new QGroupBox("step 3: ", centralWidget);
    QVBoxLayout* box4_layout = new QVBoxLayout();
    _box_4 -> setLayout(box4_layout);

    QLabel* box_4_info = new QLabel("Please select the company you are interested in.", _box_4);
    QToolButton* type_1 = new QToolButton(_box_4);
    QToolButton* type_2 = new QToolButton(_box_4);
    QToolButton* type_3 = new QToolButton(_box_4);

    type_1 -> setText("technology");
    type_2 -> setText("finance");
    type_3 -> setText("military");

    QMenu* menu_1 = new QMenu(type_1);
    QStringList technology_companies = {"Apple", "Telsa", "Microsoft", "Nvidia"};
    for (const QString& actionName : technology_companies) {
        QAction* action = new QAction(actionName, menu_1);
        menu_1 -> addAction(action);

        connect(action, &QAction::triggered, this, &MainWindow::select_tech_company);

        _buttons.insert("technology", type_1);
    }
    type_1 -> setMenu(menu_1);

    QMenu* menu_2 = new QMenu(type_2);
    QStringList finance_companies = {"Goldman Sachs", "JPMorgan Chase", "Citigroup", "Bank of America"};
    for (const QString& actionName : finance_companies) {
        QAction* action = new QAction(actionName, menu_2);
        menu_2 -> addAction(action);

        connect(action, &QAction::triggered, this, &MainWindow::select_fina_company);

        _buttons.insert("finance", type_2);
    }
    type_2 -> setMenu(menu_2);

    QMenu* menu_3 = new QMenu(type_3);
    QStringList military_companies = {"Lockheed Martin", "Raytheon", "Northrop Grumman", "General Dynamics"};
    for (const QString& actionName : military_companies) {
        QAction* action = new QAction(actionName, menu_3);
        menu_3 -> addAction(action);

        connect(action, &QAction::triggered, this, &MainWindow::select_mili_company);

        _buttons.insert("military", type_3);
    }
    type_3 -> setMenu(menu_3);

    type_1->setPopupMode(QToolButton::MenuButtonPopup);
    type_2->setPopupMode(QToolButton::MenuButtonPopup);
    type_3->setPopupMode(QToolButton::MenuButtonPopup);

    box4_layout -> addWidget(box_4_info);
    box4_layout -> addWidget(type_1);
    box4_layout -> addWidget(type_2);
    box4_layout -> addWidget(type_3);

    _box_4 -> setCheckable(true);
    _box_4 -> setChecked(false);

    _layout -> addWidget(_box_4, 3, 2, 2, 2);

    // submit按钮有关
    _submit = new QPushButton("  ---  Click this button to submit.  ---  " , centralWidget);
    _layout -> addWidget(_submit, 5, 0, 1, 4);

    // 信号与槽
    connect(register_info, &QPushButton::clicked, this, &MainWindow::registry_clicked);
    connect(_submit, &QPushButton::clicked, this, &MainWindow::submit_clicked);
}

void MainWindow::registry_clicked() {
    _is_registry = true;
    QMessageBox::information(this, "Tips", "You have successfully registered.");
}

void MainWindow::submit_clicked() {
    if (_is_registry == false) {
        QMessageBox::information(this, "Tips", "Please complete the registration first.");
    }
    else {
        QMessageBox::information(this, "Tips", "Submitted successfully.");
    }
}

void MainWindow::select_tech_company() {
    QAction* action = (QAction*)sender();
    if (action) {
        _buttons["technology"] -> setText(action -> text());
    }
}

void MainWindow::select_fina_company() {
    QAction* action = (QAction*)sender();
    if (action) {
        _buttons["finance"] -> setText(action -> text());
    }
}

void MainWindow::select_mili_company() {
    QAction* action = (QAction*)sender();
    if (action) {
        _buttons["military"] -> setText(action -> text());
    }
}

MainWindow::~MainWindow()
{
}

