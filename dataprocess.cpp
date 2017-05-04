#include "dataprocess.h"

// for TEST
#include <QDebug>
#define MAX_SIZE 10000000
//

DataProcess::DataProcess(QObject *parent):
    QObject(parent)
{

}


DataProcess::~DataProcess(){
 
}


// Считывание данных из файла и насыщение структуры данных для микроконтроллера



void DataProcess::set_microcontroller_config(int freq)
{
    // процедура насыщения контроллера данными   data_controller_in.freq = freq;
    qDebug("freq_to_MK=%i",data_controller_in.freq);
}

void DataProcess::process(const std::vector<double>& data)
{
	qDebug() << data.size();
	
	QVector<double> plot_data=QVector<double>::fromStdVector(data);
	emit SendDataToGraph(plot_data, plot_data, plot_data);

}

void DataProcess::reset()
{

}

void DataProcess::notify(const SettingBlock& current)
{

}



