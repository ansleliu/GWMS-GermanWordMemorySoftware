#include "AnsleDictDialog.h"
#include "ui_AnsleDictDialog.h"
#include "../AnsleDictConfigDialog.h"
#include "../bcmgr.h"
#include <QMenu>

AnsleDictDialog::AnsleDictDialog(QString word, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnsleDictDialog)
{
    qDebug() << QString("启动AnsleDictMini……");
    ui->setupUi(this);
    this->setAttribute (Qt::WA_DeleteOnClose);
    //////////////////////////////////////////////////////////////
    //初始化
    ///////////////////////////////////////////////////////////////////////////////////////
    //发音方法配置
    speakConfig = new ConfigFile(PathManage::makePathStr("/AnsleDict/speakConfig.ini"));
    ui->SpeakTTSPushButton->setEnabled(false);
    ui->AddToNewWordPushButton->setEnabled(false);

    //////////////////////////////////////////////////////////////////////
    //设置软件相关路径
    PathManage::createRelExeDir("/AnsleDict/MyDict/");
    PathManage::createRelExeDir("/AnsleDict/MyDict/Dict/");
    //////////////////////////////////////
    //
    speakMgr = NULL;
    minimodel = NULL;
    myDict = NULL;

    QString myDictDB = PathManage::makePathStr("/AnsleDict/MyDict/Dict/德汉词典.db");

    myDict = new CreatWordListDB(myDictDB,"MYDICT");

    minimodel = myDict->wordListDBModel(this,"WordsBook");
    ///////////////////////////////////////////////////////////
    //
    ui->WordTableView->setUpdatesEnabled(true);

    ui->WordTableView->setModel(minimodel);
    ui->WordTableView->hideColumn(0);
    ui->WordTableView->hideColumn(2);
    ui->WordTableView->hideColumn(3);
    ui->WordTableView->hideColumn(4);
    minimodel->select();

    ui->WordLineEdit->setFocus();
    ui->MeanTextBrowser->clear();

    qDebug() << QString("启动AnsleDictMini成功");
    //////////////////////////////////////////
    //
    ui->WordLineEdit->setText(word);
    minimodel->select();
}

AnsleDictDialog::~AnsleDictDialog()
{
    qDebug() << QString("关闭AnsleDictMini……");

    qDebug() << QString("~AnsleDictDialog清除model");
    if(minimodel != NULL)
    {
        minimodel->deleteLater();
        minimodel = NULL;
    }
    qDebug() << QString("~AnsleDictDialog清除speakMgr");
    if(speakMgr != NULL)
    {
        speakMgr->deleteLater();
        speakMgr = NULL;
    }
    qDebug() << QString("~AnsleDictDialog删除数据库MYDICT");
    if(myDict != NULL)
    {
        delete myDict;
        myDict = NULL;
    }
    qDebug() << QString("~AnsleDictDialog清除speakConfig");
    if(speakConfig != NULL)
    {
        delete speakConfig;
        speakConfig = NULL;
    }
    delete ui;
    qDebug() << QString("关闭AnsleDictMini成功");
}

void AnsleDictDialog::on_ConfigPushButton_clicked()
{
    AnsleDictConfigDialog * config;
    config = new AnsleDictConfigDialog(this,speakConfig);

    if(config->exec() == QDialog::Accepted)
    {

    }
    config->close();
    config->deleteLater();
    config = NULL;
}

void AnsleDictDialog::on_AddToNewWordPushButton_clicked()
{
    QModelIndex currIndex = ui->WordTableView->currentIndex();
    QString word = currIndex.data().toString();
    if(bcMgr->myBook->isExist(word))
    {
        QMessageBox::information(this, "提示信息", "该单词在生词本中已经存在,不必重复添加");
        ui->AddToNewWordPushButton->setEnabled(false);
    }
    else
    {
        int row = currIndex.row();
        QString mean = minimodel->index(row,2).data().toString();
        int count = bcMgr->myBook->getRowCount();
        int lektion = (count+1)/200 + 1;
        bcMgr->myBook->addNewRecord(word,mean,"",lektion);
        ui->AddToNewWordPushButton->setEnabled(false);
    }
}

