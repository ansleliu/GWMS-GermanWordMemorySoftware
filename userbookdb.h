#ifndef USERBOOKDB_H
#define USERBOOKDB_H
#include "mysqlite.h"
#include "QString"
#include "QList"
#include "QMap"
class UserBookDB : public MySQLite
{
public:
    UserBookDB(const QString &dbpath, const QString &connName);
    ~UserBookDB();

public:
    QSqlDatabase *getUserBookdb();

    int getWordCount();
    int getWordCount(const int &lektion);

    int getWordID(const QString &word);
    QString getWord(const int &wid);
    QString getMean(const int &wid);
    QString getConnection(const int &wid);
    QString getLektion(const int &wid);

    QMap<QString,QString> getWordMean(const int &wid);
    QStringList getWordALL(const int &wid);

    QStringList getLektionList();
    QList< QMap<QString,QString> > getLektionWordMean(const int &lektion);
    QList<QStringList> getLektionWordAll(const int &lektion);
    QList<int> getWordIDByLektion(const int &lektion);

    bool updateWord(const QString &word, const int &wid);
    bool updateMean(const QString &mean, const int &wid);
    bool updateConnection(const QString &connection, const int &wid);
    bool updateLektion(const QString &lektion, const int &wid);
};

#endif // USERBOOKDB_H
