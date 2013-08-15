#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <alsa/asoundlib.h>

#include "cmidi.hpp"
#include "cmidioutput.hpp"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_openClientButton_clicked();

    void on_closeClientButton_clicked();

    void on_curseur_valueChanged(int value);

    void on_quitButton_clicked();

    void on_createInputPortButton_clicked();

    void on_pushButton_clicked();

    void on_systemInfoCreated();

private:
    Ui::MainWindow *ui;

    CMidi * m_cMidi;

    int err;
    CMidiOutput * sortie;
    CMidiInput * entree;
    snd_seq_ev_ctrl_t controle;
};

#endif // MAINWINDOW_H
