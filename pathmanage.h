#ifndef PATHMANAGE_H
#define PATHMANAGE_H
#include <algorithm>
#include <QString>
#include <QDir>
#include <QCoreApplication>
#include <QIODevice>
#include <QByteArray>

class PathManage
{
public:
    PathManage();
    ~PathManage();

public:
    static QString makePathStr(const QString &fileName);	// 生成一个路径 相对于exe所在路径,未在后面加了"\"
    static void mkPath(const QString &strPath);	// 建立目录,如果目录不存在
    static void createRelExeDir(const QString &path);
    static QString makeRelativeFilePath(const QString &fileName);
    static bool saveToDisk(const QString &filename, QIODevice *data);// 保存数据到文件
    static bool saveToDisk(const QString &filename, QByteArray &data);
};

#endif // PATHMANAGE_H
