#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "QMessageBox"
#include "pathmanage.h"
#include "findkeydialog.h"

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit loginDialog(QWidget *parent = 0, bool bDisableAutoLogin = false);
    ~loginDialog();

private:
    bool initComboBoxUserList();

private slots:
    void on_creatNewuserButton_clicked();

    void on_forgetPasswordButton_clicked();

    void on_remembercheckBox_clicked(bool checked);

    void on_autocheckBox_clicked(bool checked);

    void on_loginButton_clicked();

    void on_quitButton_clicked();

    void on_usernameComboBox_currentIndexChanged(const QString &userName);

private:
    Ui::loginDialog *ui;
    bool m_bDisableAutoLogin;
};

#endif // LOGINDIALOG_H
