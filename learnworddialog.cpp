#include "learnworddialog.h"
#include "ui_learnworddialog.h"
#include <QKeySequence>
#include "addnewrecorddialog.h"
#include "QDebug"
#include "QFileInfo"
#include "QDesktopServices"
#include "QMenu"
#include "QCursor"

LearnWordDialog::LearnWordDialog(QWidget *parent, const QString &bookpath,
                                 const QString &learnOrreview,
                                 const bool &learnbylektion,
                                 const int &Lektion) :
    QDialog(parent),
    ui(new Ui::LearnWordDialog)
{
    ui->setupUi(this);
    ui->TabWidget->setCurrentIndex(0);
    ui->progressBar->hide();
    ///////////////////////////////////////////////////
    //获取必要信息并初始化
    bookPath = bookpath;    
    learnOrReview = learnOrreview;
    learnByLektion = learnbylektion;
    lektion = Lektion;
    QFileInfo bookInfo(bookPath);
    bookName = bookInfo.baseName();
    qDebug() << QString("当前背诵的词库为: %1").arg(bookName);

    //////////////////////////////////////////////////////////////
    //音频信号与槽连接
    speakMgr = new SpeakMgr(0,bookName);
    connect(speakMgr,SIGNAL(SpeakFininshed()),this,SLOT(setButtonState()));
/*
    sound = new SoundTread();
    connect(sound,SIGNAL(soundEnded()),this,SLOT(setButtonState()));
    connect(this,SIGNAL(rejected()),this,SLOT(stopThread()));

    speakGoogleTTS = new SpeakGoogle();
    connect(speakGoogleTTS,SIGNAL(soundEnded()),this,SLOT(setButtonState()));

    speakRealPerson = new SpeakReal();
    connect(speakRealPerson,SIGNAL(soundEnded()),this,SLOT(setButtonState()));
*/
    //////////////////////////////////////////////////////////////////
    //获取词库管理器来取得词库中的信息
    if(userBookDBMgr)
    {
        delete userBookDBMgr;
    }
    userBookDBMgr = new UserBookDBMgr(bookPath,bcMgr->getBookName(bookPath));
    if(learnByLektion)
    {
        if(learnOrReview == "Learn")
        {
            wordCount = userBookDBMgr->getWordCountByLektion(lektion);
            haveLearnedCount = learnMgr->getHaveLearnedWordCountByLektion(bookPath,lektion);
            wordID = userBookDBMgr->getWordIDByLektion(lektion);
        }
        if(learnOrReview == "Review")
        {
            wordID = learnMgr->getReviewWordIDByLektion("StateTable",bookPath,lektion);
            wordCount = wordID.count();
        }
    }
    else
    {

        if(learnOrReview == "Learn")
        {
            LearnWordConfigDialog *config;
            config = new LearnWordConfigDialog();
            config->setOutOrderlyRadioButtonUnable();

            wordCount = userBookDBMgr->getWortCount();
            haveLearnedCount = learnMgr->getHaveLearnedWordCount(bookPath);

            config->deleteLater();
            config = NULL;
        }
        if(learnOrReview == "Review")
        {
            wordID = learnMgr->getReviewWordID("StateTable",bookPath);
            wordCount = wordID.count();
        }
    }
    //////////////////////////////////////////////////////
    //创建计时器
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displayTime()));

    timerByLektion = new QTimer(this);
    connect(timerByLektion, SIGNAL(timeout()), this, SLOT(displayTime()));

    /////////////////////////////////////////////////
    //初始化
    QTimer::singleShot(1, this, SLOT(initAll()));
}

LearnWordDialog::~LearnWordDialog()
{
    qDebug() << QString("~LearnWordDialog清除ansleDict");
    if(ansleDict != NULL)
    {
        if(ansleDict->isActiveWindow())
        {
            ansleDict->close();
        }
        ansleDict->deleteLater();
        ansleDict = NULL;
    }
    qDebug() << QString("~LearnWordDialog清除speakMgr");
    speakMgr->deleteLater();
    speakMgr = NULL;

    if(timer != NULL)
    {
        delete timer;
    }
    if(timerByLektion != NULL)
    {
        delete timerByLektion;
    }
    delete ui;
}

void LearnWordDialog::initAll()
{
    ///////////////////////////
    //初始化变量
    ansleDict = NULL;
    nextButtonEnable = false;
    afterSure = false;
    time = 0;
    outWordId = 0;

    word.clear();
    reviewWordID = 0;
    judgeTime = 0;
    judgeState = "";

    Grade = 0;        //单词等级
    Repetition = 0;   //重复次数
    Interval = 0;     //间隔时间
    EF = 2.50;         //难度因子
    ///////////////////////////////////
    //如果临时状态表有记录,保存记录,并清空临时状态表
    learnMgr->transferRecord();
    showWordCount = 0;
    //////////////////////////////////
    //初始化QLCDNumber显示
    QString display = "00:00:00";
    ui->lcdNumber->display(display);
    //////////////////////////////////////////
    //初始化其它显示面板
    ui->WordShowLabel->clear();
    ui->TextBrowser->clear();
    ui->OITextBrowser->clear();
    /////////////////////////////////////////////////
    //按钮初始化显示
    ui->NextButton->setEnabled(false);

    ui->RightButton->setEnabled(false);
    ui->WrongButton->setEnabled(false);

    ui->EditWordButton->setEnabled(false);
    ui->ConfigButton->setEnabled(false);

    ui->RememButton->setEnabled(true);
    ui->NotSureButton->setEnabled(true);
    ui->ForgetButton->setEnabled(true);

    ////////////////////////////////
    //获取配置信息
    getConfInfo();
    ///////////////////////////////
    //初次出词
    currWordCount = wordCount;
    if(learnByLektion)
    {
       getWordByLektion(lektion);
    }
    else
    {
        getWord();
    }
}

