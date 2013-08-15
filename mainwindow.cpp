#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_cMidi = new CMidi(this);
    connect(m_cMidi,SIGNAL(systemInfoCreated()),this,SLOT(on_systemInfoCreated()));

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
}

void MainWindow::on_pushButton_clicked()
{
    // Todo: Faire les protections
    m_cMidi->createOutputPort();
}

void MainWindow::on_systemInfoCreated()
{
    int maxClient = m_cMidi->getMaxNumberClient();
    ui->maxClientsLineEdit->setText(QString::number(maxClient));
    int maxPort = m_cMidi->getMaxNumberPort();
    ui->maxPortsLineEdit->setText(QString::number(maxPort));
    int curPort = m_cMidi->getCurrentClients();
    ui->currentClientsLineEdit->setText(QString::number(curPort));
}

MainWindow::~MainWindow()
{
    delete ui;
}
