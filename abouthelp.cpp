#include "abouthelp.h"
#include "ui_abouthelp.h"

AboutHelp::AboutHelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutHelp)
{
    ui->setupUi(this);
}

AboutHelp::~AboutHelp()
{
    delete ui;
}
