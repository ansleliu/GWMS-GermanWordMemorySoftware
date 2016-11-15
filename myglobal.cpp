#include "myglobal.h"
#include "pathmanage.h"
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>

MyConfig *Global::Conf = NULL;
UserManage *Global::UserMag = NULL;

Global::Global(QObject *parent)
    :QObject(parent)
{
    /////////////////////////////////
    //

}

Global::~Global()
{

}

bool Global::init()
{
/*
    QLibrary eSpeakLib("./eSpeak/espeak_lib.dll");//声明所用到的dll文件
    if (!eSpeakLib.load())              //判断是否正确加载
    {
        QMessageBox::information(NULL,QString("错误"),QString("eSpeak链接库导入错误!"));
    }
*/
    ////////////////////////////////////
    //声音文件路径
    PathManage::createRelExeDir("/Sound");
    //设置用户数据路径
    PathManage::createRelExeDir("/userdata/");
    Conf = new MyConfig(PathManage::makePathStr("/Config.ini"));

    QString userdbPath = PathManage::makePathStr("/userdata/user.db");
    UserMag = new UserManage(userdbPath,"UserDB");

    return true;
}

bool Global::uninit()
{
    qDebug() << QString("主程序关闭清除全局指针变量");
    delete Conf;
    Conf = NULL;
    delete UserMag;
    UserMag = NULL;
    qDebug() << QString("主程序关闭清除全局指针变量成功");
    return true;
}

void Global::sleep(int secs)
{
    QTime dieTime = QTime::currentTime().addMSecs(secs);

    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 20);
}
