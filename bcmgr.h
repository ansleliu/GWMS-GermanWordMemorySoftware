#ifndef BCMGR_H
#define BCMGR_H
#include <QObject>
#include "pathmanage.h"
#include "myglobal.h"
#include "myconfig.h"
#include "userdatadb.h"
#include "./AnsleDictCode/CreatWordListDB.h"
#include "QTreeWidget"
#include "QMessageBox"
#include "QString"
#include "QPoint"
#include "QMap"

class BCMgr : public QObject
{
    Q_OBJECT
public:
    explicit BCMgr(QObject *parent = 0,const QString &userName = NULL);
    ~BCMgr();
    
signals:
    
public slots:
    QSqlDatabase *getUserBookdb();

    QString getUserName();

    QStringList getBookClasses();
    QString getBookClasse(const QString &bookpath);

    QStringList getBookNames();
    QStringList getBookNames(const QString &bookclass);
    QString getBookName(const QString &bookpath);

    QStringList getBookPaths();
    QString getBookPaths(const QString &bookclass, const QString &bookname);

    int getTotalNumb(const QString &bookclass, const QString &bookname);
    int getCount();

    int getHaveLearnedNum(const QString &bookclass, const QString &bookname);
    int getHaveLearnedNum(const QString &bookpath);

    int getLearnState(const QString &bookclass, const QString &bookname);
    int getLearnState(const QString &bookpath);

    bool addNewBook(const QString &bookclass,const QString &bookname,
                    const QString &bookpath,int totalnum = 0);
    void deleteBook(const QString &bookclass,const QString &bookname);

    void addRootItem(QTreeWidget *parent, const QString &strings);

    void addChildItem(QTreeWidget *parent, const QString &strings);
    void addChildItem(QTreeWidget *parent,const QString &string,const QString &strings);

    void removeRootItem(QTreeWidget *parent,const QString &strings,int column = 0);
    void removeRootItem(QTreeWidget *parent);

    void removeChildItem(QTreeWidget *parent);
    void removeChildItemByRow(QTreeWidget *parent,int row = 0);

    void editItem(QTreeWidget *parent,const QString &strings);

    bool updateBookName(QTreeWidget *parent,const QString &bookclass,
                        const QString &bookname,const QString &newbookname);
    bool updateBookClass(QTreeWidget *parent,const QString &bookclass,
                         const QString &newbookclass);

    bool updateTotalNumb(const QString &bookclass,const QString &bookname,
                         int totalNumb = 0);
    bool updateTotalNumb(const QString &bookpath,const int totalnumb = 0);

    bool updateHaveLearnedNum(const QString &bookclass,const QString &bookname,const int havelearned = 0);
    bool updateHaveLearnedNum(const QString &bookpath,const int havelearned = 0);

    bool updateLearnState(const QString &bookclass,const QString &bookname,
                          bool learnstate = true);
    bool updateLearnState(const QString &bookpath,bool learnstate = true);
    ///////////////////////////////////////////////////////////////////////////////////
    //
    bool existsDayRecord(const QString &bookpath,const QString &daytime);
    bool addNewBookStudyRecord(const QString &bookpath, const QString &daytime,
                           const int &learncount, const int &reviewcount);
    int getDayLearnRecord(const QString &bookpath,const QString &daytime);
    int getDayReviewRecord(const QString &bookpath,const QString &daytime);
    bool updateLearnRecord(const QString &bookpath, const QString &daytime,
                           const int &learncount);
    bool updateReviewRecord(const QString &bookpath, const QString &daytime,
                            const int &reviewcount);
    ///////////////////////////////////////////////////////////////////////////////////
    //
    void showBookList(QTreeWidget *parent);

    QSqlTableModel *userDataDBModel(QWidget *parent);

public:
    MyConfig *userConf;//用户的配置信息
    CreatWordListDB *myBook;

protected:
    UserDataDB *userdatadb;

};
extern BCMgr *bcMgr;
#endif // BCMGR_H
