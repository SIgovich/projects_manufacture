#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <dataprocess.h>
#include <datasaver.h>
#include <controller_settings.h>
#include <abouthelp.h>
#include <qcustomplot.h>
#include <QThread>
#include <QVector>
#include <Device.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int FREQUENCY = 0;
    bool m_signal = false;
    QVector<QString> strings;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

    void on_Start_clicked();

    void on_ExitAction_triggered();

    void on_ControllerSettingsAction_triggered();

    void on_AboutAction_triggered();

    void on_SearchButton_clicked();

    void on_SaveAsAction_triggered();

    void on_Stop_clicked();

    void on_SaveAction_triggered();

    void on_OpenAction_triggered();

    void GraphResultMousePress(QMouseEvent *event);

    void GraphResultMouseMove(QMouseEvent *event);

    void logics2 (QVector<double> x, QVector<double> y, QVector<double> z);

    void change_freq(int freq);




private:
    Ui::MainWindow *ui;
    Controller_settings * Contr_set = new Controller_settings;
    AboutHelp * About = new AboutHelp;
    DataProcess * Dproc = new DataProcess; // класс для работы данными с микроконтроллера
    QCPCurve *verticalLine;     // Объявляем объект для вертикальной линии
    QCPItemTracer *tracer;      // Трасировщик по точкам графика
    QThread * GraphThread; // поток осуществляющий работу с графиком
    QThread * SaveDataThread; // поток, который будет записывать данные, приходящие из микроконтроллера
    QThread * ProgressBarThread;
    QThread * ReadDataThread;
    DataSaver * DtSv = new DataSaver;
	std::unique_ptr<Device> _device;
};

#endif // MAINWINDOW_H