void LearnWordDialog::getConfInfo()
{
    //////////////////////////////////////////////////////////
    //获取配置信息
    learnMethod = bcMgr->userConf->getLearnMethod();
    outWordMethod = bcMgr->userConf->getOutWordMethod();
    reviewWordMethod = bcMgr->userConf->getReviewWordMethod();

    bool isOpenSound = bcMgr->userConf->getIsOpenSound();
    ui->SoundEnableCheckBox->setChecked(isOpenSound);
    if(!ui->SoundButton->isChecked())
    {
        ui->SoundButton->setEnabled(false);
        nextButtonEnable = true;
    }
    else
    {
        ui->SoundButton->setEnabled(true);
    }
    soundTime = bcMgr->userConf->getSoundTime().toInt();
    interval = bcMgr->userConf->getInterval().toInt();

    QMap<QString, QString> shortcutList = bcMgr->userConf->getShortcut();
    ui->RememButton->setShortcut(QKeySequence(shortcutList.value("RememShortcut")));
    ui->NotSureButton->setShortcut(QKeySequence(shortcutList.value("NotSureShortcut")));
    ui->ForgetButton->setShortcut(QKeySequence(shortcutList.value("ForgetShortcut")));
    ui->RightButton->setShortcut(QKeySequence(shortcutList.value("RightShortcut")));
    ui->WrongButton->setShortcut(QKeySequence(shortcutList.value("WrongShortcut")));
    ui->EditWordButton->setShortcut(QKeySequence(shortcutList.value("EditWortShortcut")));
    ui->SoundButton->setShortcut(QKeySequence(shortcutList.value("SoundShortcut")));
    ui->NextButton->setShortcut(QKeySequence(shortcutList.value("NextShortcut")));
    ui->ConfigButton->setShortcut(QKeySequence(shortcutList.value("ConfigShortcut")));
}

void LearnWordDialog::displayTime()
{
    time++;
    int hour = time/3600;
    QString hourStr;
    if( hour < 10)
    {
        hourStr = "0" + QString::number(hour,'i',0);
    }
    else
    {
        hourStr = QString::number(hour,'i',0);
    }

    int min = (time%3600)/60;
    QString minStr;
    if(min < 10)
    {
        minStr = "0" + QString::number(min,'i',0);
    }
    else
    {
        minStr = QString::number(min,'i',0);
    }

    int sec = (time%3600)%60;
    QString secStr;
    if(sec < 10)
    {
        secStr = "0" + QString::number(sec,'i',0);
    }
    else
    {
        secStr = QString::number(sec,'i',0);
    }
    QString display = hourStr + ":" + minStr + ":" + secStr;
    ui->lcdNumber->display(display);
}

void LearnWordDialog::getWordByLektion(const int &lektion)
{
    /////////////////////////////////////////////////////////////////////
    //是否有要复习的单词
    QList<int> reviewWordIDByLektion = learnMgr->getReviewWordIDByLektion("CurrTimeStateTable",
                                                                          bookPath,lektion);
    int reviewWordCount = reviewWordIDByLektion.count();
    /////////////////////////////////////////
    //如果有要复习的单词
    if(reviewWordCount > 0)
    {
        reviewWordID = reviewWordIDByLektion.at(0);
        word = learnMgr->getWordAll("CurrTimeStateTable",reviewWordID);
        wid = learnMgr->getImportantInfo("CurrTimeStateTable",reviewWordID).at(0).toInt();
    }
    else
    {
        wid = 0;
        rid = 0;
        if(outWordMethod == "Random")
        {
            if(learnOrReview == "Learn")
            {
                if(showWordCount >= (wordCount-haveLearnedCount))
                {
                    if(QMessageBox::information(this,tr("提示"),
                                                QString(tr("已经没有需要背诵的单词\n请退出选择其他单元或词库"))
                                                ,QMessageBox::Yes)
                            == QMessageBox::Yes)
                    {
                        this->reject();
                        return;
                    }
                }
                else
                {
                    int random = 0;
                    do
                    {
                        ////////////////////////////////////////
                        //产生随机数
                        QTime time;
                        time = QTime::currentTime();
                        qsrand(time.msec()+time.second()*1000);
                        random = qrand()%currWordCount;//%currWordCount ：在0-(currWordCount-1)中选出随机数
                        wid = wordID.at(random);
                        wordID.removeAt(random);
                        currWordCount--;
                    }
                    while(learnMgr->isExist("StateTable",bookPath,wid)>0);
                    showWordCount++;
                    ui->CountLcdNumber->display(showWordCount);
                }
            }
            if(learnOrReview == "Review")
            {
                if(showWordCount >= wordCount)
                {
                    if(QMessageBox::information(this,tr("提示"),
                                                QString(tr("已经没有需要背诵的单词\n请退出选择其他单元或词库"))
                                                ,QMessageBox::Yes)
                            == QMessageBox::Yes)
                    {
                        this->reject();
                        return;
                    }
                }
                else
                {
                    int random = 0;
/*                    do
                    {
                        ////////////////////////////////////////
                        //产生随机数
                        QTime time;
                        time = QTime::currentTime();
                        qsrand(time.msec()+time.second()*1000);
                        random = qrand()%currWordCount;//%wordCount ：在0-(wordCount-1)中选出随机数
                        rid = wordID.at(random);
                        QStringList wordInfo = learnMgr->getImportantInfo("StateTable",rid);
                        int widInState = wordInfo.at(0).toInt();
                        wordId = learnMgr->isExist("CurrTimeStateTable",bookPath,widInState);
                        wordID.removeAt(random);
                        currWordCount--;
                    }
                    while(wordId > 0);*/
                    ////////////////////////////////////////
                    //产生随机数
                    QTime time;
                    time = QTime::currentTime();
                    qsrand(time.msec()+time.second()*1000);
                    random = qrand()%currWordCount;//%wordCount ：在0-(wordCount-1)中选出随机数
                    rid = wordID.at(random);
                    wordID.removeAt(random);
                    currWordCount--;
                    showWordCount++;
                    ui->CountLcdNumber->display(showWordCount);
                }
            }
        }
        else
        {
            if(learnOrReview == "Learn")
            {
                if(showWordCount >= (wordCount-haveLearnedCount))
                {
                    if(QMessageBox::information(this,tr("提示"),
                                                QString(tr("已经没有需要背诵的单词\n请退出选择其他单元或词库"))
                                                ,QMessageBox::Yes)
                            == QMessageBox::Yes)
                    {
                        this->reject();
                        return;
                    }
                }
                else
                {
                    do
                    {
                        wid = wordID.at(0);
                        wordID.removeAt(0);
                    }
                    while(learnMgr->isExist("StateTable",bookPath,wid)>0);
                    showWordCount++;
                    ui->CountLcdNumber->display(showWordCount);
                }
            }
            if(learnOrReview == "Review")
            {
                if(showWordCount >= wordCount)
                {
                    if(QMessageBox::information(this,tr("提示"),
                                                QString(tr("已经没有需要背诵的单词\n请退出选择其他单元或词库"))
                                                ,QMessageBox::Yes)
                            == QMessageBox::Yes)
                    {
                        this->reject();
                        return;
                    }
                }
                else
                {
                    rid = wordID.at(0);
                    wordID.removeAt(0);
                    showWordCount++;
                    ui->CountLcdNumber->display(showWordCount);
                }
            }
        }
        //////////////////////////////////////////////
        //获取单词
        if(learnOrReview == "Learn")
        {
            word = userBookDBMgr->getWordALL(wid);
        }
        if(learnOrReview == "Review")
        {
            word = learnMgr->getWordAll("StateTable",rid);
            wid = learnMgr->getImportantInfo("StateTable",rid).at(0).toInt();
        }
    }
    //////////////////////////////////////////////
    //开始计时
    timerByLektion->start(1000);
    show();
}

