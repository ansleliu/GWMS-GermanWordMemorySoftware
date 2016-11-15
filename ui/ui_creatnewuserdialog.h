/********************************************************************************
** Form generated from reading UI file 'creatnewuserdialog.ui'
**
** Created: Tue Nov 24 04:05:56 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATNEWUSERDIALOG_H
#define UI_CREATNEWUSERDIALOG_H

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

class Ui_CreatNewUserDialog
{
public:
    QGroupBox *groupBox;
    QLabel *surePasswordlabel;
    QLineEdit *surePasswordlineEdit;
    QLabel *passwordlabel;
    QLineEdit *passwordlineEdit;
    QLineEdit *userNamelineEdit;
    QLabel *userNamelabel;
    QPushButton *YesButton;
    QPushButton *NoButton;

    void setupUi(QDialog *CreatNewUserDialog)
    {
        if (CreatNewUserDialog->objectName().isEmpty())
            CreatNewUserDialog->setObjectName(QString::fromUtf8("CreatNewUserDialog"));
        CreatNewUserDialog->resize(321, 171);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/list_add_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        CreatNewUserDialog->setWindowIcon(icon);
        groupBox = new QGroupBox(CreatNewUserDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 301, 111));
        surePasswordlabel = new QLabel(groupBox);
        surePasswordlabel->setObjectName(QString::fromUtf8("surePasswordlabel"));
        surePasswordlabel->setGeometry(QRect(30, 80, 61, 21));
        surePasswordlineEdit = new QLineEdit(groupBox);
        surePasswordlineEdit->setObjectName(QString::fromUtf8("surePasswordlineEdit"));
        surePasswordlineEdit->setGeometry(QRect(90, 80, 181, 20));
        surePasswordlineEdit->setEchoMode(QLineEdit::Password);
        passwordlabel = new QLabel(groupBox);
        passwordlabel->setObjectName(QString::fromUtf8("passwordlabel"));
        passwordlabel->setGeometry(QRect(30, 50, 61, 21));
        passwordlineEdit = new QLineEdit(groupBox);
        passwordlineEdit->setObjectName(QString::fromUtf8("passwordlineEdit"));
        passwordlineEdit->setGeometry(QRect(90, 50, 181, 20));
        passwordlineEdit->setEchoMode(QLineEdit::Password);
        userNamelineEdit = new QLineEdit(groupBox);
        userNamelineEdit->setObjectName(QString::fromUtf8("userNamelineEdit"));
        userNamelineEdit->setGeometry(QRect(90, 20, 181, 20));
        userNamelabel = new QLabel(groupBox);
        userNamelabel->setObjectName(QString::fromUtf8("userNamelabel"));
        userNamelabel->setGeometry(QRect(30, 20, 61, 21));
        YesButton = new QPushButton(CreatNewUserDialog);
        YesButton->setObjectName(QString::fromUtf8("YesButton"));
        YesButton->setGeometry(QRect(60, 130, 71, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/button_ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        YesButton->setIcon(icon1);
        NoButton = new QPushButton(CreatNewUserDialog);
        NoButton->setObjectName(QString::fromUtf8("NoButton"));
        NoButton->setGeometry(QRect(190, 130, 71, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        NoButton->setIcon(icon2);
        NoButton->setIconSize(QSize(16, 16));

        retranslateUi(CreatNewUserDialog);

        QMetaObject::connectSlotsByName(CreatNewUserDialog);
    } // setupUi

    void retranslateUi(QDialog *CreatNewUserDialog)
    {
        CreatNewUserDialog->setWindowTitle(QApplication::translate("CreatNewUserDialog", "  \346\267\273\345\212\240\346\226\260\347\224\250\346\210\267  ", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CreatNewUserDialog", "\346\226\260\345\273\272\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        surePasswordlabel->setText(QApplication::translate("CreatNewUserDialog", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        passwordlabel->setText(QApplication::translate("CreatNewUserDialog", "\345\257\206    \347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        userNamelabel->setText(QApplication::translate("CreatNewUserDialog", "\347\224\250 \346\210\267 \345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        YesButton->setText(QApplication::translate("CreatNewUserDialog", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        NoButton->setText(QApplication::translate("CreatNewUserDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreatNewUserDialog: public Ui_CreatNewUserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATNEWUSERDIALOG_H
