#ifndef CMIDIINPUT_H
#define CMIDIINPUT_H

#include "cmidi.hpp"

#include <QObject>

class CMidi;

class CMidiInput : public QObject
{
    Q_OBJECT

private:
    int m_portId;

public:
    explicit CMidiInput(QObject *parent = 0);
    void createPort();
    int getPortId();
    
signals:
    
public slots:
    //void listenPort(CMidiControlEvent )
    
};

#endif // CMIDIINPUT_H
