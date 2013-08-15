#include "cmidiinput.h"

CMidiInput::CMidiInput(QObject *parent) :
    QObject(parent)
{
    createPort();
}

void CMidiInput::createPort()
{
    m_portId = snd_seq_create_simple_port(((CMidi *)parent())->getHandle(), "Entree",
                                     SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE,
                                     SND_SEQ_PORT_TYPE_MIDI_GENERIC);
}

int CMidiInput::getPortId()
{
    return m_portId;
}
