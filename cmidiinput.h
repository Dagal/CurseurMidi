#ifndef CMIDIINPUT_H
#define CMIDIINPUT_H

#include "cmidi.hpp"
#include "cmidievent.hpp"

#include <QObject>

class CMidi;

class CMidiInput : public QObject
{
    Q_OBJECT

private:
    int m_portId;
    snd_seq_port_info_t *m_portInfo;
    QList<CMidiEvent> events;

public:
    explicit CMidiInput(QObject *parent = 0);
    void createPort();
    int getPortId();
    QString *getName();
    void createEvent();
    
signals:
    
public slots:
    //void listenPort(CMidiControlEvent )
    
};

#endif // CMIDIINPUT_H
