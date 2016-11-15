/********************************************************************************
** Form generated from reading UI file 'SpeakDialog.ui'
**
** Created: Tue Nov 24 04:05:57 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPEAKDIALOG_H
#define UI_SPEAKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_SpeakDialog
{
public:

    void setupUi(QDialog *SpeakDialog)
    {
        if (SpeakDialog->objectName().isEmpty())
            SpeakDialog->setObjectName(QString::fromUtf8("SpeakDialog"));
        SpeakDialog->resize(371, 169);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix2/rc/Sound.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SpeakDialog->setWindowIcon(icon);

        retranslateUi(SpeakDialog);

        QMetaObject::connectSlotsByName(SpeakDialog);
    } // setupUi

    void retranslateUi(QDialog *SpeakDialog)
    {
        SpeakDialog->setWindowTitle(QApplication::translate("SpeakDialog", "\351\200\211\346\213\251\346\214\207\345\256\232\345\217\221\351\237\263\346\226\271\345\274\217\344\270\213\347\232\204\345\217\221\351\237\263", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SpeakDialog: public Ui_SpeakDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPEAKDIALOG_H
