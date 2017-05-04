#ifndef CONTROLLER_SETTINGS_H
#define CONTROLLER_SETTINGS_H

#include <QWidget>

namespace Ui {
class Controller_settings;
}

class Controller_settings : public QWidget
{
    Q_OBJECT

public:
    int freq;
    explicit Controller_settings(QWidget *parent = 0);
    ~Controller_settings();


private slots:
    void on_ExitButton_clicked();
    void setFreq(bool);

    void on_SaveButton_clicked();

private:
    Ui::Controller_settings *ui;

signals:
   void  send_freq(int freq);
   void  send_freq_to_MK(int freq);
};

#endif // CONTROLLER_SETTINGS_H
