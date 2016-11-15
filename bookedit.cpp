#include "bookedit.h"
#include <QDebug>

BookEdit::BookEdit(const QString &dbpath,
                   const QString &connName)
    : MySQLite(dbpath, connName)
{

}

BookEdit::~BookEdit()
{
    if(DBModel != NULL)
    {
        delete DBModel;
        DBModel = NULL;
    }
}

bool BookEdit::addNewRecord(const QString &word,
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

bool BookEdit::removeRecord(const int &rowNum)
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

QSqlDatabase *BookEdit::getdb()
{
    return db;
}

int BookEdit::getRowCount()
{
    QSqlQuery query("select count(*) from WordsBook", *db);
    query.next();
    return query.value(0).toInt();
}

QSqlTableModel *BookEdit::wordListDBModel(QWidget *parent,
                                          const QString &tableName)
{
    DBModel = new QSqlTableModel(parent,*db);
    DBModel->setTable(tableName);
    DBModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    DBModel->select(); //选取整个表的所有行
    return DBModel;
}
