#include "cmidioutput.hpp"

CMidiOutput::CMidiOutput(QObject *parent) :
    QObject(parent)
{
    createPort();
}

void CMidiOutput::createPort()
{
    m_portId = snd_seq_create_simple_port(((CMidi *)parent())->getHandle(), "Sortie",
                                     SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ,
                                     SND_SEQ_PORT_TYPE_MIDI_GENERIC);
}

int CMidiOutput::getPortId()
{
    return m_portId;
}
