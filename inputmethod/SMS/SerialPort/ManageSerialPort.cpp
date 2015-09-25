/********************************************************************************************************
		* PROGRAM      : QSerialPortTerminal
		* DATE - TIME  : vendredi 03 octobre 2008 - 11h15
		* AUTHOR       : VIANNEY-LIAUD Philippe ( philippe.vianney.liaud gmail.com )
			* FILENAME     : ManageSerialPort.cpp
			* LICENSE      : GPL
			* COMMENTARY   :
********************************************************************************************************/
#include <QtDebug>
#include "ManageSerialPort.h"

/********************************************************************************************************
		* Classe ManageSerialPort
		*****************************************************************************************************/

//Constructeur
ManageSerialPort::ManageSerialPort()
{
	//Init pointeur a NULL
	threadSend = NULL;
	threadReceive = NULL;
	
	//Init des bool
	sendingEnabled = false;
	receivingEnabled = false;
	closeCalled = false;
	saveStateSendEnabled = false;
	saveStateReceivedEnabled = false;
	saveStateReceiveData = false;
}

ManageSerialPort::ManageSerialPort(const QString &name, const BaudRateType baudRate, \
		const DataBitsType dataBits, const ParityType parity, \
		const StopBitsType stopBits, const FlowType flowControl, \
		ulong seconds, ulong milliseconds)
{
	//Init pointeur a NULL
	threadSend = NULL;
	threadReceive = NULL;
	
	//Init des bool
	sendingEnabled = false;
	receivingEnabled = false;
	closeCalled = false;
	saveStateSendEnabled = false;
	saveStateReceivedEnabled = false;
	saveStateReceiveData = false;
	
	setPort(name);
	setBaudRate(baudRate);
	setDataBits(dataBits);
	setParity(parity);
	setStopBits(stopBits);
	setFlowControl(flowControl);
	setTimeout(seconds, milliseconds);
}

//Destructeur
ManageSerialPort::~ManageSerialPort()
{
	if (threadSend != NULL)
	{
		delete threadSend;
		threadSend = NULL;
	}
	
	if (threadReceive != NULL)
	{
		delete threadReceive;
		threadReceive = NULL;
	}
	
	if (isOpen())
		extSerialPort.close();
}

bool ManageSerialPort::open()
{
	bool res = extSerialPort.open(QIODevice::ReadWrite);
	
	if (closeCalled)
	{
		if (saveStateSendEnabled)
			enableSending();
		
		if (saveStateReceivedEnabled)
			enableReceiving();
		
		if (saveStateReceiveData)
			receiveData();
		closeCalled = false;
	}
	
	return res;
}

bool ManageSerialPort::open(const QString &name, const BaudRateType baudRate, \
		const DataBitsType dataBits,const ParityType parity, \
		const StopBitsType stopBits, const FlowType flowControl, \
		ulong seconds, ulong milliseconds)
{
	setPort(name);
	setBaudRate(baudRate);
	setDataBits(dataBits);
	setParity(parity);
	setStopBits(stopBits);
	setFlowControl(flowControl);
	setTimeout(seconds, milliseconds);
	
	bool res = extSerialPort.open(QIODevice::ReadWrite);
	
	
	return res;
}

bool ManageSerialPort::isOpen()
{
	return extSerialPort.isOpen();
}

void ManageSerialPort::close()
{
	closeCalled = true;
	saveStateSendEnabled = isSendingEnabled();
	saveStateReceivedEnabled = isReceivingEnabled();
	
	disableSending();
	disableReceiving();
	
	extSerialPort.close();
}

void ManageSerialPort::setPort(const QString &name)
{
	extSerialPort.setPortName(name);
}

QString ManageSerialPort::getPort()
{
	return extSerialPort.portName();
}


void ManageSerialPort::setBaudRate(const BaudRateType baudRate)
{
	extSerialPort.setBaudRate(baudRate);
}

QString ManageSerialPort::getBaudRate()
{
	switch (extSerialPort.baudRate())
	{
		case BAUD50:
			return QString("50");
		case BAUD75:
			return QString("75");
		case BAUD110:
			return QString("110");
		case BAUD134:
			return QString("134");
		case BAUD150:
			return QString("150");
		case BAUD200:
			return QString("200");
		case BAUD300:
			return QString("300");
		case BAUD600:
			return QString("600");
		case BAUD1200:
			return QString("1200");
		case BAUD1800:
			return QString("1800");
		case BAUD2400:
			return QString("2400");
		case BAUD4800:
			return QString("4800");
		case BAUD9600:
			return QString("9600");
		case BAUD14400:
			return QString("14400");
		case BAUD19200:
			return QString("19200");
		case BAUD38400:
			return QString("38400");
		case BAUD56000:
			return QString("56000");
		case BAUD57600:
			return QString("57600");
		case BAUD76800:
			return QString("76800");
		case BAUD115200:
			return QString("115200");
		case BAUD128000:
			return QString("128000");
		case BAUD256000:
			return QString("256000");
	}
	return 0;
}


