#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _currentRow = 0;
    initTableWidget();
    initStatusBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTableWidget()
{
    ui -> tableWidget -> setColumnCount(5);

    QStringList list_1;
    list_1 << "姓名" << "性别" << "出生日期" << "职位" << "是否已婚";
    QFont font("Microsoft YaHei", 10, QFont::Bold);
    for (int i = 0; i < list_1.count(); i++) {
        QTableWidgetItem* new_item = new QTableWidgetItem(list_1[i]);

        new_item -> setFont(font);
        new_item -> setForeground(Qt::red);

        ui -> tableWidget -> setHorizontalHeaderItem(i, new_item);
    }

    QHeaderView* header = ui -> tableWidget -> horizontalHeader();
    header -> setSectionResizeMode(QHeaderView::Stretch);
    header -> setSectionResizeMode(1, QHeaderView::Fixed);
    ui -> tableWidget -> setColumnWidth(1, 120);

    int people_count = 100;
    for (int i = 0; i < people_count; i++) {
        QString name = "员工" + QString::number(i + 1);

        QString gender = rand() % 2 == 0 ? "男" : "女";

        int year = rand() % 50 + 1960;
        int month = rand() % 12 + 1;
        int day = rand() % 28 + 1;
        QString birthday = QString::number(year) + "-" + QString::number(month) + "-" + QString::number(day);

        QStringList jobs = {"软件工程师", "硬件工程师", "测试工程师", "运维工程师", "机械工程师"};
        int index = rand() % jobs.count();
        QString job = jobs[index];

        QString married = rand() % 2 == 0 ? "已婚" : "未婚";

        addNewRow(i, name, gender, birthday, job, married);
    }

    if (ui ->actionEdit -> isChecked()) {
        ui -> tableWidget -> setEditTriggers(QAbstractItemView::AllEditTriggers);
    }
    else {
        ui -> tableWidget -> setEditTriggers(QAbstractItemView::NoEditTriggers);
    }

    connect(ui -> tableWidget, &QTableWidget::itemChanged, this, &MainWindow::itemChanged_later);
}

