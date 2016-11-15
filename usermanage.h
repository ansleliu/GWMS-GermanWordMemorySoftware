#ifndef USERMANAGE_H
#define USERMANAGE_H
#include "mysqlite.h"

class UserManage : public MySQLite
{
public:
    UserManage(const QString &dbpath, const QString &connName);
    virtual ~UserManage();

public:
    bool addUser(QMap<QString, QVariant> &ui);//添加用户
    bool exists(const QString &userName); // 判断用户是否存在

    bool getUserInfo(QMap<QString, QVariant> &ui, const QString &userName); // 获取用户相关的信息
    QVariant getUserInfo(const QString &itemName,const QString &userName); // 获取用户相关的信息

    bool verifyPsw(const QString &userName,const QString &psw); // 校验密码

    bool updateLoginTime(const QString &userName);	// 更新登录时间
    bool updateLoginCount(const QString &userName); //更新登录次数

    int getLoginCount(const QString &userName); //获取登录次数

    bool updateSavePsw(const QString &userName, bool bSave = false); // 更新保存状态密码
    bool updatePassword(const QString &userName, const QString &password); // 更新密码

    bool removeUser(const QString &userName);//删除用户

    QStringList getUserList();	// 返回用户列表,已经按最后登录时间排序好
    QStringList getUserListOrderById();	// 返回用户列表, 按id降序排号

protected:
    bool createTable();	// 创建表
};

#endif // USERMANAGE_H
