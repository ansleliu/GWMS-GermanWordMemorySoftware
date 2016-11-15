#include "userdatadb.h"
#include "QMessageBox"
#include "QFileInfo"
UserDataDB::UserDataDB(const QString &dbpath, const QString &connName)
    : MySQLite(dbpath, connName)
{
    if(!isTableExist("UserBookInfo"))
    {
        createUBInfoTable();
    }
}

UserDataDB::~UserDataDB()
{
}

void UserDataDB::createUBInfoTable()
{
    db->transaction();
    exec("CREATE TABLE [UserBookInfo] (\
         [bookid] INTEGER NOT NULL ON CONFLICT FAIL PRIMARY KEY AUTOINCREMENT,\
         [username] CHAR(32),\
         [bookclass] TEXT,\
         [bookname] TEXT,\
         [bookpath] TEXT,\
         [totalnumb] INTEGER,\
         [isLearning] BOOL NOT NULL ON CONFLICT FAIL DEFAULT 0,\
         [havelearned] INTEGER);");
    db->commit();
}

void UserDataDB::createUBSRecordTable(const QString &tablename)
{
    db->transaction();
    QString sql = QString("CREATE TABLE [%1] ("
                          "[id] INTEGER NOT NULL ON CONFLICT FAIL PRIMARY KEY AUTOINCREMENT, "
                          "[date] TEXT, "
                          "[learn] INTEGER, "
                          "[review] INTEGER);").arg(tablename);
    exec(sql);
    db->commit();
}

void UserDataDB::deleteTable(const QString &tablename)
{
    db->transaction();
    QString sql = QString("DROP TABLE %1").arg(tablename);
    exec(sql);
    db->commit();
}

QSqlDatabase *UserDataDB::getUserDatadb()
{
    return getdb();
}

bool UserDataDB::addNewBook(const QString &username, const QString &bookclass,
                            const QString &bookname, const QString &bookpath, const int totalnum)
{
    if (!exists(bookclass,bookname))
    {
        if(!exists(bookpath))
        {
            QString sql = QString("insert into UserBookInfo "
                                  "(username, bookclass, bookname, bookpath, totalnumb, isLearning, havelearned)"
                                  " values ('%1', '%2', '%3', '%4', '%5', '%6', '%7')")
                    .arg(username)
                    .arg(bookclass)
                    .arg(bookname)
                    .arg(bookpath)
                    .arg(totalnum)
                    .arg(0)
                    .arg(0);

            QFileInfo fd(bookpath);
            QString tablename = fd.baseName();
            createUBSRecordTable(tablename);

            return exec(sql);
        }
        else
        {
            return false;
        }
    }
    else
    {
        qDebug() << QString("添加词库失败，因为词库已经存在，无需重复添加");
        return false;
    }
}

bool UserDataDB::deleteBook(const QString &bookclass, const QString &bookname)
{
    if (exists(bookclass,bookname))
    {
        QString sql = QString("delete from UserBookInfo where bookclass = '%1' and bookname = '%2'")
                .arg(bookclass).arg(bookname);
        QString bookpath = getBookPaths(bookclass,bookname);
        QFileInfo fd(bookpath);
        QString tablename = fd.baseName();
        deleteTable(tablename);

        return exec(sql);
    }
    else
    {
        return false;
    }
}

bool UserDataDB::deleteBook(const QString &bookpath)
{
    if (exists(bookpath))
    {
        QString sql = QString("delete from UserBookInfo where bookpath = '%1'")
                .arg(bookpath);
        QFileInfo fd(bookpath);
        QString tablename = fd.baseName();
        deleteTable(tablename);
        return exec(sql);
    }
    else
    {
        return false;
    }
}

bool UserDataDB::exists(const QString &bookclass, const QString &bookname)
{
    QSqlQuery query(QString("select bookid from UserBookInfo where bookclass = '%1' and bookname = '%2'")
                    .arg(bookclass).arg(bookname), *db);
    return query.next();
}

bool UserDataDB::exists(const QString &bookpath)
{
    QSqlQuery query(QString("select bookid from UserBookInfo where bookpath = '%1'")
                    .arg(bookpath), *db);
    return query.next();
}

bool UserDataDB::existsDayRecord(const QString &bookpath, const QString &daytime)
{
    QFileInfo fd(bookpath);
    QString tablename = fd.baseName();
    QSqlQuery query(QString("select id from %1 where date = '%2'")
                    .arg(tablename).arg(daytime), *db);
    return query.next();
}

bool UserDataDB::addNewBookStudyRecord(const QString &bookpath, const QString &daytime,
                                   const int &learncount, const int &reviewcount)
{
    if (!existsDayRecord(bookpath,daytime))
    {
        QFileInfo fd(bookpath);
        QString tablename = fd.baseName();
        QString sql = QString("insert into %1 "
                              "(date, learn, review) "
                              "values ('%2', '%3', '%4')")
                .arg(tablename)
                .arg(daytime)
                .arg(learncount)
                .arg(reviewcount);
        return exec(sql);
    }
    else
    {
        return false;
    }
}

