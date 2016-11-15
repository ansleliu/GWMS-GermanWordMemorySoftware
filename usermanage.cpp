#include "usermanage.h"
#include "QMessageBox"
#include "QDateTime"
UserManage::UserManage(const QString &dbpath, const QString &connName)
    : MySQLite(dbpath, connName)
{
    if (!isTableExist("UserInfo"))	// 新建的数据库,创建表
    {
        createTable();
        QMap<QString, QVariant> ui;
        ui["userName"] = "default";
        ui["password"] = "";
        addUser(ui);
    }
}

UserManage::~UserManage()
{
}
// 创建用户信息表
bool UserManage::createTable()
{
    db->transaction();
//    QSqlQuery query(*db);

    exec("CREATE TABLE [UserInfo] (\
               [id] INTEGER NOT NULL ON CONFLICT FAIL PRIMARY KEY AUTOINCREMENT, \
               [userName] CHAR(32) NOT NULL ON CONFLICT FAIL, \
               [password] CHAR(32) NOT NULL ON CONFLICT FAIL, \
               [savePsw] BOOL NOT NULL ON CONFLICT FAIL DEFAULT 0, \
               [createTime] DATETIME NOT NULL ON CONFLICT FAIL, \
               [lastLoginTime] DATETIME NOT NULL ON CONFLICT FAIL,\
               [LoginCount] INTEGER NOT NULL ON CONFLICT FAIL);");

    db->commit();

    return true;
}

bool UserManage::addUser(QMap<QString, QVariant> &ui)
{
    QString userName = ui["userName"].toString();
    QString password = ui["password"].toString();

    if (!exists(userName))
    {
        QString strCurrentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        QString sql = QString("insert into UserInfo(userName, password, savePsw, createTime, lastLoginTime, LoginCount) values('%1', '%2', %3, '%4', '%5', '%6')")
            .arg(userName)
            .arg(password)
            .arg(0)
            .arg(strCurrentTime)
            .arg(strCurrentTime)
            .arg(0);

        return exec(sql);
    }
    else
    {
        return false;
    }
}

bool UserManage::exists(const QString &userName)
{
    QSqlQuery query(QString("select id from UserInfo where userName = '%1'").arg(userName), *db);
    return query.next();
}
// 获取用户相关的信息
bool UserManage::getUserInfo(QMap<QString, QVariant> &ui, const QString &userName)
{
    ui.clear();
    if (exists(userName))
    {
        QSqlQuery query(QString("select * from UserInfo where userName = '%1'").arg(userName), *db);
        query.next();

        for (int i = 0; i < query.record().count(); i++)
        {
            ui[query.record().fieldName(i)] = query.record().value(i).toString();
        }
        return true;
    }
    else
    {
        QMessageBox::warning(NULL, QObject::tr("提示错误"),
                                     QObject::tr("[%1]用户不存在").arg(userName));
        return false;
    }
}
 // 获取用户相关的信息
QVariant UserManage::getUserInfo(const QString &itemName, const QString &userName)
{
    if (exists(userName))
    {
        QSqlQuery query(QString("select * from UserInfo where userName = '%1'").arg(userName), *db);
        query.next();
        return query.record().value(itemName);
    }
    else
    {
        return NULL;
    }
}
// 校验密码
bool UserManage::verifyPsw(const QString &userName, const QString &psw)
{
    QMap<QString, QVariant> ui;

    if (getUserInfo(ui, userName))
    {
        if (ui["password"]== psw)
        {
            return true;
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

bool UserManage::updateLoginTime(const QString &userName)
{
    QString sql = QString("update UserInfo set lastLoginTime = '%1' where userName = '%2'")
            .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"))
            .arg(userName);
    return exec(sql);
}

bool UserManage::updateLoginCount(const QString &userName)
{
    QString sql = QString("update UserInfo set LoginCount = LoginCount +1 where userName = '%1'")
            .arg(userName);
    return exec(sql);
}

int UserManage::getLoginCount(const QString &userName)
{
    QSqlQuery query(QString("select LoginCount from UserInfo where userName = '%1'").arg(userName), *db);
    query.next();
    return query.record().value(0).toInt();
}

bool UserManage::updateSavePsw(const QString &userName, bool bSave)
{
    QString sql = QString("update UserInfo set savePsw = '%1' where userName = '%2'")
            .arg(QString::number(bSave))
            .arg(userName);
    return exec(sql);
}

bool UserManage::updatePassword(const QString &userName, const QString &password)
{
    QString sql = QString("update UserInfo set password = '%1' where userName = '%2'")
            .arg(password)
            .arg(userName);
    return exec(sql);
}

bool UserManage::removeUser(const QString &userName)
{
    if(exists(userName))
    {
        QString sql = QString("delete from UserInfo where userName = '%1'")
            .arg(userName);
        return exec(sql);
    }
    else
    {
        return false;
    }
}

QStringList UserManage::getUserList()
{
    QStringList orderResult;
    QSqlQuery query("select userName from UserInfo order by lastLoginTime desc", *db);
    while (query.next())
    {
        orderResult << query.record().value("userName").toString();
    }

    return orderResult;
}

QStringList UserManage::getUserListOrderById()
{
    QStringList orderResult;
    QSqlQuery query("select userName from UserInfo order by id desc", *db);
    while (query.next())
    {
        orderResult << query.record().value("userName").toString();
    }

    return orderResult;
}
