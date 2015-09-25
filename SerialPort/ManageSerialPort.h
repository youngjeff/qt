/********************************************************************************************************
* PROGRAM      : QSerialPortTerminal
* DATE - TIME  : vendredi 03 octobre 2008 - 11h15
* AUTHOR       : VIANNEY-LIAUD Philippe ( philippe.vianney.liaud gmail.com )
* FILENAME     : ManageSerialPort.h
* LICENSE      : GPL
* COMMENTARY   : Manage qExtSerialPort
********************************************************************************************************/
#ifndef MANAGESERIALPORT_H
#define MANAGESERIALPORT_H

#include <QThread>
#include <QQueue>
#include <QMetaType>
#include <QMutex>
#include "qextserialport.h"

Q_DECLARE_METATYPE(BaudRateType);
Q_DECLARE_METATYPE(DataBitsType);
Q_DECLARE_METATYPE(ParityType);
Q_DECLARE_METATYPE(StopBitsType);
Q_DECLARE_METATYPE(FlowType);

class ThreadSend;
class ThreadReceive;


class ManageSerialPort : public QObject
{
    Q_OBJECT

public:
//Constructeurs + destructeur
    ManageSerialPort();
    ManageSerialPort(const QString &name, const BaudRateType baudRate, const DataBitsType dataBits,\
                     const ParityType parity, const StopBitsType stopBits, \
                     const FlowType flowControl, ulong seconds, ulong milliseconds);
    ~ManageSerialPort();

//General
    bool open();
    bool open(const QString &name, const BaudRateType baudRate, const DataBitsType dataBits,\
              const ParityType parity, const StopBitsType stopBits, \
              const FlowType flowControl, ulong seconds, ulong milliseconds);
    bool isOpen();
    void close();

    //Sets the name of the device associated with the object, e.g. "COM1", or "/dev/ttyS0"
    void setPort(const QString &name);
    QString getPort();

    /*Most used : '*' (POSTX & Windows)
    RATE          Windows Speed   POSIX Speed
    -----------   -------------   -----------
     enum BaudRateType{
        BAUD50                 110          50		//POSIX ONLY
        BAUD75                 110          75		//POSIX ONLY
       *BAUD110                110         110
        BAUD134                110         134.5	//POSIX ONLY
        BAUD150                110         150		//POSIX ONLY
        BAUD200                110         200		//POSIX ONLY
       *BAUD300                300         300
       *BAUD600                600         600
       *BAUD1200              1200        1200
        BAUD1800              1200        1800		//POSIX ONLY
       *BAUD2400              2400        2400
       *BAUD4800              4800        4800
       *BAUD9600              9600        9600
        BAUD14400            14400        9600		//WINDOWS ONLY
       *BAUD19200            19200       19200
       *BAUD38400            38400       38400
        BAUD56000            56000       38400		//WINDOWS ONLY
       *BAUD57600            57600       57600
        BAUD76800            57600       76800		//POSIX ONLY
       *BAUD115200          115200      115200
        BAUD128000          128000      115200		//WINDOWS ONLY
        BAUD256000          256000      115200		//WINDOWS ONLY
    }*/
    void setBaudRate(const BaudRateType baudRate);

    /*getBaudRate
        return "50";
        return "75";
        return "110";
        return "134";
        return "150";
        return "200";
        return "300";
        return "600";
        return "1200";
        return "1800";
        return "2400";
        return "4800";
        return "9600";
        return "14400";
        return "19200";
        return "38400";
        return "56000";
        return "57600";
        return "76800";
        return "115200";
        return "128000";
        return "256000";*/
    QString getBaudRate();


    /*enum DataBitsType {
        DATA_5
        DATA_6
        DATA_7
        DATA_8
    };*/
    void setDataBits(const DataBitsType dataBits);

    /*getDataBits
        return '5';
        return '6';
        return '7';
        return '8';*/
    QChar getDataBits();


    /*enum ParityType {
        PAR_NONE	//None means that no parity bit is sent at all
        PAR_ODD		//Odd
        PAR_EVEN	//Even
        PAR_MARK	//Windows only : Mark parity means that the parity bit is always set to the mark signal condition (logical 1)
        PAR_SPACE	//Space parity always sends the parity bit in the space signal condition
    };*/
    void setParity(const ParityType parity);

