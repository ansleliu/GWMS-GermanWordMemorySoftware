#include "learnmgr.h"
#include <QProgressDialog>
#include <QMutex>
LearnMgr *learnMgr = NULL;

LearnMgr::LearnMgr(QObject *parent,const QString &userName) :
    QObject(parent)
{
    learnMgr = this;

    currUserName = userName;

    QString learnStateDBPath = PathManage::makePathStr("/userdata/"
                                                       + currUserName
                                                       + "/learnstate.db");
    learnBase = new LearnBase(learnStateDBPath,"LEARNSTATEDB");

    reviewAlgorithm = new ReviewAlgorithm();
}

LearnMgr::~LearnMgr()
{
    delete learnBase;
    delete reviewAlgorithm;
}

QSqlDatabase *LearnMgr::getLearnStatedb()
{
    return learnBase->getLearnStatedb();
}
/*
QString LearnMgr::copyLearnBook(const QString &bookpath)
{
    QFileInfo fd(bookpath);
    QString bookName = fd.fileName();
    QString newBookPath = PathManage::makePathStr("/userdata/"
                                                  + currUserName
                                                  + "/currlearnbook/"
                                                  + bookName);
    QFile::copy(bookpath,newBookPath);
    return newBookPath;
}
*/
bool LearnMgr::addNewWordState(const QString &tableName, const QString &bookPath,
                               const int &wid, const QString &word, const QString &mean,
                               const QString &connection, const int &lektion, const double &EF,
                               const int &Grade, const int &Repetition, const int &Interval)
{
    return learnBase->addNewWordState(tableName,bookPath,wid,
                                      word,mean,connection,lektion,
                                      EF,Grade,Repetition,Interval);
}

int LearnMgr::isExist(const QString &tableName, const QString &bookPath, const int &wid)
{
    return learnBase->isExist(tableName,bookPath,wid);
}

int LearnMgr::isExist(const QString &tableName, const QString &bookPath)
{
    return learnBase->isExist(tableName,bookPath);
}

void LearnMgr::deleteTable(const QString &tableName)
{
    return learnBase->deleteTable(tableName);
}

bool LearnMgr::deleteRecord(const QString &tableName, const QString &bookPath)
{
    return learnBase->deleteRecord(tableName,bookPath);
}

int LearnMgr::getRecordCount()
{
    return learnBase->getRecordCount("CurrTimeStateTable");
}

void LearnMgr::transferRecord()
{
    int recordCount = learnBase->getRecordCount("CurrTimeStateTable");
    if(recordCount > 0)
    {
        QProgressDialog *progressbar;
        progressbar = new QProgressDialog(NULL);
        progressbar->setWindowTitle(tr("保存学习记录进度"));
        progressbar->setRange(0,recordCount);
        progressbar->setCancelButton(0);
        progressbar->setAutoClose(true);
        int savecount = 0;
        for(int i = recordCount; i >= 1 ; i--)
        {
            savecount++;
            QStringList importantInfo = learnBase->getImportantInfo("CurrTimeStateTable",i);
            int wid = importantInfo.at(0).toInt();
            QString bookpath = importantInfo.at(1);

            QStringList wordAll = learnBase->getWordAll("CurrTimeStateTable",i);
            QString word = wordAll.at(0);
            QString mean = wordAll.at(1);
            QString connection = wordAll.at(2);
            int lektion = wordAll.at(3).toInt();

            QList<QString> wordState = learnBase->getWordState("CurrTimeStateTable",i);
            int Grade = wordState.at(0).toInt();
            double EF = wordState.at(1).toDouble();
//            int Repetition = wordState.at(2);
//            int Interval = wordState.at(3);

            ////////////////////////////////////////////////////////////////////////////////////
            //
            QMutex *mutex = new QMutex();
            mutex->lock();
            QString text = QString(tr("正在保存第 %1 个学习记录，请稍等……")).arg(savecount);
            progressbar->setLabelText(text);
            progressbar->setModal(true);
            progressbar->show();
            progressbar->setValue(savecount);
            ////////////////////////////////////////////////////////////////////////////////////
            //
            int idInStateTable = learnBase->isExist("StateTable",bookpath,wid);
            /////////////////////////////////////////////
            //如果已经存在,更新记录
            if(idInStateTable > 0)
            {
                QList<QString> state = learnBase->getWordState("StateTable",idInStateTable);
                int mainRepetition = state.at(2).toInt();
                int mainInterval = state.at(3).toInt();

                QList<QString> newState = countInterval_Repetition(mainInterval,EF,Grade,mainRepetition);
                int newRepetition = newState.at(1).toInt();
                int newInterval  = newState.at(0).toInt();

                learnBase->setWordState("StateTable",idInStateTable,
                                        Grade,EF,newRepetition,newInterval);
                learnBase->deleteRecord("CurrTimeStateTable",i);
            }
            //////////////////////////////////////////////
            //否则,新建记录
            else
            {
                QList<QString> newState = countInterval_Repetition(0,EF,Grade,0);
                int newRepetition = newState.at(1).toInt();
                int newInterval  = newState.at(0).toInt();
                learnBase->addNewWordState("StateTable",bookpath,wid,
                                           word,mean,connection,lektion,
                                           EF,Grade,newRepetition,newInterval);
                learnBase->deleteRecord("CurrTimeStateTable",i);
            }

            mutex->unlock();
            delete mutex;
            mutex = NULL;
        }
        progressbar->close();
        delete progressbar;
        progressbar =NULL;
    }
    learnBase->deleteTable("CurrTimeStateTable");
}

QList<int> LearnMgr::getReviewWordIDByLektion(const QString &tableName,
                                              const QString &bookPath,
                                              const int &lektion)
{
    return learnBase->getReviewWordIDByLektion(tableName,bookPath,lektion);
}

