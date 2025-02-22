#include "spinboxdelegate.h"
#include <QSpinBox>

SpinBoxDelegate::SpinBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *SpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 4) {
        QSpinBox* spinbox = new QSpinBox(parent);

        spinbox -> setMinimum(0);
        spinbox -> setMaximum(9999999);
        spinbox -> setSingleStep(100);
        spinbox -> setSuffix("元");

        return spinbox;
    }

    return QStyledItemDelegate::createEditor(parent, option, index);
}

void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (index.column() == 4) {
        int value = index.model() -> data(index, Qt::EditRole).toInt();
        QSpinBox* spinbox = static_cast<QSpinBox*>(editor);
        spinbox -> setValue(value);
    }
    else {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if (index.column() == 4) {
        QSpinBox* spinbox = static_cast<QSpinBox*>(editor);
        spinbox -> interpretText();
        int value = spinbox -> value();
        model -> setData(index, value, Qt::EditRole);
    }
    else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor -> setGeometry(option.rect);
}
