/********************************************************************************
** Form generated from reading UI file 'analysisdialog.ui'
**
** Created: Tue Nov 24 04:05:56 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSISDIALOG_H
#define UI_ANALYSISDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>
#include "QSintCharts"

QT_BEGIN_NAMESPACE

class Ui_AnalysisDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QListWidget *ChoiceListWidget;
    QTabWidget *tabWidget;
    QWidget *LearnRecordTab;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_3;
    QGroupBox *InfoGroupBox;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_4;
    QDateEdit *dateEdit;
    QPushButton *DataPushButton;
    QLabel *LLabel_2;
    QSpinBox *LSpinBox;
    QGroupBox *LorRGroupBox;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_5;
    QRadioButton *LRadioButton;
    QRadioButton *RRadioButton;
    QGroupBox *ChoiceGroupBox;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_6;
    QRadioButton *LBarRadioButton;
    QRadioButton *LLineRadioButton;
    QSint::BarChartPlotter *LearnBarChartPlotter;
    QWidget *ReviewCalculateTab;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_11;
    QLabel *TitelLabel;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *RBarRadioButton;
    QRadioButton *RLineRadioButton;
    QSpacerItem *horizontalSpacer_3;
    QSint::BarChartPlotter *ReviewBarChartPlotter;
    QSpinBox *RSpinBox;
    QWidget *BookInfoTab;
    QSint::PieChart *HG5PieChart;
    QSint::PieChart *LHLPieChart;
    QSint::PieChart *HU3PieChart;
    QSint::PieChart *HG4A3PieChart;
    QComboBox *BookComboBox;
    QListWidget *LHListWidget;
    QListWidget *HG5ListWidget;
    QLabel *LHLabel;
    QLabel *HG5Label;
    QListWidget *HG4A3ListWidge;
    QListWidget *HU3ListWidget;
    QLabel *HG4A3Label;
    QLabel *HU3Label;

    void setupUi(QDialog *AnalysisDialog)
    {
        if (AnalysisDialog->objectName().isEmpty())
            AnalysisDialog->setObjectName(QString::fromUtf8("AnalysisDialog"));
        AnalysisDialog->resize(737, 415);
        AnalysisDialog->setMinimumSize(QSize(737, 415));
        AnalysisDialog->setMaximumSize(QSize(737, 415));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/view_statistics.png"), QSize(), QIcon::Normal, QIcon::Off);
        AnalysisDialog->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(AnalysisDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ChoiceListWidget = new QListWidget(AnalysisDialog);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/column_chart512.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(ChoiceListWidget);
        __qlistwidgetitem->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/tongji_002.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(ChoiceListWidget);
        __qlistwidgetitem1->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/tongji_001.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(ChoiceListWidget);
        __qlistwidgetitem2->setIcon(icon3);
        ChoiceListWidget->setObjectName(QString::fromUtf8("ChoiceListWidget"));
        ChoiceListWidget->setMinimumSize(QSize(78, 0));
        ChoiceListWidget->setMaximumSize(QSize(78, 16777215));
        ChoiceListWidget->setAlternatingRowColors(false);
        ChoiceListWidget->setMovement(QListView::Static);
        ChoiceListWidget->setResizeMode(QListView::Fixed);
        ChoiceListWidget->setSpacing(10);
        ChoiceListWidget->setViewMode(QListView::IconMode);
        ChoiceListWidget->setUniformItemSizes(true);

        gridLayout->addWidget(ChoiceListWidget, 0, 0, 1, 1);

        tabWidget = new QTabWidget(AnalysisDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setIconSize(QSize(40, 40));
        LearnRecordTab = new QWidget();
        LearnRecordTab->setObjectName(QString::fromUtf8("LearnRecordTab"));
        gridLayout_10 = new QGridLayout(LearnRecordTab);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        InfoGroupBox = new QGroupBox(LearnRecordTab);
        InfoGroupBox->setObjectName(QString::fromUtf8("InfoGroupBox"));
        gridLayout_7 = new QGridLayout(InfoGroupBox);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        dateEdit = new QDateEdit(InfoGroupBox);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setMinimumSize(QSize(81, 20));

        gridLayout_4->addWidget(dateEdit, 0, 1, 1, 1);

        DataPushButton = new QPushButton(InfoGroupBox);
        DataPushButton->setObjectName(QString::fromUtf8("DataPushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DataPushButton->sizePolicy().hasHeightForWidth());
        DataPushButton->setSizePolicy(sizePolicy);
        DataPushButton->setMinimumSize(QSize(21, 23));
        DataPushButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/kontact_date.png"), QSize(), QIcon::Normal, QIcon::Off);
        DataPushButton->setIcon(icon4);

        gridLayout_4->addWidget(DataPushButton, 0, 2, 1, 1);

        LLabel_2 = new QLabel(InfoGroupBox);
        LLabel_2->setObjectName(QString::fromUtf8("LLabel_2"));
        LLabel_2->setMinimumSize(QSize(101, 23));

        gridLayout_4->addWidget(LLabel_2, 0, 3, 1, 1);

        LSpinBox = new QSpinBox(InfoGroupBox);
        LSpinBox->setObjectName(QString::fromUtf8("LSpinBox"));
        LSpinBox->setReadOnly(false);
        LSpinBox->setMinimum(50);
        LSpinBox->setMaximum(800);
        LSpinBox->setSingleStep(10);
        LSpinBox->setValue(150);

        gridLayout_4->addWidget(LSpinBox, 0, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_4, 0, 0, 1, 1);


        gridLayout_3->addWidget(InfoGroupBox, 0, 0, 1, 1);

        LorRGroupBox = new QGroupBox(LearnRecordTab);
        LorRGroupBox->setObjectName(QString::fromUtf8("LorRGroupBox"));
        gridLayout_8 = new QGridLayout(LorRGroupBox);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        LRadioButton = new QRadioButton(LorRGroupBox);
        LRadioButton->setObjectName(QString::fromUtf8("LRadioButton"));
        LRadioButton->setChecked(true);

        gridLayout_5->addWidget(LRadioButton, 0, 0, 1, 1);

        RRadioButton = new QRadioButton(LorRGroupBox);
        RRadioButton->setObjectName(QString::fromUtf8("RRadioButton"));

        gridLayout_5->addWidget(RRadioButton, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_5, 0, 0, 1, 1);


        gridLayout_3->addWidget(LorRGroupBox, 0, 1, 1, 1);

        ChoiceGroupBox = new QGroupBox(LearnRecordTab);
        ChoiceGroupBox->setObjectName(QString::fromUtf8("ChoiceGroupBox"));
        gridLayout_9 = new QGridLayout(ChoiceGroupBox);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        LBarRadioButton = new QRadioButton(ChoiceGroupBox);
        LBarRadioButton->setObjectName(QString::fromUtf8("LBarRadioButton"));
        LBarRadioButton->setChecked(false);

        gridLayout_6->addWidget(LBarRadioButton, 0, 0, 1, 1);

        LLineRadioButton = new QRadioButton(ChoiceGroupBox);
        LLineRadioButton->setObjectName(QString::fromUtf8("LLineRadioButton"));
        LLineRadioButton->setChecked(true);

        gridLayout_6->addWidget(LLineRadioButton, 0, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_6, 0, 0, 1, 1);


        gridLayout_3->addWidget(ChoiceGroupBox, 0, 2, 1, 1);

        LearnBarChartPlotter = new QSint::BarChartPlotter(LearnRecordTab);
        LearnBarChartPlotter->setObjectName(QString::fromUtf8("LearnBarChartPlotter"));

        gridLayout_3->addWidget(LearnBarChartPlotter, 1, 0, 1, 3);

        gridLayout_3->setRowStretch(0, 2);
        gridLayout_3->setRowStretch(1, 16);
        gridLayout_3->setColumnStretch(0, 7);
        gridLayout_3->setColumnStretch(1, 4);
        gridLayout_3->setColumnStretch(2, 3);
        gridLayout_3->setColumnMinimumWidth(0, 6);
        gridLayout_3->setColumnMinimumWidth(1, 3);
        gridLayout_3->setColumnMinimumWidth(2, 3);
        gridLayout_3->setRowMinimumHeight(0, 2);
        gridLayout_3->setRowMinimumHeight(1, 10);

        gridLayout_10->addLayout(gridLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(LearnRecordTab, icon1, QString());
        ReviewCalculateTab = new QWidget();
        ReviewCalculateTab->setObjectName(QString::fromUtf8("ReviewCalculateTab"));
        gridLayout_12 = new QGridLayout(ReviewCalculateTab);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        TitelLabel = new QLabel(ReviewCalculateTab);
        TitelLabel->setObjectName(QString::fromUtf8("TitelLabel"));

        gridLayout_11->addWidget(TitelLabel, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        RBarRadioButton = new QRadioButton(ReviewCalculateTab);
        RBarRadioButton->setObjectName(QString::fromUtf8("RBarRadioButton"));
        RBarRadioButton->setChecked(false);

        gridLayout_11->addWidget(RBarRadioButton, 0, 3, 1, 1);

        RLineRadioButton = new QRadioButton(ReviewCalculateTab);
        RLineRadioButton->setObjectName(QString::fromUtf8("RLineRadioButton"));
        RLineRadioButton->setChecked(true);

        gridLayout_11->addWidget(RLineRadioButton, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        ReviewBarChartPlotter = new QSint::BarChartPlotter(ReviewCalculateTab);
        ReviewBarChartPlotter->setObjectName(QString::fromUtf8("ReviewBarChartPlotter"));

        gridLayout_11->addWidget(ReviewBarChartPlotter, 1, 0, 1, 6);

        RSpinBox = new QSpinBox(ReviewCalculateTab);
        RSpinBox->setObjectName(QString::fromUtf8("RSpinBox"));
        RSpinBox->setMinimum(50);
        RSpinBox->setMaximum(800);
        RSpinBox->setSingleStep(10);
        RSpinBox->setValue(150);

        gridLayout_11->addWidget(RSpinBox, 0, 0, 1, 1);


        gridLayout_12->addLayout(gridLayout_11, 0, 0, 1, 1);

        tabWidget->addTab(ReviewCalculateTab, icon2, QString());
        BookInfoTab = new QWidget();
        BookInfoTab->setObjectName(QString::fromUtf8("BookInfoTab"));
        HG5PieChart = new QSint::PieChart(BookInfoTab);
        HG5PieChart->setObjectName(QString::fromUtf8("HG5PieChart"));
        HG5PieChart->setGeometry(QRect(310, 10, 184, 161));
        LHLPieChart = new QSint::PieChart(BookInfoTab);
        LHLPieChart->setObjectName(QString::fromUtf8("LHLPieChart"));
        LHLPieChart->setGeometry(QRect(10, 10, 184, 161));
        HU3PieChart = new QSint::PieChart(BookInfoTab);
        HU3PieChart->setObjectName(QString::fromUtf8("HU3PieChart"));
        HU3PieChart->setGeometry(QRect(310, 180, 184, 161));
        HG4A3PieChart = new QSint::PieChart(BookInfoTab);
        HG4A3PieChart->setObjectName(QString::fromUtf8("HG4A3PieChart"));
        HG4A3PieChart->setGeometry(QRect(10, 180, 184, 161));
        BookComboBox = new QComboBox(BookInfoTab);
        BookComboBox->setObjectName(QString::fromUtf8("BookComboBox"));
        BookComboBox->setGeometry(QRect(504, 10, 111, 20));
        BookComboBox->setMaxVisibleItems(20);
        LHListWidget = new QListWidget(BookInfoTab);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QBrush brush1(QColor(170, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(LHListWidget);
        __qlistwidgetitem3->setBackground(brush1);
        __qlistwidgetitem3->setForeground(brush);
        QBrush brush2(QColor(0, 170, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(LHListWidget);
        __qlistwidgetitem4->setBackground(brush2);
        __qlistwidgetitem4->setForeground(brush);
        LHListWidget->setObjectName(QString::fromUtf8("LHListWidget"));
        LHListWidget->setEnabled(false);
        LHListWidget->setGeometry(QRect(200, 110, 71, 41));
        LHListWidget->setMinimumSize(QSize(71, 41));
        LHListWidget->setMaximumSize(QSize(71, 41));
        LHListWidget->setFrameShape(QFrame::NoFrame);
        LHListWidget->setFrameShadow(QFrame::Raised);
        LHListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        LHListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        LHListWidget->setAutoScroll(false);
        LHListWidget->setSelectionMode(QAbstractItemView::NoSelection);
        LHListWidget->setProperty("isWrapping", QVariant(false));
        LHListWidget->setSpacing(2);
        LHListWidget->setUniformItemSizes(true);
        LHListWidget->setBatchSize(100);
        HG5ListWidget = new QListWidget(BookInfoTab);
        QBrush brush3(QColor(255, 255, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(HG5ListWidget);
        __qlistwidgetitem5->setBackground(brush3);
        __qlistwidgetitem5->setForeground(brush);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(HG5ListWidget);
        __qlistwidgetitem6->setBackground(brush2);
        __qlistwidgetitem6->setForeground(brush);
        HG5ListWidget->setObjectName(QString::fromUtf8("HG5ListWidget"));
        HG5ListWidget->setEnabled(false);
        HG5ListWidget->setGeometry(QRect(500, 110, 71, 41));
        HG5ListWidget->setMinimumSize(QSize(71, 41));
        HG5ListWidget->setMaximumSize(QSize(71, 41));
        HG5ListWidget->setFrameShape(QFrame::NoFrame);
        HG5ListWidget->setFrameShadow(QFrame::Raised);
        HG5ListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        HG5ListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        HG5ListWidget->setAutoScroll(false);
        HG5ListWidget->setSelectionMode(QAbstractItemView::NoSelection);
        HG5ListWidget->setProperty("isWrapping", QVariant(false));
        HG5ListWidget->setSpacing(2);
        HG5ListWidget->setUniformItemSizes(true);
        HG5ListWidget->setBatchSize(100);
        LHLabel = new QLabel(BookInfoTab);
        LHLabel->setObjectName(QString::fromUtf8("LHLabel"));
        LHLabel->setGeometry(QRect(200, 150, 96, 21));
        HG5Label = new QLabel(BookInfoTab);
        HG5Label->setObjectName(QString::fromUtf8("HG5Label"));
        HG5Label->setGeometry(QRect(500, 150, 108, 21));
        HG4A3ListWidge = new QListWidget(BookInfoTab);
        QBrush brush4(QColor(255, 170, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(HG4A3ListWidge);
        __qlistwidgetitem7->setBackground(brush4);
        __qlistwidgetitem7->setForeground(brush);
        QListWidgetItem *__qlistwidgetitem8 = new QListWidgetItem(HG4A3ListWidge);
        __qlistwidgetitem8->setBackground(brush2);
        __qlistwidgetitem8->setForeground(brush);
        HG4A3ListWidge->setObjectName(QString::fromUtf8("HG4A3ListWidge"));
        HG4A3ListWidge->setEnabled(false);
        HG4A3ListWidge->setGeometry(QRect(200, 280, 71, 41));
        HG4A3ListWidge->setMinimumSize(QSize(71, 41));
        HG4A3ListWidge->setMaximumSize(QSize(71, 41));
        HG4A3ListWidge->setFrameShape(QFrame::NoFrame);
        HG4A3ListWidge->setFrameShadow(QFrame::Raised);
        HG4A3ListWidge->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        HG4A3ListWidge->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        HG4A3ListWidge->setAutoScroll(false);
        HG4A3ListWidge->setSelectionMode(QAbstractItemView::NoSelection);
        HG4A3ListWidge->setProperty("isWrapping", QVariant(false));
        HG4A3ListWidge->setSpacing(2);
        HG4A3ListWidge->setUniformItemSizes(true);
        HG4A3ListWidge->setBatchSize(100);
        HU3ListWidget = new QListWidget(BookInfoTab);
        QBrush brush5(QColor(85, 0, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        QListWidgetItem *__qlistwidgetitem9 = new QListWidgetItem(HU3ListWidget);
        __qlistwidgetitem9->setBackground(brush5);
        __qlistwidgetitem9->setForeground(brush);
        QListWidgetItem *__qlistwidgetitem10 = new QListWidgetItem(HU3ListWidget);
        __qlistwidgetitem10->setBackground(brush2);
        __qlistwidgetitem10->setForeground(brush);
        HU3ListWidget->setObjectName(QString::fromUtf8("HU3ListWidget"));
        HU3ListWidget->setEnabled(false);
        HU3ListWidget->setGeometry(QRect(500, 280, 71, 41));
        HU3ListWidget->setMinimumSize(QSize(71, 41));
        HU3ListWidget->setMaximumSize(QSize(71, 41));
        HU3ListWidget->setFrameShape(QFrame::NoFrame);
        HU3ListWidget->setFrameShadow(QFrame::Raised);
        HU3ListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        HU3ListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        HU3ListWidget->setAutoScroll(false);
        HU3ListWidget->setSelectionMode(QAbstractItemView::NoSelection);
        HU3ListWidget->setProperty("isWrapping", QVariant(false));
        HU3ListWidget->setSpacing(2);
        HU3ListWidget->setUniformItemSizes(true);
        HU3ListWidget->setBatchSize(100);
        HG4A3Label = new QLabel(BookInfoTab);
        HG4A3Label->setObjectName(QString::fromUtf8("HG4A3Label"));
        HG4A3Label->setGeometry(QRect(200, 320, 108, 21));
        HU3Label = new QLabel(BookInfoTab);
        HU3Label->setObjectName(QString::fromUtf8("HU3Label"));
        HU3Label->setGeometry(QRect(504, 320, 108, 21));
        tabWidget->addTab(BookInfoTab, icon3, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 16);

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(AnalysisDialog);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(AnalysisDialog);
    } // setupUi

    void retranslateUi(QDialog *AnalysisDialog)
    {
        AnalysisDialog->setWindowTitle(QApplication::translate("AnalysisDialog", "  \347\273\237\350\256\241\345\210\206\346\236\220", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = ChoiceListWidget->isSortingEnabled();
        ChoiceListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = ChoiceListWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("AnalysisDialog", "\345\255\246\344\271\240\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = ChoiceListWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("AnalysisDialog", "\345\244\215\344\271\240\351\242\204\346\265\213", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = ChoiceListWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("AnalysisDialog", "\350\257\215\345\272\223\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        ChoiceListWidget->setSortingEnabled(__sortingEnabled);

        InfoGroupBox->setTitle(QString());
        dateEdit->setDisplayFormat(QApplication::translate("AnalysisDialog", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        DataPushButton->setText(QString());
        LLabel_2->setText(QApplication::translate("AnalysisDialog", "\350\265\267\344\271\213\345\220\21630\345\244\251\347\232\204\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        LorRGroupBox->setTitle(QString());
        LRadioButton->setText(QApplication::translate("AnalysisDialog", "\345\255\246\344\271\240\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        RRadioButton->setText(QApplication::translate("AnalysisDialog", "\345\244\215\344\271\240\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        ChoiceGroupBox->setTitle(QString());
        LBarRadioButton->setText(QApplication::translate("AnalysisDialog", "\346\237\261\347\212\266\345\233\276", 0, QApplication::UnicodeUTF8));
        LLineRadioButton->setText(QApplication::translate("AnalysisDialog", "\347\202\271\347\272\277\345\233\276", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(LearnRecordTab), QString());
        TitelLabel->setText(QApplication::translate("AnalysisDialog", "\351\242\204\346\265\21330\345\244\251\345\206\205\347\232\204\345\244\215\344\271\240\346\203\205\345\206\265", 0, QApplication::UnicodeUTF8));
        RBarRadioButton->setText(QApplication::translate("AnalysisDialog", "\346\237\261\347\212\266\345\233\276", 0, QApplication::UnicodeUTF8));
        RLineRadioButton->setText(QApplication::translate("AnalysisDialog", "\347\202\271\347\272\277\345\233\276", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(ReviewCalculateTab), QString());

        const bool __sortingEnabled1 = LHListWidget->isSortingEnabled();
        LHListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem3 = LHListWidget->item(0);
        ___qlistwidgetitem3->setText(QApplication::translate("AnalysisDialog", "\346\234\252\345\255\246\350\257\215\351\207\217", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem4 = LHListWidget->item(1);
        ___qlistwidgetitem4->setText(QApplication::translate("AnalysisDialog", "\345\267\262\345\255\246\350\257\215\351\207\217", 0, QApplication::UnicodeUTF8));
        LHListWidget->setSortingEnabled(__sortingEnabled1);


        const bool __sortingEnabled2 = HG5ListWidget->isSortingEnabled();
        HG5ListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem5 = HG5ListWidget->item(0);
        ___qlistwidgetitem5->setText(QApplication::translate("AnalysisDialog", "\350\256\260\345\276\227\350\257\215\351\207\217", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem6 = HG5ListWidget->item(1);
        ___qlistwidgetitem6->setText(QApplication::translate("AnalysisDialog", "\345\267\262\345\255\246\350\257\215\351\207\217", 0, QApplication::UnicodeUTF8));
        HG5ListWidget->setSortingEnabled(__sortingEnabled2);

        LHLabel->setText(QApplication::translate("AnalysisDialog", "\346\200\273\350\257\215\351\207\217\344\270\216\345\267\262\345\255\246\350\257\215\351\207\217", 0, QApplication::UnicodeUTF8));
        HG5Label->setText(QApplication::translate("AnalysisDialog", "\350\256\260\345\276\227\350\257\215\351\207\217\344\270\216\345\267\262\345\255\246\350\257\215\351\207\217", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled3 = HG4A3ListWidge->isSortingEnabled();
        HG4A3ListWidge->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem7 = HG4A3ListWidge->item(0);
        ___qlistwidgetitem7->setText(QApplication::translate("AnalysisDialog", "\346\250\241\347\263\212\350\257\215\351\207\217", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem8 = HG4A3ListWidge->item(1);
        ___qlistwidgetitem8->setText(QApplication::translate("AnalysisDialog", "\345\267\262\345\255\246\350\257\215\351\207\217", 0, QApplication::UnicodeUTF8));
        HG4A3ListWidge->setSortingEnabled(__sortingEnabled3);


        const bool __sortingEnabled4 = HU3ListWidget->isSortingEnabled();
        HU3ListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem9 = HU3ListWidget->item(0);
        ___qlistwidgetitem9->setText(QApplication::translate("AnalysisDialog", "\346\234\252\345\255\246\350\257\215\351\207\217", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem10 = HU3ListWidget->item(1);
        ___qlistwidgetitem10->setText(QApplication::translate("AnalysisDialog", "\345\267\262\345\255\246\350\257\215\351\207\217", 0, QApplication::UnicodeUTF8));
        HU3ListWidget->setSortingEnabled(__sortingEnabled4);

        HG4A3Label->setText(QApplication::translate("AnalysisDialog", "\346\250\241\347\263\212\350\257\215\351\207\217\344\270\216\345\267\262\345\255\246\350\257\215\351\207\217", 0, QApplication::UnicodeUTF8));
        HU3Label->setText(QApplication::translate("AnalysisDialog", "\345\277\230\350\256\260\350\257\215\351\207\217\344\270\216\345\267\262\345\255\246\350\257\215\351\207\217", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(BookInfoTab), QString());
    } // retranslateUi

};

namespace Ui {
    class AnalysisDialog: public Ui_AnalysisDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSISDIALOG_H
