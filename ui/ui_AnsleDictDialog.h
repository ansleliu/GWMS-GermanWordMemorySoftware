/********************************************************************************
** Form generated from reading UI file 'AnsleDictDialog.ui'
**
** Created: Tue Nov 24 04:05:57 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANSLEDICTDIALOG_H
#define UI_ANSLEDICTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AnsleDictDialog
{
public:
    QAction *action_AddToNewWord;
    QAction *action_Speak;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QPushButton *ConfigPushButton;
    QPushButton *AddToNewWordPushButton;
    QPushButton *SpeakTTSPushButton;
    QTableView *WordTableView;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *WordLabel;
    QLineEdit *WordLineEdit;
    QComboBox *ExpComboBox;
    QTextBrowser *MeanTextBrowser;

    void setupUi(QDialog *AnsleDictDialog)
    {
        if (AnsleDictDialog->objectName().isEmpty())
            AnsleDictDialog->setObjectName(QString::fromUtf8("AnsleDictDialog"));
        AnsleDictDialog->resize(502, 260);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix2/rc/Wordpress.png"), QSize(), QIcon::Normal, QIcon::Off);
        AnsleDictDialog->setWindowIcon(icon);
        AnsleDictDialog->setAutoFillBackground(true);
        action_AddToNewWord = new QAction(AnsleDictDialog);
        action_AddToNewWord->setObjectName(QString::fromUtf8("action_AddToNewWord"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix2/rc/Wait.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_AddToNewWord->setIcon(icon1);
        action_Speak = new QAction(AnsleDictDialog);
        action_Speak->setObjectName(QString::fromUtf8("action_Speak"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix2/rc/Sound.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_Speak->setIcon(icon2);
        gridLayout_5 = new QGridLayout(AnsleDictDialog);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ConfigPushButton = new QPushButton(AnsleDictDialog);
        ConfigPushButton->setObjectName(QString::fromUtf8("ConfigPushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConfigPushButton->sizePolicy().hasHeightForWidth());
        ConfigPushButton->setSizePolicy(sizePolicy);
        ConfigPushButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix2/rc/Gear.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ConfigPushButton->setIcon(icon3);
        ConfigPushButton->setIconSize(QSize(24, 16));
        ConfigPushButton->setFlat(true);

        gridLayout_2->addWidget(ConfigPushButton, 0, 0, 1, 1);

        AddToNewWordPushButton = new QPushButton(AnsleDictDialog);
        AddToNewWordPushButton->setObjectName(QString::fromUtf8("AddToNewWordPushButton"));
        sizePolicy.setHeightForWidth(AddToNewWordPushButton->sizePolicy().hasHeightForWidth());
        AddToNewWordPushButton->setSizePolicy(sizePolicy);
        AddToNewWordPushButton->setFocusPolicy(Qt::NoFocus);
        AddToNewWordPushButton->setIcon(icon1);
        AddToNewWordPushButton->setFlat(true);

        gridLayout_2->addWidget(AddToNewWordPushButton, 0, 1, 1, 1);

        SpeakTTSPushButton = new QPushButton(AnsleDictDialog);
        SpeakTTSPushButton->setObjectName(QString::fromUtf8("SpeakTTSPushButton"));
        sizePolicy.setHeightForWidth(SpeakTTSPushButton->sizePolicy().hasHeightForWidth());
        SpeakTTSPushButton->setSizePolicy(sizePolicy);
        SpeakTTSPushButton->setFocusPolicy(Qt::NoFocus);
        SpeakTTSPushButton->setIcon(icon2);
        SpeakTTSPushButton->setDefault(false);
        SpeakTTSPushButton->setFlat(true);

        gridLayout_2->addWidget(SpeakTTSPushButton, 0, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        WordTableView = new QTableView(AnsleDictDialog);
        WordTableView->setObjectName(QString::fromUtf8("WordTableView"));
        WordTableView->setMinimumSize(QSize(60, 0));
        WordTableView->setFocusPolicy(Qt::TabFocus);
        WordTableView->setContextMenuPolicy(Qt::CustomContextMenu);
        WordTableView->setAutoFillBackground(true);
        WordTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        WordTableView->setAlternatingRowColors(true);
        WordTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        WordTableView->horizontalHeader()->setCascadingSectionResizes(true);
        WordTableView->horizontalHeader()->setStretchLastSection(true);
        WordTableView->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(WordTableView, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        WordLabel = new QLabel(AnsleDictDialog);
        WordLabel->setObjectName(QString::fromUtf8("WordLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(WordLabel->sizePolicy().hasHeightForWidth());
        WordLabel->setSizePolicy(sizePolicy1);
        WordLabel->setMaximumSize(QSize(24, 24));
        WordLabel->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix2/rc/Wordpress.png")));
        WordLabel->setScaledContents(true);

        horizontalLayout_2->addWidget(WordLabel);

        WordLineEdit = new QLineEdit(AnsleDictDialog);
        WordLineEdit->setObjectName(QString::fromUtf8("WordLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(WordLineEdit->sizePolicy().hasHeightForWidth());
        WordLineEdit->setSizePolicy(sizePolicy2);
        WordLineEdit->setMouseTracking(true);
        WordLineEdit->setFocusPolicy(Qt::NoFocus);
        WordLineEdit->setContextMenuPolicy(Qt::CustomContextMenu);
        WordLineEdit->setAcceptDrops(false);

        horizontalLayout_2->addWidget(WordLineEdit);

        ExpComboBox = new QComboBox(AnsleDictDialog);
        ExpComboBox->setObjectName(QString::fromUtf8("ExpComboBox"));
        sizePolicy.setHeightForWidth(ExpComboBox->sizePolicy().hasHeightForWidth());
        ExpComboBox->setSizePolicy(sizePolicy);
        ExpComboBox->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(ExpComboBox);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        MeanTextBrowser = new QTextBrowser(AnsleDictDialog);
        MeanTextBrowser->setObjectName(QString::fromUtf8("MeanTextBrowser"));
        MeanTextBrowser->setFocusPolicy(Qt::NoFocus);
        MeanTextBrowser->setContextMenuPolicy(Qt::CustomContextMenu);
        MeanTextBrowser->setAutoFillBackground(true);
        MeanTextBrowser->setFrameShape(QFrame::StyledPanel);
        MeanTextBrowser->setFrameShadow(QFrame::Plain);

        gridLayout_3->addWidget(MeanTextBrowser, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 1, 1, 1);

        gridLayout_4->setColumnStretch(0, 2);
        gridLayout_4->setColumnStretch(1, 5);

        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);


        retranslateUi(AnsleDictDialog);

        QMetaObject::connectSlotsByName(AnsleDictDialog);
    } // setupUi

    void retranslateUi(QDialog *AnsleDictDialog)
    {
        AnsleDictDialog->setWindowTitle(QApplication::translate("AnsleDictDialog", "MiniAnsleDict", 0, QApplication::UnicodeUTF8));
        action_AddToNewWord->setText(QApplication::translate("AnsleDictDialog", "\346\267\273\345\212\240\345\210\260\347\224\237\350\257\215\346\234\254", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_AddToNewWord->setToolTip(QApplication::translate("AnsleDictDialog", "\346\267\273\345\212\240\345\210\260\347\224\237\350\257\215\346\234\254", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_Speak->setText(QApplication::translate("AnsleDictDialog", "\345\217\221\351\237\263", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Speak->setToolTip(QApplication::translate("AnsleDictDialog", "\345\215\225\350\257\215\345\217\221\351\237\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        ConfigPushButton->setToolTip(QApplication::translate("AnsleDictDialog", "\351\205\215\347\275\256\345\217\221\351\237\263\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        ConfigPushButton->setStatusTip(QApplication::translate("AnsleDictDialog", "\351\205\215\347\275\256\345\217\221\351\237\263\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        ConfigPushButton->setWhatsThis(QApplication::translate("AnsleDictDialog", "\351\205\215\347\275\256\345\217\221\351\237\263\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        ConfigPushButton->setAccessibleDescription(QApplication::translate("AnsleDictDialog", "\351\205\215\347\275\256\345\217\221\351\237\263\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        ConfigPushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        AddToNewWordPushButton->setToolTip(QApplication::translate("AnsleDictDialog", "\345\212\240\345\205\245\347\224\237\350\257\215\346\234\254", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        AddToNewWordPushButton->setStatusTip(QApplication::translate("AnsleDictDialog", "\345\212\240\345\205\245\347\224\237\350\257\215\346\234\254", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        AddToNewWordPushButton->setWhatsThis(QApplication::translate("AnsleDictDialog", "\345\212\240\345\205\245\347\224\237\350\257\215\346\234\254", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        AddToNewWordPushButton->setAccessibleDescription(QApplication::translate("AnsleDictDialog", "\345\212\240\345\205\245\347\224\237\350\257\215\346\234\254", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        AddToNewWordPushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        SpeakTTSPushButton->setToolTip(QApplication::translate("AnsleDictDialog", "\345\217\221\351\237\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        SpeakTTSPushButton->setStatusTip(QApplication::translate("AnsleDictDialog", "\345\217\221\351\237\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        SpeakTTSPushButton->setWhatsThis(QApplication::translate("AnsleDictDialog", "\345\217\221\351\237\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        SpeakTTSPushButton->setAccessibleDescription(QApplication::translate("AnsleDictDialog", "\345\217\221\351\237\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        SpeakTTSPushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        WordTableView->setToolTip(QApplication::translate("AnsleDictDialog", "\345\215\225\350\257\215\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        WordTableView->setStatusTip(QApplication::translate("AnsleDictDialog", "\345\215\225\350\257\215\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        WordTableView->setWhatsThis(QApplication::translate("AnsleDictDialog", "\345\215\225\350\257\215\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        WordLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        WordLineEdit->setToolTip(QApplication::translate("AnsleDictDialog", "\350\276\223\345\205\245\351\234\200\350\246\201\346\237\245\350\257\242\347\232\204\345\215\225\350\257\215", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        WordLineEdit->setStatusTip(QApplication::translate("AnsleDictDialog", "\350\276\223\345\205\245\351\234\200\350\246\201\346\237\245\350\257\242\347\232\204\345\215\225\350\257\215", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        WordLineEdit->setWhatsThis(QApplication::translate("AnsleDictDialog", "\350\276\223\345\205\245\351\234\200\350\246\201\346\237\245\350\257\242\347\232\204\345\215\225\350\257\215", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        ExpComboBox->clear();
        ExpComboBox->insertItems(0, QStringList()
         << QApplication::translate("AnsleDictDialog", "\345\244\264\345\214\271\351\205\215", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AnsleDictDialog", "\344\270\255\345\214\271\351\205\215", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AnsleDictDialog", "\345\260\276\345\214\271\351\205\215", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        ExpComboBox->setToolTip(QApplication::translate("AnsleDictDialog", "\351\200\211\346\213\251\345\214\271\351\205\215\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        ExpComboBox->setStatusTip(QApplication::translate("AnsleDictDialog", "\351\200\211\346\213\251\345\214\271\351\205\215\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        ExpComboBox->setWhatsThis(QApplication::translate("AnsleDictDialog", "\351\200\211\346\213\251\345\214\271\351\205\215\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        MeanTextBrowser->setToolTip(QApplication::translate("AnsleDictDialog", "\345\215\225\350\257\215\350\257\215\344\271\211", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        MeanTextBrowser->setStatusTip(QApplication::translate("AnsleDictDialog", "\345\215\225\350\257\215\350\257\215\344\271\211", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        MeanTextBrowser->setWhatsThis(QApplication::translate("AnsleDictDialog", "\345\215\225\350\257\215\350\257\215\344\271\211", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class AnsleDictDialog: public Ui_AnsleDictDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANSLEDICTDIALOG_H
