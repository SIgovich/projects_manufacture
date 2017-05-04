/********************************************************************************
** Form generated from reading UI file 'abouthelp.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTHELP_H
#define UI_ABOUTHELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutHelp
{
public:
    QLabel *About;
    QLabel *Theme;
    QLabel *Year;
    QLabel *Autors;

    void setupUi(QDialog *AboutHelp)
    {
        if (AboutHelp->objectName().isEmpty())
            AboutHelp->setObjectName(QStringLiteral("AboutHelp"));
        AboutHelp->resize(623, 163);
        AboutHelp->setSizeGripEnabled(true);
        About = new QLabel(AboutHelp);
        About->setObjectName(QStringLiteral("About"));
        About->setGeometry(QRect(20, 30, 91, 16));
        Theme = new QLabel(AboutHelp);
        Theme->setObjectName(QStringLiteral("Theme"));
        Theme->setGeometry(QRect(20, 50, 601, 61));
        Theme->setTextFormat(Qt::AutoText);
        Year = new QLabel(AboutHelp);
        Year->setObjectName(QStringLiteral("Year"));
        Year->setGeometry(QRect(20, 140, 111, 16));
        Autors = new QLabel(AboutHelp);
        Autors->setObjectName(QStringLiteral("Autors"));
        Autors->setGeometry(QRect(20, 110, 201, 16));

        retranslateUi(AboutHelp);

        QMetaObject::connectSlotsByName(AboutHelp);
    } // setupUi

    void retranslateUi(QDialog *AboutHelp)
    {
        AboutHelp->setWindowTitle(QApplication::translate("AboutHelp", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", Q_NULLPTR));
        About->setText(QApplication::translate("AboutHelp", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265:", Q_NULLPTR));
        Theme->setText(QApplication::translate("AboutHelp", "<html><head/><body><p><span style=\" font-weight:600;\">\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\275\320\276\320\265 \320\276\320\261\320\265\321\201\320\277\320\265\321\207\320\265\320\275\320\270\320\265 \320\264\320\273\321\217 \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\270\321\217, \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\270 \320\270 \320\260\320\275\320\260\320\273\320\270\320\267\320\260 \321\206\320\270\321\204\321\200\320\276\320\262\321\213\321\205 \320\264\320\260\320\275\320\275\321\213\321\205, \320\277\320\276\321\201\321\202\321\203\320\277\320\260\321\216\321\211\320\270\321\205 \320\276\321\202<br/> \320\230\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262 \320\264\320\265\321\202\320\265\320\272\321\202\320\276\321\200\320\276\320\262 \320\270\320\267\320\273\321\203\321\207\320\265\320\275\320\270\321"
                        "\217 \321\201\320\270\321\201\321\202\320\265\320\274 \320\264\320\270\321\201\321\202\320\260\320\275\321\206\320\270\320\276\320\275\320\275\320\276\320\263\320\276 \320\267\320\276\320\275\320\264\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217. </span></p></body></html>", Q_NULLPTR));
        Year->setText(QApplication::translate("AboutHelp", "<html><head/><body><p>\320\223\320\276\320\264 \321\200\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\272\320\270: 2017</p></body></html>", Q_NULLPTR));
        Autors->setText(QApplication::translate("AboutHelp", "\320\220\320\262\321\202\320\276\321\200: \320\241\320\270\320\263\320\276\320\262 \320\220\321\200\320\272\320\260\320\264\320\270\320\271 \320\241\321\202\320\260\320\275\320\270\321\201\320\273\320\260\320\262\320\276\320\262\320\270\321\207", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AboutHelp: public Ui_AboutHelp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTHELP_H
