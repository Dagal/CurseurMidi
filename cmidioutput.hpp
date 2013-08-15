#ifndef CMIDIOUTPUT_HPP
#define CMIDIOUTPUT_HPP

#include "cmidi.hpp"
#include "cmidievent.hpp"

#include <QObject>

class CMidi;

class CMidiOutput : public QObject
{
    Q_OBJECT

private:
    int m_portId;
    QList<CMidiEvent> events;

public:
    explicit CMidiOutput(QObject *parent = 0);
    void createPort();
    int getPortId();
    void createEvent();
    
signals:
    
public slots:
    
};

#endif // CMIDIOUTPUT_HPP