void ManageSerialPort::setDataBits(const DataBitsType dataBits)
{
	extSerialPort.setDataBits(dataBits);
}

QChar ManageSerialPort::getDataBits()
{
	switch (extSerialPort.dataBits())
	{
		case DATA_5:
			return QChar('5');
		case DATA_6:
			return QChar('6');
		case DATA_7:
			return QChar('7');
		case DATA_8:
			return QChar('8');
		}
		return 0;
}


void ManageSerialPort::setParity(const ParityType parity)
{
	extSerialPort.setParity(parity);
}

QString ManageSerialPort::getParity()
{
	switch (extSerialPort.parity())
	{
		case PAR_NONE:
			return QString(tr("None"));
		case PAR_ODD:
			return QString(tr("Odd"));
		case PAR_EVEN:
			return QString(tr("Even"));
		case PAR_MARK:
			return QString(tr("Mark"));
		case PAR_SPACE:
			return QString(tr("Space"));
		}
		return 0;
}


void ManageSerialPort::setStopBits(const StopBitsType stopBits)
{
	extSerialPort.setStopBits(stopBits);
}

QString ManageSerialPort::getStopBit()
{
	switch (extSerialPort.stopBits())
	{
		case STOP_1:
			return QString("1");
		case STOP_1_5:
			return QString("1.5");
		case STOP_2:
			return QString("2");
		}
		return 0;
}


void ManageSerialPort::setFlowControl(const FlowType flowControl)
{
	extSerialPort.setFlowControl(flowControl);
}

QString ManageSerialPort::getFlowControl()
{
	switch (extSerialPort.flowControl())
	{
		case FLOW_OFF:
			return QString(tr("None"));
		case FLOW_HARDWARE 	:
			return QString(tr("Hardware"));
		case FLOW_XONXOFF :
			return QString(tr("Xon/Xoff"));
		}
		return 0;
}


void ManageSerialPort::setTimeout(ulong seconds, ulong milliseconds)
{
	extSerialPort.setTimeout(seconds,milliseconds);
}

/*
QString ManageSerialPort::getLastErrorToString()
{
	ulong res = extSerialPort.lastError();
	switch (res)
	{
		case E_NO_ERROR:
			return QString(tr("No Error has occured"));
		case E_INVALID_FD:
			return QString(tr("Invalid file descriptor (port was not opened correctly)"));
		case E_NO_MEMORY:
			return QString(tr("Unable to allocate memory tables (POSIX)"));
		case E_CAUGHT_NON_BLOCKED_SIGNAL:
			return QString(tr("Caught a non-blocked signal (POSIX)"));
		case E_PORT_TIMEOUT:
			return QString(tr("Operation timed out (POSIX)"));
		case E_INVALID_DEVICE:
			return QString(tr("The file opened by the port is not a character device (POSIX)"));
		case E_BREAK_CONDITION:
			return QString(tr("The port detected a break condition"));
		case E_FRAMING_ERROR:
			return QString(tr("The port detected a framing error (usually caused by incorrect baud rate settings)"));
		case E_IO_ERROR:
			return QString(tr("There was an I/O error while communicating with the port"));
		case E_BUFFER_OVERRUN:
			return QString(tr("Character buffer overrun"));
		case E_RECEIVE_OVERFLOW:
			return QString(tr("Receive buffer overflow"));
		case E_RECEIVE_PARITY_ERROR:
			return QString(tr("The port detected a parity error in the received data"));
		case E_TRANSMIT_OVERFLOW:
			return QString(tr("Transmit buffer overflow"));
		case E_READ_FAILED:
			return QString(tr("General read operation failure"));
		case E_WRITE_FAILED:
			return QString(tr("General write operation failure"));
		}
		return 0;
}*/

/*
ulong ManageSerialPort::getLastError()
{
	return extSerialPort.lastError();
}
*/


void ManageSerialPort::enableSending()
{
	if (!sendingEnabled && threadSend == NULL) //Si l'envoi n'est pas active && si threadSend n'est pas alloue
	{
		threadSend = new ThreadSend(extSerialPort);
		sendingEnabled = true;
	}
}

void ManageSerialPort::disableSending()
{
	if (sendingEnabled && threadSend != NULL) //Si l'envoi est active && si threadSend est alloue
	{
		delete (threadSend);
		threadSend = NULL;
		sendingEnabled = false;
	}
}

