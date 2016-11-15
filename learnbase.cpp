#include "learnbase.h"
#include "QMessageBox"
#include "QDateTime"
#include "QDebug"

LearnBase::LearnBase(const QString &dbpath, const QString &connName)
    :MySQLite(dbpath, connName)
{
    if(!isTableExist("StateTable"))
    {
        createStateTable();
    }
    if(!isTableExist("CurrTimeStateTable"))
    {
        createCurrTimeStateTable();
    }
}

LearnBase::~LearnBase()
{
}

void LearnBase::createStateTable()
{
    db->transaction();
    exec("CREATE TABLE [StateTable] (\
         [id] INTEGER NOT NULL ON CONFLICT FAIL PRIMARY KEY AUTOINCREMENT,\
         [wid] INTEGER,\
         [bookpath] TEXT,\
         [word] TEXT,\
         [mean] TEXT,\
         [connection] TEXT,\
         [lektion] INTEGER,\
         [Grade] INTEGER,\
         [EF] DOUBLE,\
         [Repetition] INTEGER,\
         [Interval] INTEGER,\
         [LastTime] DATETIME NOT NULL ON CONFLICT FAIL,\
         [TimeDiff] INTEGER);");
    db->commit();
}

void LearnBase::createCurrTimeStateTable()
{
    db->transaction();
    exec("CREATE TABLE [CurrTimeStateTable] (\
         [id] INTEGER NOT NULL ON CONFLICT FAIL PRIMARY KEY AUTOINCREMENT,\
         [wid] INTEGER,\
         [bookpath] TEXT,\
         [word] TEXT,\
         [mean] TEXT,\
         [connection] TEXT,\
         [lektion] INTEGER,\
         [Grade] INTEGER,\
         [EF] DOUBLE,\
         [Repetition] INTEGER,\
         [Interval] INTEGER,\
         [LastTime] DATETIME NOT NULL ON CONFLICT FAIL,\
         [TimeDiff] INTEGER);");
    db->commit();
}

QSqlDatabase *LearnBase::getLearnStatedb()
{
    return getdb();
}

bool LearnBase::addNewWordState(const QString &tableName, const QString &bookPath,
                                const int &wid, const QString &word, const QString &mean,
                                const QString &connection, const int &lektion,
                                const double &EF,const int &Grade,const int &Repetition,const int &Interval)
{
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString sql = QString("insert into %1 "
                          "(wid, bookpath, word, mean, connection, lektion, Grade, EF, Repetition, Interval, LastTime, TimeDiff) "
                          "values ('%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12', '%13')")
            .arg(tableName)
            .arg(wid)
            .arg(bookPath)
            .arg(word)
            .arg(mean)
            .arg(connection)
            .arg(lektion)
            .arg(Grade)
            .arg(EF)
            .arg(Repetition)
            .arg(Interval)
            .arg(currentTime)
            .arg(0);

    return exec(sql);
}

int LearnBase::isExist(const QString &tableName, const QString &bookPath, const int &wid)
{
    int id;

    QString sql = QString("select id from %1 where bookpath = '%2' and wid = '%3'")
                            .arg(tableName)
                            .arg(bookPath)
                            .arg(wid);
    QSqlQuery query(sql, *db);
    query.next();

    id = query.record().value("id").toInt();

    return id;
}

int LearnBase::isExist(const QString &tableName, const QString &bookPath)
{
    int id;

    QString sql = QString("select id from %1 where bookpath = '%2'")
                            .arg(tableName)
                            .arg(bookPath);
    QSqlQuery query(sql, *db);
    query.next();

    id = query.record().value("id").toInt();

    return id;
}

void LearnBase::deleteTable(const QString &tableName)
{
    //////////////////////////////////////////////////
    //清空表内容
    exec(QString("delete from %1").arg(tableName));
    //////////////////////////////////////////////////
    //清空自增记录
    exec(QString("delete from sqlite_sequence where name = '%1'")
         .arg(tableName));
}

bool LearnBase::deleteRecord(const QString &tableName, const int &id)
{
    QString sql = QString("delete from %1 where id = '%2'")
            .arg(tableName)
            .arg(id);
    return exec(sql);
}

bool LearnBase::deleteRecord(const QString &tableName, const QString &bookPath)
{
    QString sql = QString("delete from %1 where bookpath = '%2'")
            .arg(tableName)
            .arg(bookPath);
    return exec(sql);
}

