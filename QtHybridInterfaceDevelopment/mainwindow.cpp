#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
    initSignalSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI() {
    _labelFileName = new QLabel("当前文件:");
    _labelFileName -> setMinimumWidth(200);
    ui -> statusbar -> addWidget(_labelFileName);

    _progressBar = new QProgressBar;
    _progressBar -> setMinimum(8);
    _progressBar -> setMaximum(60);
    _progressBar -> setValue(ui -> plainTextEdit -> font().pointSize());
    ui -> statusbar -> addWidget(_progressBar);

    ui -> toolBar -> addWidget(new QLabel("字体大小:"));
    _spinBox = new QSpinBox;
    _spinBox -> setMinimum(8);
    _spinBox -> setMaximum(60);
    _spinBox -> setValue(ui -> plainTextEdit -> font().pointSize());
    _spinBox -> setMaximumWidth(100);
    ui -> toolBar -> addWidget(_spinBox);
    ui -> toolBar -> addSeparator();
    ui -> toolBar -> addWidget(new QLabel("字体:"));
    _comboBox = new QFontComboBox;
    _comboBox -> setMaximumWidth(200);
    ui -> toolBar -> addWidget(_comboBox);
    ui -> toolBar -> addSeparator();

    ui -> actionBold -> setEnabled(false);
    ui -> actionItalic -> setEnabled(false);
    ui -> actionUnderline -> setEnabled(false);
    _spinBox -> setEnabled(false);
    _comboBox -> setEnabled(false);
}

void MainWindow::initSignalSlots() {
    connect(_spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::updateFontSize);
    connect(_comboBox, &QFontComboBox::currentFontChanged, this, &MainWindow::updateFont);
}

void MainWindow::on_actionNew_triggered()
{
    ui -> plainTextEdit -> clear();
    _labelFileName -> setText("当前文件:");
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "打开文件");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream in(&file);
            QString fileContent = in.readAll();
            ui -> plainTextEdit -> setPlainText(fileContent);
            _labelFileName -> setText("当前文件:" + fileName);
            file.close();
        }
    }
}

void MainWindow::on_actionBold_triggered(bool checked)
{
    QTextCursor cursor = ui -> plainTextEdit -> textCursor();
    if (cursor.hasSelection()) {
        QTextCharFormat format;
        format.setFontWeight(checked ? QFont::Bold : QFont::Normal);
        cursor.mergeCharFormat(format);
    }
}

void MainWindow::on_actionItalic_triggered(bool checked)
{
    QTextCursor cursor = ui -> plainTextEdit -> textCursor();
    if (cursor.hasSelection()) {
        QTextCharFormat format;
        format.setFontItalic(checked);
        cursor.mergeCharFormat(format);
    }
}

void MainWindow::on_actionUnderline_triggered(bool checked)
{
    QTextCursor cursor = ui -> plainTextEdit -> textCursor();
    if (cursor.hasSelection()) {
        QTextCharFormat format;
        format.setFontUnderline(checked);
        cursor.mergeCharFormat(format);
    }
}

void MainWindow::updateFontSize(int size)
{
    QTextCursor cursor = ui -> plainTextEdit -> textCursor();
    if (cursor.hasSelection()) {
        QTextCharFormat format;
        format.setFontPointSize(size);
        cursor.mergeCharFormat(format);
        _progressBar -> setValue(size);
    }
}

void MainWindow::updateFont(const QFont& font)
{
    QTextCursor cursor = ui -> plainTextEdit -> textCursor();
    if (cursor.hasSelection()) {
        QTextCharFormat format;
        format.setFontFamily(font.family());
        cursor.mergeCharFormat(format);
    }
}

void MainWindow::on_plainTextEdit_selectionChanged()
{
    QTextCursor cursor = ui -> plainTextEdit -> textCursor();
    if (cursor.hasSelection()) {
        ui -> actionBold -> setEnabled(true);
        ui -> actionItalic -> setEnabled(true);
        ui -> actionUnderline -> setEnabled(true);
        _spinBox -> setEnabled(true);
        _comboBox -> setEnabled(true);

        QTextCharFormat format = cursor.charFormat();
        ui -> actionBold -> setChecked(format.font().bold());
        ui -> actionItalic -> setChecked(format.fontItalic());
        ui -> actionUnderline -> setChecked(format.fontUnderline());
        _spinBox -> setValue((int)format.fontPointSize());
        _comboBox -> setCurrentIndex(_comboBox -> findText(format.fontFamily()));
    }
    else {
        ui -> actionBold -> setEnabled(false);
        ui -> actionItalic -> setEnabled(false);
        ui -> actionUnderline -> setEnabled(false);
        _spinBox -> setEnabled(false);
        _comboBox -> setEnabled(false);
    }
}

