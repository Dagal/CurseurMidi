#ifndef CMIDIEVENT_HPP
#define CMIDIEVENT_HPP

#include <QObject>

class CMidiEvent : public QObject
{
    Q_OBJECT
public:
    explicit CMidiEvent(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // CMIDIEVENT_HPP
