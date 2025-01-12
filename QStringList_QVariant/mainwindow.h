#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QDebug>
#include <QMainWindow>

class computer {
public:
    computer() {}
    computer(QString CPU, QString GPU, int memory) {
        _CPU = CPU;
        _GPU = GPU;
        _memory = memory;
    }
    inline void show_computer() {
        qDebug() << _CPU << " " << _GPU << _memory << "GB";
    }
private:
    QString _CPU;
    QString _GPU;
    int _memory;            // GB
};

Q_DECLARE_METATYPE(computer)

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void test_QStringList();

    void test_QVariant();
};
#endif // MAINWINDOW_H
