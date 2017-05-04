#ifndef ABOUTHELP_H
#define ABOUTHELP_H

#include <QDialog>

namespace Ui {
class AboutHelp;
}

class AboutHelp : public QDialog
{
    Q_OBJECT

public:
    explicit AboutHelp(QWidget *parent = 0);
    ~AboutHelp();

private:
    Ui::AboutHelp *ui;
};

#endif // ABOUTHELP_H