QList<int> LearnMgr::getReviewWordID(const QString &tableName,
                                     const QString &bookPath)
{
    return learnBase->getReviewWordID(tableName,bookPath);
}

QStringList LearnMgr::getImportantInfo(const QString &tableName, const int &id)
{
    return learnBase->getImportantInfo(tableName,id);
}

QString LearnMgr::getLastTime(const QString &tableName, const int &id)
{
    return learnBase->getLastTime(tableName,id);
}

QString LearnMgr::getWord(const QString &tableName, const int &id)
{
    return learnBase->getWord(tableName,id);
}

QString LearnMgr::getMean(const QString &tableName, const int &id)
{
    return learnBase->getMean(tableName,id);
}

QString LearnMgr::getConnection(const QString &tableName, const int &id)
{
    return learnBase->getConnection(tableName,id);
}

int LearnMgr::getLektion(const QString &tableName, const int &id)
{
    return learnBase->getLektion(tableName,id);
}

QStringList LearnMgr::getWordAll(const QString &tableName, const int &id)
{
    return learnBase->getWordAll(tableName,id);
}

QList<QString> LearnMgr::getWordState(const QString &tableName, const int &id)
{
    return learnBase->getWordState(tableName,id);
}

int LearnMgr::getGrade(const QString &tableName, const int &id)
{
    return learnBase->getGrade(tableName,id);
}

double LearnMgr::getEF(const QString &tableName, const int &id)
{
    return learnBase->getEF(tableName,id);
}

int LearnMgr::getRepetition(const QString &tableName, const int &id)
{
    return learnBase->getRepetition(tableName,id);
}

int LearnMgr::getInterval(const QString &tableName, const int &id)
{
    return learnBase->getInterval(tableName,id);
}

int LearnMgr::getTimeDiff(const QString &tableName, const int &id)
{
    return learnBase->getTimeDiff(tableName,id);
}

bool LearnMgr::setWordAll(const QString &tableName, const int &wid,
                          const QString &bookPath, const QStringList &wordall)
{
    return learnBase->setWordAll(tableName,wid,bookPath,wordall);
}

bool LearnMgr::setWord(const QString &tableName, const int &wid,
                       const QString &bookPath, const QString &word)
{
    return learnBase->setWord(tableName,wid,bookPath,word);
}

bool LearnMgr::setMean(const QString &tableName, const int &wid,
                       const QString &bookPath, const QString &mean)
{
    return learnBase->setMean(tableName,wid,bookPath,mean);
}

bool LearnMgr::setConnection(const QString &tableName, const int &wid,
                             const QString &bookPath, const QString &connection)
{
    return learnBase->setConnection(tableName,wid,bookPath,connection);
}

bool LearnMgr::setWordState(const QString &tableName, const int &id,
                            const int &Grade, const double &EF,
                            const int &Repetition, const int &Interval)
{
    return learnBase->setWordState(tableName,id,Grade,EF,Repetition,Interval);
}

bool LearnMgr::setGrade(const QString &tableName, const int &id, const int &Grade)
{
    return learnBase->setGrade(tableName,id,Grade);
}

bool LearnMgr::setEF(const QString &tableName, const int &id, const double &EF)
{
    return learnBase->setEF(tableName,id,EF);
}

bool LearnMgr::setRepetition(const QString &tableName, const int &id, const int &Repetition)
{
    return learnBase->setRepetition(tableName,id,Repetition);
}

bool LearnMgr::setInterval(const QString &tableName, const int &id, const int &Interval)
{
    return learnBase->setInterval(tableName,id,Interval);
}

bool LearnMgr::setTimeDiff(const QString &tableName, const int &id, const int &TimeDiff)
{
    return learnBase->setTimeDiff(tableName,id,TimeDiff);
}

int LearnMgr::getHaveLearnedWordCountByLektion(const QString &bookPath, const int &lektion)
{
    return learnBase->getHaveLearnedWordCountByLektion(bookPath,lektion);
}

int LearnMgr::getHaveLearnedWordCount(const QString &bookPath)
{
    return learnBase->getHaveLearnedWordCount(bookPath);
}

int LearnMgr::getReviewCountInfo(const QString &bookPath, const int &Interval)
{
    return learnBase->getReviewCountInfo(bookPath,Interval);
}

int LearnMgr::getWordCountG5(const QString &bookPath)
{
    return learnBase->getWordCountG5(bookPath);
}

int LearnMgr::getWordCountG4A3(const QString &bookPath)
{
    return learnBase->getWordCountG4A3(bookPath);
}

int LearnMgr::getWordCountGU3(const QString &bookPath)
{
    return learnBase->getWordCountGU3(bookPath);
}

QList<QString> LearnMgr::countInterval_Repetition(int currentInterval, double currentEF,
                                                  int currentGrade, int currentRepetition)
{
    return reviewAlgorithm->setInterval_Repetition(currentInterval,currentEF,
                                                   currentGrade,currentRepetition);
}

QList<QString> LearnMgr::countInterval_Repetition_Curr_Review(int currentInterval,
                                                              double currentEF,
                                                              int currentGrade,
                                                              int currentRepetition)
{
    return reviewAlgorithm->setInterval_Repetition_curr_Review(currentInterval,currentEF,
                                                               currentGrade,currentRepetition);
}

double LearnMgr::countEF(double currentEF, int currentGrade)
{
    return reviewAlgorithm->setEF(currentEF,currentGrade);
}

QSqlTableModel *LearnMgr::studyStateDBModel(QWidget *parent)
{
    return learnBase->studyStateDBModel(parent);
}