void LearnWordDialog::getWord()
{
    /////////////////////////////////////////////////////////////////////
    //是否有要复习的单词
    QList<int> reviewWordIDList = learnMgr->getReviewWordID("CurrTimeStateTable",bookPath);
    int reviewWordCount = reviewWordIDList.count();
    /////////////////////////////////////////
    //如果有要复习的单词
    if(reviewWordCount > 0)
    {
        reviewWordID = reviewWordIDList.at(0);
        word = learnMgr->getWordAll("CurrTimeStateTable",reviewWordID);
        wid = learnMgr->getImportantInfo("CurrTimeStateTable",reviewWordID).at(0).toInt();
    }
    else
    {
        wid = 0;
        rid = 0;
        if(outWordMethod == "Random")
        {
            if(learnOrReview == "Learn")
            {
                if(showWordCount >= (wordCount-haveLearnedCount))
                {
                    if(QMessageBox::information(this,tr("提示"),
                                                QString(tr("已经没有需要背诵的单词\n请退出选择其他单元或词库"))
                                                ,QMessageBox::Yes)
                            == QMessageBox::Yes)
                    {
                        this->reject();
                        return;
                    }
                }
                else
                {
                    do
                    {
                        /////////////////////////////////////////////////////////////////////////
                        //产生随机数
                        QTime time;
                        time = QTime::currentTime();
                        qsrand(time.msec()+time.second()*1000);
                        int random = qrand()%wordCount;//%wordCount ：在0-(wordCount-1)中选出随机数
                        wid = random + 1;
                    }
                    while(learnMgr->isExist("StateTable",bookPath,wid)>0 ||
                           learnMgr->isExist("CurrTimeStateTable",bookPath,wid)>0);
                    showWordCount++;
                    ui->CountLcdNumber->display(showWordCount);
                }
            }
            if(learnOrReview == "Review")
            {
                if(showWordCount >= wordCount)
                {
                    if(QMessageBox::information(this,tr("提示"),
                                                QString(tr("已经没有需要背诵的单词\n请退出选择其他单元或词库"))
                                                ,QMessageBox::Yes)
                            == QMessageBox::Yes)
                    {
                        this->reject();
                        return;
                    }
                }
                else
                {
//                    int wordId = 0;
/*                    do
                    {
                        /////////////////////////////////////////////////////////////////////////
                        //产生随机数
                        QTime time;
                        time = QTime::currentTime();
                        qsrand(time.msec()+time.second()*1000);
                        int random = qrand()%currWordCount;//%wordCount ：在0-(wordCount-1)中选出随机数
                        rid = wordID.at(random);
                        wordID.removeAt(random);
                        currWordCount--;
                        QStringList wordInfo = learnMgr->getImportantInfo("StateTable",rid);
                        int widInState = wordInfo.at(0).toInt();
                        wordId = learnMgr->isExist("CurrTimeStateTable",bookPath,widInState);
                    }
                    while(wordId > 0);
*/
                    /////////////////////////////////////////////////////////////////////////
                    //产生随机数
                    QTime time;
                    time = QTime::currentTime();
                    qsrand(time.msec()+time.second()*1000);
                    int random = qrand()%currWordCount;//%wordCount ：在0-(wordCount-1)中选出随机数
                    rid = wordID.at(random);
                    wordID.removeAt(random);
                    currWordCount--;
                    showWordCount++;
                    ui->CountLcdNumber->display(showWordCount);
                }
            }
        }
        else
        {
            if(learnOrReview == "Learn")
            {
                if(outWordId >= wordCount)
                {
                    if(QMessageBox::information(this,tr("提示"),
                                                QString(tr("已经没有需要背诵的单词\n请退出选择其他单元或词库"))
                                                ,QMessageBox::Yes)
                            == QMessageBox::Yes)
                    {
                        this->reject();
                        return;
                    }
                }
                else
                {
                    do
                    {
                        outWordId++;
                    }
                    while(learnMgr->isExist("StateTable",bookPath,outWordId)>0);
                    wid = outWordId;
                    ui->CountLcdNumber->display(outWordId);
                }
            }
            if(learnOrReview == "Review")
            {
                if(showWordCount >= wordCount)
                {
                    if(QMessageBox::information(this,tr("提示"),
                                                QString(tr("已经没有需要背诵的单词\n请退出选择其他单元或词库"))
                                                ,QMessageBox::Yes)
                            == QMessageBox::Yes)
                    {
                        this->reject();
                    }
                }
                else
                {
                    rid = wordID.at(0);
                    wordID.removeAt(0);
                    showWordCount++;
                    ui->CountLcdNumber->display(showWordCount);
                }
            }
        }
        //////////////////////////////////////////////
        //获取单词
        if(learnOrReview == "Learn")
        {
            word = userBookDBMgr->getWordALL(wid);
        }
        if(learnOrReview == "Review")
        {
            word = learnMgr->getWordAll("StateTable",rid);
            wid = learnMgr->getImportantInfo("StateTable",rid).at(0).toInt();
        }
    }
    //////////////////////////////////////////////
    //开始计时
    timer->start(1000);
    show();
}

