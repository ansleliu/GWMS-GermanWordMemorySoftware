/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created: Tue Nov 24 04:05:57 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

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
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QGroupBox *groupBox;
    QComboBox *usernameComboBox;
    QLineEdit *passwordlineEdit;
    QLabel *mimalabel;
    QCheckBox *remembercheckBox;
    QPushButton *creatNewuserButton;
    QPushButton *forgetPasswordButton;
    QCheckBox *autocheckBox;
    QLabel *userlabel;
    QPushButton *loginButton;
    QPushButton *quitButton;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QString::fromUtf8("loginDialog"));
        loginDialog->resize(382, 211);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix2/rc/loginicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        loginDialog->setWindowIcon(icon);
        groupBox = new QGroupBox(loginDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 361, 151));
        usernameComboBox = new QComboBox(groupBox);
        usernameComboBox->setObjectName(QString::fromUtf8("usernameComboBox"));
        usernameComboBox->setGeometry(QRect(80, 30, 171, 31));
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        usernameComboBox->setFont(font);
        usernameComboBox->setCursor(QCursor(Qt::ArrowCursor));
        usernameComboBox->setMouseTracking(false);
        usernameComboBox->setFocusPolicy(Qt::TabFocus);
        usernameComboBox->setEditable(true);
        usernameComboBox->setIconSize(QSize(24, 24));
        usernameComboBox->setModelColumn(0);
        passwordlineEdit = new QLineEdit(groupBox);
        passwordlineEdit->setObjectName(QString::fromUtf8("passwordlineEdit"));
        passwordlineEdit->setGeometry(QRect(80, 80, 171, 31));
        passwordlineEdit->setEchoMode(QLineEdit::Password);
        mimalabel = new QLabel(groupBox);
        mimalabel->setObjectName(QString::fromUtf8("mimalabel"));
        mimalabel->setGeometry(QRect(20, 70, 51, 51));
        mimalabel->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix2/rc/mimaicon.png")));
        mimalabel->setScaledContents(true);
        remembercheckBox = new QCheckBox(groupBox);
        remembercheckBox->setObjectName(QString::fromUtf8("remembercheckBox"));
        remembercheckBox->setGeometry(QRect(90, 120, 71, 20));
        creatNewuserButton = new QPushButton(groupBox);
        creatNewuserButton->setObjectName(QString::fromUtf8("creatNewuserButton"));
        creatNewuserButton->setGeometry(QRect(260, 30, 81, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/user_group_new.png"), QSize(), QIcon::Normal, QIcon::Off);
        creatNewuserButton->setIcon(icon1);
        forgetPasswordButton = new QPushButton(groupBox);
        forgetPasswordButton->setObjectName(QString::fromUtf8("forgetPasswordButton"));
        forgetPasswordButton->setGeometry(QRect(260, 80, 81, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/kgpg_identity_kgpg.png"), QSize(), QIcon::Normal, QIcon::Off);
        forgetPasswordButton->setIcon(icon2);
        autocheckBox = new QCheckBox(groupBox);
        autocheckBox->setObjectName(QString::fromUtf8("autocheckBox"));
        autocheckBox->setGeometry(QRect(190, 120, 71, 20));
        userlabel = new QLabel(groupBox);
        userlabel->setObjectName(QString::fromUtf8("userlabel"));
        userlabel->setGeometry(QRect(20, 20, 51, 51));
        userlabel->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix2/rc/loginuser.png")));
        userlabel->setScaledContents(true);
        loginButton = new QPushButton(loginDialog);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(90, 170, 75, 31));
        loginButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        loginButton->setIcon(icon3);
        quitButton = new QPushButton(loginDialog);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(220, 170, 75, 31));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        quitButton->setIcon(icon4);

        retranslateUi(loginDialog);

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QApplication::translate("loginDialog", "    \347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("loginDialog", "\346\254\242\350\277\216\344\275\277\347\224\250\345\276\267\350\257\255\350\203\214\345\215\225\350\257\215\350\275\257\344\273\266\357\274\214\350\257\267\346\202\250\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        mimalabel->setText(QString());
        remembercheckBox->setText(QApplication::translate("loginDialog", "\350\256\260\344\275\217\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        creatNewuserButton->setText(QApplication::translate("loginDialog", "\346\226\260\345\273\272\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        forgetPasswordButton->setText(QApplication::translate("loginDialog", "\345\277\230\350\256\260\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        autocheckBox->setText(QApplication::translate("loginDialog", "\350\207\252\345\212\250\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        userlabel->setText(QString());
        loginButton->setText(QApplication::translate("loginDialog", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("loginDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
