/********************************************************************************
** Form generated from reading UI file 'addbookdialog.ui'
**
** Created: Tue Nov 24 04:05:56 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOKDIALOG_H
#define UI_ADDBOOKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddBookDialog
{
public:
    QPushButton *QuitButton;
    QGroupBox *groupBox;
    QLabel *classLabel;
    QLineEdit *classLineEdit;
    QLabel *bookLabel;
    QLineEdit *bookLineEdit;
    QPushButton *pushButton;
    QPushButton *OKButton;

    void setupUi(QDialog *AddBookDialog)
    {
        if (AddBookDialog->objectName().isEmpty())
            AddBookDialog->setObjectName(QString::fromUtf8("AddBookDialog"));
        AddBookDialog->resize(332, 161);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddBookDialog->setWindowIcon(icon);
        QuitButton = new QPushButton(AddBookDialog);
        QuitButton->setObjectName(QString::fromUtf8("QuitButton"));
        QuitButton->setGeometry(QRect(210, 120, 71, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/dialog_cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        QuitButton->setIcon(icon1);
        groupBox = new QGroupBox(AddBookDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 311, 101));
        classLabel = new QLabel(groupBox);
        classLabel->setObjectName(QString::fromUtf8("classLabel"));
        classLabel->setGeometry(QRect(10, 30, 71, 21));
        classLineEdit = new QLineEdit(groupBox);
        classLineEdit->setObjectName(QString::fromUtf8("classLineEdit"));
        classLineEdit->setGeometry(QRect(80, 30, 221, 21));
        bookLabel = new QLabel(groupBox);
        bookLabel->setObjectName(QString::fromUtf8("bookLabel"));
        bookLabel->setGeometry(QRect(10, 60, 71, 21));
        bookLineEdit = new QLineEdit(groupBox);
        bookLineEdit->setObjectName(QString::fromUtf8("bookLineEdit"));
        bookLineEdit->setGeometry(QRect(80, 60, 151, 21));
        bookLineEdit->setReadOnly(true);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 60, 61, 23));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/document_import.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setAutoRepeat(false);
        pushButton->setAutoExclusive(false);
        OKButton = new QPushButton(AddBookDialog);
        OKButton->setObjectName(QString::fromUtf8("OKButton"));
        OKButton->setGeometry(QRect(50, 120, 71, 31));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/dialog_ok_apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        OKButton->setIcon(icon3);

        retranslateUi(AddBookDialog);

        QMetaObject::connectSlotsByName(AddBookDialog);
    } // setupUi

    void retranslateUi(QDialog *AddBookDialog)
    {
        AddBookDialog->setWindowTitle(QApplication::translate("AddBookDialog", "  \346\267\273\345\212\240\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
        QuitButton->setText(QApplication::translate("AddBookDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("AddBookDialog", "\350\257\267\350\276\223\345\205\245\350\246\201\346\267\273\345\212\240\347\232\204\350\257\215\345\272\223\346\211\200\345\261\236\347\232\204\347\261\273\345\222\214\350\257\215\345\272\223\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        classLabel->setText(QApplication::translate("AddBookDialog", "\350\257\215\345\272\223\346\211\200\345\261\236\347\261\273\357\274\232", 0, QApplication::UnicodeUTF8));
        bookLabel->setText(QApplication::translate("AddBookDialog", "\350\257\215      \345\272\223\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AddBookDialog", "\345\257\274\345\205\245", 0, QApplication::UnicodeUTF8));
        OKButton->setText(QApplication::translate("AddBookDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddBookDialog: public Ui_AddBookDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOKDIALOG_H
