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
    bool m_clientOpened;

    snd_seq_t * m_handle;
    snd_seq_system_info_t * m_infoSystem;
    snd_seq_client_info_t * m_infoClient;

    QList<CMidiInput *> m_inputPorts;
    QList<CMidiOutput *> m_outputPorts;

    int m_err;

public:
    explicit CMidi(QObject *parent = 0); // Le constructeur, que dire de plus...

    bool isClientOpened() const; // Test du client ouvert ou non. Ne pas confondre avec le Signal...

    snd_seq_t * getHandle();
    int getClientId();
    const char *getClientName() const;

    // Info System
    int getMaxNumberClient();
    int getMaxNumberPort();
    int getCurrentClients();
    int getMaxNumberChannel();

signals:
    void clientOpened();
    void clientClosed();
    void clientInfoCreated();
    void clientInfoKilled();
    void systemInfoCreated();
    void systemInfoKilled();
    void sendMidiError(int);
    
public slots:
    void openClient();
    void closeClient();
    void createInputPort();
    void createOutputPort();

};

#endif // CMIDI_HPP
