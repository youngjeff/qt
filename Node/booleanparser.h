#ifndef BOOLEANPARSER_H
#define BOOLEANPARSER_H
#include "widget.h"

class BooleanParser
{
public:
    Node *parse(const QString &expr);
private:
    Node *parseOrExpression();
    Node *parseNotExpression();
    Node *parseAndExpression();
    Node *parseAtom();
    Node *parseIdentifier();
    void addChild(Node *parent, Node *child);
    void addToken(Node *parent, const QString &str,Node::Type type);
    bool matchToken(const QString &str) const;

    QString in;
    int pos;
};

#endif // BOOLEANPARSER_H
