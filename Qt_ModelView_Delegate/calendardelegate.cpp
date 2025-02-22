#include "calendardelegate.h"

#include <QCalendarWidget>
#include <QDialog>
#include <QVBoxLayout>

CalendarDelegate::CalendarDelegate(QWidget* parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *CalendarDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 7) {
//        QCalendarWidget* calendar = new QCalendarWidget(parent);
//        calendar -> setGridVisible(true);
//        return calendar;

        QWidget* placeHolder = new QWidget(parent);
        placeHolder -> setVisible(false);

        showCalendarPopUp(index, parent);
    }

    return QStyledItemDelegate::createEditor(parent, option, index);
}

void CalendarDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QStyledItemDelegate::setEditorData(editor, index);
}

void CalendarDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QStyledItemDelegate::setModelData(editor, model, index);
}

void CalendarDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor -> setGeometry(option.rect);
}

void CalendarDelegate::showCalendarPopUp(const QModelIndex &index, QWidget *parent) const
{
    QDialog* popup = new QDialog(parent);
    popup -> setModal(true);
    popup -> setWindowTitle("选择日期");

    QCalendarWidget* calendar = new QCalendarWidget(parent);
    calendar -> setGridVisible(true);

    // 下 -> 上
    QString nowDate = index.model() -> data(index, Qt::EditRole).toString();
    QDate date = QDate::fromString(nowDate, "yyyy-MM-dd");
    if (date.isValid()) {
        calendar -> setSelectedDate(date);
    }

    QVBoxLayout* layout = new QVBoxLayout(popup);
    layout -> addWidget(calendar);
    popup -> setLayout(layout);

    // 上 -> 下
    connect(calendar, &QCalendarWidget::clicked, [=](const QDate &date) {
        QString selectedDateStr = date.toString("yyyy-MM-dd");
        const_cast<QAbstractItemModel*>(index.model())->setData(index, selectedDateStr, Qt::EditRole);
        popup -> accept();
    });

    popup -> exec();

    delete popup;
}

