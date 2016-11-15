#include "bcmgr.h"
#include "QDebug"

BCMgr *bcMgr = NULL;

BCMgr::BCMgr(QObject *parent, const QString &userName) :
    QObject(parent)
{
    bcMgr = this;
    PathManage::createRelExeDir("/userdata/" + userName);
    PathManage::createRelExeDir("/userdata/" + userName + "/book");
    PathManage::createRelExeDir("/userdata/" + userName + "/GoogleTTSVoice");
    PathManage::createRelExeDir("/userdata/" + userName + "/RealSpeak");

    QString udatadbPath = PathManage::makePathStr("/userdata/" + userName + "/userdata.db");
    userConf = new MyConfig(PathManage::makePathStr("/userdata/" + userName + "/%1Config.ini")
                            .arg(userName));
    qDebug() << "udatadbPath: " << udatadbPath;
    userdatadb = new UserDataDB(udatadbPath,"UDATADB");
    /////////////////////////////////////////////////////////////////////////////
    //我的生词本
    PathManage::createRelExeDir("/userdata/" + userName + "/我的生词本/");
    QString myBookDB = PathManage::makePathStr("/userdata/" + userName + "/我的生词本/我的生词本.db");
    qDebug() << "myBookDB: " << myBookDB;
    myBook = new CreatWordListDB(myBookDB,"MYBOOk");

    //将我的生词本添加到词库列表
    bool badd = addNewBook(tr("生词本"),tr("我的生词本"),myBookDB,0);
    if(badd == 1)
    {
        qDebug()<< QString("成功添加我的生词本到词库列表");
    }
    else
    {
        qDebug()<< QString("添加我的生词本到词库列表失败");
    }
    //////////////////////////////////////////////////////////////////////
    //AnsleDict
    PathManage::createRelExeDir("/AnsleDict/MyDict/");
    PathManage::createRelExeDir("/AnsleDict/MyDict/Dict/");
}
BCMgr::~BCMgr()
{
    qDebug() << QString("删除用户配置指针userConf");
    delete userConf;
    userConf = NULL;
    qDebug() << QString("删除数据库UDATADB");
    delete userdatadb;
    userdatadb = NULL;

    qDebug() << QString("删除数据库MYBOOk");
    delete myBook;
    myBook = NULL;    
}

QSqlDatabase *BCMgr::getUserBookdb()
{
    return userdatadb->getUserDatadb();
}

QString BCMgr::getUserName()
{
    return userdatadb->getUserName();
}

QStringList BCMgr::getBookClasses()
{
    return userdatadb->getBookClasses();
}

QString BCMgr::getBookClasse(const QString &bookpath)
{
    return userdatadb->getBookClasse(bookpath);
}

QStringList BCMgr::getBookNames()
{
    return userdatadb->getBookNames();
}

QStringList BCMgr::getBookNames(const QString &bookclass)
{
    return userdatadb->getBookNames(bookclass);
}

QString BCMgr::getBookName(const QString &bookpath)
{
    return userdatadb->getBookName(bookpath);
}

QStringList BCMgr::getBookPaths()
{
    return userdatadb->getBookPaths();
}

QString BCMgr::getBookPaths(const QString &bookclass, const QString &bookname)
{
    return userdatadb->getBookPaths(bookclass,bookname);
}

int BCMgr::getTotalNumb(const QString &bookclass, const QString &bookname)
{
    return userdatadb->getTotalNumb(bookclass,bookname);
}

int BCMgr::getCount()
{
    return userdatadb->getCount();
}

int BCMgr::getHaveLearnedNum(const QString &bookclass, const QString &bookname)
{
    return userdatadb->getHaveLearnedNum(bookclass,bookname);
}

int BCMgr::getHaveLearnedNum(const QString &bookpath)
{
    return userdatadb->getHaveLearnedNum(bookpath);
}

int BCMgr::getLearnState(const QString &bookclass, const QString &bookname)
{
    return userdatadb->getLearnState(bookclass,bookname);
}

int BCMgr::getLearnState(const QString &bookpath)
{
    return userdatadb->getLearnState(bookpath);
}

