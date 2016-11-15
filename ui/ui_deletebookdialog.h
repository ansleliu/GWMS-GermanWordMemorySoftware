/********************************************************************************
** Form generated from reading UI file 'deletebookdialog.ui'
**
** Created: Tue Nov 24 04:05:56 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEBOOKDIALOG_H
#define UI_DELETEBOOKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DeleteBookDialog
{
public:
    QLabel *label;
    QLineEdit *bookLineEdit;
    QPushButton *QuitButton;
    QPushButton *OKButton;
    QLineEdit *classLineEdit;
    QLabel *bookLabel;
    QLabel *classLabel;

    void setupUi(QDialog *DeleteBookDialog)
    {
        if (DeleteBookDialog->objectName().isEmpty())
            DeleteBookDialog->setObjectName(QString::fromUtf8("DeleteBookDialog"));
        DeleteBookDialog->resize(332, 151);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        DeleteBookDialog->setWindowIcon(icon);
        label = new QLabel(DeleteBookDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 10, 221, 21));
        bookLineEdit = new QLineEdit(DeleteBookDialog);
        bookLineEdit->setObjectName(QString::fromUtf8("bookLineEdit"));
        bookLineEdit->setGeometry(QRect(90, 80, 221, 21));
        bookLineEdit->setReadOnly(false);
        QuitButton = new QPushButton(DeleteBookDialog);
        QuitButton->setObjectName(QString::fromUtf8("QuitButton"));
        QuitButton->setGeometry(QRect(200, 110, 71, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        QuitButton->setIcon(icon1);
        OKButton = new QPushButton(DeleteBookDialog);
        OKButton->setObjectName(QString::fromUtf8("OKButton"));
        OKButton->setGeometry(QRect(60, 110, 71, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        OKButton->setIcon(icon2);
        classLineEdit = new QLineEdit(DeleteBookDialog);
        classLineEdit->setObjectName(QString::fromUtf8("classLineEdit"));
        classLineEdit->setGeometry(QRect(90, 40, 221, 21));
        bookLabel = new QLabel(DeleteBookDialog);
        bookLabel->setObjectName(QString::fromUtf8("bookLabel"));
        bookLabel->setGeometry(QRect(20, 80, 71, 21));
        classLabel = new QLabel(DeleteBookDialog);
        classLabel->setObjectName(QString::fromUtf8("classLabel"));
        classLabel->setGeometry(QRect(20, 40, 71, 21));

        retranslateUi(DeleteBookDialog);

        QMetaObject::connectSlotsByName(DeleteBookDialog);
    } // setupUi

    void retranslateUi(QDialog *DeleteBookDialog)
    {
        DeleteBookDialog->setWindowTitle(QApplication::translate("DeleteBookDialog", "  \347\247\273\351\231\244\350\257\215\345\272\223  ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DeleteBookDialog", "\350\257\267\350\276\223\345\205\245\350\246\201\345\210\240\351\231\244\347\232\204\350\257\215\345\272\223\346\211\200\345\261\236\347\232\204\347\261\273\345\222\214\350\257\215\345\272\223\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QuitButton->setText(QApplication::translate("DeleteBookDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        OKButton->setText(QApplication::translate("DeleteBookDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        bookLabel->setText(QApplication::translate("DeleteBookDialog", "\350\257\215      \345\272\223\357\274\232", 0, QApplication::UnicodeUTF8));
        classLabel->setText(QApplication::translate("DeleteBookDialog", "\350\257\215\345\272\223\346\211\200\345\261\236\347\261\273\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DeleteBookDialog: public Ui_DeleteBookDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEBOOKDIALOG_H
