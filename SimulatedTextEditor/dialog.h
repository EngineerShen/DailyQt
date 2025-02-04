#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void initUI();
    void initSignalSlots();

private slots:
    void onUnderlineChanged(int state);
    void onItalicChanged(int state);
    void onBoldChanged(int state);

    void onColorChanged();

    void onConfirmClicked();
    void onCancelClicked();
    void onQuitClicked();

private:
    QVBoxLayout* _layout;

    QCheckBox* _Underline;
    QCheckBox* _Italic;
    QCheckBox* _Bold;

    QRadioButton* _black;
    QRadioButton* _red;
    QRadioButton* _green;

    QPlainTextEdit* _textEdit;

    QPushButton* _confirm;
    QPushButton* _cancel;
    QPushButton* _quit;
};
#endif // DIALOG_H