void LearnWordDialog::show()
{
    if(learnMethod == "出词忆义")
    {
        ui->WordShowLabel->clear();
        if(reviewWordID > 0)
        {
            ui->WordShowLabel->setText(word.at(0)+"  #复习");
        }
        else
        {
            ui->WordShowLabel->setText(word.at(0));
        }
        QTimer::singleShot(1, this, SLOT(on_SoundButton_clicked()));
    }
    else if(learnMethod == "出义忆词")
    {
        ui->TextBrowser->clear();
        ui->TextBrowser->append(word.at(1));

        ui->OITextBrowser->clear();
        ui->OITextBrowser->append(word.at(2));

        QTimer::singleShot(1, this, SLOT(on_SoundButton_clicked()));
    }
    else
    {
        ui->WordShowLabel->clear();
        ui->TextBrowser->clear();
        ui->OITextBrowser->clear();
        QTimer::singleShot(1, this, SLOT(on_SoundButton_clicked()));
    }
}

void LearnWordDialog::otherShow()
{
    if(learnMethod == "出词忆义")
    {
        ui->TextBrowser->clear();
        ui->TextBrowser->append(word.at(1));

        ui->OITextBrowser->clear();
        ui->OITextBrowser->append(word.at(2));
    }
    else if(learnMethod == "出义忆词")
    {
        ui->WordShowLabel->clear();
        if(reviewWordID > 0)
        {
            ui->WordShowLabel->setText(word.at(0)+"  #复习");
        }
        else
        {
            ui->WordShowLabel->setText(word.at(0));
        }
    }
    else
    {
        ui->WordShowLabel->clear();
        ui->TextBrowser->clear();
        ui->OITextBrowser->clear();

        if(reviewWordID > 0)
        {
            ui->WordShowLabel->setText(word.at(0)+"  #复习");
        }
        else
        {
            ui->WordShowLabel->setText(word.at(0));
        }
        ui->TextBrowser->append(word.at(1));
        ui->OITextBrowser->append(word.at(2));
    }
}

void LearnWordDialog::on_SoundButton_clicked()
{    
    if(ui->SoundEnableCheckBox->isChecked())
    {
        ui->SoundButton->setEnabled(false);
        nextButtonEnable = false;
        ui->NextButton->setEnabled(false);
        //////////////////////////////////////////
        //
        speakMgr->Speak(word.at(0),interval,soundTime);

        //////////////////////////////////////////
        //
//        speakGoogleTTS->setSoundTime(soundTime);
//        speakGoogleTTS->speakGoogleTTS(word.at(0));

//        speakRealPerson->setSoundTime(soundTime);
//        speakRealPerson->realPersonSpeak(word.at(0));

        /////////////////////////////////////////
        //
//        ui->SoundButton->setEnabled(true);
//        sound->getSoundTime(soundTime);
//        sound->getWord(word.at(0));
//        sound->getTimeDiff(interval);
//        sound->start();
    }
}

void LearnWordDialog::on_NextButton_clicked()
{
    /////////////////////////////////////////
    //初始化按钮
    ui->RememButton->setEnabled(true);
    ui->NotSureButton->setEnabled(true);
    ui->ForgetButton->setEnabled(true);
    ui->action_Add2NewWordBook->setEnabled(true);

    ui->NextButton->setEnabled(false);

    ui->RightButton->setEnabled(false);
    ui->WrongButton->setEnabled(false);

    ui->EditWordButton->setEnabled(false);
    ui->ConfigButton->setEnabled(false);
    if(ui->SoundEnableCheckBox->isChecked())
    {
        nextButtonEnable = false;
    }
    afterSure = false;
    /////////////////////////////////////////
    //初始化QLCDNumber显示
    QString display = "00:00:00";
    ui->lcdNumber->display(display);
    /////////////////////////////////
    //停止计时器
    if(learnByLektion)
    {
        timerByLektion->stop();
    }
    else
    {
        timer->stop();
    }
    time = 0;

    ui->WordShowLabel->clear();
    ui->TextBrowser->clear();
    ui->OITextBrowser->clear();

    word.clear();
    judgeTime = 0;
    judgeState = "";
    reviewWordID = 0;

    wid = 0;
    rid = 0;

    if(learnByLektion)
    {
        getWordByLektion(lektion);
    }
    else
    {
        getWord();
    }
}

void LearnWordDialog::on_RememButton_clicked()
{
    /////////////////////////////////
    //初始化按钮
    ui->RememButton->setEnabled(false);
    ui->NotSureButton->setEnabled(false);
    ui->ForgetButton->setEnabled(false);

    ui->RightButton->setEnabled(true);
    ui->WrongButton->setEnabled(true);
    ui->EditWordButton->setEnabled(false);
//    if(learnOrReview == "Learn")
    {
//       ui->EditWordButton->setEnabled(true);
    }
    /////////////////////////////////
    //停止计时器
    if(learnByLektion)
    {
        timerByLektion->stop();
    }
    else
    {
        timer->stop();
    }
    judgeTime = time;
    time = 0;
    judgeState = "REMEMBER";
    ///////////////////////////////////////////////
    //显示其他的信息
    ui->TabWidget->setCurrentWidget(ui->ConnectTab);
    otherShow();
}

void LearnWordDialog::on_NotSureButton_clicked()
{
    /////////////////////////////////
    //初始化按钮
    ui->RememButton->setEnabled(false);
    ui->NotSureButton->setEnabled(false);
    ui->ForgetButton->setEnabled(false);

    ui->RightButton->setEnabled(true);
    ui->WrongButton->setEnabled(true);
    ui->EditWordButton->setEnabled(false);
//    if(learnOrReview == "Learn")
    {
//        ui->EditWordButton->setEnabled(true);
    }
    /////////////////////////////////
    //停止计时器
    if(learnByLektion)
    {
        timerByLektion->stop();
    }
    else
    {
        timer->stop();
    }

    judgeTime = time;
    time = 0;
    judgeState = "OBSCURE";
    ///////////////////////////////////////////////
    //显示其他的信息
    ui->TabWidget->setCurrentWidget(ui->ConnectTab);
    otherShow();
}

