/********************************************************************************
** Form generated from reading UI file 'findkeydialog.ui'
**
** Created: Tue Nov 24 04:05:57 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDKEYDIALOG_H
#define UI_FINDKEYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FindKeyDialog
{
public:
    QGroupBox *FindKeyGroupBox;
    QLabel *UserLabel;
    QLabel *KeyLabel;
    QLineEdit *UserLineEdit;
    QLineEdit *KeyLineEdit;
    QPushButton *GoBackButton;

    void setupUi(QDialog *FindKeyDialog)
    {
        if (FindKeyDialog->objectName().isEmpty())
            FindKeyDialog->setObjectName(QString::fromUtf8("FindKeyDialog"));
        FindKeyDialog->resize(292, 141);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/kgpg_identity_kgpg.png"), QSize(), QIcon::Normal, QIcon::Off);
        FindKeyDialog->setWindowIcon(icon);
        FindKeyGroupBox = new QGroupBox(FindKeyDialog);
        FindKeyGroupBox->setObjectName(QString::fromUtf8("FindKeyGroupBox"));
        FindKeyGroupBox->setGeometry(QRect(10, 10, 271, 81));
        UserLabel = new QLabel(FindKeyGroupBox);
        UserLabel->setObjectName(QString::fromUtf8("UserLabel"));
        UserLabel->setGeometry(QRect(20, 20, 61, 21));
        KeyLabel = new QLabel(FindKeyGroupBox);
        KeyLabel->setObjectName(QString::fromUtf8("KeyLabel"));
        KeyLabel->setGeometry(QRect(20, 50, 61, 21));
        UserLineEdit = new QLineEdit(FindKeyGroupBox);
        UserLineEdit->setObjectName(QString::fromUtf8("UserLineEdit"));
        UserLineEdit->setGeometry(QRect(82, 19, 171, 21));
        UserLineEdit->setReadOnly(true);
        KeyLineEdit = new QLineEdit(FindKeyGroupBox);
        KeyLineEdit->setObjectName(QString::fromUtf8("KeyLineEdit"));
        KeyLineEdit->setGeometry(QRect(82, 50, 171, 20));
        KeyLineEdit->setReadOnly(true);
        GoBackButton = new QPushButton(FindKeyDialog);
        GoBackButton->setObjectName(QString::fromUtf8("GoBackButton"));
        GoBackButton->setGeometry(QRect(190, 100, 71, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        GoBackButton->setIcon(icon1);

        retranslateUi(FindKeyDialog);

        QMetaObject::connectSlotsByName(FindKeyDialog);
    } // setupUi

    void retranslateUi(QDialog *FindKeyDialog)
    {
        FindKeyDialog->setWindowTitle(QApplication::translate("FindKeyDialog", "  \346\211\276\345\233\236\345\257\206\347\240\201  ", 0, QApplication::UnicodeUTF8));
        FindKeyGroupBox->setTitle(QApplication::translate("FindKeyDialog", "\346\211\276\345\233\236\347\224\250\346\210\267\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        UserLabel->setText(QApplication::translate("FindKeyDialog", "\347\224\250 \346\210\267 \345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        KeyLabel->setText(QApplication::translate("FindKeyDialog", "\345\257\206\347\240\201\346\217\220\347\244\272\357\274\232", 0, QApplication::UnicodeUTF8));
        GoBackButton->setText(QApplication::translate("FindKeyDialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FindKeyDialog: public Ui_FindKeyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDKEYDIALOG_H
