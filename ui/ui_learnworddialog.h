/********************************************************************************
** Form generated from reading UI file 'learnworddialog.ui'
**
** Created: Tue Nov 24 04:05:57 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNWORDDIALOG_H
#define UI_LEARNWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_LearnWordDialog
{
public:
    QAction *action_Query;
    QAction *action_Add2NewWordBook;
    QAction *action_SpeakMethode;
    QAction *action_EndSpeak;
    QAction *action__ChangeSpeakMethode;
    QGridLayout *gridLayout;
    QGroupBox *MainGroupBox;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_9;
    QGroupBox *WordShowGroupBox;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_6;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QPushButton *RememButton;
    QPushButton *NotSureButton;
    QPushButton *ForgetButton;
    QLCDNumber *CountLcdNumber;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_5;
    QLabel *IconLabel;
    QPushButton *SoundButton;
    QPushButton *NextButton;
    QFrame *line_2;
    QLabel *WordShowLabel;
    QFrame *line;
    QGridLayout *gridLayout_7;
    QTabWidget *TabWidget;
    QWidget *ConnectTab;
    QGridLayout *gridLayout_3;
    QTextBrowser *TextBrowser;
    QTextBrowser *OITextBrowser;
    QFrame *line_3;
    QWidget *InternetTab;
    QGridLayout *gridLayout_4;
    QWebView *WebView;
    QProgressBar *progressBar;
    QGroupBox *ConfigGroupBox;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_13;
    QPushButton *ConfigButton;
    QCheckBox *SoundEnableCheckBox;
    QCheckBox *FullCheckBox;
    QFrame *WrongLine;
    QPushButton *RightButton;
    QPushButton *EditWordButton;
    QPushButton *WrongButton;

    void setupUi(QDialog *LearnWordDialog)
    {
        if (LearnWordDialog->objectName().isEmpty())
            LearnWordDialog->setObjectName(QString::fromUtf8("LearnWordDialog"));
        LearnWordDialog->resize(644, 377);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        LearnWordDialog->setWindowIcon(icon);
        action_Query = new QAction(LearnWordDialog);
        action_Query->setObjectName(QString::fromUtf8("action_Query"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix2/rc/Search.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_Query->setIcon(icon1);
        action_Add2NewWordBook = new QAction(LearnWordDialog);
        action_Add2NewWordBook->setObjectName(QString::fromUtf8("action_Add2NewWordBook"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix2/rc/Wait.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_Add2NewWordBook->setIcon(icon2);
        action_SpeakMethode = new QAction(LearnWordDialog);
        action_SpeakMethode->setObjectName(QString::fromUtf8("action_SpeakMethode"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix2/rc/Sound.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_SpeakMethode->setIcon(icon3);
        action_EndSpeak = new QAction(LearnWordDialog);
        action_EndSpeak->setObjectName(QString::fromUtf8("action_EndSpeak"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix2/rc/Sound Off.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_EndSpeak->setIcon(icon4);
        action__ChangeSpeakMethode = new QAction(LearnWordDialog);
        action__ChangeSpeakMethode->setObjectName(QString::fromUtf8("action__ChangeSpeakMethode"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix2/rc/Gear.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action__ChangeSpeakMethode->setIcon(icon5);
        gridLayout = new QGridLayout(LearnWordDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        MainGroupBox = new QGroupBox(LearnWordDialog);
        MainGroupBox->setObjectName(QString::fromUtf8("MainGroupBox"));
        MainGroupBox->setMaximumSize(QSize(900, 500));
        MainGroupBox->setAutoFillBackground(true);
        gridLayout_10 = new QGridLayout(MainGroupBox);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        WordShowGroupBox = new QGroupBox(MainGroupBox);
        WordShowGroupBox->setObjectName(QString::fromUtf8("WordShowGroupBox"));
        gridLayout_8 = new QGridLayout(WordShowGroupBox);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(10);
        gridLayout_6->setVerticalSpacing(6);
        label = new QLabel(WordShowGroupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix2/rc/chronometer.png")));

        gridLayout_6->addWidget(label, 0, 1, 1, 1);

        lcdNumber = new QLCDNumber(WordShowGroupBox);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy1);
        lcdNumber->setLayoutDirection(Qt::LeftToRight);
        lcdNumber->setAutoFillBackground(true);
        lcdNumber->setFrameShape(QFrame::NoFrame);
        lcdNumber->setFrameShadow(QFrame::Sunken);
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setNumDigits(8);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_6->addWidget(lcdNumber, 0, 2, 1, 1);

        RememButton = new QPushButton(WordShowGroupBox);
        RememButton->setObjectName(QString::fromUtf8("RememButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(RememButton->sizePolicy().hasHeightForWidth());
        RememButton->setSizePolicy(sizePolicy2);
        RememButton->setFocusPolicy(Qt::StrongFocus);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/Face Happy.png"), QSize(), QIcon::Normal, QIcon::Off);
        RememButton->setIcon(icon6);

        gridLayout_6->addWidget(RememButton, 0, 4, 1, 1);

        NotSureButton = new QPushButton(WordShowGroupBox);
        NotSureButton->setObjectName(QString::fromUtf8("NotSureButton"));
        sizePolicy2.setHeightForWidth(NotSureButton->sizePolicy().hasHeightForWidth());
        NotSureButton->setSizePolicy(sizePolicy2);
        NotSureButton->setFocusPolicy(Qt::StrongFocus);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/Face.png"), QSize(), QIcon::Normal, QIcon::Off);
        NotSureButton->setIcon(icon7);

        gridLayout_6->addWidget(NotSureButton, 0, 5, 1, 1);

        ForgetButton = new QPushButton(WordShowGroupBox);
        ForgetButton->setObjectName(QString::fromUtf8("ForgetButton"));
        sizePolicy2.setHeightForWidth(ForgetButton->sizePolicy().hasHeightForWidth());
        ForgetButton->setSizePolicy(sizePolicy2);
        ForgetButton->setFocusPolicy(Qt::StrongFocus);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/Face Sad.png"), QSize(), QIcon::Normal, QIcon::Off);
        ForgetButton->setIcon(icon8);

        gridLayout_6->addWidget(ForgetButton, 0, 6, 1, 1);

        CountLcdNumber = new QLCDNumber(WordShowGroupBox);
        CountLcdNumber->setObjectName(QString::fromUtf8("CountLcdNumber"));
        sizePolicy1.setHeightForWidth(CountLcdNumber->sizePolicy().hasHeightForWidth());
        CountLcdNumber->setSizePolicy(sizePolicy1);
        CountLcdNumber->setAutoFillBackground(true);
        CountLcdNumber->setFrameShape(QFrame::NoFrame);
        CountLcdNumber->setFrameShadow(QFrame::Sunken);
        CountLcdNumber->setSmallDecimalPoint(true);
        CountLcdNumber->setNumDigits(4);
        CountLcdNumber->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_6->addWidget(CountLcdNumber, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 0, 1, 1);

        gridLayout_6->setColumnStretch(0, 2);
        gridLayout_6->setColumnStretch(1, 20);
        gridLayout_6->setColumnStretch(2, 10);
        gridLayout_6->setColumnStretch(3, 4);
        gridLayout_6->setColumnStretch(4, 4);
        gridLayout_6->setColumnStretch(5, 4);
        gridLayout_6->setColumnStretch(6, 4);

        gridLayout_8->addLayout(gridLayout_6, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setSizeConstraint(QLayout::SetMinAndMaxSize);
        IconLabel = new QLabel(WordShowGroupBox);
        IconLabel->setObjectName(QString::fromUtf8("IconLabel"));
        IconLabel->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix2/rc/Wordpress.png")));

        gridLayout_5->addWidget(IconLabel, 0, 0, 1, 1);

        SoundButton = new QPushButton(WordShowGroupBox);
        SoundButton->setObjectName(QString::fromUtf8("SoundButton"));
        sizePolicy2.setHeightForWidth(SoundButton->sizePolicy().hasHeightForWidth());
        SoundButton->setSizePolicy(sizePolicy2);
        SoundButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/speaker.png"), QSize(), QIcon::Normal, QIcon::Off);
        SoundButton->setIcon(icon9);
        SoundButton->setIconSize(QSize(32, 32));
        SoundButton->setCheckable(false);
        SoundButton->setDefault(true);
        SoundButton->setFlat(true);

        gridLayout_5->addWidget(SoundButton, 0, 2, 1, 1);

        NextButton = new QPushButton(WordShowGroupBox);
        NextButton->setObjectName(QString::fromUtf8("NextButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(NextButton->sizePolicy().hasHeightForWidth());
        NextButton->setSizePolicy(sizePolicy3);
        NextButton->setFocusPolicy(Qt::StrongFocus);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/go_next.png"), QSize(), QIcon::Normal, QIcon::Off);
        NextButton->setIcon(icon10);
        NextButton->setIconSize(QSize(24, 24));

        gridLayout_5->addWidget(NextButton, 0, 3, 1, 1);

        line_2 = new QFrame(WordShowGroupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_2, 1, 3, 1, 1);

        WordShowLabel = new QLabel(WordShowGroupBox);
        WordShowLabel->setObjectName(QString::fromUtf8("WordShowLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        WordShowLabel->setFont(font);
        WordShowLabel->setContextMenuPolicy(Qt::CustomContextMenu);

        gridLayout_5->addWidget(WordShowLabel, 0, 1, 1, 1);

        line = new QFrame(WordShowGroupBox);
        line->setObjectName(QString::fromUtf8("line"));
        sizePolicy3.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy3);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line, 1, 1, 1, 1);

        gridLayout_5->setColumnStretch(0, 1);
        gridLayout_5->setColumnStretch(1, 20);
        gridLayout_5->setColumnStretch(2, 2);
        gridLayout_5->setColumnStretch(3, 2);

        gridLayout_8->addLayout(gridLayout_5, 0, 0, 1, 1);


        gridLayout_9->addWidget(WordShowGroupBox, 0, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        TabWidget = new QTabWidget(MainGroupBox);
        TabWidget->setObjectName(QString::fromUtf8("TabWidget"));
        TabWidget->setTabPosition(QTabWidget::West);
        TabWidget->setTabShape(QTabWidget::Rounded);
        ConnectTab = new QWidget();
        ConnectTab->setObjectName(QString::fromUtf8("ConnectTab"));
        gridLayout_3 = new QGridLayout(ConnectTab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        TextBrowser = new QTextBrowser(ConnectTab);
        TextBrowser->setObjectName(QString::fromUtf8("TextBrowser"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        TextBrowser->setFont(font1);
        TextBrowser->setContextMenuPolicy(Qt::CustomContextMenu);
        TextBrowser->setAutoFillBackground(true);
        TextBrowser->setFrameShape(QFrame::NoFrame);
        TextBrowser->setFrameShadow(QFrame::Plain);
        TextBrowser->setOpenExternalLinks(true);

        gridLayout_3->addWidget(TextBrowser, 0, 0, 1, 1);

        OITextBrowser = new QTextBrowser(ConnectTab);
        OITextBrowser->setObjectName(QString::fromUtf8("OITextBrowser"));
        OITextBrowser->setFont(font1);
        OITextBrowser->setAutoFillBackground(true);
        OITextBrowser->setFrameShape(QFrame::NoFrame);
        OITextBrowser->setFrameShadow(QFrame::Plain);
        OITextBrowser->setLineWrapMode(QTextEdit::WidgetWidth);
        OITextBrowser->setOpenExternalLinks(true);

        gridLayout_3->addWidget(OITextBrowser, 0, 2, 1, 1);

        line_3 = new QFrame(ConnectTab);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_3, 0, 1, 1, 1);

        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/list.png"), QSize(), QIcon::Normal, QIcon::Off);
        TabWidget->addTab(ConnectTab, icon11, QString());
        InternetTab = new QWidget();
        InternetTab->setObjectName(QString::fromUtf8("InternetTab"));
        gridLayout_4 = new QGridLayout(InternetTab);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        WebView = new QWebView(InternetTab);
        WebView->setObjectName(QString::fromUtf8("WebView"));
        WebView->setFocusPolicy(Qt::NoFocus);
        WebView->setAcceptDrops(false);
        WebView->setAutoFillBackground(true);
        WebView->setUrl(QUrl(QString::fromUtf8("about:blank")));
        WebView->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);

        gridLayout_4->addWidget(WebView, 1, 0, 1, 1);

        progressBar = new QProgressBar(InternetTab);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_4->addWidget(progressBar, 0, 0, 1, 1);

        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/network.png"), QSize(), QIcon::Normal, QIcon::Off);
        TabWidget->addTab(InternetTab, icon12, QString());

        gridLayout_7->addWidget(TabWidget, 0, 0, 1, 1);

        ConfigGroupBox = new QGroupBox(MainGroupBox);
        ConfigGroupBox->setObjectName(QString::fromUtf8("ConfigGroupBox"));
        ConfigGroupBox->setFlat(false);
        ConfigGroupBox->setCheckable(false);
        gridLayout_2 = new QGridLayout(ConfigGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        ConfigButton = new QPushButton(ConfigGroupBox);
        ConfigButton->setObjectName(QString::fromUtf8("ConfigButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(ConfigButton->sizePolicy().hasHeightForWidth());
        ConfigButton->setSizePolicy(sizePolicy4);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/tool2.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConfigButton->setIcon(icon13);

        gridLayout_13->addWidget(ConfigButton, 10, 0, 1, 1);

        SoundEnableCheckBox = new QCheckBox(ConfigGroupBox);
        SoundEnableCheckBox->setObjectName(QString::fromUtf8("SoundEnableCheckBox"));
        SoundEnableCheckBox->setChecked(true);
        SoundEnableCheckBox->setTristate(false);

        gridLayout_13->addWidget(SoundEnableCheckBox, 4, 0, 1, 1);

        FullCheckBox = new QCheckBox(ConfigGroupBox);
        FullCheckBox->setObjectName(QString::fromUtf8("FullCheckBox"));

        gridLayout_13->addWidget(FullCheckBox, 11, 0, 1, 1);

        WrongLine = new QFrame(ConfigGroupBox);
        WrongLine->setObjectName(QString::fromUtf8("WrongLine"));
        WrongLine->setFrameShape(QFrame::HLine);
        WrongLine->setFrameShadow(QFrame::Sunken);

        gridLayout_13->addWidget(WrongLine, 7, 0, 1, 1);

        RightButton = new QPushButton(ConfigGroupBox);
        RightButton->setObjectName(QString::fromUtf8("RightButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(RightButton->sizePolicy().hasHeightForWidth());
        RightButton->setSizePolicy(sizePolicy5);
        RightButton->setFocusPolicy(Qt::StrongFocus);
        RightButton->setIcon(icon6);

        gridLayout_13->addWidget(RightButton, 0, 0, 1, 1);

        EditWordButton = new QPushButton(ConfigGroupBox);
        EditWordButton->setObjectName(QString::fromUtf8("EditWordButton"));
        sizePolicy4.setHeightForWidth(EditWordButton->sizePolicy().hasHeightForWidth());
        EditWordButton->setSizePolicy(sizePolicy4);
        EditWordButton->setFocusPolicy(Qt::StrongFocus);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditWordButton->setIcon(icon14);
        EditWordButton->setFlat(false);

        gridLayout_13->addWidget(EditWordButton, 9, 0, 1, 1);

        WrongButton = new QPushButton(ConfigGroupBox);
        WrongButton->setObjectName(QString::fromUtf8("WrongButton"));
        sizePolicy4.setHeightForWidth(WrongButton->sizePolicy().hasHeightForWidth());
        WrongButton->setSizePolicy(sizePolicy4);
        WrongButton->setFocusPolicy(Qt::StrongFocus);
        WrongButton->setIcon(icon8);

        gridLayout_13->addWidget(WrongButton, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_13, 0, 0, 1, 1);


        gridLayout_7->addWidget(ConfigGroupBox, 0, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_7, 1, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 0, 0, 1, 1);


        gridLayout->addWidget(MainGroupBox, 0, 0, 1, 1);


        retranslateUi(LearnWordDialog);

        TabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LearnWordDialog);
    } // setupUi

    void retranslateUi(QDialog *LearnWordDialog)
    {
        LearnWordDialog->setWindowTitle(QApplication::translate("LearnWordDialog", "  \345\215\225\350\257\215\345\255\246\344\271\240    ", 0, QApplication::UnicodeUTF8));
        action_Query->setText(QApplication::translate("LearnWordDialog", "\346\237\245\350\257\242\350\257\245\345\215\225\350\257\215", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Query->setToolTip(QApplication::translate("LearnWordDialog", "\345\234\250\347\224\265\345\255\220\350\257\215\345\205\270\344\270\255\346\237\245\350\257\242\350\257\245\345\215\225\350\257\215", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Query->setStatusTip(QApplication::translate("LearnWordDialog", "\345\234\250\347\224\265\345\255\220\350\257\215\345\205\270\344\270\255\346\237\245\350\257\242\350\257\245\345\215\225\350\257\215", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        action_Query->setWhatsThis(QApplication::translate("LearnWordDialog", "\345\234\250\347\224\265\345\255\220\350\257\215\345\205\270\344\270\255\346\237\245\350\257\242\350\257\245\345\215\225\350\257\215", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        action_Query->setShortcut(QApplication::translate("LearnWordDialog", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Add2NewWordBook->setText(QApplication::translate("LearnWordDialog", "\346\267\273\345\212\240\345\210\260\347\224\237\350\257\215\346\234\254", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Add2NewWordBook->setToolTip(QApplication::translate("LearnWordDialog", "\346\267\273\345\212\240\345\215\225\350\257\215\345\210\260\347\224\237\350\257\215\346\234\254", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_Add2NewWordBook->setShortcut(QApplication::translate("LearnWordDialog", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        action_SpeakMethode->setText(QApplication::translate("LearnWordDialog", "\344\273\273\346\204\217\345\217\221\351\237\263\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_SpeakMethode->setToolTip(QApplication::translate("LearnWordDialog", "\351\200\211\346\213\251\344\273\273\346\204\217\345\217\221\351\237\263\346\250\241\345\274\217\345\220\254\345\215\225\350\257\215\345\217\221\351\237\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_EndSpeak->setText(QApplication::translate("LearnWordDialog", "\344\270\255\346\226\255\345\217\221\351\237\263", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_EndSpeak->setToolTip(QApplication::translate("LearnWordDialog", "\344\270\255\346\226\255\346\255\244\346\254\241\345\217\221\351\237\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action__ChangeSpeakMethode->setText(QApplication::translate("LearnWordDialog", "\351\200\211\346\213\251\345\217\221\351\237\263\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action__ChangeSpeakMethode->setToolTip(QApplication::translate("LearnWordDialog", "\351\207\215\346\226\260\351\200\211\346\213\251\345\217\221\351\237\263\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        WordShowGroupBox->setTitle(QString());
        label->setText(QString());
        RememButton->setText(QApplication::translate("LearnWordDialog", "\350\256\260\345\276\227", 0, QApplication::UnicodeUTF8));
        NotSureButton->setText(QApplication::translate("LearnWordDialog", "\346\250\241\347\263\212", 0, QApplication::UnicodeUTF8));
        ForgetButton->setText(QApplication::translate("LearnWordDialog", "\345\277\230\350\256\260", 0, QApplication::UnicodeUTF8));
        IconLabel->setText(QString());
        SoundButton->setText(QString());
        NextButton->setText(QApplication::translate("LearnWordDialog", "\344\270\213\344\270\200\344\270\252", 0, QApplication::UnicodeUTF8));
        WordShowLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        TextBrowser->setToolTip(QApplication::translate("LearnWordDialog", "\350\257\215\344\271\211\344\270\216\344\276\213\345\217\245", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        TextBrowser->setStatusTip(QApplication::translate("LearnWordDialog", "\350\257\215\344\271\211\344\270\216\344\276\213\345\217\245", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        TextBrowser->setWhatsThis(QApplication::translate("LearnWordDialog", "\350\257\215\344\271\211\344\270\216\344\276\213\345\217\245", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        TextBrowser->setDocumentTitle(QApplication::translate("LearnWordDialog", "\350\257\215\344\271\211\344\270\216\344\276\213\345\217\245", 0, QApplication::UnicodeUTF8));
        TextBrowser->setHtml(QApplication::translate("LearnWordDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><title>\350\257\215\344\271\211\344\270\216\344\276\213\345\217\245</title><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'ADMUI3Lg'; font-size:9pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        OITextBrowser->setToolTip(QApplication::translate("LearnWordDialog", "\347\233\270\345\205\263\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        OITextBrowser->setStatusTip(QApplication::translate("LearnWordDialog", "\347\233\270\345\205\263\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        OITextBrowser->setWhatsThis(QApplication::translate("LearnWordDialog", "\347\233\270\345\205\263\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        OITextBrowser->setDocumentTitle(QApplication::translate("LearnWordDialog", "\347\233\270\345\205\263\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        TabWidget->setTabText(TabWidget->indexOf(ConnectTab), QApplication::translate("LearnWordDialog", "\347\233\270\345\205\263\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        TabWidget->setTabText(TabWidget->indexOf(InternetTab), QApplication::translate("LearnWordDialog", "\347\275\221\347\273\234\350\257\215\344\271\211", 0, QApplication::UnicodeUTF8));
        ConfigGroupBox->setTitle(QString());
        ConfigButton->setText(QApplication::translate("LearnWordDialog", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        SoundEnableCheckBox->setText(QApplication::translate("LearnWordDialog", "\345\274\200\345\220\257\350\257\255\351\237\263", 0, QApplication::UnicodeUTF8));
        FullCheckBox->setText(QApplication::translate("LearnWordDialog", "\345\205\250\345\261\217\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        RightButton->setText(QApplication::translate("LearnWordDialog", "\346\255\243\347\241\256", 0, QApplication::UnicodeUTF8));
        EditWordButton->setText(QApplication::translate("LearnWordDialog", "\347\274\226\350\276\221", 0, QApplication::UnicodeUTF8));
        WrongButton->setText(QApplication::translate("LearnWordDialog", "\351\224\231\350\257\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LearnWordDialog: public Ui_LearnWordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNWORDDIALOG_H
