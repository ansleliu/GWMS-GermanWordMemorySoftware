#include "findkeydialog.h"
#include "ui_findkeydialog.h"

FindKeyDialog::FindKeyDialog(QWidget *parent,const QString &username) :
    QDialog(parent),
    ui(new Ui::FindKeyDialog)
{
    ui->setupUi(this);

    ui->UserLineEdit->setText(username);
    QString password = Global::UserMag->getUserInfo("password",username).toString();
    QString passwordInfo = "";
    for(int i=0; i < password.count(); i++)
    {
        if(i < 3*password.count()/4)
        {
            passwordInfo.append("*");
        }
        else
        {
            passwordInfo.append(password.at(i));
        }
    }
    ui->KeyLineEdit->setText(passwordInfo);
}

FindKeyDialog::~FindKeyDialog()
{
    delete ui;
}

void FindKeyDialog::on_GoBackButton_clicked()
{
    QDialog::close();
}
