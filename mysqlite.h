#ifndef MYSQLITE_H
#define MYSQLITE_H
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QVariant>
#include <QString>
class MySQLite
{
public:
    MySQLite(const QString &dbpath, const QString &connName);
    virtual ~MySQLite();

    QVariant rexec(const QString &sql);	// 执行sql语句,返回第一行第一列的值
    uint  lastInsertID();	// 取最后插入数据的ID
    bool exec(const QString &sql); // 执行不需要返回结果sql语句

    bool isTableExist(const QString &tableName);	// 给定表名是否存在

    int recordCount(const QString &tableName);
    QSqlDatabase *getdb()
    {
        return db;
    }
protected:
    QSqlDatabase *db;
    QString m_connName;
};

#endif // MYSQLITE_H
