#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Node
{


public:
    enum Type {
        Root, OrExpression, AndExpresssion, NotExpression, Atom,
        Identifier, Operator, Punctuator
    };
    Node(Type type, const QString &str ="");
    ~Node();

    Type type;
    QString str;
    Node *parent;
    QList<Node *> children;
};

#endif // WIDGET_H
