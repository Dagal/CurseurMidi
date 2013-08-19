#include "cmidioutput.hpp"

CMidiOutput::CMidiOutput(QObject *parent) :
    QObject(parent)
{
    int m_err = -999;
    m_err = snd_seq_port_info_malloc(&m_portInfo);
    createPort();
}

void CMidiOutput::createPort()
{
    m_portId = snd_seq_create_simple_port(((CMidi *)parent())->getHandle(), "Sortie",
                                     SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ,
                                     SND_SEQ_PORT_TYPE_MIDI_GENERIC);
    int m_err = snd_seq_get_port_info(((CMidi *)(parent()))->getHandle(), m_portId, m_portInfo);
    QString name("Sortie - ");
    name.append(QString::number(m_portId));
    snd_seq_port_info_set_name(m_portInfo, name.toLocal8Bit().constData());
    snd_seq_set_port_info(((CMidi *)(parent()))->getHandle(), m_portId, m_portInfo);
}

int CMidiOutput::getPortId()
{
    return m_portId;
}

QString *CMidiOutput::getName()
{
    QString *qs;
    int m_err = snd_seq_get_port_info(((CMidi *)(parent()))->getHandle(), m_portId, m_portInfo);
    qs = new QString(snd_seq_port_info_get_name(m_portInfo));
    return qs;
}
