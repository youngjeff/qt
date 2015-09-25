#ifndef READER_H
#define READER_H

#endif // READER_H
#include <QObject>
#include <QDebug>
#include <qdebug.h>
class Reader : public QObject
{
    Q_OBJECT
public:
    Reader() {}
    ~Reader();

    void receiveNewspaper(const QString & name)
    {
        qDebug() << "Receives Newspaper: " <<name;
    }
};
