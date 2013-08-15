#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clientIsOpen = false;
    m_cMidi = NULL;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openClientButton_clicked()
{
    if (!clientIsOpen)
    {
        m_cMidi = new CMidi(this);
        ui->clientNumberLineEdit->setText(QString::number(m_cMidi->getClientId()));
        ui->clientNameLineEdit->setText(m_cMidi->getClientName());


        clientIsOpen = true;

        ui->openClientButton->setEnabled(false);
        ui->closeClientButton->setEnabled(true);

        connect(m_cMidi,SIGNAL(systemInfoCreated()),this,SLOT(on_systemInfoCreated()));
    }
}

void MainWindow::on_closeClientButton_clicked()
{
    if (clientIsOpen)
    {
        ui->curseur->setValue(0);
        err = snd_seq_close(m_cMidi->getHandle());
        clientIsOpen = false;
        ui->openClientButton->setEnabled(true);
        ui->closeClientButton->setEnabled(false);
    }
}

void MainWindow::on_curseur_valueChanged(int value)
{
    if (clientIsOpen)
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
    ui->maxClientsLineEdit->setText("Maximum encore inconnu...");
}
