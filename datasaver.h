#ifndef DATASAVER_H
#define DATASAVER_H

#include <QFile>
#include <QtCore/qmath.h>
#include <pars_strings_struct.h>
#include <QtConcurrent>
#include <QFutureWatcher>
#include <QProgressDialog>

class DataSaver : public QObject
{
    Q_OBJECT
    QString SaveFileName;
    QFile File;
    QVector <double> x_graph;
    QVector <double> y_graph;
    QVector <double> z_graph;
    QVector <QByteArray> data;
    QVector <Data_to_Graph_t> struct_to_Graph;
public:
        QString ReadFileName;
        explicit DataSaver(QObject *parent = 0);
        ~DataSaver();
        void save_txt_data(QString FileName);
        void read_data_from_txt(QString FileName);
        void read_data_from_binary(QString FileName);
        static void read_data_from_csv(Data_to_Graph_t &DGraph);
        void wright_data_to_binary (QString FileName);
        void set_FileName(QString FileName);
        void set_ReadFile (QString FileName);
        static void Splitting_file(const QByteArray *FileBytes, QVector<QByteArray> *buffer);
        void CreatingVectorToPlotOnGraph (QVector<Data_to_Graph_t> &DGraph);

signals:
        void data_finished(); // сигнал, отвечающий за останов потока,как только прекратится запись данных в файл
        void read_data_finished();
        void Start_PrgDlg(bool activated);
        void send_data_to_Graph(QVector <double> arg1,QVector <double> arg2,QVector <double> arg3);

public slots:
        void save_data();
        void read_data(QVector<QByteArray> &data);
        void get_mk_data(QVector<double> x,QVector <double> y);

private:
        static int search_end_line(const QByteArray *Buffer, int mem_buffer);
        void wright_data_to_csv(QString FileName);
        QFutureWatcher<void> Watcher;
        QProgressDialog * Dialog = new QProgressDialog;

};

#endif // DATASAVER_H
