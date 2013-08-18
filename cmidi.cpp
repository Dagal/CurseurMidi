#include "cmidi.hpp"

CMidi::CMidi(QObject *parent) :
    QObject(parent)
{
    m_clientOpened = false;
    m_err = -999;
}

void CMidi::openClient()
{
    if (!m_clientOpened)
    {
        m_err = snd_seq_open(&m_handle, "default", SND_SEQ_OPEN_DUPLEX, 0);
        if (m_err < 0)
        {
            QMessageBox msgBox;
            msgBox.setText("Impossible de creer le client!");
            msgBox.exec();

            emit sendMidiError(m_err);
        }
        else
        {
            emit clientOpened();

            snd_seq_client_info_malloc(&m_infoClient);
            updateInfoClient();

            snd_seq_system_info_malloc(&m_infoSystem);
            updateInfoSystem();
        }
    }
}

void CMidi::updateInfoSystem()
{
    m_err = snd_seq_system_info(m_handle, m_infoSystem);
    if (m_err < 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Impossible de créer l'info system!");
        msgBox.exec();

        emit sendMidiError(m_err);
    }
    else emit systemInfoCreated();
}

void CMidi::updateInfoClient()
{
    m_err = snd_seq_get_client_info(m_handle, m_infoClient);
    if (m_err < 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Impossible de créer l'info client!");
        msgBox.exec();

        emit sendMidiError(m_err);
    }
    else emit clientInfoCreated();
}

bool CMidi::isClientOpened() const
{
    return m_clientOpened;
}

void CMidi::closeClient()
{
    m_clientOpened = false;
    snd_seq_system_info_free(m_infoSystem);
    emit systemInfoKilled();
    snd_seq_client_info_free(m_infoClient);
    emit clientInfoKilled();
    snd_seq_close(m_handle);
    emit clientClosed();
}

snd_seq_t * CMidi::getHandle() const
{
    return m_handle;
}

void CMidi::createInputPort()
{
    CMidiInput * cmi = new CMidiInput(this);
    m_inputPorts.append(cmi);
    updateInfoClient();
}

void CMidi::createOutputPort()
{
    CMidiOutput * cmo = new CMidiOutput(this);
    m_outputPorts.append(cmo);
    updateInfoClient();
}

int CMidi::getClientId() const
{
    return snd_seq_client_id(m_handle);
}

const char* CMidi::getClientName() const
{
    return snd_seq_client_info_get_name(m_infoClient);
}

int CMidi::getMaxNumberClient() const
{
    return snd_seq_system_info_get_clients(m_infoSystem);
}

int CMidi::getMaxNumberPort() const
{
    return snd_seq_system_info_get_ports(m_infoSystem);
}

int CMidi::getCurrentClients() const
{
    return snd_seq_system_info_get_cur_clients(m_infoSystem);
}

int CMidi::getMaxNumberChannel() const
{
    return snd_seq_system_info_get_channels(m_infoSystem);
}

int CMidi::getMaxNumberQueue() const
{
    return snd_seq_system_info_get_queues(m_infoSystem);
}

int CMidi::getCurrentQueue() const
{
    return snd_seq_system_info_get_cur_queues(m_infoSystem);
}

size_t CMidi::getInputBufferSize() const
{
    return snd_seq_get_input_buffer_size(m_handle);
}

size_t CMidi::getOutputBufferSize() const
{
    return snd_seq_get_output_buffer_size(m_handle);
}

int CMidi::getCurrentPorts() const
{
    return snd_seq_client_info_get_num_ports(m_infoClient);
}
