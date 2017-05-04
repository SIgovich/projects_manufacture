/********************************************************************************
** Form generated from reading UI file 'controller_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLER_SETTINGS_H
#define UI_CONTROLLER_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Controller_settings
{
public:
    QPushButton *ExitButton;
    QGroupBox *Settings;
    QGroupBox *FreqSet;
    QRadioButton *freq10;
    QRadioButton *freq100;
    QRadioButton *freq1000;
    QPushButton *SaveButton;

    void setupUi(QWidget *Controller_settings)
    {
        if (Controller_settings->objectName().isEmpty())
            Controller_settings->setObjectName(QStringLiteral("Controller_settings"));
        Controller_settings->resize(479, 338);
        ExitButton = new QPushButton(Controller_settings);
        ExitButton->setObjectName(QStringLiteral("ExitButton"));
        ExitButton->setGeometry(QRect(250, 300, 111, 23));
        Settings = new QGroupBox(Controller_settings);
        Settings->setObjectName(QStringLiteral("Settings"));
        Settings->setGeometry(QRect(30, 30, 411, 241));
        FreqSet = new QGroupBox(Settings);
        FreqSet->setObjectName(QStringLiteral("FreqSet"));
        FreqSet->setGeometry(QRect(10, 30, 131, 181));
        freq10 = new QRadioButton(FreqSet);
        freq10->setObjectName(QStringLiteral("freq10"));
        freq10->setGeometry(QRect(20, 30, 82, 17));
        freq100 = new QRadioButton(FreqSet);
        freq100->setObjectName(QStringLiteral("freq100"));
        freq100->setGeometry(QRect(20, 60, 82, 17));
        freq1000 = new QRadioButton(FreqSet);
        freq1000->setObjectName(QStringLiteral("freq1000"));
        freq1000->setGeometry(QRect(20, 90, 82, 17));
        SaveButton = new QPushButton(Controller_settings);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        SaveButton->setGeometry(QRect(110, 300, 111, 23));

        retranslateUi(Controller_settings);

        QMetaObject::connectSlotsByName(Controller_settings);
    } // setupUi

    void retranslateUi(QWidget *Controller_settings)
    {
        Controller_settings->setWindowTitle(QApplication::translate("Controller_settings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\274\320\270\320\272\321\200\320\276\320\272\320\276\320\275\321\202\321\200\320\276\320\273\320\273\320\265\321\200\320\260", Q_NULLPTR));
        ExitButton->setText(QApplication::translate("Controller_settings", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", Q_NULLPTR));
        Settings->setTitle(QApplication::translate("Controller_settings", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", Q_NULLPTR));
        FreqSet->setTitle(QApplication::translate("Controller_settings", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260 \320\264\320\270\321\201\320\272\321\200\320\265\321\202\320\270\320\267\320\260\321\206\320\270\320\270", Q_NULLPTR));
        freq10->setText(QApplication::translate("Controller_settings", "10 \320\223\321\206", Q_NULLPTR));
        freq100->setText(QApplication::translate("Controller_settings", "100 \320\223\321\206", Q_NULLPTR));
        freq1000->setText(QApplication::translate("Controller_settings", "1\320\272\320\223\321\206", Q_NULLPTR));
        SaveButton->setText(QApplication::translate("Controller_settings", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Controller_settings: public Ui_Controller_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLER_SETTINGS_H