int UserDataDB::getDayLearnRecord(const QString &bookpath, const QString &daytime)
{
    if (existsDayRecord(bookpath,daytime))
    {
        QFileInfo fd(bookpath);
        QString tablename = fd.baseName();
        int learn = 0;
        QString sql = QString("select learn from %1 where date = '%2'")
                .arg(tablename).arg(daytime);
        QSqlQuery query(sql, *db);

        query.next();
        learn = query.record().value("learn").toInt();
        return learn;
    }
    else
    {
        return 0;
    }
}

int UserDataDB::getDayReviewRecord(const QString &bookpath, const QString &daytime)
{
    if (existsDayRecord(bookpath,daytime))
    {
        QFileInfo fd(bookpath);
        QString tablename = fd.baseName();
        int review = 0;
        QString sql = QString("select review from %1 where date = '%2'")
                .arg(tablename).arg(daytime);
        QSqlQuery query(sql, *db);

        query.next();
        review = query.record().value("review").toInt();
        return review;
    }
    else
    {
        return 0;
    }
}

bool UserDataDB::updateLearnRecord(const QString &bookpath, const QString &daytime,
                                       const int &learncount)
{
    if (existsDayRecord(bookpath,daytime))
    {
        QFileInfo fd(bookpath);
        QString tablename = fd.baseName();
        QString sql = QString("update %1 set "
                              "learn = '%2' "
                              "where date = '%3'")
                .arg(tablename)
                .arg(learncount)
                .arg(daytime);
        return exec(sql);
    }
    else
    {
        return false;
    }
}

bool UserDataDB::updateReviewRecord(const QString &bookpath, const QString &daytime,
                                    const int &reviewcount)
{
    if (existsDayRecord(bookpath,daytime))
    {
        QFileInfo fd(bookpath);
        QString tablename = fd.baseName();
        QString sql = QString("update %1 set "
                              "review = '%2' "
                              "where date = '%3'")
                .arg(tablename)
                .arg(reviewcount)
                .arg(daytime);
        return exec(sql);
    }
    else
    {
        return false;
    }
}

bool UserDataDB::setLearnState(const QString &bookclass, const QString &bookname, bool learnstate)
{
    if (exists(bookclass,bookname))
    {
        QString sql = QString("update UserBookInfo set "
                              "isLearning = '%1' where "
                              "bookclass = '%2' and bookname = '%3'")
                .arg(learnstate)
                .arg(bookclass)
                .arg(bookname);
        return exec(sql);
    }
    else
    {
        return false;
    }
}

bool UserDataDB::setLearnState(const QString &bookpath, bool learnstate)
{
    if (exists(bookpath))
    {
        QString sql = QString("update UserBookInfo set "
                              "isLearning = '%1' "
                              "where bookpath = '%2'")
                .arg(learnstate)
                .arg(bookpath);
        return exec(sql);
    }
    else
    {
        return false;
    }
}

bool UserDataDB::setHaveLearnedNum(const QString &bookclass, const QString &bookname, const int havelearned)
{
    if (exists(bookclass,bookname))
    {
        QString sql = QString("update UserBookInfo set "
                              "havelearned = '%1' where "
                              "bookclass = '%2' and bookname = '%3'")
                .arg(havelearned)
                .arg(bookclass)
                .arg(bookname);
        return exec(sql);
    }
    else
    {
        return false;
    }
}

bool UserDataDB::setHaveLearnedNum(const QString &bookpath, const int havelearned)
{
    if (exists(bookpath))
    {
        QString sql = QString("update UserBookInfo set "
                              "havelearned = '%1' "
                              "where bookpath = '%2'")
                .arg(havelearned)
                .arg(bookpath);
        return exec(sql);
    }
    else
    {
        return false;
    }
}

bool UserDataDB::setTotalNumb(const QString &bookclass, const QString &bookname, const int totalnumb)
{
    if (exists(bookclass,bookname))
    {
        QString sql = QString("update UserBookInfo set "
                              "totalnumb = '%1' where "
                              "bookclass = '%2' and bookname = '%3'")
                .arg(totalnumb)
                .arg(bookclass)
                .arg(bookname);
        return exec(sql);
    }
    else
    {
       return false;
    }
}

bool UserDataDB::setTotalNumb(const QString &bookpath, const int totalnumb)
{
    if (exists(bookpath))
    {
        QString sql = QString("update UserBookInfo set "
                              "totalnumb = '%1' "
                              "where bookpath = '%2'")
                .arg(totalnumb)
                .arg(bookpath);
        return exec(sql);
    }
    else
    {
       return false;
    }
}

