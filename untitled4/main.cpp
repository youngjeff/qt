#include <QCoreApplication>

#include "newspaper.h"
#include "reader.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Newspaper newspaper("Newspaper A");
    Reader    reader();
    QObject::connect(&newspaper,&Newspaper::newPaper,&reader,&Reader::receiveNewspaper);
    newspaper.send();
    return a.exec();
}
