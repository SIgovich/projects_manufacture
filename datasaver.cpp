#include "datasaver.h"

DataSaver::DataSaver(QObject *parent) : QObject(parent)
{
    connect (&Watcher,SIGNAL(finished()),Dialog,SLOT(reset()));
    connect (Dialog,SIGNAL(canceled()),&Watcher,SLOT(cancel()));
    connect (&Watcher,SIGNAL(progressRangeChanged(int,int)),Dialog,SLOT(setRange(int,int)));
    connect (&Watcher,SIGNAL(progressValueChanged(int)),Dialog,SLOT(setValue(int)));
    Dialog->close();
    x_graph.reserve(10000000);
    y_graph.reserve(10000000);
    z_graph.reserve(10000000);
}
DataSaver::~DataSaver()
{

}

void DataSaver::save_txt_data(QString FileName)
{
    QFile DataFile (FileName);
    if (DataFile.open(QIODevice::WriteOnly))
    {
        emit Start_PrgDlg(true);
        QTextStream DataStream(&DataFile);
//        for (int i =0; i<save_x.size();i++)
//        {
//        DataStream << QString::number(save_x[i]) << "\t"<< QString::number(save_y[i]) <<"\n\r";
//        }
    }
    DataFile.close();
    emit Start_PrgDlg(false);

}

void DataSaver::wright_data_to_binary(QString FileName)
{
    QFile BinFile (FileName);
    if (BinFile.open(QIODevice::WriteOnly))
    {
        emit Start_PrgDlg(true);
        QDataStream StructStream (&BinFile);
       // StructStream << save_x << save_y;

    }
    BinFile.close();
    emit Start_PrgDlg(false);

}
void DataSaver::read_data_from_binary(QString FileName)
{
    QFile BinFile (FileName);

    if (BinFile.open(QIODevice::ReadOnly))
    {
       QDataStream DataBin(&BinFile);
       while (!DataBin.atEnd())
       {
           x_graph.resize(0);
           y_graph.resize(0);
           z_graph.resize(0);
           DataBin >> x_graph >> y_graph >> z_graph;
       }
       emit send_data_to_Graph(x_graph,y_graph,z_graph);
    }


}

void DataSaver::read_data_from_txt(QString FileName)
{
    QFile       OpenFile (FileName);
    QRegExp     rx("(\\d+)"); // регулярное выражение, осуществляющее поиск только цифр!
    QString     Value1[512];  // инициализация массива строк, в которые осуществляется считывание данных из файла

    auto         pos = 0;          // позиция курсора
    auto        i = 1;

    if (OpenFile.open(QIODevice::ReadOnly))
    {
       QByteArray DataFile = OpenFile.readAll();
        while ((pos = rx.indexIn(DataFile,pos)) != -1)
        {
            Value1[i]= rx.cap(1);       
            qDebug () << "Value["<<i<<"]"<<"="<< Value1[i]; // отладочное сообщение в Debuger (временно)
            pos +=rx.matchedLength(); // смещение курсора с учетом предыдущей строки (переход на новую строку файла)
            i++;
        }

     }


}
// обновленный парсер, который не удаляет данные из строки, а просто пробегает по строке и пишет данные в вектора сразу
void DataSaver::read_data_from_csv(Data_to_Graph_t &DGraph)
{
    QString Data_read ;
    QString Format_Without_Spec;
    auto pos_counter = 0;
	auto pos_start = 0;
	auto pos_end = 0;
	auto spos = -1;
    auto pos = 0;
    if (spos == (DGraph.Buffer.indexOf('S')))
        {
            pos = 10;
        }
        QTextStream Stream(DGraph.Buffer);
        while (!Stream.atEnd())
        {
           if (pos <10)
           {
             Stream.readLineInto(&Data_read);
           }
            // считываем только данные!
             if (pos >= 10)
             {
               Stream.readLineInto(&Format_Without_Spec);
               pos_counter = Format_Without_Spec.indexOf(','); //...,
                // ищем порядковые номера и считываем их в счетчик
               DGraph.counter.append(Format_Without_Spec.left(pos_counter).toDouble());
               // ищем следующую запятую в строке и запоминаем ее в буффере
               pos_start = Format_Without_Spec.indexOf(',',pos_counter+1);
               // ищем последнюю запятую в строке
               pos_end = Format_Without_Spec.indexOf(',',pos_start+1);
               // наполняем дату значениями из строки с определенных позиций (без удаления кусков из строки)
               DGraph.osciloscope_data1.append((Format_Without_Spec.mid(pos_start+1,(pos_end-pos_start)-1).toDouble()));
               DGraph.osciloscope_data2.append((Format_Without_Spec.right(Format_Without_Spec.length()-(pos_end+1)).toDouble()));
             }
             pos++;
       }
        Stream.flush();
        Format_Without_Spec.clear();
        Data_read.clear();
        DGraph.Buffer.squeeze();
        DGraph.Buffer.clear();
        qDebug(" Test_completed in Thread, size x_data = %i,size y_data = %i,size z_data = %i", DGraph.counter.size(), DGraph.osciloscope_data1.size(), DGraph.osciloscope_data2.size());
}

void DataSaver::wright_data_to_csv(QString FileName)
{
    QFile CsvFile(FileName);
    QString saving_data;
    if (CsvFile.open(QFile::WriteOnly))
    {
        QTextStream RecCsvStream(&CsvFile);
        qDebug() << "start_saving";
        QChar separator = ',';
        for (int i=0;i<x_graph.size();i++) 
        {
            saving_data.clear();
            RecCsvStream <<  saving_data.append(QString(
                             QString::number(x_graph[i])+separator+ // counter
                             QString("0.00000")+separator+          // time
                             QString::number(y_graph[i])+separator+ // data1
                             QString::number(z_graph[i])+'\r'+'\n')); // data2

        }


        CsvFile.close();
    }
}

