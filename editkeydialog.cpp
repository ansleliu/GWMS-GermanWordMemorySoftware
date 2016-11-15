#include "editkeydialog.h"
#include "ui_editkeydialog.h"
#include "QMessageBox"
EditKeyDialog::EditKeyDialog(QWidget *parent,const QString &userName) :
    QDialog(parent),
    ui(new Ui::EditKeyDialog)
{
    ui->setupUi(this);
    currUserName = userName;
}

EditKeyDialog::~EditKeyDialog()
{
    delete ui;
}

void EditKeyDialog::on_OKButton_clicked()
{
    QString oldKey = ui->oldKeyLineEdit->text();
    if(Global::UserMag->verifyPsw(currUserName,oldKey))
    {
        if(ui->newKeyLineEdit->text() == ui->sureKeyLineEdit->text())
        {
            Global::UserMag->updatePassword(currUserName,ui->newKeyLineEdit->text());
            QDialog::accept();
        }
        else
        {
            QMessageBox::warning(this, tr("错误"), tr("密码不一致(注意大小写),请重新输入."));
        }
    }
    else
    {
        QMessageBox::warning(this, tr("错误"), tr("密码错误(注意大小写),请重新输入."));
    }

}

void EditKeyDialog::on_quitButton_clicked()
{
    QDialog::close();
}