QList<int> LearnBase::getReviewWordIDByLektion(const QString &tableName, const QString &bookPath,
                                               const int &lektion)
{
    QList<int> TimeDiff;
    if(tableName == "StateTable")
    {
//        QString sql = QString("select id from StateTable where "
//                              "((julianday(datetime('now','localtime')) "
//                              "- julianday(datetime(LastTime))) >= Interval) "
//                              "and lektion = '%1' and bookpath = '%2'")
//                                .arg(lektion)
//                                .arg(bookPath);
        QString sql = QString("select id from StateTable where "
                              "((julianday('now') "
                              "- julianday(date(LastTime))) >= Interval) "
                              "and lektion = '%1' and bookpath = '%2'")
                                .arg(lektion)
                                .arg(bookPath);
        QSqlQuery query(sql, *db);
        while(query.next())
        {
            TimeDiff << query.record().value(0).toInt();
        }
        return TimeDiff;
    }
    else if(tableName == "CurrTimeStateTable")
    {
        QList<int> TimeDiff;
        QString sql = QString("select id from CurrTimeStateTable where "
                              "((julianday(datetime('now','localtime'))*86400 "
                              "- julianday(datetime(LastTime))*86400) >= Interval) "
                              "and lektion = '%1' and bookpath = '%2'")
                                .arg(lektion)
                                .arg(bookPath);

        QSqlQuery query(sql, *db);
        while(query.next())
        {
            TimeDiff << query.record().value(0).toInt();
        }
        return TimeDiff;
    }
    else
    {
        TimeDiff << -1;
        return TimeDiff;
    }
}

QList<int> LearnBase::getReviewWordID(const QString &tableName, const QString &bookPath)
{
    QList<int> TimeDiff;
    if(tableName == "StateTable")
    {
//        QString sql = QString("select id from StateTable where "
//                              "((julianday(datetime('now','localtime')) "
//                              "- julianday(datetime(LastTime))) >= Interval) "
//                              "and bookpath = '%1'").arg(bookPath);
        QString sql = QString("select id from StateTable where "
                              "((julianday('now') "
                              "- julianday(date(LastTime))) >= Interval) "
                              "and bookpath = '%1'").arg(bookPath);
        QSqlQuery query(sql, *db);
        while(query.next())
        {
            TimeDiff << query.record().value(0).toInt();
        }
        return TimeDiff;
    }
    else if(tableName == "CurrTimeStateTable")
    {
        QList<int> TimeDiff;
        QString sql = QString("select id from CurrTimeStateTable where "
                              "((julianday(datetime('now','localtime'))*86400 "
                              "- julianday(datetime(LastTime))*86400) >= Interval) "
                              "and bookpath = '%1'").arg(bookPath);

        QSqlQuery query(sql, *db);
        while(query.next())
        {
            TimeDiff << query.record().value(0).toInt();
        }
        return TimeDiff;
    }
    else
    {
        TimeDiff << -1;
        return TimeDiff;
    }
}

QStringList LearnBase::getImportantInfo(const QString &tableName, const int &id)
{
    QStringList importantInfo;

    QString sql = QString("select wid, bookpath from %1 where id = '%2'")
            .arg(tableName).arg(id);
    QSqlQuery query(sql, *db);
    query.next();

    importantInfo << query.record().value("wid").toString()
                  << query.record().value("bookpath").toString();

    return importantInfo;
}

int LearnBase::getRecordCount(const QString &tableName)
{
    QString sql = QString("select count(*) from %1").arg(tableName);
    QSqlQuery query(sql, *db);
    query.next();
    return query.value(0).toInt();
}

QString LearnBase::getLastTime(const QString &tableName, const int &id)
{
    QString LastTime;

    QString sql = QString("select LastTime from %1 where id = '%2'")
            .arg(tableName).arg(id);
    QSqlQuery query(sql, *db);
    query.next();

    LastTime = query.record().value("LastTime").toString();

    return LastTime;
}

QString LearnBase::getWord(const QString &tableName, const int &id)
{
    QString Word;

    QString sql = QString("select word from %1 where id = '%2'")
            .arg(tableName)
            .arg(id);
    QSqlQuery query(sql, *db);
    query.next();

    Word = query.record().value("word").toString();

    return Word;
}

QString LearnBase::getMean(const QString &tableName, const int &id)
{
    QString Mean;

    QString sql = QString("select mean from %1 where id = '%2'")
            .arg(tableName).arg(id);
    QSqlQuery query(sql, *db);
    query.next();

    Mean = query.record().value("mean").toString();

    return Mean;
}

QString LearnBase::getConnection(const QString &tableName, const int &id)
{
    QString Connection;

    QString sql = QString("select connection from %1 where id = '%2'")
            .arg(tableName)
            .arg(id);
    QSqlQuery query(sql, *db);
    query.next();

    Connection = query.record().value("connection").toString();

    return Connection;
}

int LearnBase::getLektion(const QString &tableName, const int &id)
{
    int lektion;

    QString sql = QString("select lektion from %1 where id = '%2'")
            .arg(tableName)
            .arg(id);
    QSqlQuery query(sql, *db);
    query.next();

    lektion = query.record().value("lektion").toInt();

    return lektion;
}