void LearnWordDialog::on_ForgetButton_clicked()
{
    /////////////////////////////////
    //初始化按钮
    ui->RememButton->setEnabled(false);
    ui->NotSureButton->setEnabled(false);
    ui->ForgetButton->setEnabled(false);

    ui->RightButton->setEnabled(false);
    ui->WrongButton->setEnabled(false);
    ui->EditWordButton->setEnabled(true);
    ui->ConfigButton->setEnabled(true);
    afterSure = true;
    if(nextButtonEnable && afterSure)
    {
        ui->NextButton->setEnabled(true);
    }
    /////////////////////////////////
    //停止计时器
    if(learnByLektion)
    {
        timerByLektion->stop();
    }
    else
    {
        timer->stop();
    }
    judgeTime = time;
    time = 0;
    judgeState = "FORGET";
    ///////////////////////////////////////////////
    //显示其他的信息
    ui->TabWidget->setCurrentWidget(ui->ConnectTab);
    otherShow();
    //////////////////////////////////////
    //判断单词的难度等级
    Grade = 0; //不记得的单词等级为0
    //////////////////////////////////////
    //更新单词状态信息
    /*
    int id = 0;
    if(learnOrReview == "Learn")
    {
        id = learnMgr->isExist("CurrTimeStateTable",bookPath,wid);
    }
    if(learnOrReview == "Review")
    {
        QStringList wordInfo = learnMgr->getImportantInfo("StateTable",rid);
        int widInState = wordInfo.at(0).toInt();

        id = learnMgr->isExist("CurrTimeStateTable",bookPath,widInState);
    }
*/    
    ////////////////////////////////////////////////////
    //
    if(reviewWordID != 0)
    {
        QList<QString> wordState = learnMgr->getWordState("CurrTimeStateTable",reviewWordID);
//        EF = learnMgr->countEF(wordState.at(1).toDouble(),Grade);
        ////////////////////////////////////////////////////////////////////////////////////////
        //原算法
        /*
        QList<QString> countList = learnMgr->countInterval_Repetition(wordState.at(3).toInt(),
                                                                      wordState.at(1).toDouble()
                                                                      ,Grade,
                                                                      wordState.at(2).toInt());
        */
        QList<QString> countList = learnMgr->countInterval_Repetition_Curr_Review(wordState.at(3).toInt(),
                                                                                  wordState.at(1).toDouble()
                                                                                  ,Grade,
                                                                                  wordState.at(2).toInt());
        Interval = countList.at(0).toInt();
        Repetition = countList.at(1).toInt();
        EF = countList.at(2).toDouble();

        learnMgr->setWordState("CurrTimeStateTable",reviewWordID,Grade,EF,Repetition,Interval);
//        reviewWordID = 0;
    }
/*
    else if(id > 0)
    {
        QList<QString> wordState = learnMgr->getWordState("CurrTimeStateTable",id);
//        EF = learnMgr->countEF(wordState.at(1).toDouble(),Grade);
        QList<QString> countList = learnMgr->countInterval_Repetition(wordState.at(3).toInt(),
                                                                      wordState.at(1).toDouble()
                                                                      ,Grade,
                                                                      wordState.at(2).toInt());
        Interval = countList.at(0).toInt();
        Repetition = countList.at(1).toInt();
        EF = countList.at(2).toDouble();

        learnMgr->setWordState("CurrTimeStateTable",id,Grade,EF,Repetition,Interval);
    }
*/
    else
    {
        if(learnOrReview == "Learn")
        {
            int wordLektion = userBookDBMgr->getLektion(wid).toInt();
//            EF = learnMgr->countEF(2.50,Grade);
            QList<QString> countList = learnMgr->countInterval_Repetition_Curr_Review(0,
                                                                                      2.50
                                                                                      ,Grade,
                                                                                      0);
            Interval = countList.at(0).toInt();
            Repetition = countList.at(1).toInt();
            EF = countList.at(2).toDouble();

            learnMgr->addNewWordState("CurrTimeStateTable",bookPath,wid,word.at(0),word.at(1),word.at(2),
                                      wordLektion,EF,Grade,Repetition,Interval);
        }
        if(learnOrReview == "Review")
        {
            int wordLektion = learnMgr->getLektion("StateTable",rid);
            QStringList wordInfo = learnMgr->getImportantInfo("StateTable",rid);
            double currEF = learnMgr->getEF("StateTable",rid);
            int widInState = wordInfo.at(0).toInt();
//            EF = learnMgr->countEF(currEF,Grade);

            QList<QString> countList = learnMgr->countInterval_Repetition_Curr_Review(0,
                                                                                      currEF
                                                                                      ,Grade,
                                                                                      0);
            Interval = countList.at(0).toInt();
            Repetition = countList.at(1).toInt();
            EF = countList.at(2).toDouble();

            learnMgr->addNewWordState("CurrTimeStateTable",bookPath,widInState,word.at(0),word.at(1),word.at(2),
                                      wordLektion,EF,Grade,Repetition,Interval);
        }
    }
}