void MainWindow::initStatusBar()
{
    _lineEdit = new QLineEdit();
    _lineEdit -> setMaximumWidth(300);

    _button = new QPushButton("查找");

    _label = new QLabel("无");
    _label -> setMinimumWidth(350);

    ui -> statusbar -> addWidget(_lineEdit);
    ui -> statusbar -> addWidget(_button);
    ui -> statusbar -> addWidget(_label);

    connect(_button, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

QTableWidgetItem* MainWindow::addNewRow(int row, const QString &name, const QString &gender, const QString &birthday, const QString &job, const QString &married)
{
    ui -> tableWidget -> insertRow(row);

    QTableWidgetItem* nameItem = new QTableWidgetItem(name);
    ui -> tableWidget -> setItem(row, 0, nameItem);

    QIcon icon;
    if (gender == "男") { icon.addFile(":/images/boy.png"); }
    else if (gender == "女"){ icon.addFile(":/images/girl.png"); }
    else { icon.addFile(":/images/wenhao.png"); }
    QTableWidgetItem* genderItem = new QTableWidgetItem(gender);
    genderItem ->setTextAlignment(Qt::AlignCenter);
    genderItem -> setIcon(icon);
    ui -> tableWidget -> setItem(row, 1, genderItem);

    QTableWidgetItem* birthdayItem = new QTableWidgetItem(birthday);
    birthdayItem ->setTextAlignment(Qt::AlignCenter);
    ui -> tableWidget -> setItem(row, 2, birthdayItem);

    QTableWidgetItem* jobItem = new QTableWidgetItem(job);
    jobItem ->setTextAlignment(Qt::AlignCenter);
    ui -> tableWidget -> setItem(row, 3, jobItem);

    QTableWidgetItem* marriedItem = new QTableWidgetItem(married);
    if (married == "已婚") {
        marriedItem -> setBackground(QBrush(QColor(200, 200, 200)));
        QFont tmp_font = marriedItem -> font();
        tmp_font.setBold(true);
        marriedItem -> setFont(tmp_font);
    }
    marriedItem ->setTextAlignment(Qt::AlignCenter);
    ui ->tableWidget -> setItem(row, 4, marriedItem);

    return nameItem;
}

void MainWindow::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    if (currentRow != previousRow && (!ui -> actionEdit -> isChecked())) {
        ui -> tableWidget -> setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}

void MainWindow::on_actionInsert_triggered()
{
    disconnect(ui -> tableWidget, &QTableWidget::itemChanged, this, &MainWindow::itemChanged_later);

    QList<QTableWidgetItem*> selectItems = ui -> tableWidget -> selectedItems();

    if (!selectItems.empty()) {
        QTableWidgetItem* selectedItem = selectItems.first();

        _currentRow = selectedItem-> row();
        QTableWidgetItem* newStart = addNewRow(_currentRow, "Unknown", "未知", "2000-1-1", "待定", "待查");

        ui -> tableWidget -> setCurrentItem(newStart);
        ui -> tableWidget -> setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
    }

    connect(ui -> tableWidget, &QTableWidget::itemChanged, this, &MainWindow::itemChanged_later);
}

void MainWindow::on_actionDel_triggered()
{
    disconnect(ui -> tableWidget, &QTableWidget::itemChanged, this, &MainWindow::itemChanged_later);

    QList<QTableWidgetItem*> selectItems = ui -> tableWidget -> selectedItems();

    if (!selectItems.empty()) {
        QTableWidgetItem* selectedItem = selectItems.first();
        _currentRow = selectedItem-> row();
        ui -> tableWidget -> removeRow(_currentRow);
    }

    connect(ui -> tableWidget, &QTableWidget::itemChanged, this, &MainWindow::itemChanged_later);
}

void MainWindow::on_actionEdit_triggered(bool checked)
{
    if (checked) {
        ui -> tableWidget -> setEditTriggers(QAbstractItemView::AllEditTriggers);
    }
    else {
        ui -> tableWidget -> setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}

void MainWindow::itemChanged_later(QTableWidgetItem *item)
{
    disconnect(ui -> tableWidget, &QTableWidget::itemChanged, this, &MainWindow::itemChanged_later);

    int col = item -> column();
    if (col == 1) {
        QString gender = item -> text();

        QIcon icon;
        if (gender == "男") { icon.addFile(":/images/boy.png"); }
        else if (gender == "女"){ icon.addFile(":/images/girl.png"); }
        else { icon.addFile(":/images/wenhao.png"); }
        item -> setIcon(icon);
    }
    else if (col == 4) {
        QString married = item -> text();
        if (married == "已婚") {
            item -> setBackground(QBrush(QColor(200, 200, 200)));
            QFont tmp_font = item -> font();
            tmp_font.setBold(true);
            item -> setFont(tmp_font);
        }
        else {
            item -> setBackground(QBrush(QColor(255, 255, 255)));
            QFont tmp_font = item -> font();
            tmp_font.setBold(false);
            item -> setFont(tmp_font);
        }
    }

    connect(ui -> tableWidget, &QTableWidget::itemChanged, this, &MainWindow::itemChanged_later);
}

void MainWindow::on_pushButton_clicked()
{
    disconnect(ui -> tableWidget, &QTableWidget::itemChanged, this, &MainWindow::itemChanged_later);

    QString search_content = _lineEdit -> text();

    if (!search_content.isEmpty()) {
        for (int i = 0; i < ui -> tableWidget -> rowCount(); i++) {
            for (int j = 0; j < ui ->tableWidget -> columnCount(); j++) {
                QTableWidgetItem *item = ui -> tableWidget -> item(i, j);
                if (item -> text().contains(search_content, Qt::CaseInsensitive)) {
                    item->setBackground(QBrush(QColor(255, 165, 0))); // 橙色背景
                }
                else {
                    if (j == 4) {
                        if (item -> text() == "已婚") { item -> setBackground(QBrush(QColor(200, 200, 200))); }
                        else { item -> setBackground(QBrush(QColor(255, 255, 255))); }
                    }
                    else { item->setBackground(QBrush()); }
                }
            }
        }
    }

    connect(ui -> tableWidget, &QTableWidget::itemChanged, this, &MainWindow::itemChanged_later);
}

void MainWindow::on_tableWidget_itemSelectionChanged()
{
    QList<QTableWidgetItem*> selectItems = ui -> tableWidget -> selectedItems();

    if (!selectItems.empty()) {
        _currentRow = selectItems.first() -> row();
    }

    QString text;
    for (int i = 0; i < ui -> tableWidget -> columnCount(); i++) {
        text += ui -> tableWidget -> item(_currentRow, i) -> text();
        text += " / ";
    }
    text = text.left(text.size() - 3);

    _label -> setText(text);
}