bool BCMgr::addNewBook(const QString &bookclass, const QString &bookname,
                       const QString &bookpath, int totalnum)
{
    QString userName = Global::Conf->getCurrentUser();
    return userdatadb->addNewBook(userName,bookclass,bookname,bookpath,totalnum);
}

void BCMgr::deleteBook(const QString &bookclass, const QString &bookname)
{
    userdatadb->deleteBook(bookclass,bookname);
}

void BCMgr::addRootItem(QTreeWidget *parent, const QString &strings)
{
    QList<QTreeWidgetItem *>index = parent->findItems(strings,0,0);
    bool i = index.isEmpty();
    if(i == true)
    {
        QTreeWidgetItem *root = new QTreeWidgetItem(QStringList(strings));
        root->setIcon(0,QIcon("./rc/document_open.png"));
        parent->addTopLevelItem(root);
    }
    else
    {
        index.at(0)->setSelected(true);
        index.at(0)->setExpanded(true);
    }
}

void BCMgr::addChildItem(QTreeWidget *parent, const QString &strings)
{
    QTreeWidgetItem *item = parent->currentItem();
    if(item->parent() == NULL)
    {
        QTreeWidgetItem *child = new QTreeWidgetItem(QStringList(strings));
        child->setIcon(0,QIcon("./rc/book2.png"));
        item->addChild(child);
        item->setExpanded(true);
    }
    else
    {
        QTreeWidgetItem *rootItem = item->parent();
        QTreeWidgetItem *child = new QTreeWidgetItem(QStringList(strings));
        child->setIcon(0,QIcon("./rc/book2.png"));
        rootItem->addChild(child);
        rootItem->setExpanded(true);
    }
}

void BCMgr::addChildItem(QTreeWidget *parent, const QString &string, const QString &strings)
{
    QList<QTreeWidgetItem *>index = parent->findItems(string,0,0);
    bool i = index.isEmpty();

    if(i == true)
    {
        QTreeWidgetItem *root = new QTreeWidgetItem(parent,QStringList(string));
        root->setIcon(0,QIcon("./rc/document_open.png"));
        QTreeWidgetItem *child = new QTreeWidgetItem(QStringList(strings));
        child->setIcon(0,QIcon("./rc/book2.png"));
        root->addChild(child);

        root->setExpanded(true);
    }
    else
    {
        QTreeWidgetItem* childItem = new QTreeWidgetItem(QStringList(strings));
        childItem->setIcon(0,QIcon("./rc/book2.png"));
        int childCount = index.at(0)->childCount();
        int isEqual = 0;

        for(int i=0; i<childCount; i++)
        {
            QString childText = index.at(0)->child(i)->text(0);
            if(childText != strings)
            {
                isEqual++;
            }
        }

        if(isEqual == childCount)
        {
            index.at(0)->addChild(childItem);
            index.at(0)->setExpanded(true);
        }
    }
}

void BCMgr::removeRootItem(QTreeWidget *parent, const QString &strings, int column)
{
    QList<QTreeWidgetItem *>index = parent->findItems(strings,0,column);
    bool i = index.isEmpty();

    if(i == false)
    {
        int inx = parent->indexOfTopLevelItem(index.at(0));

        parent->takeTopLevelItem(inx);

        int childCount = index.at(0)->childCount();//子节点数
        for (int i=0;i<childCount;i++)
        {
            QTreeWidgetItem* item = parent ->currentItem();
            item = index.at(0)->child(0);
            delete item;
            item=NULL;
       }
    }
    index.clear();
}

void BCMgr::removeRootItem(QTreeWidget *parent)
{
    QTreeWidgetItem* item = parent->currentItem();

    if(item->parent() == NULL)
    {
        int inx = parent->indexOfTopLevelItem(item);

        int childCount = item->childCount();//子节点数
        for (int i=0; i<childCount; i++)
        {
            QTreeWidgetItem* newItem = parent ->currentItem();
            newItem = item->child(0);
            delete newItem;
            newItem=NULL;
       }

        parent->takeTopLevelItem(inx);
    }
    delete item;
}

