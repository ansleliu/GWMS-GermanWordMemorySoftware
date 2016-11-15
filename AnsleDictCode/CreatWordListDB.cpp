#include "CreatWordListDB.h"
#include "QFileInfo"
CreatWordListDB::CreatWordListDB(const QString &dbpath,
                                 const QString &connName)
    : MySQLite(dbpath, connName)
{
    QFileInfo info(dbpath);
    wordListName = info.fileName();

    if (!isTableExist("WordsBook"))	// 新建的数据库,创建表
    {
        createTable();
    }
    DBModel = NULL;
}

CreatWordListDB::~CreatWordListDB()
{
    if(DBModel != NULL)
    {
        delete DBModel;
        DBModel = NULL;
    }
}

bool CreatWordListDB::addNewRecord(const QString &word,
                                   const QString &mean,
                                   const QString &connection,
                                   const int &lektion)
{
    QString sql = QString("insert into WordsBook "
                          "(Wort, Bedeutung, Connection, Lektion)"
                          " values ('%1', '%2', '%3', '%4')")
            .arg(word)
            .arg(mean)
            .arg(connection)
            .arg(lektion);
    return exec(sql);
}

bool CreatWordListDB::removeRecord(const int &rowNum)
{
    QString sql = QString("delete from WordsBook where Wid = '%1'")
            .arg(rowNum);
    if(rowNum == getRowCount())
    {
        QString resetsql = QString("update sqlite_sequence set seq = %1 where name = '%2'")
                .arg((getRowCount()-1)).arg("WordsBook");
         exec(resetsql);
    }
    return exec(sql);
}

QStringList CreatWordListDB::getRecord(const int &wid)
{
    QStringList Record;
    QSqlQuery query(QString("select Wort, Bedeutung, Connection from WordsBook where Wid = '%1'")
                    .arg(wid), *db);
    query.next();
    Record << query.record().value("Wort").toString()
            << query.record().value("Bedeutung").toString()
            << query.record().value("Connection").toString();
    return Record;
}

bool CreatWordListDB::isExist(const QString &word)
{
    int wid;
    QSqlQuery query(QString("select Wid from WordsBook where Wort = '%1'")
                    .arg(word), *db);
    query.next();
    wid = query.record().value("Wid").toInt();
    return wid;
}

bool CreatWordListDB::updataWord(const QString &word, const int &wid)
{
    QString sql = QString("update WordsBook set Wort = '%1' where Wid = '%2'")
            .arg(word)
            .arg(wid);
    return exec(sql);
}

bool CreatWordListDB::updataMean(const QString &mean, const int &wid)
{
    QString sql = QString("update WordsBook set Bedeutung = '%1' where Wid = '%2'")
            .arg(mean)
            .arg(wid);
    return exec(sql);
}

bool CreatWordListDB::updataConnection(const QString &connection, const int &wid)
{
    QString sql = QString("update WordsBook set Connection = '%1' where Wid = '%2'")
            .arg(connection)
            .arg(wid);
    return exec(sql);
}

QSqlDatabase *CreatWordListDB::getdb()
{
    return db;
}

int CreatWordListDB::getRowCount()
{
    QSqlQuery query("select count(*) from WordsBook", *db);
    query.next();
    return query.value(0).toInt();
}

QSqlTableModel *CreatWordListDB::wordListDBModel(QWidget *parent,
                                                 const QString &tableName)
{
    DBModel = new QSqlTableModel(parent,*db);
    DBModel->setTable(tableName);
    DBModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    DBModel->select(); //选取整个表的所有行
    return DBModel;
}

QString CreatWordListDB::getWordListName()
{
    return wordListName;
}

bool CreatWordListDB::createTable()
{
    db->transaction();
    QSqlQuery query(*db);
    query.exec("CREATE TABLE [WordsBook] (\
               [Wid] INTEGER NOT NULL ON CONFLICT FAIL PRIMARY KEY AUTOINCREMENT, \
               [Wort] TEXT, \
               [Bedeutung] TEXT, \
               [Connection] TEXT, \
               [Lektion] INTEGER);");

    db->commit();
    return true;
}
