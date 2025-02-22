#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QSet>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _model = new QStandardItemModel(0, 6);
    QStringList list = {"姓名", "性别", "部门", "岗位", "薪资", "婚否"};
    _model -> setHorizontalHeaderLabels(list);

    ui -> tableView -> setModel(_model);
    ui -> tableView -> horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch);

    QFont font("Microsoft YaHei", 10, QFont::Bold);
    ui -> tableView -> horizontalHeader() -> setFont(font);
    ui -> tableView -> horizontalHeader() -> setStyleSheet("QHeaderView:horizontal::section { color: red; }");

    ui -> tableView -> setSelectionMode(QAbstractItemView::ExtendedSelection);

    _selectedItems = ui -> tableView ->selectionModel();

    connect(_selectedItems, &QItemSelectionModel::selectionChanged, this, &MainWindow::on_selection_changed);

    _label = new QLabel();
    ui -> statusbar -> addWidget(_label);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::applyFormat(Qt::Alignment alignment)
{
    QModelIndexList selected = ui ->tableView -> selectionModel() -> selectedIndexes();
    if (selected.isEmpty()) {
        QMessageBox::information(this, "提示", "请先选中至少一个单元格！");
        return;
    }

    for (const QModelIndex& index : selected) {
        QStandardItem* item = _model -> itemFromIndex(index);
        if (item) {
            item -> setTextAlignment(alignment);
        }
    }
}

void MainWindow::on_actionLoad_triggered()
{
    _model ->clear();

    QString fileName = QFileDialog::getOpenFileName(nullptr, "打开员工信息文件", "D:\\Christopher\\Desktop", "Text Files (*.txt);;All Files (*)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            in.setCodec("UTF-8");

            int row = 0;
            while (!in.atEnd()) {
                QString line = in.readLine().trimmed();
                QStringList fields = line.split(" ", Qt::SkipEmptyParts);

                if (fields.count() == 6) {
                    _model->insertRow(row);
                    for (int i = 0; i < 5; i++) { _model -> setItem(row, i, new QStandardItem(fields[i])); }

                    QStandardItem* new_item = new QStandardItem(fields[5]);
                    new_item -> setFlags(new_item -> flags() | Qt::ItemIsUserCheckable);
                    new_item -> setCheckState(fields[5] == "已婚" ? Qt::Checked : Qt::Unchecked);
                    _model -> setItem(row, 5, new_item);

                    row++;
                }
                else { QMessageBox::warning(nullptr, "错误", "文件格式错误: 第" + QString::number(row + 1) + "行数据列数不准确!"); }
            }
            file.close();
        }
        else { QMessageBox::warning(nullptr, "错误", "无法打开文件：" + fileName); }
    }
    else { QMessageBox::information(nullptr, "提示", "未选择文件，表格将为空"); }
}

void MainWindow::on_actionAdd_triggered()
{
    int insert_row = _model -> rowCount();
    _model -> insertRow(insert_row);

    _model -> setItem(insert_row, 0, new QStandardItem("新员工"));
    _model -> setItem(insert_row, 1, new QStandardItem("男/女"));
    _model -> setItem(insert_row, 2, new QStandardItem("未分配"));
    _model -> setItem(insert_row, 3, new QStandardItem("未定"));
    _model -> setItem(insert_row, 4, new QStandardItem("0"));

    QStandardItem* new_item = new QStandardItem("未婚");
    new_item -> setFlags(new_item -> flags() | Qt::ItemIsUserCheckable);
    new_item -> setCheckState(Qt::Unchecked);
    _model -> setItem(insert_row, 5, new_item);

    ui -> tableView -> clearSelection();
    ui -> tableView -> selectRow(insert_row);
}

void MainWindow::on_actionInsert_triggered()
{
    QModelIndexList selected = ui -> tableView -> selectionModel() -> selectedIndexes();

    int insert_row = _model -> rowCount();
    if (!selected.isEmpty()) { insert_row = selected.first().row(); }
    _model -> insertRow(insert_row);

    _model -> setItem(insert_row, 0, new QStandardItem("新员工"));
    _model -> setItem(insert_row, 1, new QStandardItem("男/女"));
    _model -> setItem(insert_row, 2, new QStandardItem("未分配"));
    _model -> setItem(insert_row, 3, new QStandardItem("未定"));
    _model -> setItem(insert_row, 4, new QStandardItem("0"));

    QStandardItem* new_item = new QStandardItem("未婚");
    new_item -> setFlags(new_item -> flags() | Qt::ItemIsUserCheckable);
    new_item -> setCheckState(Qt::Unchecked);
    _model -> setItem(insert_row, 5, new_item);

    ui -> tableView -> clearSelection();
    ui -> tableView -> selectRow(insert_row);
}

