/********************************************************************************
** Form generated from reading UI file 'optionsdialog.ui'
**
** Created: Tue Nov 24 04:05:57 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSDIALOG_H
#define UI_OPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionsDialog
{
public:
    QListWidget *listWidget;
    QTabWidget *tabWidget;
    QWidget *userTab;
    QLabel *CurrUserLabel;
    QLineEdit *userLineEdit;
    QPushButton *reviseKeyButton;
    QCheckBox *rememKeyCheckBox;
    QCheckBox *autoLoginCheckBox;
    QLabel *creatlabel;
    QLineEdit *creatLineEdit;
    QLabel *lastlabel;
    QLineEdit *lastLineEdit;
    QLabel *infolabel;
    QPushButton *forgetKeyButton;
    QLabel *icolabel;
    QWidget *bookTab;
    QPushButton *addButton;
    QPushButton *removeButton;
    QLabel *booklabel;
    QTableView *bookTableView;
    QWidget *widget;
    QWidget *studyTab;
    QTableView *studyRecordTableView;
    QLabel *label;
    QPushButton *deleteRecordButton;
    QLineEdit *SearchLineEdit;
    QPushButton *ShowAllPushButton;
    QWidget *configTab;
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
    QGroupBox *SoundParameterGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *SoundSpeedLabel;
    QSlider *SSpeedSlider;
    QLabel *SVolumeLabel;
    QSlider *SVolumeSlider;
    QLabel *SPitchLabel;
    QSlider *SPitchSlider;
    QLabel *GapLabel;
    QSlider *GapSlider;
    QLabel *TestSoundLabel;
    QLineEdit *TestSoundLineEdit;
    QPushButton *TestSondButton;
    QLabel *PRangeLabel;
    QSlider *PRangeSlider;
    QPushButton *BackToSysButton;
    QGroupBox *CircleGroupBox;
    QGridLayout *gridLayout;
    QCheckBox *SoundCheckBox;
    QRadioButton *TTSRadioButton;
    QRadioButton *OnlineRadioButton;
    QRadioButton *Real_TTSRadioButton;
    QLabel *TimeLabel;
    QComboBox *TimeComboBox;
    QLabel *IntervalLabel;
    QComboBox *IntervalComboBox;
    QComboBox *TTSComboBox;
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
    QPushButton *quitButton;
    QPushButton *applyButton;

    void setupUi(QDialog *OptionsDialog)
    {
        if (OptionsDialog->objectName().isEmpty())
            OptionsDialog->setObjectName(QString::fromUtf8("OptionsDialog"));
        OptionsDialog->resize(602, 361);
        OptionsDialog->setMinimumSize(QSize(602, 361));
        OptionsDialog->setMaximumSize(QSize(602, 361));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/gear.png"), QSize(), QIcon::Normal, QIcon::Off);
        OptionsDialog->setWindowIcon(icon);
        listWidget = new QListWidget(OptionsDialog);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix2/rc/loginuser.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix2/rc/kontact.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/history.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/tool2.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setIcon(icon4);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 71, 311));
        listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        listWidget->setTextElideMode(Qt::ElideMiddle);
        listWidget->setMovement(QListView::Static);
        listWidget->setFlow(QListView::TopToBottom);
        listWidget->setResizeMode(QListView::Fixed);
        listWidget->setLayoutMode(QListView::SinglePass);
        listWidget->setSpacing(5);
        listWidget->setViewMode(QListView::IconMode);
        listWidget->setModelColumn(0);
        listWidget->setUniformItemSizes(true);
        listWidget->setWordWrap(false);
        tabWidget = new QTabWidget(OptionsDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(90, 10, 501, 311));
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setIconSize(QSize(32, 32));
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        userTab = new QWidget();
        userTab->setObjectName(QString::fromUtf8("userTab"));
        CurrUserLabel = new QLabel(userTab);
        CurrUserLabel->setObjectName(QString::fromUtf8("CurrUserLabel"));
        CurrUserLabel->setGeometry(QRect(30, 30, 54, 21));
        userLineEdit = new QLineEdit(userTab);
        userLineEdit->setObjectName(QString::fromUtf8("userLineEdit"));
        userLineEdit->setGeometry(QRect(90, 30, 181, 21));
        userLineEdit->setReadOnly(true);
        reviseKeyButton = new QPushButton(userTab);
        reviseKeyButton->setObjectName(QString::fromUtf8("reviseKeyButton"));
        reviseKeyButton->setGeometry(QRect(280, 30, 81, 21));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/kgpg_sign_kgpg.png"), QSize(), QIcon::Normal, QIcon::Off);
        reviseKeyButton->setIcon(icon5);
        rememKeyCheckBox = new QCheckBox(userTab);
        rememKeyCheckBox->setObjectName(QString::fromUtf8("rememKeyCheckBox"));
        rememKeyCheckBox->setGeometry(QRect(90, 140, 71, 21));
        autoLoginCheckBox = new QCheckBox(userTab);
        autoLoginCheckBox->setObjectName(QString::fromUtf8("autoLoginCheckBox"));
        autoLoginCheckBox->setGeometry(QRect(200, 140, 71, 21));
        creatlabel = new QLabel(userTab);
        creatlabel->setObjectName(QString::fromUtf8("creatlabel"));
        creatlabel->setGeometry(QRect(30, 70, 54, 21));
        creatLineEdit = new QLineEdit(userTab);
        creatLineEdit->setObjectName(QString::fromUtf8("creatLineEdit"));
        creatLineEdit->setGeometry(QRect(90, 70, 181, 21));
        creatLineEdit->setReadOnly(true);
        lastlabel = new QLabel(userTab);
        lastlabel->setObjectName(QString::fromUtf8("lastlabel"));
        lastlabel->setGeometry(QRect(30, 110, 54, 21));
        lastLineEdit = new QLineEdit(userTab);
        lastLineEdit->setObjectName(QString::fromUtf8("lastLineEdit"));
        lastLineEdit->setGeometry(QRect(90, 110, 181, 21));
        lastLineEdit->setReadOnly(true);
        infolabel = new QLabel(userTab);
        infolabel->setObjectName(QString::fromUtf8("infolabel"));
        infolabel->setGeometry(QRect(30, 170, 331, 31));
        forgetKeyButton = new QPushButton(userTab);
        forgetKeyButton->setObjectName(QString::fromUtf8("forgetKeyButton"));
        forgetKeyButton->setGeometry(QRect(280, 70, 81, 21));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/kgpg_info_kgpg.png"), QSize(), QIcon::Normal, QIcon::Off);
        forgetKeyButton->setIcon(icon6);
        icolabel = new QLabel(userTab);
        icolabel->setObjectName(QString::fromUtf8("icolabel"));
        icolabel->setGeometry(QRect(390, 170, 81, 71));
        icolabel->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/rc/actions/user_properties.png")));
        icolabel->setScaledContents(true);
        tabWidget->addTab(userTab, icon1, QString());
        bookTab = new QWidget();
        bookTab->setObjectName(QString::fromUtf8("bookTab"));
        addButton = new QPushButton(bookTab);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(410, 10, 81, 31));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon7);
        removeButton = new QPushButton(bookTab);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setGeometry(QRect(410, 50, 81, 31));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeButton->setIcon(icon8);
        booklabel = new QLabel(bookTab);
        booklabel->setObjectName(QString::fromUtf8("booklabel"));
        booklabel->setGeometry(QRect(410, 180, 81, 81));
        booklabel->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/rc/actions/sayabout.png")));
        booklabel->setScaledContents(true);
        bookTableView = new QTableView(bookTab);
        bookTableView->setObjectName(QString::fromUtf8("bookTableView"));
        bookTableView->setGeometry(QRect(10, 10, 391, 251));
        bookTableView->setFocusPolicy(Qt::NoFocus);
        bookTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        bookTableView->setAlternatingRowColors(true);
        bookTableView->setSelectionMode(QAbstractItemView::NoSelection);
        bookTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        widget = new QWidget(bookTab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-1, -1, 501, 271));
        tabWidget->addTab(bookTab, icon2, QString());
        widget->raise();
        addButton->raise();
        removeButton->raise();
        booklabel->raise();
        bookTableView->raise();
        studyTab = new QWidget();
        studyTab->setObjectName(QString::fromUtf8("studyTab"));
        studyRecordTableView = new QTableView(studyTab);
        studyRecordTableView->setObjectName(QString::fromUtf8("studyRecordTableView"));
        studyRecordTableView->setGeometry(QRect(10, 40, 481, 221));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        studyRecordTableView->setPalette(palette);
        studyRecordTableView->setFocusPolicy(Qt::NoFocus);
        studyRecordTableView->setAlternatingRowColors(true);
        studyRecordTableView->setSelectionMode(QAbstractItemView::NoSelection);
        studyRecordTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        label = new QLabel(studyTab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 11, 51, 20));
        deleteRecordButton = new QPushButton(studyTab);
        deleteRecordButton->setObjectName(QString::fromUtf8("deleteRecordButton"));
        deleteRecordButton->setGeometry(QRect(420, 10, 71, 21));
        deleteRecordButton->setIcon(icon8);
        SearchLineEdit = new QLineEdit(studyTab);
        SearchLineEdit->setObjectName(QString::fromUtf8("SearchLineEdit"));
        SearchLineEdit->setGeometry(QRect(90, 10, 231, 21));
        ShowAllPushButton = new QPushButton(studyTab);
        ShowAllPushButton->setObjectName(QString::fromUtf8("ShowAllPushButton"));
        ShowAllPushButton->setGeometry(QRect(330, 10, 81, 21));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ShowAllPushButton->sizePolicy().hasHeightForWidth());
        ShowAllPushButton->setSizePolicy(sizePolicy);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/sayabout.png"), QSize(), QIcon::Normal, QIcon::Off);
        ShowAllPushButton->setIcon(icon9);
        tabWidget->addTab(studyTab, icon3, QString());
        configTab = new QWidget();
        configTab->setObjectName(QString::fromUtf8("configTab"));
        ConfigTabWidget = new QTabWidget(configTab);
        ConfigTabWidget->setObjectName(QString::fromUtf8("ConfigTabWidget"));
        ConfigTabWidget->setGeometry(QRect(10, 10, 481, 251));
        ConfigTabWidget->setFocusPolicy(Qt::NoFocus);
        ConfigTabWidget->setTabPosition(QTabWidget::East);
        ConfigTabWidget->setTabShape(QTabWidget::Rounded);
        ConfigTabWidget->setIconSize(QSize(19, 24));
        ConfigTabWidget->setElideMode(Qt::ElideMiddle);
        LearnTab = new QWidget();
        LearnTab->setObjectName(QString::fromUtf8("LearnTab"));
        LearnMethodGroupBox = new QGroupBox(LearnTab);
        LearnMethodGroupBox->setObjectName(QString::fromUtf8("LearnMethodGroupBox"));
        LearnMethodGroupBox->setGeometry(QRect(20, 20, 131, 211));
        LearnMethodComboBox = new QComboBox(LearnMethodGroupBox);
        LearnMethodComboBox->setObjectName(QString::fromUtf8("LearnMethodComboBox"));
        LearnMethodComboBox->setGeometry(QRect(10, 80, 91, 22));
        LearnLabel = new QLabel(LearnMethodGroupBox);
        LearnLabel->setObjectName(QString::fromUtf8("LearnLabel"));
        LearnLabel->setGeometry(QRect(10, 50, 81, 16));
        OutGroupBox = new QGroupBox(LearnTab);
        OutGroupBox->setObjectName(QString::fromUtf8("OutGroupBox"));
        OutGroupBox->setGeometry(QRect(160, 20, 271, 91));
        OutOrderlyRadioButton = new QRadioButton(OutGroupBox);
        OutOrderlyRadioButton->setObjectName(QString::fromUtf8("OutOrderlyRadioButton"));
        OutOrderlyRadioButton->setGeometry(QRect(50, 30, 51, 31));
        OutRandomRadioButton = new QRadioButton(OutGroupBox);
        OutRandomRadioButton->setObjectName(QString::fromUtf8("OutRandomRadioButton"));
        OutRandomRadioButton->setGeometry(QRect(140, 30, 51, 31));
        OutRandomRadioButton->setChecked(true);
        ReviewGroupBox = new QGroupBox(LearnTab);
        ReviewGroupBox->setObjectName(QString::fromUtf8("ReviewGroupBox"));
        ReviewGroupBox->setGeometry(QRect(160, 120, 271, 111));
        ReviewOrderlyRadioButton = new QRadioButton(ReviewGroupBox);
        ReviewOrderlyRadioButton->setObjectName(QString::fromUtf8("ReviewOrderlyRadioButton"));
        ReviewOrderlyRadioButton->setGeometry(QRect(50, 40, 51, 31));
        ReviewRandomRadioButton = new QRadioButton(ReviewGroupBox);
        ReviewRandomRadioButton->setObjectName(QString::fromUtf8("ReviewRandomRadioButton"));
        ReviewRandomRadioButton->setGeometry(QRect(140, 40, 51, 31));
        ReviewRandomRadioButton->setChecked(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/configure_shortcuts.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConfigTabWidget->addTab(LearnTab, icon10, QString());
        SoundTab = new QWidget();
        SoundTab->setObjectName(QString::fromUtf8("SoundTab"));
        gridLayout_3 = new QGridLayout(SoundTab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        SoundParameterGroupBox = new QGroupBox(SoundTab);
        SoundParameterGroupBox->setObjectName(QString::fromUtf8("SoundParameterGroupBox"));
        gridLayout_2 = new QGridLayout(SoundParameterGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        SoundSpeedLabel = new QLabel(SoundParameterGroupBox);
        SoundSpeedLabel->setObjectName(QString::fromUtf8("SoundSpeedLabel"));

        gridLayout_2->addWidget(SoundSpeedLabel, 0, 0, 1, 1);

        SSpeedSlider = new QSlider(SoundParameterGroupBox);
        SSpeedSlider->setObjectName(QString::fromUtf8("SSpeedSlider"));
        SSpeedSlider->setMinimum(80);
        SSpeedSlider->setMaximum(450);
        SSpeedSlider->setValue(180);
        SSpeedSlider->setOrientation(Qt::Horizontal);
        SSpeedSlider->setInvertedAppearance(false);
        SSpeedSlider->setInvertedControls(false);
        SSpeedSlider->setTickPosition(QSlider::NoTicks);

        gridLayout_2->addWidget(SSpeedSlider, 0, 1, 1, 2);

        SVolumeLabel = new QLabel(SoundParameterGroupBox);
        SVolumeLabel->setObjectName(QString::fromUtf8("SVolumeLabel"));
        SVolumeLabel->setFrameShape(QFrame::NoFrame);

        gridLayout_2->addWidget(SVolumeLabel, 1, 0, 1, 1);

        SVolumeSlider = new QSlider(SoundParameterGroupBox);
        SVolumeSlider->setObjectName(QString::fromUtf8("SVolumeSlider"));
        SVolumeSlider->setMaximum(200);
        SVolumeSlider->setValue(100);
        SVolumeSlider->setOrientation(Qt::Horizontal);
        SVolumeSlider->setTickPosition(QSlider::NoTicks);
        SVolumeSlider->setTickInterval(0);

        gridLayout_2->addWidget(SVolumeSlider, 1, 1, 1, 2);

        SPitchLabel = new QLabel(SoundParameterGroupBox);
        SPitchLabel->setObjectName(QString::fromUtf8("SPitchLabel"));

        gridLayout_2->addWidget(SPitchLabel, 2, 0, 1, 1);

        SPitchSlider = new QSlider(SoundParameterGroupBox);
        SPitchSlider->setObjectName(QString::fromUtf8("SPitchSlider"));
        SPitchSlider->setMaximum(100);
        SPitchSlider->setValue(50);
        SPitchSlider->setOrientation(Qt::Horizontal);
        SPitchSlider->setTickPosition(QSlider::NoTicks);

        gridLayout_2->addWidget(SPitchSlider, 2, 1, 1, 2);

        GapLabel = new QLabel(SoundParameterGroupBox);
        GapLabel->setObjectName(QString::fromUtf8("GapLabel"));

        gridLayout_2->addWidget(GapLabel, 4, 0, 1, 1);

        GapSlider = new QSlider(SoundParameterGroupBox);
        GapSlider->setObjectName(QString::fromUtf8("GapSlider"));
        GapSlider->setMinimum(1);
        GapSlider->setMaximum(100);
        GapSlider->setValue(1);
        GapSlider->setOrientation(Qt::Horizontal);
        GapSlider->setTickPosition(QSlider::NoTicks);

        gridLayout_2->addWidget(GapSlider, 4, 1, 1, 2);

        TestSoundLabel = new QLabel(SoundParameterGroupBox);
        TestSoundLabel->setObjectName(QString::fromUtf8("TestSoundLabel"));

        gridLayout_2->addWidget(TestSoundLabel, 5, 0, 1, 1);

        TestSoundLineEdit = new QLineEdit(SoundParameterGroupBox);
        TestSoundLineEdit->setObjectName(QString::fromUtf8("TestSoundLineEdit"));

        gridLayout_2->addWidget(TestSoundLineEdit, 5, 1, 1, 1);

        TestSondButton = new QPushButton(SoundParameterGroupBox);
        TestSondButton->setObjectName(QString::fromUtf8("TestSondButton"));
        TestSondButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        TestSondButton->setIcon(icon11);

        gridLayout_2->addWidget(TestSondButton, 5, 2, 1, 1);

        PRangeLabel = new QLabel(SoundParameterGroupBox);
        PRangeLabel->setObjectName(QString::fromUtf8("PRangeLabel"));

        gridLayout_2->addWidget(PRangeLabel, 3, 0, 1, 1);

        PRangeSlider = new QSlider(SoundParameterGroupBox);
        PRangeSlider->setObjectName(QString::fromUtf8("PRangeSlider"));
        PRangeSlider->setMaximum(100);
        PRangeSlider->setValue(50);
        PRangeSlider->setOrientation(Qt::Horizontal);
        PRangeSlider->setTickPosition(QSlider::NoTicks);

        gridLayout_2->addWidget(PRangeSlider, 3, 1, 1, 2);

        BackToSysButton = new QPushButton(SoundParameterGroupBox);
        BackToSysButton->setObjectName(QString::fromUtf8("BackToSysButton"));
        sizePolicy.setHeightForWidth(BackToSysButton->sizePolicy().hasHeightForWidth());
        BackToSysButton->setSizePolicy(sizePolicy);
        BackToSysButton->setMaximumSize(QSize(200, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("ADMUI3Lg"));
        font.setUnderline(false);
        BackToSysButton->setFont(font);
        BackToSysButton->setDefault(false);
        BackToSysButton->setFlat(false);

        gridLayout_2->addWidget(BackToSysButton, 6, 1, 1, 1);


        gridLayout_3->addWidget(SoundParameterGroupBox, 0, 1, 1, 1);

        CircleGroupBox = new QGroupBox(SoundTab);
        CircleGroupBox->setObjectName(QString::fromUtf8("CircleGroupBox"));
        CircleGroupBox->setFlat(false);
        gridLayout = new QGridLayout(CircleGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        SoundCheckBox = new QCheckBox(CircleGroupBox);
        SoundCheckBox->setObjectName(QString::fromUtf8("SoundCheckBox"));
        SoundCheckBox->setChecked(true);

        gridLayout->addWidget(SoundCheckBox, 0, 0, 1, 2);

        TTSRadioButton = new QRadioButton(CircleGroupBox);
        TTSRadioButton->setObjectName(QString::fromUtf8("TTSRadioButton"));

        gridLayout->addWidget(TTSRadioButton, 1, 0, 1, 2);

        OnlineRadioButton = new QRadioButton(CircleGroupBox);
        OnlineRadioButton->setObjectName(QString::fromUtf8("OnlineRadioButton"));

        gridLayout->addWidget(OnlineRadioButton, 2, 0, 1, 2);

        Real_TTSRadioButton = new QRadioButton(CircleGroupBox);
        Real_TTSRadioButton->setObjectName(QString::fromUtf8("Real_TTSRadioButton"));
        Real_TTSRadioButton->setCheckable(true);

        gridLayout->addWidget(Real_TTSRadioButton, 3, 0, 1, 2);

        TimeLabel = new QLabel(CircleGroupBox);
        TimeLabel->setObjectName(QString::fromUtf8("TimeLabel"));

        gridLayout->addWidget(TimeLabel, 5, 0, 1, 1);

        TimeComboBox = new QComboBox(CircleGroupBox);
        TimeComboBox->setObjectName(QString::fromUtf8("TimeComboBox"));

        gridLayout->addWidget(TimeComboBox, 5, 1, 1, 1);

        IntervalLabel = new QLabel(CircleGroupBox);
        IntervalLabel->setObjectName(QString::fromUtf8("IntervalLabel"));

        gridLayout->addWidget(IntervalLabel, 6, 0, 1, 1);

        IntervalComboBox = new QComboBox(CircleGroupBox);
        IntervalComboBox->setObjectName(QString::fromUtf8("IntervalComboBox"));

        gridLayout->addWidget(IntervalComboBox, 6, 1, 1, 1);

        TTSComboBox = new QComboBox(CircleGroupBox);
        TTSComboBox->setObjectName(QString::fromUtf8("TTSComboBox"));

        gridLayout->addWidget(TTSComboBox, 4, 0, 1, 2);


        gridLayout_3->addWidget(CircleGroupBox, 0, 0, 1, 1);

        gridLayout_3->setColumnStretch(0, 3);
        gridLayout_3->setColumnStretch(1, 5);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/speaker.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConfigTabWidget->addTab(SoundTab, icon12, QString());
        ShortcutsTab = new QWidget();
        ShortcutsTab->setObjectName(QString::fromUtf8("ShortcutsTab"));
        RememLabel = new QLabel(ShortcutsTab);
        RememLabel->setObjectName(QString::fromUtf8("RememLabel"));
        RememLabel->setGeometry(QRect(30, 40, 31, 20));
        RememLineEdit = new QLineEdit(ShortcutsTab);
        RememLineEdit->setObjectName(QString::fromUtf8("RememLineEdit"));
        RememLineEdit->setGeometry(QRect(70, 40, 31, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        RememLineEdit->setFont(font1);
        ObscureLabel = new QLabel(ShortcutsTab);
        ObscureLabel->setObjectName(QString::fromUtf8("ObscureLabel"));
        ObscureLabel->setGeometry(QRect(180, 40, 31, 20));
        ObscureLineEdit = new QLineEdit(ShortcutsTab);
        ObscureLineEdit->setObjectName(QString::fromUtf8("ObscureLineEdit"));
        ObscureLineEdit->setGeometry(QRect(220, 40, 31, 20));
        ObscureLineEdit->setFont(font1);
        ForgetLabel = new QLabel(ShortcutsTab);
        ForgetLabel->setObjectName(QString::fromUtf8("ForgetLabel"));
        ForgetLabel->setGeometry(QRect(310, 40, 31, 20));
        ForgetLineEdit = new QLineEdit(ShortcutsTab);
        ForgetLineEdit->setObjectName(QString::fromUtf8("ForgetLineEdit"));
        ForgetLineEdit->setGeometry(QRect(350, 40, 31, 20));
        ForgetLineEdit->setFont(font1);
        RightLabel = new QLabel(ShortcutsTab);
        RightLabel->setObjectName(QString::fromUtf8("RightLabel"));
        RightLabel->setGeometry(QRect(30, 101, 31, 20));
        RightLineEdit = new QLineEdit(ShortcutsTab);
        RightLineEdit->setObjectName(QString::fromUtf8("RightLineEdit"));
        RightLineEdit->setGeometry(QRect(70, 100, 31, 20));
        RightLineEdit->setFont(font1);
        WrongLabel = new QLabel(ShortcutsTab);
        WrongLabel->setObjectName(QString::fromUtf8("WrongLabel"));
        WrongLabel->setGeometry(QRect(180, 101, 31, 20));
        WrongLineEdit = new QLineEdit(ShortcutsTab);
        WrongLineEdit->setObjectName(QString::fromUtf8("WrongLineEdit"));
        WrongLineEdit->setGeometry(QRect(220, 100, 31, 20));
        WrongLineEdit->setFont(font1);
        SoundLabel = new QLabel(ShortcutsTab);
        SoundLabel->setObjectName(QString::fromUtf8("SoundLabel"));
        SoundLabel->setGeometry(QRect(30, 161, 31, 20));
        SoundLineEdit = new QLineEdit(ShortcutsTab);
        SoundLineEdit->setObjectName(QString::fromUtf8("SoundLineEdit"));
        SoundLineEdit->setGeometry(QRect(70, 160, 31, 20));
        SoundLineEdit->setFont(font1);
        NextLabel = new QLabel(ShortcutsTab);
        NextLabel->setObjectName(QString::fromUtf8("NextLabel"));
        NextLabel->setGeometry(QRect(180, 160, 31, 21));
        NextLineEdit = new QLineEdit(ShortcutsTab);
        NextLineEdit->setObjectName(QString::fromUtf8("NextLineEdit"));
        NextLineEdit->setGeometry(QRect(220, 160, 31, 20));
        NextLineEdit->setFont(font1);
        ConfigLabel = new QLabel(ShortcutsTab);
        ConfigLabel->setObjectName(QString::fromUtf8("ConfigLabel"));
        ConfigLabel->setGeometry(QRect(310, 160, 31, 21));
        ConfigLineEdit = new QLineEdit(ShortcutsTab);
        ConfigLineEdit->setObjectName(QString::fromUtf8("ConfigLineEdit"));
        ConfigLineEdit->setGeometry(QRect(350, 160, 31, 20));
        ConfigLineEdit->setFont(font1);
        EditWordLabel = new QLabel(ShortcutsTab);
        EditWordLabel->setObjectName(QString::fromUtf8("EditWordLabel"));
        EditWordLabel->setGeometry(QRect(310, 101, 31, 20));
        EditWordLineEdit = new QLineEdit(ShortcutsTab);
        EditWordLineEdit->setObjectName(QString::fromUtf8("EditWordLineEdit"));
        EditWordLineEdit->setGeometry(QRect(350, 100, 31, 20));
        EditWordLineEdit->setFont(font1);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/transform_move.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConfigTabWidget->addTab(ShortcutsTab, icon13, QString());
        tabWidget->addTab(configTab, icon4, QString());
        quitButton = new QPushButton(OptionsDialog);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(510, 330, 75, 23));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        quitButton->setIcon(icon14);
        applyButton = new QPushButton(OptionsDialog);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setGeometry(QRect(410, 330, 75, 23));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/dialog_ok_apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        applyButton->setIcon(icon15);

        retranslateUi(OptionsDialog);

        tabWidget->setCurrentIndex(3);
        ConfigTabWidget->setCurrentIndex(1);
        LearnMethodComboBox->setCurrentIndex(-1);
        TimeComboBox->setCurrentIndex(0);
        IntervalComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(OptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionsDialog)
    {
        OptionsDialog->setWindowTitle(QApplication::translate("OptionsDialog", "    \351\200\211\351\241\271    ", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("OptionsDialog", "\345\270\220\345\217\267\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("OptionsDialog", "\350\257\215\345\272\223\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("OptionsDialog", "\345\255\246\344\271\240\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("OptionsDialog", "\345\255\246\344\271\240\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);

        CurrUserLabel->setText(QApplication::translate("OptionsDialog", "\345\275\223\345\211\215\347\224\250\346\210\267\357\274\232", 0, QApplication::UnicodeUTF8));
        reviseKeyButton->setText(QApplication::translate("OptionsDialog", "\344\277\256\346\224\271\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        rememKeyCheckBox->setText(QApplication::translate("OptionsDialog", "\350\256\260\344\275\217\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        autoLoginCheckBox->setText(QApplication::translate("OptionsDialog", "\350\207\252\345\212\250\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        creatlabel->setText(QApplication::translate("OptionsDialog", "\345\273\272\345\217\267\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        lastlabel->setText(QApplication::translate("OptionsDialog", "\346\234\200\345\220\216\347\231\273\345\275\225\357\274\232", 0, QApplication::UnicodeUTF8));
        infolabel->setText(QString());
        forgetKeyButton->setText(QApplication::translate("OptionsDialog", "\345\277\230\350\256\260\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        icolabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(userTab), QString());
        addButton->setText(QApplication::translate("OptionsDialog", "\346\267\273\345\212\240\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("OptionsDialog", "\347\247\273\351\231\244\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
        booklabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(bookTab), QString());
        label->setText(QApplication::translate("OptionsDialog", "\345\255\246\344\271\240\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        deleteRecordButton->setText(QApplication::translate("OptionsDialog", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        ShowAllPushButton->setText(QApplication::translate("OptionsDialog", "\346\230\276\347\244\272\345\205\250\350\241\250", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(studyTab), QString());
        LearnMethodGroupBox->setTitle(QApplication::translate("OptionsDialog", "\345\255\246\344\271\240\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
        LearnMethodComboBox->clear();
        LearnMethodComboBox->insertItems(0, QStringList()
         << QApplication::translate("OptionsDialog", "\345\207\272\350\257\215\345\277\206\344\271\211", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionsDialog", "\345\207\272\344\271\211\345\277\206\350\257\215", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionsDialog", "\345\220\254\351\237\263\350\276\250\350\257\215", 0, QApplication::UnicodeUTF8)
        );
        LearnLabel->setText(QApplication::translate("OptionsDialog", "\345\255\246\344\271\240\346\226\271\345\274\217\351\200\211\346\213\251\357\274\232", 0, QApplication::UnicodeUTF8));
        OutGroupBox->setTitle(QApplication::translate("OptionsDialog", "\345\207\272\350\257\215\351\241\272\345\272\217", 0, QApplication::UnicodeUTF8));
        OutOrderlyRadioButton->setText(QApplication::translate("OptionsDialog", "\351\241\272\345\272\217", 0, QApplication::UnicodeUTF8));
        OutRandomRadioButton->setText(QApplication::translate("OptionsDialog", "\351\232\217\346\234\272", 0, QApplication::UnicodeUTF8));
        ReviewGroupBox->setTitle(QApplication::translate("OptionsDialog", "\345\244\215\344\271\240\351\241\272\345\272\217", 0, QApplication::UnicodeUTF8));
        ReviewOrderlyRadioButton->setText(QApplication::translate("OptionsDialog", "\351\241\272\345\272\217", 0, QApplication::UnicodeUTF8));
        ReviewRandomRadioButton->setText(QApplication::translate("OptionsDialog", "\351\232\217\346\234\272", 0, QApplication::UnicodeUTF8));
        ConfigTabWidget->setTabText(ConfigTabWidget->indexOf(LearnTab), QApplication::translate("OptionsDialog", "\345\255\246\344\271\240\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        SoundParameterGroupBox->setTitle(QApplication::translate("OptionsDialog", "\345\206\205\347\275\256\346\210\226\347\254\254\344\270\211\346\226\271TTS\345\217\221\351\237\263\345\217\202\346\225\260\350\256\276\345\256\232", 0, QApplication::UnicodeUTF8));
        SoundSpeedLabel->setText(QApplication::translate("OptionsDialog", "\350\257\255\351\200\237\357\274\232", 0, QApplication::UnicodeUTF8));
        SVolumeLabel->setText(QApplication::translate("OptionsDialog", "\351\237\263\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        SPitchLabel->setText(QApplication::translate("OptionsDialog", "\351\237\263\350\260\203\357\274\232", 0, QApplication::UnicodeUTF8));
        GapLabel->setText(QApplication::translate("OptionsDialog", "\345\201\234\351\241\277\357\274\232", 0, QApplication::UnicodeUTF8));
        TestSoundLabel->setText(QApplication::translate("OptionsDialog", "\346\265\213\350\257\225\357\274\232", 0, QApplication::UnicodeUTF8));
        TestSoundLineEdit->setText(QApplication::translate("OptionsDialog", "Besser sp\303\244t als nie.", 0, QApplication::UnicodeUTF8));
        TestSondButton->setText(QString());
        PRangeLabel->setText(QApplication::translate("OptionsDialog", "\351\237\263\345\237\237\357\274\232", 0, QApplication::UnicodeUTF8));
        BackToSysButton->setText(QApplication::translate("OptionsDialog", "\347\202\271\345\207\273\350\277\230\345\216\237\351\273\230\350\256\244\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        CircleGroupBox->setTitle(QApplication::translate("OptionsDialog", "\350\257\255\351\237\263\350\256\276\345\256\232", 0, QApplication::UnicodeUTF8));
        SoundCheckBox->setText(QApplication::translate("OptionsDialog", "\345\274\200\345\220\257\350\257\255\351\237\263\345\212\237\350\203\275", 0, QApplication::UnicodeUTF8));
        TTSRadioButton->setText(QApplication::translate("OptionsDialog", "\345\206\205\347\275\256\346\210\226\347\254\254\344\270\211\346\226\271TTS", 0, QApplication::UnicodeUTF8));
        OnlineRadioButton->setText(QApplication::translate("OptionsDialog", "Google\345\234\250\347\272\277TTS", 0, QApplication::UnicodeUTF8));
        Real_TTSRadioButton->setText(QApplication::translate("OptionsDialog", "\347\234\237\344\272\272\350\257\255\351\237\263\351\205\215\345\220\210TTS", 0, QApplication::UnicodeUTF8));
        TimeLabel->setText(QApplication::translate("OptionsDialog", "\345\276\252\347\216\257\346\254\241\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        TimeComboBox->clear();
        TimeComboBox->insertItems(0, QStringList()
         << QApplication::translate("OptionsDialog", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionsDialog", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionsDialog", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionsDialog", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionsDialog", "5", 0, QApplication::UnicodeUTF8)
        );
        IntervalLabel->setText(QApplication::translate("OptionsDialog", "\345\276\252\347\216\257\351\227\264\351\232\224\357\274\232", 0, QApplication::UnicodeUTF8));
        IntervalComboBox->clear();
        IntervalComboBox->insertItems(0, QStringList()
         << QApplication::translate("OptionsDialog", "500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionsDialog", "800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionsDialog", "1000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionsDialog", "1300", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionsDialog", "1600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionsDialog", "2000", 0, QApplication::UnicodeUTF8)
        );
        TTSComboBox->clear();
        TTSComboBox->insertItems(0, QStringList()
         << QApplication::translate("OptionsDialog", "eSpeakTTS", 0, QApplication::UnicodeUTF8)
        );
        ConfigTabWidget->setTabText(ConfigTabWidget->indexOf(SoundTab), QApplication::translate("OptionsDialog", "\350\257\255\351\237\263", 0, QApplication::UnicodeUTF8));
        RememLabel->setText(QApplication::translate("OptionsDialog", "\350\256\260\345\276\227\357\274\232", 0, QApplication::UnicodeUTF8));
        RememLineEdit->setText(QString());
        ObscureLabel->setText(QApplication::translate("OptionsDialog", "\346\250\241\347\263\212\357\274\232", 0, QApplication::UnicodeUTF8));
        ObscureLineEdit->setText(QString());
        ForgetLabel->setText(QApplication::translate("OptionsDialog", "\345\277\230\350\256\260\357\274\232", 0, QApplication::UnicodeUTF8));
        ForgetLineEdit->setText(QString());
        RightLabel->setText(QApplication::translate("OptionsDialog", "\346\255\243\347\241\256\357\274\232", 0, QApplication::UnicodeUTF8));
        RightLineEdit->setText(QString());
        WrongLabel->setText(QApplication::translate("OptionsDialog", "\351\224\231\350\257\257\357\274\232", 0, QApplication::UnicodeUTF8));
        WrongLineEdit->setText(QString());
        SoundLabel->setText(QApplication::translate("OptionsDialog", "\350\257\255\351\237\263\357\274\232", 0, QApplication::UnicodeUTF8));
        SoundLineEdit->setText(QString());
        NextLabel->setText(QApplication::translate("OptionsDialog", "\344\270\213\344\270\252\357\274\232", 0, QApplication::UnicodeUTF8));
        NextLineEdit->setText(QString());
        ConfigLabel->setText(QApplication::translate("OptionsDialog", "\351\205\215\347\275\256\357\274\232", 0, QApplication::UnicodeUTF8));
        ConfigLineEdit->setText(QString());
        EditWordLabel->setText(QApplication::translate("OptionsDialog", "\347\274\226\350\276\221\357\274\232", 0, QApplication::UnicodeUTF8));
        ConfigTabWidget->setTabText(ConfigTabWidget->indexOf(ShortcutsTab), QApplication::translate("OptionsDialog", "\345\277\253\346\215\267\351\224\256", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(configTab), QString());
        quitButton->setText(QApplication::translate("OptionsDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        applyButton->setText(QApplication::translate("OptionsDialog", "\345\272\224\347\224\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OptionsDialog: public Ui_OptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSDIALOG_H
