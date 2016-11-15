/********************************************************************************
** Form generated from reading UI file 'editordialog.ui'
**
** Created: Tue Nov 24 04:05:56 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITORDIALOG_H
#define UI_EDITORDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_EditorDialog
{
public:
    QPushButton *clearButton;
    QLabel *label;
    QPushButton *applyButton;
    QPushButton *closeButton;
    QTextEdit *textEdit;

    void setupUi(QDialog *EditorDialog)
    {
        if (EditorDialog->objectName().isEmpty())
            EditorDialog->setObjectName(QString::fromUtf8("EditorDialog"));
        EditorDialog->resize(301, 411);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditorDialog->setWindowIcon(icon);
        clearButton = new QPushButton(EditorDialog);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(210, 10, 81, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/edit_clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearButton->setIcon(icon1);
        label = new QLabel(EditorDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 151, 31));
        applyButton = new QPushButton(EditorDialog);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setGeometry(QRect(100, 370, 91, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        applyButton->setIcon(icon2);
        closeButton = new QPushButton(EditorDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(200, 370, 91, 31));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon3);
        textEdit = new QTextEdit(EditorDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 50, 281, 311));

        retranslateUi(EditorDialog);

        QMetaObject::connectSlotsByName(EditorDialog);
    } // setupUi

    void retranslateUi(QDialog *EditorDialog)
    {
        EditorDialog->setWindowTitle(QApplication::translate("EditorDialog", "  \350\241\250\347\274\226\350\276\221\346\241\206  ", 0, QApplication::UnicodeUTF8));
        clearButton->setText(QApplication::translate("EditorDialog", "\346\270\205\351\231\244", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EditorDialog", "\350\257\267\346\212\212\344\277\241\346\201\257\350\276\223\345\205\245\344\270\213\351\235\242\347\274\226\350\276\221\346\241\206\357\274\232", 0, QApplication::UnicodeUTF8));
        applyButton->setText(QApplication::translate("EditorDialog", "\345\272\224\347\224\250\346\233\264\346\224\271", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("EditorDialog", "\345\217\226\346\266\210\346\233\264\346\224\271", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("EditorDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'\345\256\213\344\275\223';\"></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EditorDialog: public Ui_EditorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITORDIALOG_H
