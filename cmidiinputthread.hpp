#ifndef CMIDIINPUTTHREAD_HPP
#define CMIDIINPUTTHREAD_HPP

#include "cmidiinput.h"

#include <QThread>

class CMidiInputThread : public QThread
{
    Q_OBJECT

private:
    CMidiInput * m_cmidiinput;
    bool clientOk;

public:
    explicit CMidiInputThread(QObject *parent = 0);
    int exec();
    void initializer(CMidiInput *cmidiinput);
    
signals:
    void eventReceived();
    
public slots:
    
};

#endif // CMIDIINPUTTHREAD_HPP