    /*getParity
        return "None";
        return "Odd";
        return "Even";
        return "Mark";	Windows only
        return "Space";*/
    QString getParity();


    /*enum StopBitsType {
        STOP_1
        STOP_1_5	//WINDOWS ONLY
        STOP_2
    };*/
    void setStopBits(const StopBitsType stopBits);

    /*getStopBit
        return "1"
        return "1.5"
        return "2"*/
    QString getStopBit();


    /*enum FlowType {
        FLOW_OFF
        FLOW_HARDWARE
        FLOW_XONXOFF
    };*/
    void setFlowControl(const FlowType flowControl);

    /*getFlowControl
        return "None"
        return "Hardware"
        return "Xon/Xoff"*/
    QString getFlowControl();


    void setTimeout(ulong seconds, ulong milliseconds);

    /*getLastErrorToString
        return "No Error has occured"
        return "Invalid file descriptor (port was not opened correctly)"
        return "Unable to allocate memory tables (POSIX)"
        return "Caught a non-blocked signal (POSIX)"
        return "Operation timed out (POSIX)"
        return "The file opened by the port is not a character device (POSIX)"
        return "The port detected a break condition"
        return "The port detected a framing error (usually caused by incorrect baud rate settings)"

        return "There was an I/O error while communicating with the port"
        return "Character buffer overrun"
        return "Receive buffer overflow"
        return "The port detected a parity error in the received data"
        return "Transmit buffer overflow"
        return "General read operation failure"
        return "General write operation failure"*/
    /*QString getLastErrorToString();*/

    /*getLastError
        return 0 : No Error has occured
        return 1 : Invalid file descriptor (port was not opened correctly)
        return 2 : Unable to allocate memory tables (POSIX)
        return 3 : Caught a non-blocked signal (POSIX)
        return 4 : Operation timed out (POSIX)
        return 5 : The file opened by the port is not a character device (POSIX)
        return 6 : The port detected a break condition"
        return 7 : The port detected a framing error (usually caused by incorrect baud rate settings)

        return 8 : There was an I/O error while communicating with the port
        return 9 : Character buffer overrun
        return 10 : Receive buffer overflow
        return 11 : The port detected a parity error in the received data
        return 12 : Transmit buffer overflow
        return 13 : General read operation failure
        return 14 : General write operation failure*/
    /*ulong getLastError();*/



    //Emission
    void enableSending();
    void disableSending();

    /*isSendingEnabled
        return 0 : sending is not enable
        return 1 : sending is enable*/
    bool isSendingEnabled();

    /*sendData
        return 1 : add OK
        return 2 : port is not open
        return 3 : sending is not enable*/
    uchar sendData(QByteArray &dataToSend);

    void stopSending();

//Reception
    void enableReceiving();
    void disableReceiving();

    /*isReceivingEnabled
        return 0 : receiving is not enable
        return 1 : receiving is enable*/
    bool isReceivingEnabled();

    /*receiveData
        return 1 : start thread OK
        return 2 : port is not open
        return 3 : receiving is not enable*/
    uchar receiveData();

    void stopReceiving();

signals:
    void newDataReceived(const QByteArray &dataReceived);

private:
    //Variables privees
    QextSerialPort extSerialPort ;
    ThreadSend *threadSend;
    ThreadReceive *threadReceive;

    bool sendingEnabled;
    bool receivingEnabled;

    bool closeCalled;
    bool saveStateSendEnabled;
    bool saveStateReceivedEnabled;
    bool saveStateReceiveData;

};

//#endif // MANAGESERIALPORT_H

class ThreadSend : public QThread
{
    Q_OBJECT

public:
    ThreadSend(QextSerialPort &addressSerialPort);
    ~ThreadSend();
    void addDataToSend(QByteArray &dataToAdd);
    void stopSending();

protected:
    void run();

private:
    QMutex mutexSend;
    QextSerialPort &extSerialPort;
    QQueue<QByteArray> dataToSend;
    bool stopped;
};

class ThreadReceive : public QThread
{
    Q_OBJECT

public:
    ThreadReceive(QextSerialPort &addressSerialPort);
    ~ThreadReceive();
    void stopReceiving();

protected:
    void run();

private :
    QMutex mutexReceive;
    QextSerialPort &extSerialPort;
    bool stopped;

signals:
    void newDataReceived(const QByteArray &dataReceived);
};
#endif
