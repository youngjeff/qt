#ifndef NODE_H
#define NODE_H

#include <QList>
#include <QString>

class Node
{
public:
    enum Type { Root, OrExpression, AndExpression, NotExpression, Atom,
                Identifier, Operator, Punctuator };
    //Type 指明这个node的类型
    Node(Type type, const QString &str = "");
    ~Node();

    Type type;
    QString str;
    Node *parent;//父亲节点
    QList<Node *> children;//孩子节点
};

#endif
