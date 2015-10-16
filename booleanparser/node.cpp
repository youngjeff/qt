#include <QtCore>

#include "booleanparser.h"

Node::Node(Type type, const QString &str)
{
    this->type = type;
    this->str = str;
    parent = 0;//parent属性保存父节点,QString 保存内容
}

Node::~Node()
{
    qDeleteAll(children);//删除所有内容
}
