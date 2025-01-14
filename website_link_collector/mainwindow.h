#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QCommandLinkButton>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QDialog>
#include <QString>
#include <QUrl>
#include <QDesktopServices>
#include <QHash>

class ConfirmationDialog : public QDialog {
    Q_OBJECT
public:
    ConfirmationDialog(QString website_name, QWidget* parent = nullptr) : QDialog(parent) {
        setWindowTitle("confirm again...");

        // 获取网站名字与聚合标签内容
        _website_name = website_name;
        QString words = "Are you sure to visit " + _website_name;

        /* ConfirmationDialog本身就是一个容器类部件 */
        // 小部件构造
        _confirm_info = new QLabel(words, this);
        _buttonBox = new QDialogButtonBox(this);
        _buttonBox -> setStandardButtons(QDialogButtonBox::Yes | QDialogButtonBox::No);

        // 布局设置与放入小部件
        _layout = new QVBoxLayout(this);
        _layout -> addWidget(_confirm_info);
        _layout -> addWidget(_buttonBox);

        // 信号与槽
        connect(_buttonBox, &QDialogButtonBox::accepted, this, &ConfirmationDialog::goToWebSite);
        connect(_buttonBox, &QDialogButtonBox::rejected, this, &ConfirmationDialog::reject);
        /* reject函数就是关闭这个对话框 */
    }
private slots:
    void goToWebSite() {
        QDesktopServices::openUrl(QUrl(_real_sites[_website_name]));
        reject();
    }
private:
    /* ConfirmationDialog本身就是一个容器类部件 */
    QVBoxLayout* _layout;
    QString _website_name;
    static QHash<QString, QString> _real_sites;
    QDialogButtonBox* _buttonBox;
    QLabel* _confirm_info;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel* _header;
    QGridLayout* _layout;
    QCommandLinkButton* _website_1;
    QCommandLinkButton* _website_2;
    QCommandLinkButton* _website_3;
    QCommandLinkButton* _website_4;
    QPalette* _pal;

private slots:
    void choose_site_1();
    void choose_site_2();
    void choose_site_3();
    void choose_site_4();
};
#endif // MAINWINDOW_H
