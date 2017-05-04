#include "controller_settings.h"
#include "ui_controller_settings.h"

Controller_settings::Controller_settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Controller_settings)
{
    freq = 0;
    ui->setupUi(this);
    connect (ui->freq10,    SIGNAL(toggled(bool)),this,SLOT(setFreq(bool)));
    connect (ui->freq100,   SIGNAL(toggled(bool)),this,SLOT(setFreq(bool)));
    connect (ui->freq1000,  SIGNAL(toggled(bool)),this,SLOT(setFreq(bool)));
}

Controller_settings::~Controller_settings()
{
    delete ui;
}

void Controller_settings::on_ExitButton_clicked()
{
    this ->close();
}

void Controller_settings::setFreq(bool activated)
{
    if (activated && ui->freq10->isChecked())
    {
        freq = 10;
        qDebug("Freq10Enabled =%i",freq);
    }
    if (activated && ui->freq100->isChecked())
    {
        freq = 100;
        qDebug("Freq100Enabled =%i",freq);
    }
    if (activated && ui->freq1000->isChecked())
    {
        freq = 1000;
        qDebug("Freq1000Enabled =%i",freq);
    }

}

void Controller_settings::on_SaveButton_clicked()
{
    emit send_freq(freq);
    emit send_freq_to_MK(freq);
    this->close();
}
