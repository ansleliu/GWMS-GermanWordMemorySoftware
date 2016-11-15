#ifndef USERDATADB_H
#define USERDATADB_H
#include "mysqlite.h"
#include "QString"
class UserDataDB : public MySQLite
{
public:
    UserDataDB(const QString &dbpath, const QString &connName);
    ~UserDataDB();

protected:
    void createUBInfoTable();
    void createUBSRecordTable(const QString &tablename);
    void deleteTable(const QString &tablename);

public:
    QSqlDatabase *getUserDatadb();

    bool addNewBook(const QString &username,const QString &bookclass,
                    const QString &bookname,const QString &bookpath,const int totalnum = 0);

    bool deleteBook(const QString &bookclass,const QString &bookname);
    bool deleteBook(const QString &bookpath);

    bool exists(const QString &bookclass,const QString &bookname);
    bool exists(const QString &bookpath);
    bool existsDayRecord(const QString &bookpath,const QString &daytime);

    bool addNewBookStudyRecord(const QString &bookpath, const QString &daytime,
                           const int &learncount, const int &reviewcount);
    int getDayLearnRecord(const QString &bookpath,const QString &daytime);
    int getDayReviewRecord(const QString &bookpath,const QString &daytime);
    bool updateLearnRecord(const QString &bookpath, const QString &daytime,
                           const int &learncount);
    bool updateReviewRecord(const QString &bookpath, const QString &daytime,
                            const int &reviewcount);

    bool setLearnState(const QString &bookclass,const QString &bookname, bool learnstate = true);
    bool setLearnState(const QString &bookpath,bool learnstate = true);

    bool setHaveLearnedNum(const QString &bookclass,const QString &bookname,const int havelearned = 0);
    bool setHaveLearnedNum(const QString &bookpath,const int havelearned = 0);

    bool setTotalNumb(const QString &bookclass,const QString &bookname,const int totalnumb = 0);
    bool setTotalNumb(const QString &bookpath,const int totalnumb = 0);

    bool setBookName(const QString &bookclass,const QString &bookname,const QString &newbookname);

    bool setBookClass(const QString &bookclass,const QString &newbookclass);

    QString getUserName();

    QStringList getBookClasses();
    QString getBookClasse(const QString &bookpath);

    QStringList getBookNames();
    QStringList getBookNames(const QString &bookclass);
    QString getBookName(const QString &bookpath);

    QStringList getBookPaths();
    QString getBookPaths(const QString &bookclass,const QString &bookname);

    int getLearnState(const QString &bookclass,const QString &bookname);
    int getLearnState(const QString &bookpath);
    int getBookId(const QString &bookpath);
    int getCount();

    int getTotalNumb(const QString &bookclass,const QString &bookname);
    int getHaveLearnedNum(const QString &bookclass,const QString &bookname);
    int getHaveLearnedNum(const QString &bookpath);

public:
    QSqlTableModel *userDataDBModel(QWidget *parent);
};

#endif // USERDATADB_H
