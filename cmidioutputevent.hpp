#ifndef CMIDIOUTPUTEVENT_HPP
#define CMIDIOUTPUTEVENT_HPP

#include <QObject>

class CMidiOutputEvent : public QObject
{
    Q_OBJECT
public:
    explicit CMidiOutputEvent(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // CMIDIOUTPUTEVENT_HPP