void LearnWordDialog::on_RightButton_clicked()
{
    /////////////////////////////////////////
    //初始化按钮
    ui->WrongButton->setEnabled(false);
    ui->RightButton->setEnabled(false);
    ui->EditWordButton->setEnabled(true);
    ui->ConfigButton->setEnabled(true);
    afterSure = true;
    if(nextButtonEnable && afterSure)
    {
        ui->NextButton->setEnabled(true);
    }
    ///////////////////////////////////////////////
    //判断单词的难度等级
    if(judgeState == "REMEMBER")
    {
        if(judgeTime <= 4)
        {
            Grade = 5;
        }
        else if(judgeTime <= 8 && judgeTime > 4)
        {
            Grade = 4;
        }
        else if(judgeTime <= 12 && judgeTime > 8)
        {
            Grade = 3;
        }
        else
        {
            Grade = 2;
        }
    }
    if(judgeState == "OBSCURE")
    {
        if(judgeTime <= 8)
        {
            Grade = 3;
        }
        else if(judgeTime <= 16 && judgeTime > 8)
        {
            Grade = 2;
        }
        else
        {
            Grade = 1;
        }
    }
    //////////////////////////////////////
    //更新单词状态信息
/*
    int id = 0;
    if(learnOrReview == "Learn")
    {
        id = learnMgr->isExist("CurrTimeStateTable",bookPath,wid);
    }
    if(learnOrReview == "Review")
    {
        QStringList wordInfo = learnMgr->getImportantInfo("StateTable",rid);
        int widInState = wordInfo.at(0).toInt();

        id = learnMgr->isExist("CurrTimeStateTable",bookPath,widInState);
    }
*/
    ////////////////////////////////////////////////////
    //
    if(reviewWordID != 0)
    {
        QList<QString> wordState = learnMgr->getWordState("CurrTimeStateTable",reviewWordID);
//        EF = learnMgr->countEF(wordState.at(1).toDouble(),Grade);
        ////////////////////////////////////////////////////////////////////////////////////////
        //原算法
        /*
        QList<QString> countList = learnMgr->countInterval_Repetition(wordState.at(3).toInt(),
                                                                      wordState.at(1).toDouble()
                                                                      ,Grade,
                                                                      wordState.at(2).toInt());
        */
        QList<QString> countList = learnMgr->countInterval_Repetition_Curr_Review(wordState.at(3).toInt(),
                                                                                  wordState.at(1).toDouble()
                                                                                  ,Grade,
                                                                                  wordState.at(2).toInt());
        Interval = countList.at(0).toInt();
        Repetition = countList.at(1).toInt();
        EF = countList.at(2).toDouble();

        learnMgr->setWordState("CurrTimeStateTable",reviewWordID,Grade,EF,Repetition,Interval);
//        reviewWordID = 0;
    }
/*
    else if(id > 0)
    {
        QList<QString> wordState = learnMgr->getWordState("CurrTimeStateTable",id);
//        EF = learnMgr->countEF(wordState.at(1).toDouble(),Grade);
        QList<QString> countList = learnMgr->countInterval_Repetition(wordState.at(3).toInt(),
                                                                      wordState.at(1).toDouble()
                                                                      ,Grade,
                                                                      wordState.at(2).toInt());
        Interval = countList.at(0).toInt();
        Repetition = countList.at(1).toInt();
        EF = countList.at(2).toDouble();

        learnMgr->setWordState("CurrTimeStateTable",id,Grade,EF,Repetition,Interval);
    }
*/
    else
    {
        if(learnOrReview == "Learn")
        {
            int wordLektion = userBookDBMgr->getLektion(wid).toInt();
//            EF = learnMgr->countEF(2.50,Grade);
            QList<QString> countList = learnMgr->countInterval_Repetition_Curr_Review(0,
                                                                                      2.50
                                                                                      ,Grade,
                                                                                      0);
            Interval = countList.at(0).toInt();
            Repetition = countList.at(1).toInt();
            EF = countList.at(2).toDouble();

            learnMgr->addNewWordState("CurrTimeStateTable",bookPath,wid,word.at(0),word.at(1),word.at(2),
                                      wordLektion,EF,Grade,Repetition,Interval);
        }
        if(learnOrReview == "Review")
        {
            int wordLektion = learnMgr->getLektion("StateTable",rid);
            QStringList wordInfo = learnMgr->getImportantInfo("StateTable",rid);
            double currEF = learnMgr->getEF("StateTable",rid);
            int widInState = wordInfo.at(0).toInt();
//            EF = learnMgr->countEF(currEF,Grade);

            QList<QString> countList = learnMgr->countInterval_Repetition_Curr_Review(0,
                                                                                      currEF
                                                                                      ,Grade,
                                                                                      0);
            Interval = countList.at(0).toInt();
            Repetition = countList.at(1).toInt();
            EF = countList.at(2).toDouble();

            learnMgr->addNewWordState("CurrTimeStateTable",bookPath,widInState,word.at(0),word.at(1),word.at(2),
                                      wordLektion,EF,Grade,Repetition,Interval);
        }
    }
}

