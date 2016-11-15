/********************************************************************************
** Form generated from reading UI file 'AnsleDictConfigDialog.ui'
**
** Created: Tue Nov 24 04:05:57 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANSLEDICTCONFIGDIALOG_H
#define UI_ANSLEDICTCONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_AnsleDictConfigDialog
{
public:
    QPushButton *ApplyButton;
    QGroupBox *VoiceGroupBox;
    QRadioButton *GoogleTTSRadioButton;
    QRadioButton *ESpeakTTSRadioButton;
    QRadioButton *OtherRadioButton;
    QPushButton *CancelButton;
    QGroupBox *OtherGroupBox;
    QComboBox *TTSComboBox;
    QSlider *RateHorizontalSlider;
    QLabel *TTSLabel;
    QLabel *RateLabel;

    void setupUi(QDialog *AnsleDictConfigDialog)
    {
        if (AnsleDictConfigDialog->objectName().isEmpty())
            AnsleDictConfigDialog->setObjectName(QString::fromUtf8("AnsleDictConfigDialog"));
        AnsleDictConfigDialog->resize(362, 183);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix2/rc/Gear.ico"), QSize(), QIcon::Normal, QIcon::Off);
        AnsleDictConfigDialog->setWindowIcon(icon);
        ApplyButton = new QPushButton(AnsleDictConfigDialog);
        ApplyButton->setObjectName(QString::fromUtf8("ApplyButton"));
        ApplyButton->setGeometry(QRect(30, 150, 81, 23));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix2/rc/Ok (2).ico"), QSize(), QIcon::Normal, QIcon::Off);
        ApplyButton->setIcon(icon1);
        VoiceGroupBox = new QGroupBox(AnsleDictConfigDialog);
        VoiceGroupBox->setObjectName(QString::fromUtf8("VoiceGroupBox"));
        VoiceGroupBox->setGeometry(QRect(10, 10, 121, 131));
        GoogleTTSRadioButton = new QRadioButton(VoiceGroupBox);
        GoogleTTSRadioButton->setObjectName(QString::fromUtf8("GoogleTTSRadioButton"));
        GoogleTTSRadioButton->setGeometry(QRect(20, 60, 81, 21));
        ESpeakTTSRadioButton = new QRadioButton(VoiceGroupBox);
        ESpeakTTSRadioButton->setObjectName(QString::fromUtf8("ESpeakTTSRadioButton"));
        ESpeakTTSRadioButton->setGeometry(QRect(20, 20, 89, 21));
        ESpeakTTSRadioButton->setChecked(true);
        OtherRadioButton = new QRadioButton(VoiceGroupBox);
        OtherRadioButton->setObjectName(QString::fromUtf8("OtherRadioButton"));
        OtherRadioButton->setGeometry(QRect(20, 100, 89, 21));
        CancelButton = new QPushButton(AnsleDictConfigDialog);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        CancelButton->setGeometry(QRect(250, 150, 81, 23));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix2/rc/Cancel.ico"), QSize(), QIcon::Normal, QIcon::Off);
        CancelButton->setIcon(icon2);
        OtherGroupBox = new QGroupBox(AnsleDictConfigDialog);
        OtherGroupBox->setObjectName(QString::fromUtf8("OtherGroupBox"));
        OtherGroupBox->setGeometry(QRect(140, 10, 211, 131));
        TTSComboBox = new QComboBox(OtherGroupBox);
        TTSComboBox->setObjectName(QString::fromUtf8("TTSComboBox"));
        TTSComboBox->setGeometry(QRect(10, 40, 191, 21));
        RateHorizontalSlider = new QSlider(OtherGroupBox);
        RateHorizontalSlider->setObjectName(QString::fromUtf8("RateHorizontalSlider"));
        RateHorizontalSlider->setGeometry(QRect(10, 100, 191, 19));
        RateHorizontalSlider->setMinimum(-10);
        RateHorizontalSlider->setMaximum(10);
        RateHorizontalSlider->setPageStep(2);
        RateHorizontalSlider->setOrientation(Qt::Horizontal);
        TTSLabel = new QLabel(OtherGroupBox);
        TTSLabel->setObjectName(QString::fromUtf8("TTSLabel"));
        TTSLabel->setGeometry(QRect(10, 20, 91, 16));
        RateLabel = new QLabel(OtherGroupBox);
        RateLabel->setObjectName(QString::fromUtf8("RateLabel"));
        RateLabel->setGeometry(QRect(10, 71, 91, 21));

        retranslateUi(AnsleDictConfigDialog);

        QMetaObject::connectSlotsByName(AnsleDictConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *AnsleDictConfigDialog)
    {
        AnsleDictConfigDialog->setWindowTitle(QApplication::translate("AnsleDictConfigDialog", "\345\217\221\351\237\263\346\226\271\345\274\217\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        ApplyButton->setText(QApplication::translate("AnsleDictConfigDialog", "\345\272\224\347\224\250", 0, QApplication::UnicodeUTF8));
        VoiceGroupBox->setTitle(QApplication::translate("AnsleDictConfigDialog", "\345\217\221\351\237\263\346\226\271\345\274\217\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        GoogleTTSRadioButton->setText(QApplication::translate("AnsleDictConfigDialog", "GoogleTTS", 0, QApplication::UnicodeUTF8));
        ESpeakTTSRadioButton->setText(QApplication::translate("AnsleDictConfigDialog", "eSpeakTTS", 0, QApplication::UnicodeUTF8));
        OtherRadioButton->setText(QApplication::translate("AnsleDictConfigDialog", "\347\254\254\344\270\211\346\226\271TTS", 0, QApplication::UnicodeUTF8));
        CancelButton->setText(QApplication::translate("AnsleDictConfigDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        OtherGroupBox->setTitle(QApplication::translate("AnsleDictConfigDialog", "\347\254\254\344\270\211\346\226\271TTS\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
        TTSLabel->setText(QApplication::translate("AnsleDictConfigDialog", "\345\217\221\351\237\263\345\274\225\346\223\216\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        RateLabel->setText(QApplication::translate("AnsleDictConfigDialog", "\345\217\221\351\237\263\351\200\237\345\272\246\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AnsleDictConfigDialog: public Ui_AnsleDictConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANSLEDICTCONFIGDIALOG_H
