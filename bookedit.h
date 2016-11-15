#ifndef BOOKEDIT_H
#define BOOKEDIT_H
#include "mysqlite.h"
#include "QString"
#include <QSqlTableModel>

class BookEdit : public MySQLite
{
public:
    BookEdit(const QString &dbpath,
             const QString &connName);
    ~BookEdit();

public:
    bool addNewRecord(const QString &word,
                      const QString &mean,
                      const QString &connection,
                      const int &lektion);
    bool removeRecord(const int &rowNum);
    QSqlDatabase *getdb();
    int getRowCount();
    QSqlTableModel *wordListDBModel(QWidget *parent,
                                    const QString &tableName);

private:
    QSqlTableModel *DBModel;
};

#endif // BOOKEDIT_H
