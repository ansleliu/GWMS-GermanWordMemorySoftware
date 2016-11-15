/********************************************************************************
** Form generated from reading UI file 'addrootdialog.ui'
**
** Created: Tue Nov 24 04:05:56 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDROOTDIALOG_H
#define UI_ADDROOTDIALOG_H

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

class Ui_AddRootDialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *NOPushButton;
    QPushButton *OKPushButton;

    void setupUi(QDialog *AddRootDialog)
    {
        if (AddRootDialog->objectName().isEmpty())
            AddRootDialog->setObjectName(QString::fromUtf8("AddRootDialog"));
        AddRootDialog->resize(312, 131);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/folder_new.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddRootDialog->setWindowIcon(icon);
        groupBox = new QGroupBox(AddRootDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 291, 71));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 51, 21));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 30, 201, 21));
        NOPushButton = new QPushButton(AddRootDialog);
        NOPushButton->setObjectName(QString::fromUtf8("NOPushButton"));
        NOPushButton->setGeometry(QRect(190, 90, 71, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        NOPushButton->setIcon(icon1);
        OKPushButton = new QPushButton(AddRootDialog);
        OKPushButton->setObjectName(QString::fromUtf8("OKPushButton"));
        OKPushButton->setGeometry(QRect(50, 90, 71, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        OKPushButton->setIcon(icon2);

        retranslateUi(AddRootDialog);

        QMetaObject::connectSlotsByName(AddRootDialog);
    } // setupUi

    void retranslateUi(QDialog *AddRootDialog)
    {
        AddRootDialog->setWindowTitle(QApplication::translate("AddRootDialog", "  \346\267\273\345\212\240\346\226\260\345\210\206\347\261\273\345\220\215  ", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("AddRootDialog", "\350\257\267\350\276\223\345\205\245\350\246\201\346\267\273\345\212\240\347\232\204\345\210\206\347\261\273\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddRootDialog", "\345\210\206\347\261\273\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        NOPushButton->setText(QApplication::translate("AddRootDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        OKPushButton->setText(QApplication::translate("AddRootDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddRootDialog: public Ui_AddRootDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDROOTDIALOG_H