void LearnWordDialog::on_WrongButton_clicked()
{
    /////////////////////////////////////////
    //初始化按钮
    ui->RightButton->setEnabled(false);
    ui->WrongButton->setEnabled(false);
    ui->EditWordButton->setEnabled(true);
    ui->ConfigButton->setEnabled(true);
    afterSure = true;
    if(nextButtonEnable && afterSure)
    {
        ui->NextButton->setEnabled(true);
    }
    ///////////////////////////////////////////////
    //判断单词的难度等级
    Grade = 0;
    //////////////////////////////////////
    //更新单词状态信息
    //////////////////////////////////////
    //更新单词状态信息
/*
    int id = 0;
    if(learnOrReview == "Learn")
    {
        id = learnMgr->isExist("CurrTimeStateTable",bookPath,wid);
    }
    if(learnOrReview == "Review")
    {
        QStringList wordInfo = learnMgr->getImportantInfo("StateTable",rid);
        int widInState = wordInfo.at(0).toInt();

        id = learnMgr->isExist("CurrTimeStateTable",bookPath,widInState);
    }
*/
    ////////////////////////////////////////////////////
    //
    if(reviewWordID != 0)
    {
        QList<QString> wordState = learnMgr->getWordState("CurrTimeStateTable",reviewWordID);
//        EF = learnMgr->countEF(wordState.at(1).toDouble(),Grade);
        ////////////////////////////////////////////////////////////////////////////////////////
        //原算法
        /*
        QList<QString> countList = learnMgr->countInterval_Repetition(wordState.at(3).toInt(),
                                                                      wordState.at(1).toDouble()
                                                                      ,Grade,
                                                                      wordState.at(2).toInt());
        */
        QList<QString> countList = learnMgr->countInterval_Repetition_Curr_Review(wordState.at(3).toInt(),
                                                                                  wordState.at(1).toDouble()
                                                                                  ,Grade,
                                                                                  wordState.at(2).toInt());
        Interval = countList.at(0).toInt();
        Repetition = countList.at(1).toInt();
        EF = countList.at(2).toDouble();

        learnMgr->setWordState("CurrTimeStateTable",reviewWordID,Grade,EF,Repetition,Interval);
//        reviewWordID = 0;
    }
/*
    else if(id > 0)
    {
        QList<QString> wordState = learnMgr->getWordState("CurrTimeStateTable",id);
//        EF = learnMgr->countEF(wordState.at(1).toDouble(),Grade);
        QList<QString> countList = learnMgr->countInterval_Repetition(wordState.at(3).toInt(),
                                                                      wordState.at(1).toDouble()
                                                                      ,Grade,
                                                                      wordState.at(2).toInt());
        Interval = countList.at(0).toInt();
        Repetition = countList.at(1).toInt();
        EF = countList.at(2).toDouble();

        learnMgr->setWordState("CurrTimeStateTable",id,Grade,EF,Repetition,Interval);
    }
*/
    else
    {
        if(learnOrReview == "Learn")
        {
            int wordLektion = userBookDBMgr->getLektion(wid).toInt();
//            EF = learnMgr->countEF(2.50,Grade);
            QList<QString> countList = learnMgr->countInterval_Repetition_Curr_Review(0,
                                                                                      2.50
                                                                                      ,Grade,
                                                                                      0);
            Interval = countList.at(0).toInt();
            Repetition = countList.at(1).toInt();
            EF = countList.at(2).toDouble();

            learnMgr->addNewWordState("CurrTimeStateTable",bookPath,wid,word.at(0),word.at(1),word.at(2),
                                      wordLektion,EF,Grade,Repetition,Interval);
        }
        if(learnOrReview == "Review")
        {
            int wordLektion = learnMgr->getLektion("StateTable",rid);
            QStringList wordInfo = learnMgr->getImportantInfo("StateTable",rid);
            double currEF = learnMgr->getEF("StateTable",rid);
            int widInState = wordInfo.at(0).toInt();
//            EF = learnMgr->countEF(currEF,Grade);

            QList<QString> countList = learnMgr->countInterval_Repetition_Curr_Review(0,
                                                                                      currEF
                                                                                      ,Grade,
                                                                                      0);
            Interval = countList.at(0).toInt();
            Repetition = countList.at(1).toInt();
            EF = countList.at(2).toDouble();

            learnMgr->addNewWordState("CurrTimeStateTable",bookPath,widInState,word.at(0),word.at(1),word.at(2),
                                      wordLektion,EF,Grade,Repetition,Interval);
        }
    }
}

void LearnWordDialog::on_EditWordButton_clicked()
{
    AddNewRecordDialog *editWort;
    editWort = new AddNewRecordDialog(this);
    editWort->setWindowTitle(tr("  编辑该词条  "));
    editWort->setWindowIcon(QIcon("./rc/edit_rename.png"));
    editWort->setGroupTitle(tr("编辑该已存在词条"));
    editWort->setLektionLineEditRradOnly();
    //////////////////////////////////////////////////////////
    //获取单词
    qDebug() << QString("要修改的单词的编号为：");
    qDebug() << QString::number(wid,'i',0);
    qDebug() << QString("要修改的单词为：");
    qDebug() << word.at(0);

    editWort->setWord(word.at(0));
    editWort->setMean(word.at(1));
    editWort->setOther(word.at(2));

    qDebug() << QString("要修改的单词所属单元为：");
    qDebug() << userBookDBMgr->getLektion(wid);
    editWort->setLektion(userBookDBMgr->getLektion(wid).toInt());
    //////////////////////////////////////////////////////////////////////
    //开始修改
    if(editWort->exec() == QDialog::Accepted)
    {
        //////////////////////////////////////////////////////////////////
        //保存记录
        word.clear();
        word.append(editWort->getWord());
        word.append(editWort->getMean());
        word.append(editWort->getOther());
        qDebug() << QString("单词缓存更新成功：");
        qDebug() << word;

        {
            ////////////////////////////////////////////////////////
            //更新词库中的单词信息
            bool uw = userBookDBMgr->updateWord(editWort->getWord(),wid);
            bool um = userBookDBMgr->updateMean(editWort->getMean(),wid);
            bool uc = userBookDBMgr->updateConnection(editWort->getOther(),wid);
            bool ul = userBookDBMgr->updateLektion(QString::number(editWort->getLektion(),'i',0),wid);
            /////////////////////////////////////////////////
            //当词汇修改成功
            if(uw == 1 && um == 1 && uc == 1 && ul ==1)
            {
                ////////////////////////////////////////////////////////
                //在背单词界面中显示修改过后的单词
                ui->WordShowLabel->clear();
                if(reviewWordID > 0)
                {
                    ui->WordShowLabel->setText(editWort->getWord()+"  #复习");
                }
                else
                {
                    ui->WordShowLabel->setText(editWort->getWord());
                }

                ui->TextBrowser->clear();
                ui->TextBrowser->append(editWort->getMean());

                ui->OITextBrowser->clear();
                ui->OITextBrowser->append(editWort->getOther());
                qDebug() << QString("修改背单词界面词汇信息成功");
                //////////////////////////////////////////////////////
                //
                qDebug() << QString("修改词库中单词记录成功");
                ////////////////////////////////////////////////////////
                //更新临时学习记录中的单词信息
                int idCT = learnMgr->isExist("CurrTimeStateTable",bookPath,wid);
                if(idCT > 0)
                {
                    QStringList wordall;
                    wordall.append(editWort->getWord());
                    wordall.append(editWort->getMean());
                    wordall.append(editWort->getOther());
                    wordall.append(QString::number(editWort->getLektion(),'i',0));

                    bool swa = learnMgr->setWordAll("CurrTimeStateTable",wid,bookPath,wordall);
                    if(swa == 1)
                    {
                        qDebug() << QString("修改临时记录表中单词记录成功");
                    }
                    else
                    {
                        qDebug() << QString("修改临时记录表中单词记录失败");
                    }
                }

                ////////////////////////////////////////////////////////
                //更新学习记录中的单词信息
                int idST = learnMgr->isExist("StateTable",bookPath,wid);
                if(idST > 0)
                {
                    QStringList wordall;
                    wordall.append(editWort->getWord());
                    wordall.append(editWort->getMean());
                    wordall.append(editWort->getOther());
                    wordall.append(QString::number(editWort->getLektion(),'i',0));

                    bool swa = learnMgr->setWordAll("StateTable",wid,bookPath,wordall);
                    if(swa == 1)
                    {
                        qDebug() << QString("修改记录表中单词记录成功");
                    }
                    else
                    {
                        qDebug() << QString("修改记录表中单词记录失败");
                    }
                }
            }
            else
            {
                qDebug() << QString("修改词库中单词记录失败");
            }
            /////////////////////////////////
            //其他
        }//
    }
    ///////////////////////////////////////////////////////////////////
    //窗口后续处理
    editWort->close();
    editWort->deleteLater();
    editWort = NULL;
}

