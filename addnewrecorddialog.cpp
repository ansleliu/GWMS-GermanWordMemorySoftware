#include "addnewrecorddialog.h"
#include "ui_addnewrecorddialog.h"

AddNewRecordDialog::AddNewRecordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewRecordDialog)
{
    ui->setupUi(this);
}

AddNewRecordDialog::~AddNewRecordDialog()
{
    delete ui;
}

QString AddNewRecordDialog::getWord()
{
    return ui->WordLineEdit->text();
}

QString AddNewRecordDialog::getMean()
{
    return ui->MeanTextEdit->toPlainText();
}

QString AddNewRecordDialog::getOther()
{
    return ui->OtherTextEdit->toPlainText();
}

int AddNewRecordDialog::getLektion()
{
    return ui->LektionLineEdit->text().toInt();
}

void AddNewRecordDialog::setWord(const QString &word)
{
    ui->WordLineEdit->setText(word);
}

void AddNewRecordDialog::setMean(const QString &mean)
{
    ui->MeanTextEdit->setText(mean);
}

void AddNewRecordDialog::setOther(const QString &other)
{
    ui->OtherTextEdit->setText(other);
}

void AddNewRecordDialog::setLektion(const int &lektion)
{
    ui->LektionLineEdit->setText(QString::number(lektion,'i',0));
}

void AddNewRecordDialog::setGroupTitle(const QString &title)
{
    ui->InfoGroupBox->setTitle(title);
}

void AddNewRecordDialog::setLektionLineEditRradOnly()
{
    ui->LektionLineEdit->setReadOnly(true);
}

void AddNewRecordDialog::on_CloseButton_clicked()
{
    QDialog::reject();
}

void AddNewRecordDialog::on_OKButton_clicked()
{
    QDialog::accept();
}