void BCMgr::removeChildItem(QTreeWidget *parent)
{
    QTreeWidgetItem* item = parent->currentItem();
    if(item->parent() != NULL)
    {
        item->removeChild(item);
    }
    delete item;
}

void BCMgr::removeChildItemByRow(QTreeWidget *parent, int row)
{
    QTreeWidgetItem* item = parent->currentItem();
    if(item->parent() == NULL)
    {
        item->removeChild(item->child(row));
    }
}

void BCMgr::editItem(QTreeWidget *parent, const QString &strings)
{
    QTreeWidgetItem* item = parent->currentItem();
    item->setText(0,strings);
}

bool BCMgr::updateBookName(QTreeWidget *parent,const QString &bookclass, const QString &bookname,
                           const QString &newbookname)
{
    if(userdatadb->setBookName(bookclass,bookname,newbookname))
    {
        editItem(parent,newbookname);
        return true;
    }
    else
    {
        return false;
    }
}

bool BCMgr::updateBookClass(QTreeWidget *parent,const QString &bookclass, const QString &newbookclass)
{
    if(userdatadb->setBookClass(bookclass,newbookclass))
    {
        editItem(parent,newbookclass);
        return true;
    }
    else
    {
        return false;
    }

}

bool BCMgr::updateTotalNumb(const QString &bookclass, const QString &bookname, int totalNumb)
{
    return userdatadb->setTotalNumb(bookclass,bookname,totalNumb);
}

bool BCMgr::updateTotalNumb(const QString &bookpath, const int totalnumb)
{
    return userdatadb->setTotalNumb(bookpath,totalnumb);
}

bool BCMgr::updateHaveLearnedNum(const QString &bookclass,
                                 const QString &bookname,
                                 const int havelearned)
{
    return userdatadb->setHaveLearnedNum(bookclass,bookname,havelearned);
}

bool BCMgr::updateHaveLearnedNum(const QString &bookpath, const int havelearned)
{
    return userdatadb->setHaveLearnedNum(bookpath,havelearned);
}

bool BCMgr::updateLearnState(const QString &bookclass, const QString &bookname, bool learnstate)
{
    return userdatadb->setLearnState(bookclass,bookname,learnstate);
}

bool BCMgr::updateLearnState(const QString &bookpath, bool learnstate)
{
    return userdatadb->setLearnState(bookpath,learnstate);
}

bool BCMgr::existsDayRecord(const QString &bookpath, const QString &daytime)
{
    return userdatadb->existsDayRecord(bookpath,daytime);
}

bool BCMgr::addNewBookStudyRecord(const QString &bookpath, const QString &daytime,
                                  const int &learncount, const int &reviewcount)
{
    return userdatadb->addNewBookStudyRecord(bookpath,daytime,
                                             learncount,reviewcount);
}

int BCMgr::getDayLearnRecord(const QString &bookpath, const QString &daytime)
{
    return userdatadb->getDayLearnRecord(bookpath,daytime);
}

int BCMgr::getDayReviewRecord(const QString &bookpath, const QString &daytime)
{
    return userdatadb->getDayReviewRecord(bookpath,daytime);
}

bool BCMgr::updateLearnRecord(const QString &bookpath, const QString &daytime,
                              const int &learncount)
{
    return userdatadb->updateLearnRecord(bookpath,daytime,
                                         learncount);
}

bool BCMgr::updateReviewRecord(const QString &bookpath, const QString &daytime,
                               const int &reviewcount)
{
    return userdatadb->updateReviewRecord(bookpath,daytime,
                                         reviewcount);
}

void BCMgr::showBookList(QTreeWidget *parent)
{
    parent->clear();
    QStringList bookClassList;
    QStringList bookNameList;
    bookClassList = getBookClasses();
    bookNameList = getBookNames();

    for(int i = 0; i<bookClassList.size(); i++)
    {
        addChildItem(parent,bookClassList.at(i),bookNameList.at(i));
    }
}

QSqlTableModel *BCMgr::userDataDBModel(QWidget *parent)
{
    return userdatadb->userDataDBModel(parent);
}
