#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QRegExp>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    model = new QStringListModel(QColor::colorNames(),this);//创建一个颜色的stringlistmodel
    modelProxy = new QSortFilterProxyModel(this);//用于sort filter
    modelProxy->setSourceModel(model);//This property holds the source model this proxy model.
    modelProxy->setFilterKeyColumn(2);//

    view = new QListView(this);
    view->setModel(modelProxy);

    QLineEdit *filterInput = new QLineEdit;
    QLabel * filterLabel = new QLabel(tr("Filter"));
    QHBoxLayout *filterLayout = new QHBoxLayout;
    filterLayout->addWidget(filterLabel);
    filterLayout->addWidget(filterInput);

    syntaxBox = new QComboBox;
    syntaxBox->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);//滚动条
    syntaxBox->addItem(tr("Regular expression"),QRegExp::RegExp);
    syntaxBox->addItem(tr("Wildcard"),QRegExp::Wildcard);
    syntaxBox->addItem(tr("Fixed string"),QRegExp::FixedString);
    QLabel  *syntaxLabel = new QLabel(tr("Syntax"));
    QHBoxLayout *syntaxLayout = new QHBoxLayout;
    syntaxLayout->addWidget(syntaxLabel);
    syntaxLayout->addWidget(syntaxBox);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(view);
    layout->addLayout(filterLayout);
    layout->addLayout(syntaxLayout);

    connect(filterInput,&QLineEdit::textChanged,this,&Widget::filterChanged);

}

Widget::~Widget()
{

}
void Widget::filterChanged(const QString &text)
{
    QRegExp::PatternSyntax syntax = QRegExp::PatternSyntax(syntaxBox->itemData(syntaxBox->currentIndex()).toInt());
    //选择筛选模式
    QRegExp regExp(text,Qt::CaseSensitive,syntax);
    //CaseInsensitive 不区分大小写
    modelProxy->setFilterRegExp(regExp);
    //This property holds the QRegExp used to filter the contents of the source model.

}

//sortfilterProxyModel