void DataSaver::save_data()
{
    bool FormStr;
    if ((FormStr = SaveFileName.contains(".txt", Qt::CaseInsensitive)))
    {
         save_txt_data(SaveFileName);
         emit data_finished();
    }
    if ((FormStr = SaveFileName.contains(".bin", Qt::CaseInsensitive)))
    {
         QFile BinFile(SaveFileName);
         if (BinFile.open(QIODevice::WriteOnly))
         {
             QDataStream StreamToBin(&BinFile);
             StreamToBin << x_graph << y_graph << z_graph;
             BinFile.close();
         }
    }
    if ((FormStr = SaveFileName.contains(".csv", Qt::CaseInsensitive)))
    {
       /* Watcher.setFuture(QtConcurrent::run(this,wright_data_to_csv,SaveFileName));
        Dialog->setLabelText("Processing to write data to *.csv");
        Dialog->exec();
        Dialog->show();
        Watcher.waitForFinished();
        Dialog->close();*/
		wright_data_to_csv(SaveFileName);
    }
}
void DataSaver::read_data(QVector<QByteArray> &data)
{
    bool FormStr;
    if ((FormStr = ReadFileName.contains(".txt", Qt::CaseInsensitive)))
    {
        qDebug("txt_file");
        read_data_from_txt(ReadFileName);
        emit read_data_finished();
    }
    if ((FormStr = ReadFileName.contains(".bin", Qt::CaseInsensitive)))
    {
        //Watcher.setFuture(QtConcurrent::run(this,read_data_from_binary,ReadFileName));
        //Dialog->setLabelText("Processing read data from"+ReadFileName);
        //Dialog->exec();
        //Dialog->show();
        //Watcher.waitForFinished();
        //Dialog->close();
		read_data_from_binary(ReadFileName);
    }
    if ((FormStr = ReadFileName.contains(".csv", Qt::CaseInsensitive)))
    {
        QFile CsvFile (ReadFileName);
            if (CsvFile.open(QFile::ReadOnly))
            {
                QByteArray FileBytes (CsvFile.readAll());
                Splitting_file(&FileBytes,&data);
                CsvFile.close();
                FileBytes.clear();
            }
        struct_to_Graph.resize(data.size());
            for (int i = 0; i<data.size();i++)
            {
                struct_to_Graph[i].Buffer.append(data[i]);
            }
        data.clear();
        Watcher.setFuture(QtConcurrent::map(struct_to_Graph,read_data_from_csv));
        Dialog->exec();
        Watcher.waitForFinished();
        Dialog->close();
        CreatingVectorToPlotOnGraph(struct_to_Graph);

    }
}

void DataSaver::get_mk_data(QVector<double> x, QVector<double> y)
{
    //save_x = x;
    //save_y = y;
}

void DataSaver::set_FileName(QString FileName)
{
   SaveFileName  = FileName;
   save_data();
}

void DataSaver::set_ReadFile(QString FileName)
{
   ReadFileName.clear();
   ReadFileName = FileName;
   read_data(data);
}

void DataSaver::Splitting_file(const QByteArray * FileBytes, QVector<QByteArray> * buffer)
{
    auto start_cursor = -1;
	auto  size_FileBytes = FileBytes->size();
    qDebug()<<"size_FileBytes="<<size_FileBytes;
	auto cursor = qCeil(size_FileBytes/QThread::idealThreadCount());
	auto end_cursor = cursor;
	auto i = 0;
        for (i=0;i<=QThread::idealThreadCount();i++)
        {
            end_cursor = search_end_line(FileBytes,end_cursor);
            buffer->append(FileBytes->mid(start_cursor+1,(end_cursor-start_cursor)-1));
            qDebug("create buffer %i completed!\t buf_size=%i",i,buffer->size());
            if (end_cursor+cursor>=size_FileBytes)
            {
                qDebug() << "ERROR! SIZE > FULL SIZE";
                break;
            }

            start_cursor = end_cursor;
            end_cursor +=cursor;
        }


        buffer->append(FileBytes->mid(end_cursor+1,(size_FileBytes-end_cursor)-1));
        qDebug("create buffer %i completed!\t buf_size=%i",i+1,buffer->size());

}

int  DataSaver::search_end_line(const QByteArray * Buffer, int mem_buffer)
{
    while (Buffer->at(mem_buffer)!= '\n')
    {
        mem_buffer--;
    }
    return mem_buffer;
}

void DataSaver::CreatingVectorToPlotOnGraph(QVector<Data_to_Graph_t> &DGraph)
{
    x_graph.resize(0);
    y_graph.resize(0);
    z_graph.resize(0);
    x_graph.reserve(10000000);
    y_graph.reserve(10000000);
    z_graph.reserve(10000000);
    for (auto i = 0 ; i<=DGraph.size()-1;i++)
    {
        DGraph[i].counter.squeeze();
        DGraph[i].osciloscope_data1.squeeze();
        DGraph[i].osciloscope_data2.squeeze();
        x_graph.append(DGraph[i].counter);
        y_graph.append(DGraph[i].osciloscope_data1);
        z_graph.append(DGraph[i].osciloscope_data2);
        DGraph[i].counter.clear();
        DGraph[i].osciloscope_data1.clear();
        DGraph[i].osciloscope_data2.clear();
    }
   DGraph.squeeze();
   DGraph.clear();
   emit send_data_to_Graph(x_graph,y_graph,z_graph);
}
