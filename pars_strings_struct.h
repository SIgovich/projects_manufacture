#ifndef PARS_STRINGS_STRUCT_H
#define PARS_STRINGS_STRUCT_H
#include <QByteArray>
#include <QVector>

struct Data_to_Graph_t
{
    QByteArray Buffer;
    QVector <double> counter;
    QVector <double> osciloscope_data1;
    QVector <double> osciloscope_data2;
};

#endif // PARS_STRINGS_STRUCT_H
