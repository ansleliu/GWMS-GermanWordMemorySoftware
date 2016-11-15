#include "userbookdbmgr.h"
UserBookDBMgr *userBookDBMgr = NULL;

UserBookDBMgr::UserBookDBMgr(const QString &dbpath, const QString &connName)
{
    userBookDBMgr = this;
    userBookDB = new UserBookDB(dbpath,connName);
}

UserBookDBMgr::~UserBookDBMgr()
{
    delete userBookDB;
}

int UserBookDBMgr::getWortCount()
{
    return userBookDB->getWordCount();
}

int UserBookDBMgr::getWordCountByLektion(const int &lektion)
{
    return userBookDB->getWordCount(lektion);
}

int UserBookDBMgr::getWordID(const QString &word)
{
    return userBookDB->getWordID(word);
}

QString UserBookDBMgr::getWort(const int &wid)
{
    return userBookDB->getWord(wid);
}

QString UserBookDBMgr::getMean(const int &wid)
{
    return userBookDB->getMean(wid);
}

QString UserBookDBMgr::getConnection(const int &wid)
{
    return userBookDB->getConnection(wid);
}

QString UserBookDBMgr::getLektion(const int &wid)
{
    return userBookDB->getLektion(wid);
}

QMap<QString, QString> UserBookDBMgr::getWordMean(const int &wid)
{
    return userBookDB->getWordMean(wid);
}

QStringList UserBookDBMgr::getWordALL(const int &wid)
{
    return userBookDB->getWordALL(wid);
}

QStringList UserBookDBMgr::getLektionList()
{
    return userBookDB->getLektionList();
}

QList< QMap<QString, QString> > UserBookDBMgr::getLektionWordMean(const int &lektion)
{
    return userBookDB->getLektionWordMean(lektion);
}

QList<QStringList> UserBookDBMgr::getLektionWordAll(const int &lektion)
{
    return userBookDB->getLektionWordAll(lektion);
}

QList<int> UserBookDBMgr::getWordIDByLektion(const int &lektion)
{
    return userBookDB->getWordIDByLektion(lektion);
}

bool UserBookDBMgr::updateWord(const QString &word, const int &wid)
{
    return userBookDB->updateWord(word,wid);
}

bool UserBookDBMgr::updateMean(const QString &mean, const int &wid)
{
    return userBookDB->updateMean(mean,wid);
}

bool UserBookDBMgr::updateConnection(const QString &connection, const int &wid)
{
    return userBookDB->updateConnection(connection,wid);
}

bool UserBookDBMgr::updateLektion(const QString &lektion, const int &wid)
{
    return userBookDB->updateLektion(lektion,wid);
}