void LearnWordDialog::on_ConfigButton_clicked()
{
    /////////////////////////////////////////////////////
    //配置开始
    LearnWordConfigDialog *configDialog;
    configDialog = new LearnWordConfigDialog(this);
    if(learnByLektion)
    {
    }
    else
    {
        if(learnOrReview == "Learn")
        {
            configDialog->setOutOrderlyRadioButtonUnable();
        }
    }
    if(configDialog->exec() == QDialog::Accepted)
    {
        //////////////////////////////////////////////
        //获取配置信息
        getConfInfo();
        ///////////////////////////////////////////////
        //取词
        on_NextButton_clicked();

        configDialog->close();
        delete configDialog;
        configDialog = NULL;
    }
    else
    {
        configDialog->close();
        delete configDialog;
        configDialog = NULL;
    }
}

void LearnWordDialog::on_FullCheckBox_clicked(bool checked)
{
    if(checked)
    {
        QDialog::showFullScreen();
    }
    else
    {
        QDialog::showNormal();
    }
}

void LearnWordDialog::stopThread()
{
    /*
    if (sound->isRunning())
    {
        sound->stop();
        sound->quit();
    }
    */
}

void LearnWordDialog::setButtonState()
{
    if(ui->SoundEnableCheckBox->isChecked())
    {
//        sound->quit();
        ui->SoundButton->setEnabled(true);
    }
    nextButtonEnable = true;
    if(afterSure && nextButtonEnable)
    {
        ui->NextButton->setEnabled(true);
    }
}

void LearnWordDialog::on_TabWidget_currentChanged(int index)
{
    if(index == 1)
    {
       QNetworkProxyFactory::setUseSystemConfiguration(true);
       QNetworkDiskCache *diskCache = new QNetworkDiskCache(this);
       QString location =QDesktopServices::storageLocation(QDesktopServices::CacheLocation);
       diskCache->setCacheDirectory(location);
       QNetworkAccessManager *networkAccessManager = new QNetworkAccessManager(this);
       networkAccessManager->setCache(diskCache);

       QUrl url = QUrl::fromEncoded("http://www.godic.net");
       QString searchWord = QString("/dicts/de/%1").arg(word.at(0));
       QByteArray addWordText = searchWord.toLatin1();
       url.setEncodedPath(addWordText);
       ui->WebView->load(url);
       ui->WebView->show();
       connect(ui->WebView, SIGNAL(loadProgress(int)),this, SLOT(setProgress(int)));
       connect(ui->WebView, SIGNAL(loadFinished(bool)),this, SLOT(hideProgressBar()));
    }
}

void LearnWordDialog::replyFinished(QNetworkReply *)
{

}

void LearnWordDialog::setProgress(int value)
{
    ui->progressBar->setHidden(false);
    ui->progressBar->setValue(value);
}

void LearnWordDialog::hideProgressBar()
{
    ui->progressBar->hide();
    QWebPage *page = ui->WebView->page();
    page->setContentEditable(true);
}

void LearnWordDialog::on_SoundEnableCheckBox_clicked(bool checked)
{
    if(!checked)
    {
        ui->SoundButton->setEnabled(false);
        nextButtonEnable = true;
    }
    else
    {
        ui->SoundButton->setEnabled(true);
    }
}

void LearnWordDialog::on_WordShowLabel_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);
    QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单
    popMenu->addAction(ui->action_Query);
    popMenu->addAction(ui->action_Add2NewWordBook);
    popMenu->addAction(ui->action_EndSpeak);
//    popMenu->addAction(ui->action_SpeakMethode);
//    popMenu->addAction(ui->action__ChangeSpeakMethode);
    popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置

    delete popMenu;
    popMenu = NULL;
}

void LearnWordDialog::on_action_Query_triggered()
{
    if(ansleDict != NULL)
    {
        ansleDict->close();
        ansleDict->deleteLater();
        ansleDict = NULL;
    }
    ansleDict = new AnsleDictDialog(word.at(0),this);
    ansleDict->setModal(false);
//    if(ansleDict->exec() == QDialog::Rejected)
//    {
//        ansleDict->close();
//        ansleDict->deleteLater();
//        ansleDict = NULL;
//    }
    ansleDict->setModal(false);
    ansleDict->show();

    ansleDict = NULL;
}

void LearnWordDialog::on_action_Add2NewWordBook_triggered()
{
    QString myWord = ui->WordShowLabel->text();
    qDebug() << QString("将单词 %1 加入我的生词库").arg(myWord);
    if(bcMgr->myBook->isExist(myWord))
    {
        QMessageBox::information(this, "提示信息", "该单词在生词本中已经存在,不必重复添加");
        ui->action_Add2NewWordBook->setEnabled(false);
    }
    else
    {
        QString mean = word.at(1);
        QString other = word.at(2);

        int count = bcMgr->myBook->getRowCount();
        int lektion = (count+1)/200 + 1;

        bcMgr->myBook->addNewRecord(myWord,mean,other,lektion);
        ui->action_Add2NewWordBook->setEnabled(false);
    }
}

void LearnWordDialog::on_action_SpeakMethode_triggered()
{

}

void LearnWordDialog::on_action_EndSpeak_triggered()
{
    speakMgr->Stop();
    ui->SoundButton->setEnabled(true);
    if(ui->EditWordButton->isEnabled())
    {
        nextButtonEnable = true;
        ui->NextButton->setEnabled(true);
    }
    else
    {
        nextButtonEnable = true;
    }
}

void LearnWordDialog::on_action__ChangeSpeakMethode_triggered()
{

}
