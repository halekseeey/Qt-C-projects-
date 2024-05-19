#include "myitemdelegate.h"
#include <QSpinBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QWidget>

MyItemDelegate::MyItemDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}

QWidget *MyItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QWidget *editor = new QWidget(parent);
    QHBoxLayout *layout = new QHBoxLayout(editor);
    layout->setContentsMargins(0, 0, 0, 0);

    QSpinBox *spinBox = new QSpinBox(editor);
    spinBox->setMinimum(0);
    spinBox->setMaximum(100000);

    QLineEdit *lineEdit = new QLineEdit(editor);

    layout->addWidget(spinBox);
    layout->addWidget(lineEdit);

    return editor;
}

void MyItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QStringList parts = index.model()->data(index, Qt::EditRole).toString().split(": ");
    if (parts.size() != 2)
        return;

    QSpinBox *spinBox = editor->findChild<QSpinBox*>();
    QLineEdit *lineEdit = editor->findChild<QLineEdit*>();

    spinBox->setValue(parts[0].toInt());
    lineEdit->setText(parts[1]);
}

void MyItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinBox = editor->findChild<QSpinBox*>();
    QLineEdit *lineEdit = editor->findChild<QLineEdit*>();

    int key = spinBox->value();
    QString value = lineEdit->text();

    model->setData(index, QString("%1: %2").arg(key).arg(value), Qt::EditRole);
}

void MyItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
