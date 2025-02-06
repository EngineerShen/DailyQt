#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QFontComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_actionBold_triggered(bool checked);

    void on_actionItalic_triggered(bool checked);

    void on_actionUnderline_triggered(bool checked);

    void updateFontSize(int size);

    void updateFont(const QFont& font);

    void on_plainTextEdit_selectionChanged();

private:
    void initUI();

    void initSignalSlots();

private:
    QLabel* _labelFileName;
    QProgressBar* _progressBar;
    QSpinBox* _spinBox;
    QFontComboBox* _comboBox;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
