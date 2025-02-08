#include "dialog.h"
#include "ui_dialog.h"
#include <QColor>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    initSignalSlots();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_slider_valueChanged() {
    int red = ui -> horizontalSliderRed -> value();
    int green = ui -> horizontalSliderGreen -> value();
    int blue = ui -> horizontalSliderBlue -> value();
    int transparent = ui -> horizontalSliderTransparent -> value();

    QColor newColor(red, green, blue, transparent);

    ui -> textEdit -> setStyleSheet("QTextEdit { background-color: " + newColor.name(QColor::HexArgb) + "; }");
}

void Dialog::initSignalSlots() {
    connect(ui -> horizontalSliderRed, &QSlider::valueChanged, this, &Dialog::on_slider_valueChanged);
    connect(ui -> horizontalSliderGreen, &QSlider::valueChanged, this, &Dialog::on_slider_valueChanged);
    connect(ui -> horizontalSliderBlue, &QSlider::valueChanged, this, &Dialog::on_slider_valueChanged);
    connect(ui -> horizontalSliderTransparent, &QSlider::valueChanged, this, &Dialog::on_slider_valueChanged);
}

void Dialog::on_horizontalScrollBar_valueChanged(int value)
{
    QTextCursor cursor = ui -> textEdit_big -> textCursor();
    if (!cursor.hasSelection()) {
        cursor.movePosition(QTextCursor::Start);
        cursor.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
    }

    QTextCharFormat format;
    format.setFontPointSize(value);
    cursor.mergeCharFormat(format);
}

void Dialog::on_dial_valueChanged(int value)
{
    ui -> labelSpeed -> setText(QString::number(value) + " KM / H");
    ui -> progressBar -> setValue(value);
}