QStringList LearnBase::getWordAll(const QString &tableName, const int &id)
{
    QStringList WordAll;
    QString sql = QString("select word, mean, connection, lektion from %1 where id = '%2'")
            .arg(tableName)
            .arg(id);
    QSqlQuery query(sql, *db);
    query.next();

    WordAll << query.record().value("word").toString()
            << query.record().value("mean").toString()
            << query.record().value("connection").toString()
            << query.record().value("lektion").toString();

    return WordAll;
}

QList<QString> LearnBase::getWordState(const QString &tableName, const int &id)
{
    QList<QString> wordStateList;

    QString sql = QString("select Grade, EF, Repetition, Interval from %1 where id = '%2'")
            .arg(tableName)
            .arg(id);
    QSqlQuery query(sql, *db);
    query.next();

    wordStateList << query.record().value("Grade").toString()
                  << query.record().value("EF").toString()
                  << query.record().value("Repetition").toString()
                  << query.record().value("Interval").toString();

    return wordStateList;
}

int LearnBase::getGrade(const QString &tableName, const int &id)
{
    int Grade;

    QString sql = QString("select Grade from %1 where id = '%2'")
            .arg(tableName)
            .arg(id);
    QSqlQuery query(sql, *db);
    query.next();

    Grade = query.record().value("Grade").toInt();

    return Grade;
}

double LearnBase::getEF(const QString &tableName, const int &id)
{
    double EF;

    QString sql = QString("select EF from %1 where id = '%2'")
            .arg(tableName)
            .arg(id);
    QSqlQuery query(sql, *db);
    query.next();

    EF = query.record().value("EF").toDouble();

    return EF;
}

int LearnBase::getRepetition(const QString &tableName, const int &id)
{
    int Repetition;

    QString sql = QString("select Repetition from %1 where id = '%2'")
            .arg(tableName)
            .arg(id);
    QSqlQuery query(sql, *db);
    query.next();

    Repetition = query.record().value("Repetition").toInt();

    return Repetition;
}

int LearnBase::getInterval(const QString &tableName, const int &id)
{
    int Interval;

    QString sql = QString("select Interval from %1 where id = '%2'")
            .arg(tableName)
            .arg(id);
    QSqlQuery query(sql, *db);
    query.next();

    Interval = query.record().value("Interval").toInt();

    return Interval;
}

int LearnBase::getTimeDiff(const QString &tableName, const int &id)
{
    int TimeDiff;

    QString sql = QString("select TimeDiff from %1 where id = '%2'")
            .arg(tableName)
            .arg(id);
    QSqlQuery query(sql, *db);
    query.next();

    TimeDiff = query.record().value("TimeDiff").toInt();

    return TimeDiff;
}

bool LearnBase::setWordAll(const QString &tableName, const int &wid,
                           const QString &bookPath, const QStringList &wordall)
{
    QString word = wordall.at(0);
    QString mean = wordall.at(1);
    QString connection = wordall.at(2);
    int lektion = wordall.at(3).toInt();
    QString sql = QString("update '%1' set word = '%2', mean = '%3', connection = '%4', "
                          "lektion = '%5' where wid = '%6' and bookpath = '%7'")
            .arg(tableName)
            .arg(word)
            .arg(mean)
            .arg(connection)
            .arg(lektion)
            .arg(wid)
            .arg(bookPath);
    return exec(sql);
}

bool LearnBase::setWord(const QString &tableName, const int &wid, const QString &bookPath,
                        const QString &word)
{
    QString sql = QString("update '%1' set word = '%2' where wid = '%3' and bookpath = '%4'")
            .arg(tableName)
            .arg(word)
            .arg(wid)
            .arg(bookPath);
    return exec(sql);
}

bool LearnBase::setMean(const QString &tableName, const int &wid, const QString &bookPath,
                        const QString &mean)
{
    QString sql = QString("update '%1' set mean = '%2' where wid = '%3' and bookPath = '%4'")
            .arg(tableName)
            .arg(mean)
            .arg(wid)
            .arg(bookPath);
    return exec(sql);
}

bool LearnBase::setConnection(const QString &tableName, const int &wid, const QString &bookPath,
                              const QString &connection)
{
    QString sql = QString("update '%1' set connection = '%2' where wid = '%3' and bookPath = '%4'")
            .arg(tableName)
            .arg(connection)
            .arg(wid)
            .arg(bookPath);
    return exec(sql);
}

bool LearnBase::setLektion(const QString &tableName, const int &wid,
                           const QString &bookPath, const int &lektion)
{
    QString sql = QString("update '%1' set lektion = '%2' where wid = '%3' and bookPath = '%4'")
            .arg(tableName)
            .arg(lektion)
            .arg(wid)
            .arg(bookPath);
    return exec(sql);
}