void MainWindow::on_actionDel_triggered()
{
    QModelIndexList selected = ui -> tableView -> selectionModel() -> selectedIndexes();
    if (selected.isEmpty()) {
        QMessageBox::information(this, "提示", "请先选中至少一个单元格！");
        return;
    }

    QSet<int> rowsToDelete;
    for (const QModelIndex &index : selected) { rowsToDelete.insert(index.row()); }

    QList<int> delete_list = rowsToDelete.toList();
    std::sort(delete_list.begin(), delete_list.end(), std::greater<int>());

    for (int row : delete_list) { _model -> removeRow(row); }

    if (_model -> rowCount() > 0) {
        int newSelectedRow = delete_list.last() - 1; // 删除的最后一行上一行
        if (newSelectedRow < 0) newSelectedRow = 0; // 如果删除的是第一行，选第一行
        ui -> tableView -> selectRow(newSelectedRow);
    }
}

void MainWindow::on_actionSee_triggered()
{
    ui -> plainTextEdit -> clear();

    for (int i = 0; i < _model -> rowCount(); i++) {
        QString line;
        for (int j = 0; j < _model -> columnCount(); j++) {
            QStandardItem* item = _model -> item(i, j);
            if (j != 5) {
                line += item -> text();
                line += " ";
            }
            else {
                line += (item -> checkState() == Qt::Checked ? "已婚" : "未婚");
            }
        }
        ui -> plainTextEdit -> appendPlainText(line);
    }

    if (_model -> rowCount() == 0) { ui -> plainTextEdit -> appendPlainText("表格为空"); }
}

void MainWindow::on_actionLeft_triggered()
{
    applyFormat(Qt::AlignLeft | Qt::AlignVCenter);
}

void MainWindow::on_actionMid_triggered()
{
    applyFormat(Qt::AlignCenter);
}

void MainWindow::on_actionRight_triggered()
{
    applyFormat(Qt::AlignRight | Qt::AlignVCenter);
}

void MainWindow::on_actionBold_triggered(bool checked)
{
    QModelIndexList selected = ui ->tableView -> selectionModel() -> selectedIndexes();
    if (selected.isEmpty()) {
        QMessageBox::information(this, "提示", "请先选中至少一个单元格！");
        return;
    }

    QFont font;
    font.setBold(checked);

    for (const QModelIndex& index : selected) {
        QStandardItem* item = _model -> itemFromIndex(index);
        item -> setFont(font);
    }
}

void MainWindow::on_selection_changed(const QItemSelection &selected, const QItemSelection &deselected)
{
    if (!selected.isEmpty()) {
        // part1
        QModelIndex the_index = selected.indexes().first();
        int row = the_index.row();
        int col = the_index.column();
        QString data = the_index.data().toString();
        _label -> setText(QString("当前单元格 Row: %1, Col: %2, Text: %3").arg(row).arg(col).arg(data));

        // part2
        const QItemSelectionRange& range = selected.first();
        QModelIndex index = range.topLeft();
        QStandardItem* item = _model -> itemFromIndex(index);
        ui -> actionBold -> setChecked(item -> font().bold());
    }
    else {
        _label -> setText("没有单元格被选中");
    }
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "保存文件", "D:\\Christopher\\Desktop", "Text Files (*.txt);;CSV Files (*.csv);;All Files (*)");

    if (fileName.isEmpty()) { return; }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::warning(this, "Error", "Cannot open file for writing!");
        return;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8");

    for (int i = 0; i < _model -> rowCount(); i++) {
        QString line;

        for (int j = 0; j < _model -> columnCount(); j++) {
            QStandardItem* item = _model -> item(i, j);
            line += item ->text();
            line += " ";
        }

        out << line << "\n";
    }

    file.close();

    QMessageBox::information(this, "Success", "Table data saved to " + fileName);
}

