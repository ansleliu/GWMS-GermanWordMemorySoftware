/********************************************************************************
** Form generated from reading UI file 'explaindialog.ui'
**
** Created: Tue Nov 24 04:05:56 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPLAINDIALOG_H
#define UI_EXPLAINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_ExplainDialog
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *ExplainDialog)
    {
        if (ExplainDialog->objectName().isEmpty())
            ExplainDialog->setObjectName(QString::fromUtf8("ExplainDialog"));
        ExplainDialog->resize(331, 424);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/sayabout.png"), QSize(), QIcon::Normal, QIcon::Off);
        ExplainDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(ExplainDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textBrowser = new QTextBrowser(ExplainDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);


        retranslateUi(ExplainDialog);

        QMetaObject::connectSlotsByName(ExplainDialog);
    } // setupUi

    void retranslateUi(QDialog *ExplainDialog)
    {
        ExplainDialog->setWindowTitle(QApplication::translate("ExplainDialog", "  \350\257\264\346\230\216 ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExplainDialog: public Ui_ExplainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPLAINDIALOG_H
