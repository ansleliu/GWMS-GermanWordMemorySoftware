/********************************************************************************
** Form generated from reading UI file 'addnewrecorddialog.ui'
**
** Created: Tue Nov 24 04:05:57 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWRECORDDIALOG_H
#define UI_ADDNEWRECORDDIALOG_H

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
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddNewRecordDialog
{
public:
    QPushButton *OKButton;
    QGroupBox *InfoGroupBox;
    QLabel *word;
    QLabel *mean;
    QLabel *other;
    QLineEdit *WordLineEdit;
    QTextEdit *MeanTextEdit;
    QTextEdit *OtherTextEdit;
    QLabel *lektion;
    QLineEdit *LektionLineEdit;
    QPushButton *CloseButton;

    void setupUi(QDialog *AddNewRecordDialog)
    {
        if (AddNewRecordDialog->objectName().isEmpty())
            AddNewRecordDialog->setObjectName(QString::fromUtf8("AddNewRecordDialog"));
        AddNewRecordDialog->resize(360, 422);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddNewRecordDialog->setWindowIcon(icon);
        OKButton = new QPushButton(AddNewRecordDialog);
        OKButton->setObjectName(QString::fromUtf8("OKButton"));
        OKButton->setGeometry(QRect(210, 380, 61, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/dialog_ok_apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        OKButton->setIcon(icon1);
        InfoGroupBox = new QGroupBox(AddNewRecordDialog);
        InfoGroupBox->setObjectName(QString::fromUtf8("InfoGroupBox"));
        InfoGroupBox->setGeometry(QRect(10, 10, 341, 361));
        word = new QLabel(InfoGroupBox);
        word->setObjectName(QString::fromUtf8("word"));
        word->setGeometry(QRect(10, 20, 41, 21));
        mean = new QLabel(InfoGroupBox);
        mean->setObjectName(QString::fromUtf8("mean"));
        mean->setGeometry(QRect(10, 60, 51, 21));
        other = new QLabel(InfoGroupBox);
        other->setObjectName(QString::fromUtf8("other"));
        other->setGeometry(QRect(10, 230, 71, 21));
        WordLineEdit = new QLineEdit(InfoGroupBox);
        WordLineEdit->setObjectName(QString::fromUtf8("WordLineEdit"));
        WordLineEdit->setGeometry(QRect(10, 40, 221, 21));
        MeanTextEdit = new QTextEdit(InfoGroupBox);
        MeanTextEdit->setObjectName(QString::fromUtf8("MeanTextEdit"));
        MeanTextEdit->setGeometry(QRect(10, 80, 321, 151));
        OtherTextEdit = new QTextEdit(InfoGroupBox);
        OtherTextEdit->setObjectName(QString::fromUtf8("OtherTextEdit"));
        OtherTextEdit->setGeometry(QRect(10, 250, 321, 101));
        lektion = new QLabel(InfoGroupBox);
        lektion->setObjectName(QString::fromUtf8("lektion"));
        lektion->setGeometry(QRect(240, 16, 54, 20));
        LektionLineEdit = new QLineEdit(InfoGroupBox);
        LektionLineEdit->setObjectName(QString::fromUtf8("LektionLineEdit"));
        LektionLineEdit->setGeometry(QRect(242, 40, 91, 20));
        CloseButton = new QPushButton(AddNewRecordDialog);
        CloseButton->setObjectName(QString::fromUtf8("CloseButton"));
        CloseButton->setGeometry(QRect(290, 380, 61, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        CloseButton->setIcon(icon2);

        retranslateUi(AddNewRecordDialog);

        QMetaObject::connectSlotsByName(AddNewRecordDialog);
    } // setupUi

    void retranslateUi(QDialog *AddNewRecordDialog)
    {
        AddNewRecordDialog->setWindowTitle(QApplication::translate("AddNewRecordDialog", "  \346\267\273\345\212\240\346\226\260\350\257\215\346\235\241", 0, QApplication::UnicodeUTF8));
        OKButton->setText(QApplication::translate("AddNewRecordDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        InfoGroupBox->setTitle(QApplication::translate("AddNewRecordDialog", "\346\267\273\345\212\240\344\270\200\346\235\241\346\226\260\347\232\204\350\257\215\346\235\241", 0, QApplication::UnicodeUTF8));
        word->setText(QApplication::translate("AddNewRecordDialog", "\345\215\225\350\257\215\357\274\232", 0, QApplication::UnicodeUTF8));
        mean->setText(QApplication::translate("AddNewRecordDialog", "\350\257\215\344\271\211\357\274\232", 0, QApplication::UnicodeUTF8));
        other->setText(QApplication::translate("AddNewRecordDialog", "\347\233\270\345\205\263\344\277\241\346\201\257\357\274\232", 0, QApplication::UnicodeUTF8));
        lektion->setText(QApplication::translate("AddNewRecordDialog", "\345\215\225\345\205\203\357\274\232", 0, QApplication::UnicodeUTF8));
        CloseButton->setText(QApplication::translate("AddNewRecordDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddNewRecordDialog: public Ui_AddNewRecordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWRECORDDIALOG_H
