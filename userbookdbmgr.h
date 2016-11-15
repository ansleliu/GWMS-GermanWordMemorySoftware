#ifndef USERBOOKDBMGR_H
#define USERBOOKDBMGR_H
#include "userbookdb.h"
#include "QMap"
#include "QString"
#include "QList"

class UserBookDBMgr
{
public:
    UserBookDBMgr(const QString &dbpath, const QString &connName);
    ~UserBookDBMgr();

public:
    int getWortCount();
    int getWordCountByLektion(const int &lektion);

    int getWordID(const QString &word);
    QString getWort(const int &wid);
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

protected:
    UserBookDB * userBookDB;

};
extern UserBookDBMgr *userBookDBMgr;
#endif // USERBOOKDBMGR_H
