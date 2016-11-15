/********************************************************************************
** Form generated from reading UI file 'edititemdialog.ui'
**
** Created: Tue Nov 24 04:05:56 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITITEMDIALOG_H
#define UI_EDITITEMDIALOG_H

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

class Ui_editItemDialog
{
public:
    QPushButton *OKPushButton;
    QPushButton *NOPushButton;
    QGroupBox *groupBox;
    QLineEdit *newNamelineEdit;
    QLabel *label;

    void setupUi(QDialog *editItemDialog)
    {
        if (editItemDialog->objectName().isEmpty())
            editItemDialog->setObjectName(QString::fromUtf8("editItemDialog"));
        editItemDialog->resize(301, 141);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/edit_rename.png"), QSize(), QIcon::Normal, QIcon::Off);
        editItemDialog->setWindowIcon(icon);
        OKPushButton = new QPushButton(editItemDialog);
        OKPushButton->setObjectName(QString::fromUtf8("OKPushButton"));
        OKPushButton->setGeometry(QRect(50, 100, 71, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        OKPushButton->setIcon(icon1);
        NOPushButton = new QPushButton(editItemDialog);
        NOPushButton->setObjectName(QString::fromUtf8("NOPushButton"));
        NOPushButton->setGeometry(QRect(170, 100, 71, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        NOPushButton->setIcon(icon2);
        groupBox = new QGroupBox(editItemDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 281, 71));
        newNamelineEdit = new QLineEdit(groupBox);
        newNamelineEdit->setObjectName(QString::fromUtf8("newNamelineEdit"));
        newNamelineEdit->setGeometry(QRect(70, 30, 191, 21));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 51, 21));

        retranslateUi(editItemDialog);

        QMetaObject::connectSlotsByName(editItemDialog);
    } // setupUi

    void retranslateUi(QDialog *editItemDialog)
    {
        editItemDialog->setWindowTitle(QApplication::translate("editItemDialog", "  \347\274\226\350\276\221\345\220\215\347\247\260  ", 0, QApplication::UnicodeUTF8));
        OKPushButton->setText(QApplication::translate("editItemDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        NOPushButton->setText(QApplication::translate("editItemDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("editItemDialog", "\346\226\260\345\220\215\347\247\260\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class editItemDialog: public Ui_editItemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITITEMDIALOG_H
