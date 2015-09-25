
#ifndef _QEXTSERIALPORT_H_
#define _QEXTSERIALPORT_H_

/*POSIX CODE*/
#include "posix_qextserialport.h"
#define QextBaseType Posix_QextSerialPort



class QextSerialPort: public QextBaseType {
public:
    QextSerialPort();
    QextSerialPort(const QString & name);
    QextSerialPort(PortSettings const& s);
    QextSerialPort(const QString & name, PortSettings const& s);
    QextSerialPort(const QextSerialPort& s);
    QextSerialPort& operator=(const QextSerialPort&);
    virtual ~QextSerialPort();
};

#endif
