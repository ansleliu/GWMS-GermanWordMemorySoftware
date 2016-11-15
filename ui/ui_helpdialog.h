/********************************************************************************
** Form generated from reading UI file 'helpdialog.ui'
**
** Created: Tue Nov 24 04:05:56 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_HelpDialog
{
public:
    QLabel *FlagLabel;
    QLabel *titelLabel;
    QTextBrowser *textBrowser;
    QLabel *label;

    void setupUi(QDialog *HelpDialog)
    {
        if (HelpDialog->objectName().isEmpty())
            HelpDialog->setObjectName(QString::fromUtf8("HelpDialog"));
        HelpDialog->resize(374, 462);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix2/rc/love.png"), QSize(), QIcon::Normal, QIcon::Off);
        HelpDialog->setWindowIcon(icon);
        FlagLabel = new QLabel(HelpDialog);
        FlagLabel->setObjectName(QString::fromUtf8("FlagLabel"));
        FlagLabel->setGeometry(QRect(20, 10, 331, 151));
        FlagLabel->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix2/rc/ansle.png")));
        FlagLabel->setScaledContents(true);
        titelLabel = new QLabel(HelpDialog);
        titelLabel->setObjectName(QString::fromUtf8("titelLabel"));
        titelLabel->setGeometry(QRect(30, 170, 311, 21));
        textBrowser = new QTextBrowser(HelpDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 190, 321, 241));
        textBrowser->setOpenExternalLinks(true);
        label = new QLabel(HelpDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 430, 321, 31));

        retranslateUi(HelpDialog);

        QMetaObject::connectSlotsByName(HelpDialog);
    } // setupUi

    void retranslateUi(QDialog *HelpDialog)
    {
        HelpDialog->setWindowTitle(QApplication::translate("HelpDialog", "\346\224\257\346\214\201\350\275\257\344\273\266", 0, QApplication::UnicodeUTF8));
        FlagLabel->setText(QString());
        titelLabel->setText(QApplication::translate("HelpDialog", "\345\246\202\346\236\234\346\202\250\345\226\234\346\254\242\346\234\254\350\275\257\344\273\266\346\202\250\345\217\257\344\273\245\351\200\232\350\277\207\344\273\245\344\270\213\346\226\271\345\274\217\346\224\257\346\214\201\346\234\254\350\275\257\344\273\266\347\232\204\345\274\200\345\217\221\357\274\232", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("HelpDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#aa0000;\">\344\270\200\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#aa0000;\">  \345\220\221\346\202\250\350\272\253\350\276\271\345\255\246\345\276\267\350\257\255\347\232\204\345\220\214\345\255\246\345\222\214\346\234\213\345\217\213\346\216\250\350\215\220\350\277\231\346\254\276\350\275\257\344\273\266\357\274\214\345\234\250\350\264\264\345\220\247\343\200\201\347\275\221\347\233\230"
                        "\343\200\201\345\276\256\344\277\241\343\200\201\345\276\256\345\215\232\343\200\201\345\215\232\345\256\242\346\210\226\345\205\266\344\273\226\345\252\222\344\275\223\344\270\212\345\270\256\345\212\251\350\275\257\344\273\266\347\232\204\346\216\250\345\271\277\345\222\214\346\231\256\345\217\212</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:top;\">\357\274\214\350\256\251\346\233\264\345\244\232\347\232\204\344\272\272\350\203\275\345\244\237\344\272\206\350\247\243\345\210\260\350\277\231\346\254\276\350\275\257\344\273\266\357\274\233</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600; color:#aa0000;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color"
                        ":#aa0000;\">\344\272\214\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#aa0000;\">  \345\212\240\345\205\245\350\257\245\350\275\257\344\273\266\347\232\204\345\256\230\346\226\271QQ\347\276\244</span><a name=\"group_name\"></a><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma'; font-weight:600; color:#aa0000;\">D</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma'; font-weight:600; color:#aa0000;\">eutschland--ansleliu</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000;\">\302\240</span><a name=\"group_number\"></a><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:top;\">3</span><span style=\" font-"
                        "family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:top;\">34905867\345\217\215\351\246\210\346\202\250\345\234\250\344\275\277\347\224\250\350\275\257\344\273\266\347\232\204\350\277\207\347\250\213\344\270\255\351\201\207\345\210\260\347\232\204\351\227\256\351\242\230\344\273\245\345\270\256\345\212\251\350\275\257\344\273\266\345\217\257\344\273\245\345\217\230\345\276\227\346\233\264\344\270\272\345\256\214\345\226\204\345\222\214\345\274\272\345\243\256\357\274\233</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:top;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-fami"
                        "ly:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:top;\">\344\270\211\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:top;\">  \346\233\264\345\244\232\347\232\204\345\210\233\345\273\272\350\207\252\345\267\261\347\232\204\350\257\215\345\272\223\357\274\214\345\271\266\345\205\261\344\272\253\345\210\260\345\256\230\346\226\271\347\276\244\344\270\212\357\274\214\344\270\272\345\255\246\345\276\267\350\257\255\347\232\204\345\220\214\345\255\246\346\217\220\344\276\233\346\233\264\345\244\232\347\232\204\345\215\225\350\257\215\350\265\204\346\272\220\357\274\233</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-"
                        "right:0px; -qt-block-indent:0; text-indent:0px; font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:top;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:top;\">\345\233\233\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:top;\">  \350\265\204\351\207\221\350\265\236\345\212\251\346\234\254\350\275\257\344\273\266\347\232\204\345\274\200\345\217\221\357\274\214\344\270\215\350\256\272\345\244\232\345\260\221\357\274\214\344\275\206"
                        "\350\277\231\344\270\215\345\271\266\346\230\257\345\277\205\351\241\273\347\232\204\357\274\214\345\246\202\346\236\234\346\202\250\345\270\214\346\234\233\347\224\250\350\277\231\347\247\215\346\226\271\345\274\217\346\224\257\346\214\201\346\234\254\350\275\257\344\273\266\357\274\214\346\202\250\345\217\257\344\273\245\351\200\211\346\213\251\347\232\204\350\265\236\345\212\251\346\226\271\345\274\217\344\270\272\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:top;\">  1.\346\224\257\344\273\230\345\256\235\350\264\246\346\210\267\357\274\232ansleliu@gmail.com\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275"
                        "\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:top;\">  2.\344\272\244\351\200\232\351\223\266\350\241\214\350\264\246\346\210\267\357\274\232\345\210\230\346\205\247\345\206\2336222600810011233798\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:top;\">  3.\344\270\255\345\233\275\351\223\266\350\241\214\350\264\246\346\210\267\357\274\232\345\210\230\346\205\247\345\206\2336217853600006698152\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:t"
                        "op;\">\344\272\224\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:top;\">  \351\200\232\350\277\207\344\270\216\346\234\254\344\272\272\346\264\275\350\260\210\345\271\277\345\221\212\346\235\245\350\265\204\345\212\251\346\234\254\350\275\257\344\273\266\357\274\214\346\234\254\350\275\257\344\273\266\344\274\232\345\234\250\345\220\210\351\200\202\347\232\204\344\275\215\345\255\220\344\270\212\346\244\215\345\205\245\345\260\221\351\207\217\345\271\277\345\221\212\357\274\214\344\273\245\350\216\267\345\276\227\344\270\200\345\256\232\347\232\204\346\224\266\345\205\245\357\274\214\345\246\202\346\236\234\346\202\250\350\247\211\345\276\227\350\275\257\344\273\266\344\270\215\351\224\231\357\274\214\345\271\266\344\270\224\345\217\210\346\203\263\345\200"
                        "\237\345\212\251\350\275\257\344\273\266\347\232\204\346\216\250\345\271\277\346\210\226\350\200\205\345\234\250\346\216\250\345\271\277\350\275\257\344\273\266\347\232\204\345\220\214\346\227\266\346\216\250\345\271\277\346\202\250\347\232\204\344\272\247\345\223\201\346\210\226\346\234\272\346\236\204\357\274\214\350\257\267\346\202\250\350\201\224\347\263\273\346\210\221\357\274\232984009568@qq.com\343\200\202</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:top;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221,Tahoma,\345\256\213\344\275\223'; font-weight:600; color:#aa0000; vertical-align:top;\">\344"
                        "\272\206\350\247\243\346\233\264\345\244\232\344\277\241\346\201\257\350\257\267\350\256\277\351\227\256\357\274\232</span><a href=\"http://hi.baidu.com/ansleliu\"><span style=\" font-weight:600; text-decoration: underline; color:#00007f;\">\346\210\221\347\232\204\347\231\276\345\272\246\347\251\272\351\227\264\344\270\273\351\241\265</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HelpDialog", "\345\271\277\345\221\212\344\275\215 --- \345\271\277\345\221\212\344\275\215 --- \345\271\277\345\221\212\344\275\215 --- \345\271\277\345\221\212\344\275\215 --- \345\271\277\345\221\212\344\275\215 ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HelpDialog: public Ui_HelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H
