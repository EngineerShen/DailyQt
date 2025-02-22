#include "doublespinboxdelegate.h"

#include <QDoubleSpinBox>

DoubleSpinBoxDelegate::DoubleSpinBoxDelegate(QWidget* parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *DoubleSpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 6) {
        QDoubleSpinBox* doublespinbox = new QDoubleSpinBox(parent);

        doublespinbox -> setMinimum(0.5);
        doublespinbox -> setMaximum(5.0);
        doublespinbox -> setSingleStep(0.1);
        doublespinbox -> setSuffix("倍数");

        return doublespinbox;
    }

    return QStyledItemDelegate::createEditor(parent, option, index);
}

void DoubleSpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (index.column() == 6) {
        double value = index.model() -> data(index, Qt::EditRole).toDouble();
        QDoubleSpinBox* doublespinbox = static_cast<QDoubleSpinBox*>(editor);
        doublespinbox -> setValue(value);
    }
    else {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

void DoubleSpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if (index.column() == 6) {
        QDoubleSpinBox* doublespinbox = static_cast<QDoubleSpinBox*>(editor);
        doublespinbox -> interpretText();
        double value = doublespinbox -> value();
        model -> setData(index, value, Qt::EditRole);
    }
    else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}

void DoubleSpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor -> setGeometry(option.rect);
}
