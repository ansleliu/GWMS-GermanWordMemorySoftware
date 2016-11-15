/********************************************************************************
** Form generated from reading UI file 'learnwordconfigdialog.ui'
**
** Created: Tue Nov 24 04:05:56 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNWORDCONFIGDIALOG_H
#define UI_LEARNWORDCONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LearnWordConfigDialog
{
public:
    QPushButton *OKButton;
    QGroupBox *ConfigGroupBox;
    QGridLayout *gridLayout_2;
    QTabWidget *ConfigTabWidget;
    QWidget *LearnTab;
    QGroupBox *LearnMethodGroupBox;
    QComboBox *LearnMethodComboBox;
    QLabel *LearnLabel;
    QGroupBox *OutGroupBox;
    QRadioButton *OutOrderlyRadioButton;
    QRadioButton *OutRandomRadioButton;
    QGroupBox *ReviewGroupBox;
    QRadioButton *ReviewOrderlyRadioButton;
    QRadioButton *ReviewRandomRadioButton;
    QWidget *SoundTab;
    QGridLayout *gridLayout_3;
    QGroupBox *SpeakMethodeGroupBox;
    QGridLayout *gridLayout;
    QRadioButton *TTSRadioButton;
    QRadioButton *OnlineRadioButton;
    QRadioButton *Real_TTSRadioButton;
    QGroupBox *CircleGroupBox;
    QLabel *TimeLabel;
    QComboBox *TimeComboBox;
    QLabel *IntervalLabel;
    QComboBox *IntervalComboBox;
    QWidget *ShortcutsTab;
    QLabel *RememLabel;
    QLineEdit *RememLineEdit;
    QLabel *ObscureLabel;
    QLineEdit *ObscureLineEdit;
    QLabel *ForgetLabel;
    QLineEdit *ForgetLineEdit;
    QLabel *RightLabel;
    QLineEdit *RightLineEdit;
    QLabel *WrongLabel;
    QLineEdit *WrongLineEdit;
    QLabel *SoundLabel;
    QLineEdit *SoundLineEdit;
    QLabel *NextLabel;
    QLineEdit *NextLineEdit;
    QLabel *ConfigLabel;
    QLineEdit *ConfigLineEdit;
    QLabel *EditWordLabel;
    QLineEdit *EditWordLineEdit;
    QPushButton *QuitButton;

    void setupUi(QDialog *LearnWordConfigDialog)
    {
        if (LearnWordConfigDialog->objectName().isEmpty())
            LearnWordConfigDialog->setObjectName(QString::fromUtf8("LearnWordConfigDialog"));
        LearnWordConfigDialog->resize(352, 263);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/gear.png"), QSize(), QIcon::Normal, QIcon::Off);
        LearnWordConfigDialog->setWindowIcon(icon);
        OKButton = new QPushButton(LearnWordConfigDialog);
        OKButton->setObjectName(QString::fromUtf8("OKButton"));
        OKButton->setGeometry(QRect(70, 220, 71, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        OKButton->setIcon(icon1);
        ConfigGroupBox = new QGroupBox(LearnWordConfigDialog);
        ConfigGroupBox->setObjectName(QString::fromUtf8("ConfigGroupBox"));
        ConfigGroupBox->setGeometry(QRect(10, 10, 331, 201));
        gridLayout_2 = new QGridLayout(ConfigGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ConfigTabWidget = new QTabWidget(ConfigGroupBox);
        ConfigTabWidget->setObjectName(QString::fromUtf8("ConfigTabWidget"));
        ConfigTabWidget->setFocusPolicy(Qt::NoFocus);
        ConfigTabWidget->setTabPosition(QTabWidget::North);
        ConfigTabWidget->setTabShape(QTabWidget::Rounded);
        ConfigTabWidget->setIconSize(QSize(24, 24));
        ConfigTabWidget->setElideMode(Qt::ElideMiddle);
        LearnTab = new QWidget();
        LearnTab->setObjectName(QString::fromUtf8("LearnTab"));
        LearnMethodGroupBox = new QGroupBox(LearnTab);
        LearnMethodGroupBox->setObjectName(QString::fromUtf8("LearnMethodGroupBox"));
        LearnMethodGroupBox->setGeometry(QRect(10, 10, 111, 111));
        LearnMethodComboBox = new QComboBox(LearnMethodGroupBox);
        LearnMethodComboBox->setObjectName(QString::fromUtf8("LearnMethodComboBox"));
        LearnMethodComboBox->setGeometry(QRect(10, 60, 91, 22));
        LearnLabel = new QLabel(LearnMethodGroupBox);
        LearnLabel->setObjectName(QString::fromUtf8("LearnLabel"));
        LearnLabel->setGeometry(QRect(10, 30, 91, 16));
        OutGroupBox = new QGroupBox(LearnTab);
        OutGroupBox->setObjectName(QString::fromUtf8("OutGroupBox"));
        OutGroupBox->setGeometry(QRect(130, 10, 161, 51));
        OutOrderlyRadioButton = new QRadioButton(OutGroupBox);
        OutOrderlyRadioButton->setObjectName(QString::fromUtf8("OutOrderlyRadioButton"));
        OutOrderlyRadioButton->setGeometry(QRect(20, 20, 51, 21));
        OutRandomRadioButton = new QRadioButton(OutGroupBox);
        OutRandomRadioButton->setObjectName(QString::fromUtf8("OutRandomRadioButton"));
        OutRandomRadioButton->setGeometry(QRect(100, 20, 51, 21));
        OutRandomRadioButton->setChecked(true);
        ReviewGroupBox = new QGroupBox(LearnTab);
        ReviewGroupBox->setObjectName(QString::fromUtf8("ReviewGroupBox"));
        ReviewGroupBox->setGeometry(QRect(130, 70, 161, 51));
        ReviewOrderlyRadioButton = new QRadioButton(ReviewGroupBox);
        ReviewOrderlyRadioButton->setObjectName(QString::fromUtf8("ReviewOrderlyRadioButton"));
        ReviewOrderlyRadioButton->setGeometry(QRect(20, 20, 51, 21));
        ReviewRandomRadioButton = new QRadioButton(ReviewGroupBox);
        ReviewRandomRadioButton->setObjectName(QString::fromUtf8("ReviewRandomRadioButton"));
        ReviewRandomRadioButton->setGeometry(QRect(100, 20, 51, 21));
        ReviewRandomRadioButton->setChecked(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/configure_shortcuts.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConfigTabWidget->addTab(LearnTab, icon2, QString());
        SoundTab = new QWidget();
        SoundTab->setObjectName(QString::fromUtf8("SoundTab"));
        gridLayout_3 = new QGridLayout(SoundTab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        SpeakMethodeGroupBox = new QGroupBox(SoundTab);
        SpeakMethodeGroupBox->setObjectName(QString::fromUtf8("SpeakMethodeGroupBox"));
        SpeakMethodeGroupBox->setFlat(false);
        gridLayout = new QGridLayout(SpeakMethodeGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TTSRadioButton = new QRadioButton(SpeakMethodeGroupBox);
        TTSRadioButton->setObjectName(QString::fromUtf8("TTSRadioButton"));

        gridLayout->addWidget(TTSRadioButton, 0, 0, 1, 2);

        OnlineRadioButton = new QRadioButton(SpeakMethodeGroupBox);
        OnlineRadioButton->setObjectName(QString::fromUtf8("OnlineRadioButton"));

        gridLayout->addWidget(OnlineRadioButton, 1, 0, 1, 2);

        Real_TTSRadioButton = new QRadioButton(SpeakMethodeGroupBox);
        Real_TTSRadioButton->setObjectName(QString::fromUtf8("Real_TTSRadioButton"));
        Real_TTSRadioButton->setCheckable(true);

        gridLayout->addWidget(Real_TTSRadioButton, 2, 0, 1, 2);


        gridLayout_3->addWidget(SpeakMethodeGroupBox, 0, 1, 1, 1);

        CircleGroupBox = new QGroupBox(SoundTab);
        CircleGroupBox->setObjectName(QString::fromUtf8("CircleGroupBox"));
        TimeLabel = new QLabel(CircleGroupBox);
        TimeLabel->setObjectName(QString::fromUtf8("TimeLabel"));
        TimeLabel->setGeometry(QRect(10, 30, 60, 21));
        TimeComboBox = new QComboBox(CircleGroupBox);
        TimeComboBox->setObjectName(QString::fromUtf8("TimeComboBox"));
        TimeComboBox->setGeometry(QRect(70, 30, 61, 20));
        IntervalLabel = new QLabel(CircleGroupBox);
        IntervalLabel->setObjectName(QString::fromUtf8("IntervalLabel"));
        IntervalLabel->setGeometry(QRect(10, 70, 60, 21));
        IntervalComboBox = new QComboBox(CircleGroupBox);
        IntervalComboBox->setObjectName(QString::fromUtf8("IntervalComboBox"));
        IntervalComboBox->setGeometry(QRect(70, 70, 61, 20));

        gridLayout_3->addWidget(CircleGroupBox, 0, 0, 1, 1);

        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/speaker.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConfigTabWidget->addTab(SoundTab, icon3, QString());
        ShortcutsTab = new QWidget();
        ShortcutsTab->setObjectName(QString::fromUtf8("ShortcutsTab"));
        RememLabel = new QLabel(ShortcutsTab);
        RememLabel->setObjectName(QString::fromUtf8("RememLabel"));
        RememLabel->setGeometry(QRect(10, 20, 31, 20));
        RememLineEdit = new QLineEdit(ShortcutsTab);
        RememLineEdit->setObjectName(QString::fromUtf8("RememLineEdit"));
        RememLineEdit->setGeometry(QRect(50, 20, 31, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        RememLineEdit->setFont(font);
        ObscureLabel = new QLabel(ShortcutsTab);
        ObscureLabel->setObjectName(QString::fromUtf8("ObscureLabel"));
        ObscureLabel->setGeometry(QRect(110, 20, 31, 20));
        ObscureLineEdit = new QLineEdit(ShortcutsTab);
        ObscureLineEdit->setObjectName(QString::fromUtf8("ObscureLineEdit"));
        ObscureLineEdit->setGeometry(QRect(150, 20, 31, 20));
        ObscureLineEdit->setFont(font);
        ForgetLabel = new QLabel(ShortcutsTab);
        ForgetLabel->setObjectName(QString::fromUtf8("ForgetLabel"));
        ForgetLabel->setGeometry(QRect(210, 20, 31, 20));
        ForgetLineEdit = new QLineEdit(ShortcutsTab);
        ForgetLineEdit->setObjectName(QString::fromUtf8("ForgetLineEdit"));
        ForgetLineEdit->setGeometry(QRect(250, 20, 31, 20));
        ForgetLineEdit->setFont(font);
        RightLabel = new QLabel(ShortcutsTab);
        RightLabel->setObjectName(QString::fromUtf8("RightLabel"));
        RightLabel->setGeometry(QRect(10, 61, 31, 20));
        RightLineEdit = new QLineEdit(ShortcutsTab);
        RightLineEdit->setObjectName(QString::fromUtf8("RightLineEdit"));
        RightLineEdit->setGeometry(QRect(50, 60, 31, 20));
        RightLineEdit->setFont(font);
        WrongLabel = new QLabel(ShortcutsTab);
        WrongLabel->setObjectName(QString::fromUtf8("WrongLabel"));
        WrongLabel->setGeometry(QRect(110, 61, 31, 20));
        WrongLineEdit = new QLineEdit(ShortcutsTab);
        WrongLineEdit->setObjectName(QString::fromUtf8("WrongLineEdit"));
        WrongLineEdit->setGeometry(QRect(150, 60, 31, 20));
        WrongLineEdit->setFont(font);
        SoundLabel = new QLabel(ShortcutsTab);
        SoundLabel->setObjectName(QString::fromUtf8("SoundLabel"));
        SoundLabel->setGeometry(QRect(10, 101, 31, 20));
        SoundLineEdit = new QLineEdit(ShortcutsTab);
        SoundLineEdit->setObjectName(QString::fromUtf8("SoundLineEdit"));
        SoundLineEdit->setGeometry(QRect(50, 100, 31, 20));
        SoundLineEdit->setFont(font);
        NextLabel = new QLabel(ShortcutsTab);
        NextLabel->setObjectName(QString::fromUtf8("NextLabel"));
        NextLabel->setGeometry(QRect(110, 100, 31, 21));
        NextLineEdit = new QLineEdit(ShortcutsTab);
        NextLineEdit->setObjectName(QString::fromUtf8("NextLineEdit"));
        NextLineEdit->setGeometry(QRect(150, 100, 31, 20));
        NextLineEdit->setFont(font);
        ConfigLabel = new QLabel(ShortcutsTab);
        ConfigLabel->setObjectName(QString::fromUtf8("ConfigLabel"));
        ConfigLabel->setGeometry(QRect(210, 100, 31, 21));
        ConfigLineEdit = new QLineEdit(ShortcutsTab);
        ConfigLineEdit->setObjectName(QString::fromUtf8("ConfigLineEdit"));
        ConfigLineEdit->setGeometry(QRect(250, 100, 31, 20));
        ConfigLineEdit->setFont(font);
        EditWordLabel = new QLabel(ShortcutsTab);
        EditWordLabel->setObjectName(QString::fromUtf8("EditWordLabel"));
        EditWordLabel->setGeometry(QRect(210, 61, 31, 20));
        EditWordLineEdit = new QLineEdit(ShortcutsTab);
        EditWordLineEdit->setObjectName(QString::fromUtf8("EditWordLineEdit"));
        EditWordLineEdit->setGeometry(QRect(250, 60, 31, 20));
        EditWordLineEdit->setFont(font);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/transform_move.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConfigTabWidget->addTab(ShortcutsTab, icon4, QString());

        gridLayout_2->addWidget(ConfigTabWidget, 0, 0, 1, 1);

        QuitButton = new QPushButton(LearnWordConfigDialog);
        QuitButton->setObjectName(QString::fromUtf8("QuitButton"));
        QuitButton->setGeometry(QRect(210, 220, 71, 31));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/dialog_cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        QuitButton->setIcon(icon5);

        retranslateUi(LearnWordConfigDialog);

        ConfigTabWidget->setCurrentIndex(1);
        LearnMethodComboBox->setCurrentIndex(-1);
        TimeComboBox->setCurrentIndex(-1);
        IntervalComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LearnWordConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *LearnWordConfigDialog)
    {
        LearnWordConfigDialog->setWindowTitle(QApplication::translate("LearnWordConfigDialog", "    \351\205\215\347\275\256   ", 0, QApplication::UnicodeUTF8));
        OKButton->setText(QApplication::translate("LearnWordConfigDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        ConfigGroupBox->setTitle(QApplication::translate("LearnWordConfigDialog", "\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
        LearnMethodGroupBox->setTitle(QApplication::translate("LearnWordConfigDialog", "\345\255\246\344\271\240\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
        LearnMethodComboBox->clear();
        LearnMethodComboBox->insertItems(0, QStringList()
         << QApplication::translate("LearnWordConfigDialog", "\345\207\272\350\257\215\345\277\206\344\271\211", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LearnWordConfigDialog", "\345\207\272\344\271\211\345\277\206\350\257\215", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LearnWordConfigDialog", "\345\220\254\351\237\263\350\276\250\350\257\215", 0, QApplication::UnicodeUTF8)
        );
        LearnLabel->setText(QApplication::translate("LearnWordConfigDialog", "\345\255\246\344\271\240\346\226\271\345\274\217\351\200\211\346\213\251\357\274\232", 0, QApplication::UnicodeUTF8));
        OutGroupBox->setTitle(QApplication::translate("LearnWordConfigDialog", "\345\207\272\350\257\215\351\241\272\345\272\217", 0, QApplication::UnicodeUTF8));
        OutOrderlyRadioButton->setText(QApplication::translate("LearnWordConfigDialog", "\351\241\272\345\272\217", 0, QApplication::UnicodeUTF8));
        OutRandomRadioButton->setText(QApplication::translate("LearnWordConfigDialog", "\351\232\217\346\234\272", 0, QApplication::UnicodeUTF8));
        ReviewGroupBox->setTitle(QApplication::translate("LearnWordConfigDialog", "\345\244\215\344\271\240\351\241\272\345\272\217", 0, QApplication::UnicodeUTF8));
        ReviewOrderlyRadioButton->setText(QApplication::translate("LearnWordConfigDialog", "\351\241\272\345\272\217", 0, QApplication::UnicodeUTF8));
        ReviewRandomRadioButton->setText(QApplication::translate("LearnWordConfigDialog", "\351\232\217\346\234\272", 0, QApplication::UnicodeUTF8));
        ConfigTabWidget->setTabText(ConfigTabWidget->indexOf(LearnTab), QApplication::translate("LearnWordConfigDialog", "\345\255\246\344\271\240\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        SpeakMethodeGroupBox->setTitle(QApplication::translate("LearnWordConfigDialog", "\345\217\221\351\237\263\346\250\241\345\274\217\350\256\276\345\256\232", 0, QApplication::UnicodeUTF8));
        TTSRadioButton->setText(QApplication::translate("LearnWordConfigDialog", "\345\206\205\347\275\256\346\210\226\347\254\254\344\270\211\346\226\271TTS", 0, QApplication::UnicodeUTF8));
        OnlineRadioButton->setText(QApplication::translate("LearnWordConfigDialog", "Google\345\234\250\347\272\277TTS", 0, QApplication::UnicodeUTF8));
        Real_TTSRadioButton->setText(QApplication::translate("LearnWordConfigDialog", "\347\234\237\344\272\272\350\257\255\351\237\263\351\205\215\345\220\210TTS", 0, QApplication::UnicodeUTF8));
        CircleGroupBox->setTitle(QApplication::translate("LearnWordConfigDialog", "\350\257\255\351\237\263\345\276\252\347\216\257\350\256\276\345\256\232", 0, QApplication::UnicodeUTF8));
        TimeLabel->setText(QApplication::translate("LearnWordConfigDialog", "\345\276\252\347\216\257\346\254\241\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        TimeComboBox->clear();
        TimeComboBox->insertItems(0, QStringList()
         << QApplication::translate("LearnWordConfigDialog", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LearnWordConfigDialog", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LearnWordConfigDialog", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LearnWordConfigDialog", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LearnWordConfigDialog", "5", 0, QApplication::UnicodeUTF8)
        );
        IntervalLabel->setText(QApplication::translate("LearnWordConfigDialog", "\345\276\252\347\216\257\351\227\264\351\232\224\357\274\232", 0, QApplication::UnicodeUTF8));
        IntervalComboBox->clear();
        IntervalComboBox->insertItems(0, QStringList()
         << QApplication::translate("LearnWordConfigDialog", "500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LearnWordConfigDialog", "800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LearnWordConfigDialog", "1000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LearnWordConfigDialog", "1300", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LearnWordConfigDialog", "1600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LearnWordConfigDialog", "2000", 0, QApplication::UnicodeUTF8)
        );
        ConfigTabWidget->setTabText(ConfigTabWidget->indexOf(SoundTab), QApplication::translate("LearnWordConfigDialog", "\350\257\255\351\237\263", 0, QApplication::UnicodeUTF8));
        RememLabel->setText(QApplication::translate("LearnWordConfigDialog", "\350\256\260\345\276\227\357\274\232", 0, QApplication::UnicodeUTF8));
        RememLineEdit->setText(QString());
        ObscureLabel->setText(QApplication::translate("LearnWordConfigDialog", "\346\250\241\347\263\212\357\274\232", 0, QApplication::UnicodeUTF8));
        ObscureLineEdit->setText(QString());
        ForgetLabel->setText(QApplication::translate("LearnWordConfigDialog", "\345\277\230\350\256\260\357\274\232", 0, QApplication::UnicodeUTF8));
        ForgetLineEdit->setText(QString());
        RightLabel->setText(QApplication::translate("LearnWordConfigDialog", "\346\255\243\347\241\256\357\274\232", 0, QApplication::UnicodeUTF8));
        RightLineEdit->setText(QString());
        WrongLabel->setText(QApplication::translate("LearnWordConfigDialog", "\351\224\231\350\257\257\357\274\232", 0, QApplication::UnicodeUTF8));
        WrongLineEdit->setText(QString());
        SoundLabel->setText(QApplication::translate("LearnWordConfigDialog", "\350\257\255\351\237\263\357\274\232", 0, QApplication::UnicodeUTF8));
        SoundLineEdit->setText(QString());
        NextLabel->setText(QApplication::translate("LearnWordConfigDialog", "\344\270\213\344\270\252\357\274\232", 0, QApplication::UnicodeUTF8));
        NextLineEdit->setText(QString());
        ConfigLabel->setText(QApplication::translate("LearnWordConfigDialog", "\351\205\215\347\275\256\357\274\232", 0, QApplication::UnicodeUTF8));
        ConfigLineEdit->setText(QString());
        EditWordLabel->setText(QApplication::translate("LearnWordConfigDialog", "\347\274\226\350\276\221\357\274\232", 0, QApplication::UnicodeUTF8));
        ConfigTabWidget->setTabText(ConfigTabWidget->indexOf(ShortcutsTab), QApplication::translate("LearnWordConfigDialog", "\345\277\253\346\215\267\351\224\256", 0, QApplication::UnicodeUTF8));
        QuitButton->setText(QApplication::translate("LearnWordConfigDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LearnWordConfigDialog: public Ui_LearnWordConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNWORDCONFIGDIALOG_H
