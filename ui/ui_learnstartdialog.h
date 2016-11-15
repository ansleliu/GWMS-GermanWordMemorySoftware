/********************************************************************************
** Form generated from reading UI file 'learnstartdialog.ui'
**
** Created: Tue Nov 24 04:05:56 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNSTARTDIALOG_H
#define UI_LEARNSTARTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include "QSintCharts"

QT_BEGIN_NAMESPACE

class Ui_LearnStartDialog
{
public:
    QGroupBox *InfoGroupBox;
    QSint::PieChart *PieChart;
    QListWidget *InfoListWidget;
    QLabel *InfoLabel;
    QGroupBox *LearnGroupBox;
    QPushButton *LearnPushButton;
    QPushButton *ReviewPushButton;
    QGroupBox *ChoiceGroupBox;
    QCheckBox *ChoiceCheckBox;
    QLabel *LekLabel;
    QComboBox *LektionComboBox;
    QLineEdit *LektionLineEdit;
    QLabel *Label;
    QComboBox *ReviewLektionComboBox;
    QListWidget *InfoTextBrowser;

    void setupUi(QDialog *LearnStartDialog)
    {
        if (LearnStartDialog->objectName().isEmpty())
            LearnStartDialog->setObjectName(QString::fromUtf8("LearnStartDialog"));
        LearnStartDialog->resize(612, 331);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix2/rc/Wordpress.png"), QSize(), QIcon::Normal, QIcon::Off);
        LearnStartDialog->setWindowIcon(icon);
        InfoGroupBox = new QGroupBox(LearnStartDialog);
        InfoGroupBox->setObjectName(QString::fromUtf8("InfoGroupBox"));
        InfoGroupBox->setGeometry(QRect(10, 10, 311, 301));
        PieChart = new QSint::PieChart(InfoGroupBox);
        PieChart->setObjectName(QString::fromUtf8("PieChart"));
        PieChart->setGeometry(QRect(10, 20, 291, 241));
        PieChart->setAutoFillBackground(true);
        InfoListWidget = new QListWidget(InfoGroupBox);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QBrush brush1(QColor(255, 255, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(InfoListWidget);
        __qlistwidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setBackground(brush1);
        __qlistwidgetitem->setForeground(brush);
        QBrush brush2(QColor(0, 255, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(InfoListWidget);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qlistwidgetitem1->setBackground(brush2);
        __qlistwidgetitem1->setForeground(brush);
        InfoListWidget->setObjectName(QString::fromUtf8("InfoListWidget"));
        InfoListWidget->setEnabled(false);
        InfoListWidget->setGeometry(QRect(250, 220, 51, 41));
        InfoListWidget->setFocusPolicy(Qt::NoFocus);
        InfoListWidget->setAutoFillBackground(true);
        InfoListWidget->setFrameShape(QFrame::NoFrame);
        InfoListWidget->setFrameShadow(QFrame::Sunken);
        InfoListWidget->setLineWidth(1);
        InfoListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        InfoListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        InfoListWidget->setAutoScroll(true);
        InfoListWidget->setFlow(QListView::TopToBottom);
        InfoListWidget->setProperty("isWrapping", QVariant(false));
        InfoListWidget->setResizeMode(QListView::Adjust);
        InfoListWidget->setLayoutMode(QListView::SinglePass);
        InfoListWidget->setSpacing(0);
        InfoListWidget->setUniformItemSizes(false);
        InfoListWidget->setWordWrap(false);
        InfoListWidget->setSelectionRectVisible(false);
        InfoLabel = new QLabel(InfoGroupBox);
        InfoLabel->setObjectName(QString::fromUtf8("InfoLabel"));
        InfoLabel->setGeometry(QRect(110, 270, 91, 20));
        LearnGroupBox = new QGroupBox(LearnStartDialog);
        LearnGroupBox->setObjectName(QString::fromUtf8("LearnGroupBox"));
        LearnGroupBox->setGeometry(QRect(330, 10, 271, 311));
        LearnPushButton = new QPushButton(LearnGroupBox);
        LearnPushButton->setObjectName(QString::fromUtf8("LearnPushButton"));
        LearnPushButton->setGeometry(QRect(10, 270, 101, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        LearnPushButton->setIcon(icon1);
        ReviewPushButton = new QPushButton(LearnGroupBox);
        ReviewPushButton->setObjectName(QString::fromUtf8("ReviewPushButton"));
        ReviewPushButton->setGeometry(QRect(160, 270, 101, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/player_time.png"), QSize(), QIcon::Normal, QIcon::Off);
        ReviewPushButton->setIcon(icon2);
        ChoiceGroupBox = new QGroupBox(LearnGroupBox);
        ChoiceGroupBox->setObjectName(QString::fromUtf8("ChoiceGroupBox"));
        ChoiceGroupBox->setGeometry(QRect(10, 180, 251, 81));
        ChoiceCheckBox = new QCheckBox(ChoiceGroupBox);
        ChoiceCheckBox->setObjectName(QString::fromUtf8("ChoiceCheckBox"));
        ChoiceCheckBox->setGeometry(QRect(10, 20, 101, 20));
        ChoiceCheckBox->setChecked(true);
        LekLabel = new QLabel(ChoiceGroupBox);
        LekLabel->setObjectName(QString::fromUtf8("LekLabel"));
        LekLabel->setGeometry(QRect(10, 51, 61, 21));
        LektionComboBox = new QComboBox(ChoiceGroupBox);
        LektionComboBox->setObjectName(QString::fromUtf8("LektionComboBox"));
        LektionComboBox->setGeometry(QRect(70, 50, 81, 21));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        font1.setStyleStrategy(QFont::PreferAntialias);
        LektionComboBox->setFont(font1);
        LektionComboBox->setModelColumn(0);
        LektionLineEdit = new QLineEdit(ChoiceGroupBox);
        LektionLineEdit->setObjectName(QString::fromUtf8("LektionLineEdit"));
        LektionLineEdit->setGeometry(QRect(190, 20, 51, 20));
        Label = new QLabel(ChoiceGroupBox);
        Label->setObjectName(QString::fromUtf8("Label"));
        Label->setGeometry(QRect(130, 20, 61, 21));
        ReviewLektionComboBox = new QComboBox(ChoiceGroupBox);
        ReviewLektionComboBox->setObjectName(QString::fromUtf8("ReviewLektionComboBox"));
        ReviewLektionComboBox->setGeometry(QRect(160, 50, 81, 21));
        InfoTextBrowser = new QListWidget(LearnGroupBox);
        InfoTextBrowser->setObjectName(QString::fromUtf8("InfoTextBrowser"));
        InfoTextBrowser->setGeometry(QRect(10, 20, 251, 151));
        InfoTextBrowser->setProperty("isWrapping", QVariant(false));
        InfoTextBrowser->setUniformItemSizes(false);
        ChoiceGroupBox->raise();
        LearnPushButton->raise();
        ReviewPushButton->raise();
        InfoTextBrowser->raise();

        retranslateUi(LearnStartDialog);

        QMetaObject::connectSlotsByName(LearnStartDialog);
    } // setupUi

    void retranslateUi(QDialog *LearnStartDialog)
    {
        LearnStartDialog->setWindowTitle(QApplication::translate("LearnStartDialog", "    \345\274\200\345\247\213\345\255\246\344\271\240   ", 0, QApplication::UnicodeUTF8));
        InfoGroupBox->setTitle(QApplication::translate("LearnStartDialog", "\345\233\276\345\275\242\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = InfoListWidget->isSortingEnabled();
        InfoListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = InfoListWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("LearnStartDialog", "\346\234\252\345\255\246\344\271\240", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = InfoListWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("LearnStartDialog", "\345\267\262\345\255\246\344\271\240", 0, QApplication::UnicodeUTF8));
        InfoListWidget->setSortingEnabled(__sortingEnabled);

        InfoLabel->setText(QApplication::translate("LearnStartDialog", "\345\255\246\344\271\240\350\277\233\345\272\246\351\245\274\347\212\266\345\233\276", 0, QApplication::UnicodeUTF8));
        LearnGroupBox->setTitle(QApplication::translate("LearnStartDialog", "\345\255\246\344\271\240\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        LearnPushButton->setText(QApplication::translate("LearnStartDialog", "\345\274\200\345\247\213\345\255\246\344\271\240", 0, QApplication::UnicodeUTF8));
        ReviewPushButton->setText(QApplication::translate("LearnStartDialog", "\345\274\200\345\247\213\345\244\215\344\271\240", 0, QApplication::UnicodeUTF8));
        ChoiceGroupBox->setTitle(QApplication::translate("LearnStartDialog", "\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        ChoiceCheckBox->setText(QApplication::translate("LearnStartDialog", "\346\214\211\345\215\225\345\205\203\345\255\246\344\271\240\345\244\215\344\271\240", 0, QApplication::UnicodeUTF8));
        LekLabel->setText(QApplication::translate("LearnStartDialog", "\351\200\211\346\213\251\345\215\225\345\205\203\357\274\232", 0, QApplication::UnicodeUTF8));
        Label->setText(QApplication::translate("LearnStartDialog", "\350\276\223\345\205\245\345\215\225\345\205\203\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LearnStartDialog: public Ui_LearnStartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNSTARTDIALOG_H
