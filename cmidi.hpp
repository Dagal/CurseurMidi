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

protected:
    void updateInfoClient();
    void updateInfoSystem();

public:
    explicit CMidi(QObject *parent = 0); // Le constructeur, que dire de plus...

    // Client
    snd_seq_t * getHandle() const;
    bool isClientOpened() const; // Test du client ouvert ou non. Ne pas confondre avec le Signal...
    int getClientId() const;
    const char *getClientName() const;
    size_t getInputBufferSize() const;
    size_t getOutputBufferSize() const;

    // Info System
    int getMaxNumberClients() const;
    int getNumberClients() const;
    int getMaxNumberPorts() const;
    int getMaxNumberChannels() const;
    int getMaxNumberQueues() const;
    int getNumberQueues() const;

    // Info Client
    int getNumberPorts() const;

    // Port
    int getNumberInputs() const;
    int getNumberOutputs() const;
    QString *getInputName(int);
    QString *getOutputName(int);

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
