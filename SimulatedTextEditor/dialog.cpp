#include "dialog.h"
#include <QDebug>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    initUI();
    initSignalSlots();
}

Dialog::~Dialog()
{
}

void Dialog::initUI() {
    // 总布局相关
    _layout = new QVBoxLayout(this);
    setLayout(_layout);

    // _Underline/_Italic/_Bold相关
    _Underline = new QCheckBox("下划线", this);
    _Italic = new QCheckBox("斜体", this);
    _Bold = new QCheckBox("粗体", this);
    QHBoxLayout* _child_layout_1 = new QHBoxLayout();
    _child_layout_1 -> addWidget(_Underline);
    _child_layout_1 -> addWidget(_Italic);
    _child_layout_1 -> addWidget(_Bold);
    _layout -> addLayout(_child_layout_1);

    // _black/_red/_green相关
    _black = new QRadioButton("黑色", this);
    _red = new QRadioButton("红色", this);
    _green = new QRadioButton("绿色", this);
    QHBoxLayout* _child_layout_2 = new QHBoxLayout();
    _child_layout_2 -> addWidget(_black);
    _child_layout_2 -> addWidget(_red);
    _child_layout_2 -> addWidget(_green);
    _layout -> addLayout(_child_layout_2);

    // _textEdit相关
    _textEdit = new QPlainTextEdit(this);
    _layout -> addWidget(_textEdit);

    // _confirm/_cancel/_quit相关
    _confirm = new QPushButton("确认", this);
    _cancel = new QPushButton("取消", this);
    _quit = new QPushButton("退出", this);
    QHBoxLayout* _child_layout_3 = new QHBoxLayout();
    _child_layout_3 -> addWidget(_confirm);
    _child_layout_3 -> addWidget(_cancel);
    _child_layout_3 -> addStretch(2);
    _child_layout_3 -> addWidget(_quit);
    _layout -> addLayout(_child_layout_3);
}

void Dialog::initSignalSlots() {
    connect(_Underline, &QCheckBox::stateChanged, this, &Dialog::onUnderlineChanged);
    connect(_Italic, &QCheckBox::stateChanged, this, &Dialog::onItalicChanged);
    connect(_Bold, &QCheckBox::stateChanged, this, &Dialog::onBoldChanged);

    connect(_black, &QRadioButton::clicked, this, &Dialog::onColorChanged);
    connect(_red, &QRadioButton::clicked, this, &Dialog::onColorChanged);
    connect(_green, &QRadioButton::clicked, this, &Dialog::onColorChanged);

    connect(_confirm, &QPushButton::clicked, this, &Dialog::onConfirmClicked);
    connect(_cancel, &QPushButton::clicked, this, &Dialog::onCancelClicked);
    connect(_quit, &QPushButton::clicked, this, &Dialog::onQuitClicked);
}

void Dialog::onUnderlineChanged(int state) {
    QTextCharFormat format;
    format.setFontUnderline(state);

    QTextCursor cursor = _textEdit -> textCursor();
    if (!cursor.hasSelection()) {
        cursor.movePosition(QTextCursor::Start);
        cursor.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
    }
    cursor.mergeCharFormat(format);
}

void Dialog::onItalicChanged(int state) {
    QTextCharFormat format;
    format.setFontItalic(state);

    QTextCursor cursor = _textEdit -> textCursor();
    if (!cursor.hasSelection()) {
        cursor.movePosition(QTextCursor::Start);
        cursor.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
    }
    cursor.mergeCharFormat(format);
}

void Dialog::onBoldChanged(int state) {
    QTextCharFormat format;
    if (state != 0) { format.setFontWeight(QFont::Bold); }
    else { format.setFontWeight(QFont::Normal); }

    QTextCursor cursor = _textEdit -> textCursor();
    if (!cursor.hasSelection()) {
        cursor.movePosition(QTextCursor::Start);
        cursor.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
    }
    cursor.mergeCharFormat(format);
}

void Dialog::onColorChanged() {
    QTextCharFormat format;
    if (_black -> isChecked()) { format.setForeground(Qt::black); }
    else if (_red -> isChecked()) { format.setForeground(Qt::red); }
    else if (_green -> isChecked()) { format.setForeground(Qt::green); }

    QTextCursor cursor = _textEdit -> textCursor();
    if (!cursor.hasSelection()) {
        cursor.movePosition(QTextCursor::Start);
        cursor.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
    }
    cursor.mergeCharFormat(format);
}

void Dialog::onConfirmClicked() {
    QMessageBox::information(this, "Tips", "已经确认!");
}

void Dialog::onCancelClicked() {
    QMessageBox::information(this, "Tips", "已经取消!");
}

void Dialog::onQuitClicked() {
    close();
}
