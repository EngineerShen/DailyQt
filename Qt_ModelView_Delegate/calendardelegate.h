#ifndef CALENDARDELEGATE_H
#define CALENDARDELEGATE_H

#include <QStyledItemDelegate>

class CalendarDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CalendarDelegate(QWidget* parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

private:
    void showCalendarPopUp(const QModelIndex &index, QWidget *parent) const;
};

#endif // CALENDARDELEGATE_H
