#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#endif // NEWSPAPER_H
#include <QObject>
class Newspaper : public QObject
{
    Q_OBJECT
public  :
    Newspaper(const QString & name):
            m_name(name)
    {

    }
    ~Newspaper();
    void send()
    {
        emit newPaper(m_name);
    }

    void newPaper( QString name);
private:
    QString m_name;
};