bool UserDataDB::setBookName(const QString &bookclass, const QString &bookname, const QString &newbookname)
{
    if (exists(bookclass,bookname))
    {
        if (!exists(bookclass,newbookname))
        {
            QString sql = QString("update UserBookInfo set "
                                  "bookname = '%1' where "
                                  "bookclass = '%2' and bookname = '%3'")
                    .arg(newbookname)
                    .arg(bookclass)
                    .arg(bookname);
            return exec(sql);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool UserDataDB::setBookClass(const QString &bookclass, const QString &newbookclass)
{
    QString sql = QString("update UserBookInfo set "
                              "bookclass = '%1' where "
                              "bookclass = '%2'")
            .arg(newbookclass)
            .arg(bookclass);
    return exec(sql);
}

QString UserDataDB::getUserName()
{
    QString UserName;
    QSqlQuery query("select username from UserBookInfo", *db);
    query.next();
    UserName = query.record().value("username").toString();

    return UserName;
}

QStringList UserDataDB::getBookClasses()
{
    QStringList BookClasses;
    QSqlQuery query("select bookclass from UserBookInfo", *db);
    while (query.next())
    {
        BookClasses << query.record().value("bookclass").toString();
    }
    return BookClasses;
}

QString UserDataDB::getBookClasse(const QString &bookpath)
{
    QString BookClasse;
    QString sql = QString("select bookclass from UserBookInfo where bookpath = '%1'").arg(bookpath);
    QSqlQuery query(sql, *db);

    query.next();
    BookClasse = query.record().value("bookclass").toString();
    return BookClasse;
}

QStringList UserDataDB::getBookNames()
{
    QStringList BookNames;
    QSqlQuery query("select bookname from UserBookInfo", *db);
    while (query.next())
    {
        BookNames << query.record().value("bookname").toString();
    }
    return BookNames;
}

QStringList UserDataDB::getBookNames(const QString &bookclass)
{
    QStringList BookNames;
    QSqlQuery query(QString("select bookname from UserBookInfo where bookclass = '%1'")
                    .arg(bookclass), *db);
    while (query.next())
    {
        BookNames << query.record().value("bookname").toString();
    }
    return BookNames;
}

QString UserDataDB::getBookName(const QString &bookpath)
{
    QString BookName;
    QString sql = QString("select bookname from UserBookInfo where bookpath = '%1'").arg(bookpath);
    QSqlQuery query(sql, *db);

    query.next();
    BookName = query.record().value("bookname").toString();
    return BookName;
}

QStringList UserDataDB::getBookPaths()
{
    QStringList BookPaths;
    QSqlQuery query("select bookpath from UserBookInfo", *db);
    while (query.next())
    {
        BookPaths << query.record().value("bookpath").toString();
    }
    return BookPaths;
}

QString UserDataDB::getBookPaths(const QString &bookclass, const QString &bookname)
{
    QString BookPaths;
    QSqlQuery query(QString("select bookpath from UserBookInfo where bookclass = '%1' and bookname = '%2'")
                    .arg(bookclass).arg(bookname), *db);
    while (query.next())
    {
        BookPaths = query.record().value("bookpath").toString();
    }
    return BookPaths;
}

int UserDataDB::getLearnState(const QString &bookclass, const QString &bookname)
{
    bool learnState = false;
    QSqlQuery query(QString("select isLearning from UserBookInfo where bookclass = '%1' and bookname = '%2'")
                    .arg(bookclass).arg(bookname), *db);
    while (query.next())
    {
        learnState = query.record().value("isLearning").toInt();
    }
    return learnState;
}

int UserDataDB::getLearnState(const QString &bookpath)
{
    bool learnState;
    QString sql = QString("select isLearning from UserBookInfo where bookpath = '%1'").arg(bookpath);
    QSqlQuery query(sql, *db);

    query.next();
    learnState = query.record().value("isLearning").toInt();
    return learnState;
}

int UserDataDB::getBookId(const QString &bookpath)
{
    QSqlQuery query(QString("select bookid from UserBookInfo where bookpath = '%1'")
                    .arg(bookpath), *db);
    query.next();
    return query.record().value("bookid").toInt();
}

int UserDataDB::getCount()
{
    QSqlQuery query("select count(*) from UserBookInfo", *db);
    query.next();
    return query.value(0).toInt();

}

int UserDataDB::getTotalNumb(const QString &bookclass, const QString &bookname)
{
    QSqlQuery query(QString("select totalnumb from UserBookInfo where bookclass = '%1' and bookname = '%2'")
                    .arg(bookclass).arg(bookname), *db);
    query.next();
    return query.record().value("totalnumb").toInt();
}

int UserDataDB::getHaveLearnedNum(const QString &bookclass, const QString &bookname)
{
    QSqlQuery query(QString("select havelearned from UserBookInfo where bookclass = '%1' and bookname = '%2'")
                    .arg(bookclass).arg(bookname), *db);
    query.next();
    return query.record().value("havelearned").toInt();
}

int UserDataDB::getHaveLearnedNum(const QString &bookpath)
{
    QSqlQuery query(QString("select havelearned from UserBookInfo where bookpath = '%1'")
                    .arg(bookpath), *db);
    query.next();
    return query.record().value("havelearned").toInt();
}

QSqlTableModel *UserDataDB::userDataDBModel(QWidget *parent)
{
    QSqlTableModel *userDataModel;
    userDataModel = new QSqlTableModel(parent,*db);
    QString tableName = QString("UserBookInfo");
    userDataModel->setTable(tableName);
    userDataModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    userDataModel->select(); //选取整个表的所有行
    return userDataModel;
}