bool ManageSerialPort::isSendingEnabled()
{
	return sendingEnabled;
}

uchar ManageSerialPort::sendData(QByteArray &dataToSend)
{
	if (!isOpen()) //Si le port n'est pas ouvert
		return 2;
	
	if (!sendingEnabled || threadSend == NULL) //Si l'envoi n'est pas active || si threadSend n'est pas alloue
		return 3;
	
	threadSend->addDataToSend(dataToSend); //Ajout des donnees a envoyer
	return 1;
}

void ManageSerialPort::stopSending()
{
	if (!sendingEnabled || threadSend == NULL) //Si l'envoi n'est pas active || si threadSend n'est pas été alloue
		return;
	
	if (threadSend->isRunning()) //si un envoi est en cour
	{
		threadSend->stopSending(); //on donne l'ordre d'arreter l'envoi
		threadSend->wait(); //on attend l'arret
	}
}



void ManageSerialPort::enableReceiving()
{
	if (!receivingEnabled && threadReceive == NULL) //Si la reception n'est pas active && si threadReceive n'est pas alloue
	{
		threadReceive = new ThreadReceive(extSerialPort);
		connect(threadReceive, SIGNAL(newDataReceived(const QByteArray &)), this, SIGNAL(newDataReceived(const QByteArray &)));
		receivingEnabled = true;
	}
}

void ManageSerialPort::disableReceiving()
{
	if (receivingEnabled && threadReceive != NULL) //Si la reception est pas active && si threadReceive est alloue
	{
		delete (threadReceive);
		threadReceive = NULL;
		receivingEnabled = false;
	}
}

bool ManageSerialPort::isReceivingEnabled()
{
	return receivingEnabled;
}

uchar ManageSerialPort::receiveData()
{
	if (!isOpen()) //Si le port n'est pas ouvert
		return 2;
	if (!receivingEnabled || threadReceive == NULL) //Si la reception n'est pas active || si threadReceive n'est pas été alloue
		return 3;
	
	if (!threadReceive->isRunning())
	{
		saveStateReceiveData = true;
		threadReceive->start(); //Demarrage du thread de reception
	}
	return 1;
}

void ManageSerialPort::stopReceiving()
{
	if (!receivingEnabled || threadReceive == NULL) //Si la reception n'est pas active || si threadReceive n'est pas alloue
		return;
	
	if (threadReceive->isRunning()) //Si le thread de reception est en fonctionnement
	{
		saveStateReceiveData = false;
		threadReceive->stopReceiving(); //on donne l'ordre d'arreter la reception
		threadReceive->wait(); //on attend l'arret
	}
}

/********************************************************************************************************
		* Classe ThreadSend
		*****************************************************************************************************/

ThreadSend::ThreadSend(QextSerialPort &addressSerialPort) : extSerialPort(addressSerialPort)
{
	dataToSend.clear();
	stopped=false;
}

ThreadSend::~ThreadSend()
{
	if (isRunning())
	{
		stopSending();
		wait();
	}
}


void ThreadSend::addDataToSend(QByteArray &dataToAdd)
{
	QMutexLocker locker(&mutexSend);
	for (int i=0; i<dataToAdd.size(); i++)
		dataToSend.enqueue(QByteArray(1,dataToAdd.at(i)));
	
	if (!isRunning())
		start();
}

void ThreadSend::stopSending()
{
	stopped=true;
}

void ThreadSend::run()
{
	QByteArray byteArray;
	
	forever
	{
		if (dataToSend.isEmpty() || stopped)
		{
			stopped = false;
			break;
		}
		mutexSend.lock();
		byteArray = dataToSend.dequeue();
		mutexSend.unlock();
		
		extSerialPort.write(byteArray, 1);
	}
}

/********************************************************************************************************
		* Classe ThreadReceive - A TERMINER
		*****************************************************************************************************/

ThreadReceive::ThreadReceive(QextSerialPort &addressSerialPort) : extSerialPort(addressSerialPort)
{
	stopped=false;
}

ThreadReceive::~ThreadReceive()
{
	if (isRunning())
	{
		stopReceiving();
		wait();
	}
}

void ThreadReceive::stopReceiving()
{
	stopped = true;
}

void ThreadReceive::run()
{
	int numBytes=0;
	char data[1024];
	QByteArray dataReceived;
	
	forever
	{
		if (stopped)
		{
			stopped = false;
			break;
		}
		numBytes = extSerialPort.bytesAvailable();
		if (numBytes > 0)
		{
			mutexReceive.lock();
			
			extSerialPort.read(data, numBytes);
			data[numBytes]='\0';
			
			dataReceived = data;
			
			mutexReceive.unlock();
			
			emit newDataReceived(dataReceived);
		}
	}
}

