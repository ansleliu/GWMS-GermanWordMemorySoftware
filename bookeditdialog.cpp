#include "bookeditdialog.h"
#include "ui_bookeditdialog.h"
#include "addnewrecorddialog.h"
#include <QMessageBox>
#include <QSqlError>
#include <QIcon>
#include <QSqlQuery>
#include <QTime>
#include <QTimer>
#include "bcmgr.h"

BookEditDialog::BookEditDialog(QWidget *parent, const QString &BookPath) :
    QDialog(parent),
    ui(new Ui::BookEditDialog)
{
    ui->setupUi(this);

    QDateTime currtime = QDateTime::currentDateTime();//获取系统现在的时间
    QString str = currtime.toString("yyyy-MM-dd dddd hh:mm:ss  "); //设置显示格式
    ui->label->setText(str);//在标签上显示时间

    //定时器，每1000ms执行一次槽函数displayTime()
    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(displayTime()));

    bookpath = BookPath;
    tableName = "WordsBook";
    bookEdit = new BookEdit(bookpath,"BOOKEDIT");
    model = bookEdit->wordListDBModel(this,tableName);
    ui->tableView->setModel(model);

    asIdSelect = "FALSE";//按id查询关
    asWortSelect = "FALSE";//按wort查询关
    descendingOrder = "FALSE";//按降序关

    ui->goTolineEdit->setDisabled(true);
}

BookEditDialog::~BookEditDialog()
{
    delete bookEdit;
    delete ui;
}

void BookEditDialog::displayTime()
{
    QDateTime currtime = QDateTime::currentDateTime();//获取系统现在的时间
    QString str = currtime.toString("yyyy-MM-dd dddd hh:mm:ss "); //设置显示格式
    ui->label->setText(str);//在标签上显示时间
}

void BookEditDialog::on_newRecordButton_clicked()
{
    int rowNum = bookEdit->getRowCount();
    qDebug() << rowNum;

    AddNewRecordDialog *newRecord;
    newRecord = new AddNewRecordDialog(this);

    if(newRecord->exec() == QDialog::Accepted)
    {
/*
        model->insertRow(rowNum); //添加一行
        model->setData(model->index(rowNum,0),rowNum+1);//主键id自增
        model->setData(model->index(rowNum,1),newRecord->getWord());
        model->setData(model->index(rowNum,2),newRecord->getMean());
        model->setData(model->index(rowNum,3),newRecord->getOther());
        model->setData(model->index(rowNum,4),newRecord->getLektion());
        model->submitAll(); //直接提交
*/
        bookEdit->addNewRecord(newRecord->getWord(),
                               newRecord->getMean(),
                               newRecord->getOther(),
                               newRecord->getLektion());
        model->select();
    }
    ///////////////////////////////////////////////////////////////////
    //窗口后续处理
    newRecord->close();
    newRecord->deleteLater();
    newRecord = NULL;
    ////////////////////////////
    //更新词库词汇量
    updateWordCount();
}

void BookEditDialog::on_deleteRecordButton_clicked()
{
    int rowNum = bookEdit->getRowCount();
    qDebug() << rowNum;
    //删除该行
//    model->removeRow(rowNum-1);
    int ok = QMessageBox::warning(this,tr("删除最后一行"),
                                  tr("选择所要删除的行后再进行这个操作！"
                                      "\n         "
                                      "你确定删除第 %1 行吗？").arg(rowNum),
                                  QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No)
    {
       model->select(); //如果不删除，则撤销
    }
    else
    {
        bookEdit->removeRecord(rowNum); //否则提交，在数据库中删除该行
        model->select();
        ////////////////////////////
        //更新词库词汇量
        updateWordCount();
    }
}

void BookEditDialog::on_showAllButton_clicked()
{
    descendingOrder = "FALSE";

    model->setTable(tableName);//重新关联表
    model->select();   //显示整个表的内容

    ui->newRecordButton->setDisabled(false);
    ui->deleteRecordButton->setEnabled(true);
}

void BookEditDialog::on_ascendingOrderButton_clicked()
{
    descendingOrder = "FALSE";

    model->setSort(0, Qt::AscendingOrder); //按Wid属性即第0列升序排列
    model->select();
}

void BookEditDialog::on_descendingOrderButton_clicked()
{
    descendingOrder = "TRUE";
    model->setSort(0, Qt::DescendingOrder);  //按Wid属性即第0列降序排列
    model->select();
}

void BookEditDialog::on_idSelectradioButton_clicked()
{
    asWortSelect = "FALSE";//按wort查询关
    asIdSelect = "TRUE";//按id查询开

    ui->goTolineEdit->setDisabled(false);

    deleteMethode == "FALSE";
    ui->deleteRecordButton->setDisabled(true);
    ui->newRecordButton->setDisabled(true);
}

void BookEditDialog::on_wortSelectradioButton_clicked()
{
    asIdSelect = "FALSE";//按id查询关
    asWortSelect = "TRUE";//按wort查询开

    ui->goTolineEdit->setDisabled(false);

    deleteMethode == "FALSE";
    ui->deleteRecordButton->setDisabled(true);
    ui->newRecordButton->setDisabled(true);
}

void BookEditDialog::updateWordCount()
{
    //////////////////////////
    //获取词库量
    int rowCount = bookEdit->getRowCount();
    bcMgr->updateTotalNumb(bookpath,rowCount);
}

void BookEditDialog::on_tableView_doubleClicked(const QModelIndex &index)
{
    EditorDialog *dialog;
    dialog = new EditorDialog(this);

    QString text;
    text = index.data().toString();
    dialog->setText(text);

    dialog->exec();
    text = dialog->getText();

    if(dialog->applyChange == "TRUE")
    {
        model->setData(index,text);
        model->submitAll();
    }
    else
    {
        model->submitAll();
    }
    dialog->close();
    delete dialog;
    dialog = NULL;
}

void BookEditDialog::on_goTolineEdit_textChanged(const QString &keyWort)
{
    ui->newRecordButton->setDisabled(true);
    //根据姓名进行筛选
    if(asWortSelect == "TRUE" && asIdSelect == "FALSE")
    {
        model->setFilter(QString("Wort like '%%1%'").arg(keyWort));
        //显示结果
        model->select();
    }
    else if(asWortSelect == "FALSE" && asIdSelect == "TRUE")
    {
        model->setFilter(QString("Wid = '%1'").arg(keyWort.toInt()));
        //显示结果
        model->select();
    }
}
