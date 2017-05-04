#include "mainwindow.h"
#include "ui_mainwindow.h"
typedef QVector <double> x12,y12,z12;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->SaveAction->setEnabled(false);
    ui->SaveAsAction->setEnabled(false);

        QLinearGradient plotGradient; // создание фона для графика
        plotGradient.setStart(0, 0);
        plotGradient.setFinalStop(0, 350);
        plotGradient.setColorAt(0, QColor(60, 60, 60));
        plotGradient.setColorAt(1, QColor(50, 50, 50));
        ui->GraphResult->setBackground(plotGradient);
        ui->dataX->clear();
        ui->dataY->clear();
        // конфигурация цветов осей графиков
        ui->GraphResult->xAxis->setBasePen(QPen(Qt::white, 1));
        ui->GraphResult->yAxis->setBasePen(QPen(Qt::white, 1));
        ui->GraphResult->xAxis->setTickPen(QPen(Qt::white, 1));
        ui->GraphResult->yAxis->setTickPen(QPen(Qt::white, 1));
        ui->GraphResult->xAxis->setSubTickPen(QPen(Qt::white, 1));
        ui->GraphResult->yAxis->setSubTickPen(QPen(Qt::white, 1));
        ui->GraphResult->xAxis->setTickLabelColor(Qt::white);
        ui->GraphResult->yAxis->setTickLabelColor(Qt::white);
        /// конфигурация осей полотна
        ui->GraphResult ->xAxis->setLabel("Time,t");
        ui->GraphResult ->xAxis->setLabelColor(QColor(255,255,255)); // цвет подписей осей на графике - белый
        ui->GraphResult ->yAxis->setLabel("F(t)");
        ui->GraphResult ->yAxis->setLabelColor(QColor(255,255,255));
        ui->GraphResult ->setInteractions(QCP::iRangeZoom | QCP::iSelectPlottables | QCP::iRangeDrag);
        ui->GraphResult->replot();

    qRegisterMetaType <x12> ("x");
    qRegisterMetaType <y12> ("y");
    qRegisterMetaType <z12> ("z");


/** Создание потока для построения графиков **/
    GraphThread = new QThread;
  //  connect (Dproc,&DataProcess::finished,GraphThread,&QThread::terminate); //коннектор, передающий сигнал о окончании потока
  //  Dproc->moveToThread(GraphThread);
/** Создание потока для записи данных в файл  **/
    SaveDataThread = new QThread;
    connect (SaveDataThread,&QThread::started,DtSv,&DataSaver::save_data);
    connect (DtSv,&DataSaver::data_finished,SaveDataThread,&QThread::terminate);
    DtSv ->moveToThread(SaveDataThread);
/** Создание потока для чтения данных из файла **/

/** Создание сигнала для передачи конфигурационных данных на график **/

    connect (Contr_set,&Controller_settings::send_freq,this,&MainWindow::change_freq);
  //  connect (Contr_set,&Controller_settings::send_freq_to_MK,Dproc,&DataProcess::set_microcontroller_config,Qt::DirectConnection);
    connect (Dproc,&DataProcess::SendDataToGraph,this,&MainWindow::logics2,Qt::DirectConnection);
    connect (DtSv,&DataSaver::send_data_to_Graph,this,&MainWindow::logics2,Qt::QueuedConnection);

	//TODO

}


MainWindow::~MainWindow()
{
    delete ui;
    delete Dproc;
    delete Contr_set;
    delete About;
    delete SaveDataThread;
    delete GraphThread;

}

/** обработчик события нажатия кнопки "Старт" **/
void MainWindow::on_Start_clicked()
{
    // TODO
    ui->History->clear();
    ui->History->insertPlainText("Run- Ok\n");
    ui->History->insertPlainText("Initialize DataProc - ok");
    ui->SaveAction->setEnabled(true);
    ui->SaveAsAction->setEnabled(true);
	// определение устройства
	_device=Device::instance(USB_PID, USB_VID);
	if (_device == nullptr)
	{
		ui->History->insertPlainText("No_device_init");
		return;
	}
	_device->channel(1).connect(Dproc);
	_device->channel(1).sampleRate(SampleRate::SR_100K);
	// включение устройства
	_device->channel(1).turnOn();
    // передача в класс обработки информации с детекторов ИУ данных, поступающих от ИУ
    //GraphThread->start();

}

/** обработчик события нажатия кнопки "Стоп" **/
void MainWindow::on_Stop_clicked()
{
    ui->Start->setEnabled(true);
    ui->History->insertPlainText("\n___________________\n");
    ui->History->insertPlainText("Application Stopped");
    ui->GraphResult->replot();
	_device->channel(1).turnOff();

}

/** обработчик события нажатия кнопки контекстного меню "Выход" **/
void MainWindow::on_ExitAction_triggered()
{
    this->close();
}

