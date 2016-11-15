#ifndef CREATWORDLISTDB_H
#define CREATWORDLISTDB_H
#include "../mysqlite.h"
#include <QSqlTableModel>
#include <QWidget>

class CreatWordListDB : public MySQLite
{
public:
    CreatWordListDB(const QString &dbpath,
                    const QString &connName);
    ~CreatWordListDB();

public:
    bool addNewRecord(const QString &word,
                      const QString &mean,
                      const QString &connection,
                      const int &lektion);
    bool removeRecord(const int &rowNum);

    QStringList getRecord(const int &wid);
    bool isExist(const QString &word);

    bool updataWord(const QString &word, const int &wid);
    bool updataMean(const QString &mean, const int &wid);
    bool updataConnection(const QString &connection, const int &wid);

    QSqlDatabase *getdb();
    int getRowCount();
    QSqlTableModel *wordListDBModel(QWidget *parent,
                                    const QString &tableName);

    QString getWordListName();

protected:
    bool createTable();	// ´´½¨±í

private:
    QString wordListName;
    QSqlTableModel *DBModel;
};

#endif // CREATWORDLISTDB_H
