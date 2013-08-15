#include "cmidi.hpp"

CMidi::CMidi(QObject *parent) :
    QObject(parent)
{
    m_err = -999;
    m_err = snd_seq_open(&m_handle, "default", SND_SEQ_OPEN_DUPLEX, 0);
    if (m_err < 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Impossible de creer le client!");
        msgBox.exec();

        exit(1);
    }
    emit isOpened();

    snd_seq_client_info_malloc(&m_infoClient);
    m_err = snd_seq_get_client_info(m_handle, m_infoClient);
    if (m_err < 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Impossible de créer l'info client!");
        msgBox.exec();

        exit(1);
    }
    emit clientInfoCreated();

    snd_seq_system_info_malloc(&m_infoSystem);
    m_err = snd_seq_system_info(m_handle, m_infoSystem);
    if (m_err < 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Impossible de créer l'info system!");
        msgBox.exec();

        exit(1);
    }
    emit systemInfoCreated();
}

snd_seq_t * CMidi::getHandle()
{
    return m_handle;
}

void CMidi::createInputPort()
{
    CMidiInput * cmi = new CMidiInput(this);
    m_inputPorts.append(cmi);
}

void CMidi::createOutputPort()
{
    CMidiOutput * cmo = new CMidiOutput(this);
    m_outputPorts.append(cmo);
}

int CMidi::getClientId()
{
    return snd_seq_client_id(m_handle);
}

const char* CMidi::getClientName() const
{
    return snd_seq_client_info_get_name(m_infoClient);
}