/** обработчик события нажатия кнопки контекстного меню "Настройки микроконтроллера" **/
void MainWindow::on_ControllerSettingsAction_triggered()
{
    Contr_set->show();
}

/** обработчик события нажатия кнопки контекстного меню "О программе" **/
void MainWindow::on_AboutAction_triggered()
{
    About->show();
}

/** обработчик события нажатия кнопки контекстного меню "Поиск устройств" **/
void MainWindow::on_SearchButton_clicked()
{
    ui->SearchButton->setEnabled(false);
    ui->ConnectorTable->setItem(0,0,new QTableWidgetItem("STM32 microcontroller"));
    ui->ConnectorTable->setItem(0,1,new QTableWidgetItem("0x1234"));
    ui->ConnectorTable->setItem(0,2,new QTableWidgetItem("0x5678"));
    ui->SearchButton->setEnabled(true);
}

/** обработчик события нажатия кнопки контекстного меню "Открыть" **/
void MainWindow::on_OpenAction_triggered()
{
    QFileDialog OpenFile;
    QString str;
    str = OpenFile.getOpenFileName(this,
                                   tr("Открыть"),
                                   QDir::currentPath(),
                                   tr("Текстовый документ(*.txt);;Электронная таблица(*.csv);;Бинарный файл(*.bin)"));
    if (!str.isNull())
    {
     OpenFile.close();
     DtSv->set_ReadFile(str);
    }
    ui->SaveAction->setEnabled(true);
    ui->SaveAsAction->setEnabled(true);
}

/** обработчик события нажатия кнопки контекстного меню "Сохранить как..." **/
void MainWindow::on_SaveAsAction_triggered()
{

    QFileDialog SaveAsFile;
    QString str;
    str = SaveAsFile.getSaveFileName(this,
                                   tr("Сохранить как"),
                                   "results",
                                   tr("Text document(*.txt);;Comma separated file(*.csv);;Binary (*.bin)"));
    //после получения полного пути на файл, вызываем поток, осуществляющий запись данных в файл
    if (!str.isNull())
    {
    SaveAsFile.close();
    DtSv ->set_FileName(str); // передача имени файла
    }
}

/** обработчик события нажатия кнопки контекстного меню "Сохранить"**/
void MainWindow::on_SaveAction_triggered()
{
    QString str;
    str = "results.bin";
    DtSv->save_txt_data(str);
}

void MainWindow::logics2 (QVector<double> x,QVector<double> y,QVector<double>  z)
{
    ui->GraphResult->clearGraphs();
    ui->GraphResult->addGraph();
    ui->GraphResult->addGraph();
    /** Конфигурация графика **/
    QVector <double> x_vert(2),y_vert(2);
    x_vert[0]=0;
    y_vert[0]=-10;
    x_vert[1]=0;
    y_vert[1]=10;
    verticalLine = new QCPCurve(ui->GraphResult->xAxis,ui->GraphResult->yAxis);
    verticalLine->setName("Tracer");
    verticalLine->setData(x_vert,y_vert);
    tracer = new QCPItemTracer(ui->GraphResult);
    tracer->setGraph(ui->GraphResult->graph(0));
    connect (ui->GraphResult,&QCustomPlot::mousePress,this,&MainWindow::GraphResultMousePress);
    connect (ui->GraphResult,&QCustomPlot::mouseMove,this,&MainWindow::GraphResultMouseMove);
    ui->GraphResult->replot();
    /// График 0
    ui->GraphResult->graph(0)->setPen(QPen(QColor(Qt::yellow))); // цвет графика - желтый
    ui->GraphResult->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->GraphResult->graph(0)->addData(x,y,true);
    /// График 1
    ui->GraphResult->graph(1)->setPen(QPen(QColor(Qt::cyan))); // цвет графика - желтый
    ui->GraphResult->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->GraphResult->graph(1)->addData(x,z,true);

    ui->GraphResult ->xAxis-> setRange(0,1000);
    ui->GraphResult ->yAxis-> setRange(-300,300);
    ui->GraphResult->replot();

}
void MainWindow::GraphResultMousePress(QMouseEvent *event)
{
    double CoordX = ui->GraphResult->xAxis->pixelToCoord(event->pos().x());
    QVector <double> x_vert(2),y_vert(2);
    x_vert[0] = CoordX;
    y_vert[0] = -10;
    x_vert[1] = CoordX;
    y_vert[1] = 10;

    verticalLine ->setData(x_vert,y_vert);
    tracer ->setGraphKey(CoordX);

    ui->dataX->setText(QString::number(tracer->position->key()));
    ui->dataY->setText(QString::number(tracer->position->value()));
    ui->GraphResult->replot();
}

void MainWindow::GraphResultMouseMove(QMouseEvent *event)
{
    if(QApplication::mouseButtons()) GraphResultMousePress(event);
}

void MainWindow::change_freq(int freq)
{
    //FREQUENCY = freq;
    //qDebug("FREQ = %i",FREQUENCY);
}