bool LearnBase::setWordState(const QString &tableName, const int &id, const int &Grade,
                             const double &EF, const int &Repetition, const int &Interval)
{
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString sql = QString("update '%1' set Grade = '%2', EF = '%3', Repetition = '%4',"
                          " Interval = '%5', LastTime = '%6' where id = '%7'")
            .arg(tableName)
            .arg(Grade)
            .arg(EF)
            .arg(Repetition)
            .arg(Interval)
            .arg(currentTime)
            .arg(id);
    return exec(sql);
}

bool LearnBase::setGrade(const QString &tableName, const int &id, const int &Grade)
{
    QString sql = QString("update '%1' set Grade = '%2' where id = '%3'")
            .arg(tableName)
            .arg(Grade)
            .arg(id);
    return exec(sql);
}

bool LearnBase::setEF(const QString &tableName, const int &id, const double &EF)
{
    QString sql = QString("update '%1' set EF = '%2' where id = '%3'")
            .arg(tableName)
            .arg(EF)
            .arg(id);
    return exec(sql);
}

bool LearnBase::setRepetition(const QString &tableName, const int &id, const int &Repetition)
{
    QString sql = QString("update '%1' set Repetition = '%2' where id = '%3'")
            .arg(tableName)
            .arg(Repetition)
            .arg(id);
    return exec(sql);
}

bool LearnBase::setInterval(const QString &tableName, const int &id, const int &Interval)
{
    QString sql = QString("update '%1' set Interval = '%2' where id = '%3'")
            .arg(tableName)
            .arg(Interval)
            .arg(id);
    return exec(sql);
}

bool LearnBase::setTimeDiff(const QString &tableName, const int &id, const int &TimeDiff)
{
    QString sql = QString("update '%1' set TimeDiff = '%2' where id = '%3'")
            .arg(tableName)
            .arg(TimeDiff)
            .arg(id);
    return exec(sql);
}

int LearnBase::getHaveLearnedWordCountByLektion(const QString &bookPath, const int &lektion)
{
    QString sql = QString("select count(*) from StateTable where bookpath = '%1' and lektion = '%2'")
            .arg(bookPath)
            .arg(lektion);
    QSqlQuery query(sql, *db);
    query.next();
    return query.value(0).toInt();
}

int LearnBase::getHaveLearnedWordCount(const QString &bookPath)
{
    QString sql = QString("select count(*) from StateTable where bookpath = '%1'")
            .arg(bookPath);
    QSqlQuery query(sql, *db);
    query.next();
    return query.value(0).toInt();
}

int LearnBase::getReviewCountInfo(const QString &bookPath, const int &Interval)
{
    QString sql = QString("select count(*) from StateTable "
                          "where bookpath = '%1' and Interval = '%2'")
            .arg(bookPath).arg(Interval);
//    QString sql = QString("select count(*) from StateTable "
//                          "where bookpath = '%1' and ((julianday('now') "
//                          "- julianday(date(LastTime))) <= %2)")
//            .arg(bookPath).arg(Interval);
    QSqlQuery query(sql, *db);
    query.next();
    return query.value(0).toInt();
}

int LearnBase::getWordCountG5(const QString &bookPath)
{
    QString sql = QString("select count(*) from StateTable "
                          "where bookpath = '%1' and Grade = 5")
            .arg(bookPath);
    QSqlQuery query(sql, *db);
    query.next();
    return query.value(0).toInt();
}

int LearnBase::getWordCountG4A3(const QString &bookPath)
{
    QString sqlG4 = QString("select count(*) from StateTable "
                          "where bookpath = '%1'and Grade = 4")
            .arg(bookPath);
    QSqlQuery queryG4(sqlG4, *db);
    queryG4.next();
    int G4 = queryG4.value(0).toInt();

    QString sqlG3 = QString("select count(*) from StateTable "
                          "where bookpath = '%1' and Grade = 3")
            .arg(bookPath);
    QSqlQuery queryG3(sqlG3, *db);
    queryG3.next();
    int G3 = queryG3.value(0).toInt();

    return (G3+G4);
}

int LearnBase::getWordCountGU3(const QString &bookPath)
{
    QString sql = QString("select count(*) from StateTable "
                          "where bookpath = '%1' and Grade < 3")
            .arg(bookPath);
    QSqlQuery query(sql, *db);
    query.next();
    return query.value(0).toInt();
}

QSqlTableModel *LearnBase::studyStateDBModel(QWidget *parent)
{
    QSqlTableModel *studyStateModel;
    studyStateModel = new QSqlTableModel(parent,*db);
    QString tableName = QString("StateTable");
    studyStateModel->setTable(tableName);
    studyStateModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    studyStateModel->select(); //选取整个表的所有行
    return studyStateModel;
}
