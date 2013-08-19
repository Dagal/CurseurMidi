#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_cMidi = new CMidi(this);
    connect(m_cMidi,SIGNAL(systemInfoCreated()),this,SLOT(on_systemInfoCreated()));
    connect(m_cMidi,SIGNAL(clientInfoCreated()),this,SLOT(on_clientInfoCreated()));
    connect(m_cMidi,SIGNAL(clientOpened()),this,SLOT(on_clientOpened()));

}

void MainWindow::on_openClientButton_clicked()
{
    if (!m_cMidi->isClientOpened())
    {
        m_cMidi->openClient();
        ui->clientNumberLineEdit->setText(QString::number(m_cMidi->getClientId()));
        ui->clientNameLineEdit->setText(m_cMidi->getClientName());

        ui->openClientButton->setEnabled(false);
        ui->closeClientButton->setEnabled(true);
    }
}

void MainWindow::on_closeClientButton_clicked()
{
    if (m_cMidi->isClientOpened())
    {
        ui->curseur->setValue(0);
        m_cMidi->closeClient();

        ui->openClientButton->setEnabled(true);
        ui->closeClientButton->setEnabled(false);
    }
}

void MainWindow::on_curseur_valueChanged(int value)
{
    if (m_cMidi->isClientOpened())
    {
        value = value;
    }
}

void MainWindow::on_quitButton_clicked()
{
    on_closeClientButton_clicked();
    exit(0);
}


void MainWindow::on_createInputPortButton_clicked()
{
    // Todo: Faire les protections
    m_cMidi->createInputPort();
    updatePortTab();
}

void MainWindow::on_pushButton_clicked()
{
    // Todo: Faire les protections
    m_cMidi->createOutputPort();
    updatePortTab();
    ui->outputPortComboBox->addItem(m_cMidi->getOutputName(ui->outputPortComboBox->count())->append(""));
}

void MainWindow::on_systemInfoCreated()
{
    int maxClient = m_cMidi->getMaxNumberClients();
    ui->maxClientsLineEdit->setText(QString::number(maxClient));
    int maxPort = m_cMidi->getMaxNumberPorts();
    ui->maxPortsLineEdit->setText(QString::number(maxPort));
    int curPort = m_cMidi->getNumberClients();
    ui->currentClientsLineEdit->setText(QString::number(curPort));
    int maxChan = m_cMidi->getMaxNumberChannels();
    ui->maxChannelsLineEdit->setText(QString::number(maxChan));
    int maxQ = m_cMidi->getMaxNumberQueues();
    ui->maxQueuesLineEdit->setText(QString::number(maxQ));
    int curQ = m_cMidi->getNumberQueues();
    ui->currentQueuesLineEdit->setText(QString::number(curQ));
    size_t inBuffSize = m_cMidi->getInputBufferSize();
    ui->inputBufferSizeLineEdit->setText(QString::number(inBuffSize));
    size_t outBuffSize = m_cMidi->getOutputBufferSize();
    ui->outputBufferSizeLineEdit->setText(QString::number(outBuffSize));
}

void MainWindow::on_clientInfoCreated()
{
    int curPorts = m_cMidi->getNumberPorts();
    ui->numberCurrentPortsLineEdit->setText(QString::number(curPorts));
}

void MainWindow::on_clientOpened()
{
    updatePortTab();
}

void MainWindow::updatePortTab()
{
    int numInput = m_cMidi->getNumberInputs();
    ui->numberInputPortLineEdit->setText(QString::number(numInput));
    int numOutput = m_cMidi->getNumberOutputs();
    ui->numberOutputPortLineEdit->setText(QString::number(numOutput));
}

MainWindow::~MainWindow()
{
    delete ui;
}
