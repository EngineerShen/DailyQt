#include "comboboxdelegate.h"
#include <QComboBox>

ComboBoxDelegate::ComboBoxDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *ComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 3) {
        QComboBox* combobox = new QComboBox(parent);

        QStringList list = {"C++工程师", "Java工程师", "前端工程师", "运维工程师", "硬件工程师", "测试工程师", "网络工程师"};
        combobox -> addItems(list);
        combobox -> setEditable(false);

        return combobox;
    }
    else if (index.column() == 1) {
        QComboBox* combobox = new QComboBox(parent);

        QStringList list = {"男", "女"};
        combobox -> addItems(list);
        combobox -> setEditable(false);

        return combobox;
    }
    else if (index.column() == 2) {
        QComboBox* combobox = new QComboBox(parent);

        QStringList list = {"技术部", "销售部", "人事部", "研发部", "市场部", "运营部", "财务部"};
        combobox -> addItems(list);
        combobox -> setEditable(false);

        return combobox;
    }

    return QStyledItemDelegate::createEditor(parent, option, index);
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (index.column() == 3 || index.column() == 1 || index.column() == 2) {
        QString value = index.model() -> data(index, Qt::EditRole).toString();
        QComboBox* combobox = static_cast<QComboBox*>(editor);
        combobox -> setCurrentText(value);
    }
    else {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if (index.column() == 3 || index.column() == 1 || index.column() == 2) {
        QComboBox* combobox = static_cast<QComboBox*>(editor);
        QString value = combobox -> currentText();
        model -> setData(index, value, Qt::EditRole);
    }
    else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor -> setGeometry(option.rect);
}
