#ifndef DATAPROCESS_H
#define DATAPROCESS_H
#define USB_PID  0x4321
#define	USB_VID  0x1234

#include "Connectors.h"
#include <ui_mainwindow.h>

// основной класс, обработчик информации от МК, построение графика, сохранение данных
class DataProcess : public QObject, public DataProcessor
{
	Q_OBJECT	

    struct data_controller_in_t
    {
        int freq; // частота дискретизации на передачу в микроконтроллер
    }data_controller_in;


	void __stdcall process(const std::vector<double>& data) override;
	void __stdcall reset() override;
	void __stdcall notify(const SettingBlock& current) override;
		

public:
    explicit DataProcess(QObject * parent =nullptr); // конструктор класса
	virtual ~DataProcess(); // деструктор
	void set_microcontroller_config(int freq);

	
public slots:
     

signals:
        void SendDataToGraph(QVector <double> x,QVector <double> y,QVector <double> y2);
        void finished(); // сигнал, отвечающий за прекращение потока, как только прекратится получение данных с микроконтроллера
        void SendDataToSave(QVector <double> x,QVector <double> y);


};

#endif // DATAPROCESS_H
