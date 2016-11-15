#include "addrootdialog.h"
#include "ui_addrootdialog.h"

AddRootDialog::AddRootDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRootDialog)
{
    ui->setupUi(this);
}

AddRootDialog::~AddRootDialog()
{
    delete ui;
}

QString AddRootDialog::getNewRoot()
{
    return ui->lineEdit->text();
}

void AddRootDialog::on_OKPushButton_clicked()
{
    if(getNewRoot().isEmpty())
    {
        QMessageBox::warning(this, tr("错误"),
                             tr("\n新添加的分类名不能为空!"),
                             QMessageBox::Ok);
    }
    else
    {
        accept();
    }
}

void AddRootDialog::on_NOPushButton_clicked()
{
    close();
}
