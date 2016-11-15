#include "userbookdb.h"
#include "QMessageBox"
UserBookDB::UserBookDB(const QString &dbpath, const QString &connName)
    :MySQLite(dbpath, connName)
{
    if(!isTableExist("WordsBook"))
    {
        QMessageBox::warning(NULL, QObject::tr("数据库错误"),
                                     QObject::tr("非法词库: 您选择的词库不正确"));
    }
}

UserBookDB::~UserBookDB()
{
}

QSqlDatabase *UserBookDB::getUserBookdb()
{
    return getdb();
}

int UserBookDB::getWordCount()
{
    QSqlQuery query("select count(*) from WordsBook", *db);
    query.next();
    return query.value(0).toInt();
}

int UserBookDB::getWordCount(const int &lektion)
{
    QString sql = QString("select count(*) from WordsBook where Lektion = '%1'")
            .arg(lektion);
    QSqlQuery query(sql, *db);
    query.next();
    return query.value(0).toInt();
}

int UserBookDB::getWordID(const QString &word)
{
    QString sql = QString("select Wid from WordsBook where Wort = '%1'")
            .arg(word);
    QSqlQuery query(sql, *db);
    query.next();
    return query.record().value("Wid").toInt();
}

QString UserBookDB::getWord(const int &wid)
{
    QString wort;
    QString sql;
    sql = QString("select Wort from WordsBook where Wid = '%1'").arg(wid);

    QSqlQuery query(sql, *db);
    query.next();
    wort = query.record().value("Wort").toString();
    return wort;
}

QString UserBookDB::getMean(const int &wid)
{
    QString mean;
    QString sql;
    sql = QString("select Bedeutung from WordsBook where Wid = '%1'")
                .arg(wid);

    QSqlQuery query(sql, *db);
    query.next();
    mean = query.record().value("Bedeutung").toString();
    return mean;
}

QString UserBookDB::getConnection(const int &wid)
{
    QString connection;
    QString sql;
    sql = QString("select Connection from WordsBook where Wid = '%1'")
                .arg(wid);

    QSqlQuery query(sql, *db);
    query.next();
    connection = query.record().value("Connection").toString();
    return connection;
}

QString UserBookDB::getLektion(const int &wid)
{
    QString lektion;
    QSqlQuery query(QString("select Lektion from WordsBook where Wid = '%1'")
                    .arg(wid), *db);
    query.next();
    lektion = query.record().value("Lektion").toString();
    return lektion;
}

QMap<QString, QString> UserBookDB::getWordMean(const int &wid)
{
    QMap<QString, QString> map;
    QSqlQuery query(QString("select Wort, Bedeutung from WordsBook where Wid = '%1'")
                    .arg(wid), *db);
    query.next();
    QString wort = query.record().value("Wort").toString();
    QString mean = query.record().value("Bedeutung").toString();
    map.insert(wort,mean);
    return map;
}

QStringList UserBookDB::getWordALL(const int &wid)
{
    QStringList wordAll;
    QSqlQuery query(QString("select Wort, Bedeutung, Connection from WordsBook where Wid = '%1'")
                    .arg(wid), *db);
    query.next();
    wordAll << query.record().value("Wort").toString()
            << query.record().value("Bedeutung").toString()
            << query.record().value("Connection").toString();
    return wordAll;
}

QStringList UserBookDB::getLektionList()
{
    QStringList list;
//    QSqlQuery query(QString("select Lektion from WordsBook group by Lektion"), *db);
    QSqlQuery query(QString("select distinct Lektion from WordsBook"), *db);
    while (query.next())
    {
        QString lektion = query.record().value("Lektion").toString();
        if(lektion != "")
        {
            list << lektion;
        }
    }
    return list;
}

QList< QMap<QString, QString> > UserBookDB::getLektionWordMean(const int &lektion)
{
    QList<QMap<QString, QString> > list;
    QMap<QString, QString> map;
    QSqlQuery query(QString("select Wid from WordsBook where Lektion = '%1'")
                    .arg(lektion), *db);
    while(query.next())
    {
        int wid = query.record().value("Wid").toInt();
        map = getWordMean(wid);
        list.append(map);
    }
    return list;
}

QList<QStringList> UserBookDB::getLektionWordAll(const int &lektion)
{
    QList<QStringList> list;
    QStringList wordAll;
    QSqlQuery query(QString("select Wid from WordsBook where Lektion = '%1'")
                    .arg(lektion), *db);
    while(query.next())
    {
        int wid = query.record().value("Wid").toInt();
        wordAll = getWordALL(wid);
        list.append(wordAll);
    }
    return list;
}

QList<int> UserBookDB::getWordIDByLektion(const int &lektion)
{
    QList<int> wordIDList;
    QSqlQuery query(QString("select Wid from WordsBook where Lektion = '%1'")
                    .arg(lektion), *db);
    while(query.next())
    {
        int wid = query.record().value("Wid").toInt();
        wordIDList.append(wid);
    }
    return wordIDList;
}

bool UserBookDB::updateWord(const QString &word, const int &wid)
{
    QString sql = QString("update WordsBook set Wort = '%1' where Wid = '%2'")
            .arg(word)
            .arg(wid);
    return exec(sql);
}

bool UserBookDB::updateMean(const QString &mean, const int &wid)
{
    QString sql = QString("update WordsBook set Bedeutung = '%1' where Wid = '%2'")
            .arg(mean)
            .arg(wid);
    return exec(sql);
}

bool UserBookDB::updateConnection(const QString &connection, const int &wid)
{
    QString sql = QString("update WordsBook set Connection = '%1' where Wid = '%2'")
            .arg(connection)
            .arg(wid);
    return exec(sql);
}

bool UserBookDB::updateLektion(const QString &lektion, const int &wid)
{
    QString sql = QString("update WordsBook set Lektion = '%1' where Wid = '%2'")
            .arg(lektion)
            .arg(wid);
    return exec(sql);
}
