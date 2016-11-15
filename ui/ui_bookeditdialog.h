/********************************************************************************
** Form generated from reading UI file 'bookeditdialog.ui'
**
** Created: Tue Nov 24 04:05:56 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKEDITDIALOG_H
#define UI_BOOKEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BookEditDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *newRecordButton;
    QPushButton *deleteRecordButton;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *idSelectradioButton;
    QRadioButton *wortSelectradioButton;
    QLineEdit *goTolineEdit;
    QPushButton *showAllButton;
    QPushButton *ascendingOrderButton;
    QPushButton *descendingOrderButton;

    void setupUi(QDialog *BookEditDialog)
    {
        if (BookEditDialog->objectName().isEmpty())
            BookEditDialog->setObjectName(QString::fromUtf8("BookEditDialog"));
        BookEditDialog->resize(562, 401);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        BookEditDialog->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(BookEditDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(BookEditDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);

        horizontalLayout->addWidget(label);

        newRecordButton = new QPushButton(BookEditDialog);
        newRecordButton->setObjectName(QString::fromUtf8("newRecordButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newRecordButton->sizePolicy().hasHeightForWidth());
        newRecordButton->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        newRecordButton->setIcon(icon1);

        horizontalLayout->addWidget(newRecordButton);

        deleteRecordButton = new QPushButton(BookEditDialog);
        deleteRecordButton->setObjectName(QString::fromUtf8("deleteRecordButton"));
        sizePolicy.setHeightForWidth(deleteRecordButton->sizePolicy().hasHeightForWidth());
        deleteRecordButton->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteRecordButton->setIcon(icon2);

        horizontalLayout->addWidget(deleteRecordButton);

        horizontalLayout->setStretch(0, 6);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 2);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableView = new QTableView(BookEditDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        idSelectradioButton = new QRadioButton(BookEditDialog);
        idSelectradioButton->setObjectName(QString::fromUtf8("idSelectradioButton"));

        verticalLayout->addWidget(idSelectradioButton);

        wortSelectradioButton = new QRadioButton(BookEditDialog);
        wortSelectradioButton->setObjectName(QString::fromUtf8("wortSelectradioButton"));

        verticalLayout->addWidget(wortSelectradioButton);


        horizontalLayout_2->addLayout(verticalLayout);

        goTolineEdit = new QLineEdit(BookEditDialog);
        goTolineEdit->setObjectName(QString::fromUtf8("goTolineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(goTolineEdit->sizePolicy().hasHeightForWidth());
        goTolineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(goTolineEdit);

        showAllButton = new QPushButton(BookEditDialog);
        showAllButton->setObjectName(QString::fromUtf8("showAllButton"));
        sizePolicy.setHeightForWidth(showAllButton->sizePolicy().hasHeightForWidth());
        showAllButton->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/sayabout.png"), QSize(), QIcon::Normal, QIcon::Off);
        showAllButton->setIcon(icon3);

        horizontalLayout_2->addWidget(showAllButton);

        ascendingOrderButton = new QPushButton(BookEditDialog);
        ascendingOrderButton->setObjectName(QString::fromUtf8("ascendingOrderButton"));
        sizePolicy.setHeightForWidth(ascendingOrderButton->sizePolicy().hasHeightForWidth());
        ascendingOrderButton->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/view_sort_ascending.png"), QSize(), QIcon::Normal, QIcon::Off);
        ascendingOrderButton->setIcon(icon4);

        horizontalLayout_2->addWidget(ascendingOrderButton);

        descendingOrderButton = new QPushButton(BookEditDialog);
        descendingOrderButton->setObjectName(QString::fromUtf8("descendingOrderButton"));
        sizePolicy.setHeightForWidth(descendingOrderButton->sizePolicy().hasHeightForWidth());
        descendingOrderButton->setSizePolicy(sizePolicy);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/view_sort_descending.png"), QSize(), QIcon::Normal, QIcon::Off);
        descendingOrderButton->setIcon(icon5);

        horizontalLayout_2->addWidget(descendingOrderButton);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        gridLayout->setRowStretch(0, 2);
        gridLayout->setRowStretch(1, 20);
        gridLayout->setRowStretch(2, 2);

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(BookEditDialog);

        QMetaObject::connectSlotsByName(BookEditDialog);
    } // setupUi

    void retranslateUi(QDialog *BookEditDialog)
    {
        BookEditDialog->setWindowTitle(QApplication::translate("BookEditDialog", "  \347\274\226\350\276\221\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        newRecordButton->setText(QApplication::translate("BookEditDialog", "\346\267\273\345\212\240\344\270\200\346\235\241\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        deleteRecordButton->setText(QApplication::translate("BookEditDialog", "\345\210\240\351\231\244\344\270\200\346\235\241\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        idSelectradioButton->setText(QApplication::translate("BookEditDialog", "\346\214\211 id \346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        wortSelectradioButton->setText(QApplication::translate("BookEditDialog", "\346\214\211\345\215\225\350\257\215\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        showAllButton->setText(QApplication::translate("BookEditDialog", "\346\230\276\347\244\272\345\205\250\350\241\250", 0, QApplication::UnicodeUTF8));
        ascendingOrderButton->setText(QApplication::translate("BookEditDialog", "\351\241\272\345\272\217\346\216\222\345\210\227", 0, QApplication::UnicodeUTF8));
        descendingOrderButton->setText(QApplication::translate("BookEditDialog", "\351\231\215\345\272\217\346\216\222\345\210\227", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BookEditDialog: public Ui_BookEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKEDITDIALOG_H
