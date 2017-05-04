/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *SaveAction;
    QAction *SaveAsAction;
    QAction *ExitAction;
    QAction *ControllerSettingsAction;
    QAction *AboutAction;
    QAction *OpenAction;
    QWidget *centralWidget;
    QPushButton *Start;
    QTextBrowser *History;
    QCustomPlot *GraphResult;
    QTableWidget *ConnectorTable;
    QPushButton *SearchButton;
    QPushButton *Stop;
    QLabel *posX;
    QLabel *dataX;
    QLabel *posY;
    QLabel *dataY;
    QMenuBar *menuBar;
    QMenu *File;
    QMenu *Settings;
    QMenu *Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1454, 802);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        SaveAction = new QAction(MainWindow);
        SaveAction->setObjectName(QStringLiteral("SaveAction"));
        SaveAsAction = new QAction(MainWindow);
        SaveAsAction->setObjectName(QStringLiteral("SaveAsAction"));
        ExitAction = new QAction(MainWindow);
        ExitAction->setObjectName(QStringLiteral("ExitAction"));
        ControllerSettingsAction = new QAction(MainWindow);
        ControllerSettingsAction->setObjectName(QStringLiteral("ControllerSettingsAction"));
        AboutAction = new QAction(MainWindow);
        AboutAction->setObjectName(QStringLiteral("AboutAction"));
        OpenAction = new QAction(MainWindow);
        OpenAction->setObjectName(QStringLiteral("OpenAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Start = new QPushButton(centralWidget);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setGeometry(QRect(1360, 620, 91, 23));
        History = new QTextBrowser(centralWidget);
        History->setObjectName(QStringLiteral("History"));
        History->setGeometry(QRect(500, 590, 851, 151));
        GraphResult = new QCustomPlot(centralWidget);
        GraphResult->setObjectName(QStringLiteral("GraphResult"));
        GraphResult->setGeometry(QRect(10, 10, 1431, 581));
        ConnectorTable = new QTableWidget(centralWidget);
        if (ConnectorTable->columnCount() < 3)
            ConnectorTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        ConnectorTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        ConnectorTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        ConnectorTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (ConnectorTable->rowCount() < 4)
            ConnectorTable->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        ConnectorTable->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        ConnectorTable->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        ConnectorTable->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        ConnectorTable->setVerticalHeaderItem(3, __qtablewidgetitem6);
        ConnectorTable->setObjectName(QStringLiteral("ConnectorTable"));
        ConnectorTable->setGeometry(QRect(10, 590, 361, 151));
        SearchButton = new QPushButton(centralWidget);
        SearchButton->setObjectName(QStringLiteral("SearchButton"));
        SearchButton->setGeometry(QRect(1360, 680, 93, 23));
        Stop = new QPushButton(centralWidget);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setGeometry(QRect(1360, 650, 91, 23));
        posX = new QLabel(centralWidget);
        posX->setObjectName(QStringLiteral("posX"));
        posX->setGeometry(QRect(380, 600, 47, 13));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        posX->setFont(font);
        dataX = new QLabel(centralWidget);
        dataX->setObjectName(QStringLiteral("dataX"));
        dataX->setGeometry(QRect(380, 620, 47, 13));
        posY = new QLabel(centralWidget);
        posY->setObjectName(QStringLiteral("posY"));
        posY->setGeometry(QRect(380, 640, 47, 13));
        posY->setFont(font);
        dataY = new QLabel(centralWidget);
        dataY->setObjectName(QStringLiteral("dataY"));
        dataY->setGeometry(QRect(380, 660, 47, 13));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1454, 21));
        File = new QMenu(menuBar);
        File->setObjectName(QStringLiteral("File"));
        Settings = new QMenu(menuBar);
        Settings->setObjectName(QStringLiteral("Settings"));
        Help = new QMenu(menuBar);
        Help->setObjectName(QStringLiteral("Help"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(File->menuAction());
        menuBar->addAction(Settings->menuAction());
        menuBar->addAction(Help->menuAction());
        File->addAction(OpenAction);
        File->addSeparator();
        File->addAction(SaveAction);
        File->addAction(SaveAsAction);
        File->addSeparator();
        File->addAction(ExitAction);
        Settings->addAction(ControllerSettingsAction);
        Help->addAction(AboutAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\234\320\276\320\275\320\270\321\202\320\276\321\200", Q_NULLPTR));
        SaveAction->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        SaveAsAction->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", Q_NULLPTR));
        ExitAction->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", Q_NULLPTR));
        ControllerSettingsAction->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\274\320\270\320\272\321\200\320\276\320\272\320\276\320\275\321\202\321\200\320\276\320\273\320\273\320\265\321\200\320\260", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ControllerSettingsAction->setToolTip(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\274\320\270\320\272\321\200\320\276\320\272\320\276\320\275\321\202\321\200\320\276\320\273\320\273\320\265\321\200\320\260", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        AboutAction->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", Q_NULLPTR));
        OpenAction->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 ", Q_NULLPTR));
        Start->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\320\272", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = ConnectorTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = ConnectorTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "VID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = ConnectorTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "PID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = ConnectorTable->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = ConnectorTable->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = ConnectorTable->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = ConnectorTable->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        SearchButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262", Q_NULLPTR));
        Stop->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214", Q_NULLPTR));
        posX->setText(QApplication::translate("MainWindow", "posX:", Q_NULLPTR));
        dataX->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        posY->setText(QApplication::translate("MainWindow", "posY:", Q_NULLPTR));
        dataY->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        File->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", Q_NULLPTR));
        Settings->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", Q_NULLPTR));
        Help->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
