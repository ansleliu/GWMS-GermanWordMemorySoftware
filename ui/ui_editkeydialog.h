/********************************************************************************
** Form generated from reading UI file 'editkeydialog.ui'
**
** Created: Tue Nov 24 04:05:57 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITKEYDIALOG_H
#define UI_EDITKEYDIALOG_H

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

class Ui_EditKeyDialog
{
public:
    QGroupBox *GroupBox;
    QLabel *oldkeylabel;
    QLabel *newkeylabel;
    QLabel *surelabel;
    QLineEdit *oldKeyLineEdit;
    QLineEdit *newKeyLineEdit;
    QLineEdit *sureKeyLineEdit;
    QPushButton *quitButton;
    QPushButton *OKButton;

    void setupUi(QDialog *EditKeyDialog)
    {
        if (EditKeyDialog->objectName().isEmpty())
            EditKeyDialog->setObjectName(QString::fromUtf8("EditKeyDialog"));
        EditKeyDialog->resize(272, 181);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/kgpg_sign_kgpg.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditKeyDialog->setWindowIcon(icon);
        GroupBox = new QGroupBox(EditKeyDialog);
        GroupBox->setObjectName(QString::fromUtf8("GroupBox"));
        GroupBox->setGeometry(QRect(10, 10, 251, 131));
        oldkeylabel = new QLabel(GroupBox);
        oldkeylabel->setObjectName(QString::fromUtf8("oldkeylabel"));
        oldkeylabel->setGeometry(QRect(20, 30, 54, 21));
        newkeylabel = new QLabel(GroupBox);
        newkeylabel->setObjectName(QString::fromUtf8("newkeylabel"));
        newkeylabel->setGeometry(QRect(20, 60, 54, 21));
        surelabel = new QLabel(GroupBox);
        surelabel->setObjectName(QString::fromUtf8("surelabel"));
        surelabel->setGeometry(QRect(20, 90, 54, 20));
        oldKeyLineEdit = new QLineEdit(GroupBox);
        oldKeyLineEdit->setObjectName(QString::fromUtf8("oldKeyLineEdit"));
        oldKeyLineEdit->setGeometry(QRect(80, 30, 151, 21));
        newKeyLineEdit = new QLineEdit(GroupBox);
        newKeyLineEdit->setObjectName(QString::fromUtf8("newKeyLineEdit"));
        newKeyLineEdit->setGeometry(QRect(80, 60, 151, 20));
        sureKeyLineEdit = new QLineEdit(GroupBox);
        sureKeyLineEdit->setObjectName(QString::fromUtf8("sureKeyLineEdit"));
        sureKeyLineEdit->setGeometry(QRect(80, 89, 151, 21));
        quitButton = new QPushButton(EditKeyDialog);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(160, 150, 71, 23));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        quitButton->setIcon(icon1);
        OKButton = new QPushButton(EditKeyDialog);
        OKButton->setObjectName(QString::fromUtf8("OKButton"));
        OKButton->setGeometry(QRect(40, 150, 71, 23));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        OKButton->setIcon(icon2);

        retranslateUi(EditKeyDialog);

        QMetaObject::connectSlotsByName(EditKeyDialog);
    } // setupUi

    void retranslateUi(QDialog *EditKeyDialog)
    {
        EditKeyDialog->setWindowTitle(QApplication::translate("EditKeyDialog", "  \346\233\264\346\224\271\345\257\206\347\240\201  ", 0, QApplication::UnicodeUTF8));
        GroupBox->setTitle(QApplication::translate("EditKeyDialog", "\346\233\264\346\224\271\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        oldkeylabel->setText(QApplication::translate("EditKeyDialog", "\346\227\247 \345\257\206 \347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        newkeylabel->setText(QApplication::translate("EditKeyDialog", "\346\226\260 \345\257\206 \347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        surelabel->setText(QApplication::translate("EditKeyDialog", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("EditKeyDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        OKButton->setText(QApplication::translate("EditKeyDialog", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EditKeyDialog: public Ui_EditKeyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITKEYDIALOG_H