void AnsleDictDialog::on_SpeakTTSPushButton_clicked()
{
    ui->SpeakTTSPushButton->setEnabled(false);

    QModelIndex currIndex = ui->WordTableView->currentIndex();
    QString word = currIndex.data().toString();
    if(speakMgr != NULL)
    {
        speakMgr->deleteLater();
        speakMgr = NULL;
    }
    speakMgr = new AnsleDictSpeakMgr(speakConfig,this);
    connect(speakMgr,SIGNAL(SpeakFininshed()),this,SLOT(setButtonState()));
    speakMgr->Speak(word,500,1);
}

void AnsleDictDialog::on_WordTableView_customContextMenuRequested(const QPoint &pos)
{
    QModelIndex currIndex = ui->WordTableView->indexAt(pos);
    //这种情况是右键的位置不在范围内，即在空白位置右击
    if(!currIndex.isValid())
    {

    }
    else
    {
        QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单
        popMenu->addAction(ui->action_AddToNewWord);
        popMenu->addAction(ui->action_Speak);

        popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置

        delete popMenu;
        popMenu = NULL;
    }
}

void AnsleDictDialog::on_WordLineEdit_textChanged(const QString &word)
{
    ui->WordLineEdit->setFocus();
    ui->MeanTextBrowser->clear();

    ui->SpeakTTSPushButton->setEnabled(false);
    ui->AddToNewWordPushButton->setEnabled(false);

    if(ui->ExpComboBox->currentIndex() == 0)
    {
        minimodel->setFilter(QString("Wort like '%1%'").arg(word));
        //显示结果
        minimodel->select();
    }
    else if(ui->ExpComboBox->currentIndex() == 1)
    {
        minimodel->setFilter(QString("Wort like '%%1%'").arg(word));
        //显示结果
        minimodel->select();
    }
    else if(ui->ExpComboBox->currentIndex() == 2)
    {
        minimodel->setFilter(QString("Wort like '%%1'").arg(word));
        //显示结果
        minimodel->select();
    }
}

void AnsleDictDialog::on_WordTableView_clicked(const QModelIndex &index)
{
    ui->SpeakTTSPushButton->setEnabled(true);
    ui->AddToNewWordPushButton->setEnabled(true);

    int row = index.row();
    QString mean = minimodel->index(row,2).data().toString();

    ui->MeanTextBrowser->clear();
    ui->MeanTextBrowser->setText(mean);
}

void AnsleDictDialog::on_ExpComboBox_currentIndexChanged(int index)
{
    ui->WordLineEdit->setFocus();
    ui->MeanTextBrowser->clear();
    ui->SpeakTTSPushButton->setEnabled(false);
    ui->AddToNewWordPushButton->setEnabled(false);

    if(index == 0)
    {
        minimodel->setFilter(QString("Wort like '%1%'").arg(ui->WordLineEdit->text()));
        //显示结果
        minimodel->select();
    }
    else if(index == 1)
    {
        minimodel->setFilter(QString("Wort like '%%1%'").arg(ui->WordLineEdit->text()));
        //显示结果
        minimodel->select();
    }
    else if(index == 2)
    {
        minimodel->setFilter(QString("Wort like '%%1'").arg(ui->WordLineEdit->text()));
        //显示结果
        minimodel->select();
    }
}

void AnsleDictDialog::on_action_AddToNewWord_triggered()
{
    on_AddToNewWordPushButton_clicked();
}

void AnsleDictDialog::on_action_Speak_triggered()
{
    on_SpeakTTSPushButton_clicked();
}

void AnsleDictDialog::setButtonState()
{
    ui->SpeakTTSPushButton->setEnabled(true);
    if(speakMgr != NULL)
    {
        speakMgr->deleteLater();
        speakMgr = NULL;
    }
}
