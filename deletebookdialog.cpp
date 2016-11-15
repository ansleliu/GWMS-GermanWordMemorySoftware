#include "deletebookdialog.h"
#include "ui_deletebookdialog.h"

DeleteBookDialog::DeleteBookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteBookDialog)
{
    ui->setupUi(this);

    bookName = "";
    bookPath = "";
}

DeleteBookDialog::~DeleteBookDialog()
{
    delete ui;
}

QString DeleteBookDialog::getClassName()
{
    return ui->classLineEdit->text();
}

QString DeleteBookDialog::getBookName()
{
    return ui->bookLineEdit->text();
}

QString DeleteBookDialog::getBookPath()
{
    return bookPath;
}

void DeleteBookDialog::setClassName(const QString &bookclass)
{
    ui->classLineEdit->setText(bookclass);
}

void DeleteBookDialog::setBookName(const QString &bookname)
{
    ui->bookLineEdit->setText(bookname);
}

void DeleteBookDialog::on_OKButton_clicked()
{
    if(getClassName().isEmpty() || getBookName().isEmpty())
    {
        QMessageBox::warning(this, tr("错误"),
                             tr("\n类名和词库名都不能为空!"),
                             QMessageBox::Ok);
    }
    else
    {
        accept();
    }
}

void DeleteBookDialog::on_QuitButton_clicked()
{
    close();
}
