#include "cmidiinputthread.hpp"

CMidiInputThread::CMidiInputThread(QObject *parent) :
    QThread(parent)
{
    clientOk = false;
    m_cmidiinput = NULL;
    setPriority(TimeCriticalPriority);
}

void CMidiInputThread::initializer(CMidiInput *cmidiinput)
{
    m_cmidiinput = cmidiinput;
    if (cmidiinput) clientOk = true;
}

int CMidiInputThread::exec()
{
    // Todo: Gestion du clientOk
    return m_cmidiinput->getPortId();
}
