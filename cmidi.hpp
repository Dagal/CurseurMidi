#ifndef CMIDI_HPP
#define CMIDI_HPP

#include <alsa/asoundlib.h>

#include "cmidiinput.h"
#include "cmidioutput.hpp"

#include <QObject>
#include <QMessageBox>

class CMidiInput;
class CMidiOutput;

class CMidi : public QObject
{
    Q_OBJECT

private:
    snd_seq_t * m_handle;
    snd_seq_system_info_t * m_infoSystem;
    snd_seq_client_info_t * m_infoClient;

    QList<CMidiInput *> m_inputPorts;
    QList<CMidiOutput *> m_outputPorts;

    int m_err;

public:
    explicit CMidi(QObject *parent = 0);
    snd_seq_t * getHandle();
    int getClientId();
    const char *getClientName() const;

signals:
    void isOpened();
    void clientInfoCreated();
    void systemInfoCreated();
    
public slots:
    void createInputPort();
    void createOutputPort();

};

#endif // CMIDI_HPP
