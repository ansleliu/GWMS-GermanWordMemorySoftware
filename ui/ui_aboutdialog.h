/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created: Tue Nov 24 04:05:56 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_aboutDialog
{
public:
    QLabel *icoLabel;
    QTextBrowser *AboutTextBrowser;
    QLabel *label;

    void setupUi(QDialog *aboutDialog)
    {
        if (aboutDialog->objectName().isEmpty())
            aboutDialog->setObjectName(QString::fromUtf8("aboutDialog"));
        aboutDialog->resize(462, 213);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix2/rc/ansle.png"), QSize(), QIcon::Normal, QIcon::Off);
        aboutDialog->setWindowIcon(icon);
        icoLabel = new QLabel(aboutDialog);
        icoLabel->setObjectName(QString::fromUtf8("icoLabel"));
        icoLabel->setGeometry(QRect(10, 10, 201, 161));
        icoLabel->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix2/rc/pic.png")));
        icoLabel->setScaledContents(true);
        icoLabel->setAlignment(Qt::AlignCenter);
        icoLabel->setWordWrap(false);
        AboutTextBrowser = new QTextBrowser(aboutDialog);
        AboutTextBrowser->setObjectName(QString::fromUtf8("AboutTextBrowser"));
        AboutTextBrowser->setGeometry(QRect(220, 10, 231, 171));
        AboutTextBrowser->setOpenExternalLinks(true);
        AboutTextBrowser->setOpenLinks(true);
        label = new QLabel(aboutDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 180, 451, 31));

        retranslateUi(aboutDialog);

        QMetaObject::connectSlotsByName(aboutDialog);
    } // setupUi

    void retranslateUi(QDialog *aboutDialog)
    {
        aboutDialog->setWindowTitle(QApplication::translate("aboutDialog", "  \345\205\263\344\272\216\350\275\257\344\273\266", 0, QApplication::UnicodeUTF8));
        icoLabel->setText(QString());
        AboutTextBrowser->setHtml(QApplication::translate("aboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">           </span><span style=\" font-weight:600; color:#000000;\">\345\205\263\344\272\216\350\275\257\344\273\266</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">------------------------------</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#000000;\">  \350\275\257\344\273\266\345\220\215"
                        "\347\247\260</span><span style=\" font-weight:600;\">\357\274\232  \345\276\267\350\257\255\350\203\214\345\215\225\350\257\215</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#aa0000;\"> </span><span style=\" font-weight:600; color:#ff0000;\"> \350\275\257\344\273\266\344\275\234\350\200\205\357\274\232  \345\210\230\346\205\247\345\206\233(ansleliu)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#ff0000;\">  \346\257\225\344\270\232\351\231\242\346\240\241\357\274\232  \350\245\277\345\256\211\347\224\265\345\255\220\347\247\221\346\212\200\345\244\247\345\255\246</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#ff0000;\">  \346\234\254"
                        "\347\247\221\344\270\223\344\270\232\357\274\232  \351\200\232\344\277\241\345\267\245\347\250\213</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#ffaa00;\">  \345\217\221\345\270\203\346\227\245\346\234\237\357\274\232  28/08/2014</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#ffaa00;\">  \345\275\223\345\211\215\347\211\210\346\234\254\357\274\232  Beta 4.2.0</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600; color:#ffaa00;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#ffaa00;\"> \344\272\206\350\247\243\346\233\264"
                        "\345\244\232\346\226\260\347\211\271\346\200\247\344\270\216\344\275\277\347\224\250\346\226\271\346\263\225\350\257\267\350\256\277\351\227\256\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">  <a href=\"http://hi.baidu.com/ansleliu\"><span style=\" font-weight:600; text-decoration: underline; color:#0000ff;\">\346\210\221\347\232\204\347\231\276\345\272\246\347\251\272\351\227\264\344\270\273\351\241\265</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("aboutDialog", "\346\234\254\350\275\257\344\273\266\347\224\261(\345\271\277\345\221\212\344\275\215-\345\271\277\345\221\212\344\275\215-\345\271\277\345\221\212\344\275\215-\345\271\277\345\221\212\344\275\215-\345\271\277\345\221\212\344\275\215-\345\271\277\345\221\212\344\275\215-\345\271\277\345\221\212\344\275\215-\345\271\277\345\221\212\344\275\215)\350\265\236\345\212\251\345\274\200\345\217\221", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class aboutDialog: public Ui_aboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
