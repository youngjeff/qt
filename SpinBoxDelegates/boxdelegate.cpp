#include "boxdelegate.h"

#include <QSpinBox>
QWidget * BoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox *editor = new QSpinBox (parent);//创建一个控件
    editor->setMinimum(0);
    editor->setMaximum(100);
    return editor;
}
void BoxDelegate::setEditorData(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();//获取 定位数据
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);    //
    spinBox->setValue(value);
}
void BoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinbox = static_cast<QSpinBox *>(editor);
    spinbox->interpretText();  //调整数据,接收数据改变的信号
    int value = spinbox->value();   //获取改变的数据
    model->setData(index,value,Qt::EditRole);   //将改变的数据输入到model

}
void BoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
//styleOptionViewItem 将输入框的大小设置为单元格的大小
