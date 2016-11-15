#include "addbookdialog.h"
#include "ui_addbookdialog.h"
#include "QMessageBox"
#include "QFileDialog"
#include "QFileInfo"
#include "pathmanage.h"
#include "myglobal.h"

AddBookDialog::AddBookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBookDialog)
{
    ui->setupUi(this);

    bookName = "";
    bookPath = "";
}

AddBookDialog::~AddBookDialog()
{
    delete ui;
}

QString AddBookDialog::getClassName()
{
    return ui->classLineEdit->text();
}

QString AddBookDialog::getBookName()
{
    return ui->bookLineEdit->text();
}

QString AddBookDialog::getBookPath()
{
    return bookPath;
}

void AddBookDialog::setClassName(const QString &bookclass)
{
    ui->classLineEdit->setText(bookclass);
}

void AddBookDialog::setBookName(const QString &bookname)
{
    ui->bookLineEdit->setText(bookname);
}

void AddBookDialog::on_pushButton_clicked()
{
    QString userBookPath = PathManage::makePathStr("/userdata/" +
                                                   Global::Conf->getCurrentUser() + "/book/");
    QString filename = QFileDialog::getOpenFileName(this,
            tr("添加新词库"), userBookPath, tr("数据库文件(*.db)"));
    if (filename.isEmpty())
        return;
    else if(!filename.contains(".db", Qt::CaseInsensitive))
    {
        QMessageBox::warning(this, tr("出错了"),
         QString(tr("请把词库文件放到%1目录下并将其打开！")).arg(userBookPath));
        return;
    }
    else
    {
        QFileInfo fd(filename);
        bookName = fd.baseName();
        //bookPath = fd.filePath();
        bookPath = userBookPath.append(bookName);
        setBookName(bookName);
    }
}

void AddBookDialog::on_OKButton_clicked()
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

void AddBookDialog::on_QuitButton_clicked()
{
    close();
}
