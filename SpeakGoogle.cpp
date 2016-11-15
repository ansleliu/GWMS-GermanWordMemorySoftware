#include "SpeakGoogle.h"
#include <QTextCodec>
#include <QTimer>
#include "myglobal.h"
#include "pathmanage.h"
#include "QDebug"
#include <QMutex>

SpeakGoogle::SpeakGoogle(QObject *parent) :
    QObject(parent)
{
    /////////////////////////////////////////////////////////////////
    //phonon
    mediaObject = new Phonon::MediaObject(this);
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::createPath(mediaObject, audioOutput);

    connect(mediaObject,
            SIGNAL(stateChanged(Phonon::State,Phonon::State)),
            this,
            SLOT(stateChanged(Phonon::State, Phonon::State)));
    ///////////////////////////////////////////////////////////////////
    //
    manager = NULL;
    reply = NULL;
    file = NULL;
    soundPath = "";
    time = 0;
    tryTime = 0;
}

SpeakGoogle::~SpeakGoogle()
{
    mediaObject->deleteLater();
    mediaObject = NULL;
    audioOutput->deleteLater();
    audioOutput = NULL;

    if(manager != NULL)
    {
        manager->deleteLater();
        manager = NULL;
    }
    if(file != NULL)
    {

        file = NULL;
    }
    if(reply != NULL)
    {
        reply = NULL;
    }
}

void SpeakGoogle::stateChanged(Phonon::State newState,
                               Phonon::State oldstate)
{
    //////////////////////////////////////////////////////
    //
    qDebug() << QString("Phonon的状态是发生改变");
    qDebug() << QString("Phonon的旧状态是: %1").arg(oldstate);
    qDebug() << QString("Phonon的新状态是: %1").arg(oldstate);
    ////////////////////////////////////////////
    //处理状态的改变
    curState = newState;
    if(curState == Phonon::PausedState)
    {
        qDebug() << "状态改变为PausedState，开始发音";
        startSpeak();
    }
    else if(curState == Phonon::StoppedState)
    {
        qDebug() << "状态改变为StoppedState，结束信号发送";
        tryTime = 0;
        time = 0;
        emit soundEnded();
    }
    else if(curState == Phonon::ErrorState)
    {
        qDebug() << QString("状态改变为ErrorState");
        qDebug() << QString("由于发音错误，下载的音频文件将被移除");
        file->remove(soundPath);
//        qDebug() << QString("下载的音频文件将被移除后再重新尝试音频下载文件");
//        tryTime++;
//        if(tryTime <= 1)
//        {
//            qDebug() << QString("尝试下载%1").arg(tryTime);
//            speakGoogleTTS(wordText);
//        }
//        else
        {
            qDebug() << "发声错误状态无法通过尝试重新下载音频文件得以更改，发送发音错误信号给发音管理器";
            tryTime = 0;
            emit speakError();
        }
    }
}

void SpeakGoogle::startSpeak()
{
    qDebug() << QString("开始发音，设置发音源为音频文件所在的路径:%1").arg(soundPath);
    mediaObject->setCurrentSource(Phonon::MediaSource(soundPath));
    //开始发音
    googleTTS();
}

void SpeakGoogle::googleTTS()
{
    qDebug() << "开始发音，判断播放次数";
    speakGoogleRestart();
    time++;
    if(time > soundTime)
    {
        qDebug() << "播放次数达到，停止发音";       
        googleTTSStop();
    }
    else
    {
        qDebug() << "播放次数未达到，继续发音";
//        QTimer::singleShot(Interval, this, SLOT(googleTTSPlay()));
        googleTTSPlay();
    }
}

void SpeakGoogle::setSoundTime(const int &soundtime)
{
    soundTime = soundtime;
}

void SpeakGoogle::setInterval(const int &interval)
{
    Interval = interval;
}

void SpeakGoogle::speakGoogleTTS(const QString &text)
{
    if(mediaObject->currentTime() == mediaObject->totalTime())
    {
        mediaObject->seek(0);
    }
    time = 0;
    ///////////////////////////////////////////////////////////////////////////////////
    //
    wordText = text;
    qDebug() << QString("等待发音的单词为: %1").arg(wordText);
    QString strUrl = QString("http://translate.google.com/translate_tts?tl=de&q=%1")
                            .arg(wordText);
    QUrl url(strUrl);
    qDebug() << QString("设置音频文件的下载地址:%1").arg(strUrl);
    //////////////////////////////////////////////////////////////
    //    
    QString userName = Global::Conf->getCurrentUser();

    if(wordText.contains(QRegExp("[\?\\*\\:<>\\|]")))
    {
        wordText.remove(QRegExp("[\?\\*\\:<>\\|]"));
    }

    soundPath = PathManage::makePathStr(QString("/userdata/%1/GoogleTTSVoice/%2.mp3")
                                        .arg(userName)
                                        .arg(wordText));
    qDebug() << QString("设置音频文件的存放地址为:%1").arg(soundPath);

    if(file != NULL)
    {
        file->deleteLater();
        file = NULL;
    }
    file = new QFile(soundPath);

    if(file->exists())
    {
        qDebug() << "该音频文件已经存在，放弃音频文件下载，直接进行发音";
        startSpeak();
    }
    else
    {
        if(!file->open(QIODevice::WriteOnly))
        {
            qDebug() << "文件打开失败,放弃下载，放弃发音，发送文件打开失败印好转换发音方式";
            file->deleteLater();
            file = NULL;

            emit fileOpenError();
            return;
        }
        /////////////////////////////////////////////////////////////////
        //准备下载音频文件
        /////////////////////////////////////////////////////////////////
        //设置NetWork相关
        qDebug() << QString("文件已经打开，准备网络的相关配置");
        if(manager != NULL)
        {
            manager->deleteLater();
            manager = NULL;
        }
        qDebug() << QString("创建新的QNetworkAccessManager指针manager");
        manager = new QNetworkAccessManager(this);
        ///////////////////////////////////////////////
        //下载对应的语音文件
//        QEventLoop loop;
        if(reply != NULL)
        {
//            reply->deleteLater();
            reply = NULL;
        }
        qDebug() << QString("创建新的QNetworkRequestr指针reply");
        reply = manager->get(QNetworkRequest(url));
        qDebug() << QString("建立相关信号与槽的连接");
        connect(reply, SIGNAL(readyRead()),
                this, SLOT(httpReadyRead()));

        connect(reply, SIGNAL(finished()),
                this, SLOT(httpFinished()));
//        connect(reply, SIGNAL(finished()),
//                         &loop, SLOT(quit()));

        connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
                this, SLOT(haveError(QNetworkReply::NetworkError)));
//        loop.exec();
        /////////////////////////////////////////////////////////////////
        /*
        DownloadControl *control = new DownloadControl();
        int PointCount = 1;

        QEventLoop loop;
        connect(control, SIGNAL(FileDownloadFinished()),
                         &loop, SLOT(quit()));
        connect(control, SIGNAL(FileDownloadFinished()),
                         this, SLOT(startSpeak()));
        connect(control, SIGNAL(DownloadFail()),
                         &loop, SLOT(quit()));
        connect(control, SIGNAL(DownloadFail()),
                         this, SLOT(googleTTSStop()));
        ////////////////////////////////////////////////////////
        //开始下载文件
        starttime = QTime::currentTime();
        control->StartFileDownload(strUrl, PointCount,file);

        loop.exec();
        */
    }

    //////////////////////////////////////////////////////////////
    //
//    mediaObject->setCurrentSource(Phonon::MediaSource(url));
//    mediaObject->play();
//    time = 1;
}

void SpeakGoogle::speakGoogleRestart()
{
    qDebug() << "重复发音,重置播放位置为开始位置";
    if(mediaObject->currentTime() == mediaObject->totalTime())
    {
        mediaObject->seek(0);
    }
}

void SpeakGoogle::googleTTSPlay()
{
    qDebug() << QString("发音函数：play()进行音频发音");
    mediaObject->play();
}

void SpeakGoogle::googleTTSStop()
{
    qDebug() << QString("停止谷歌在线语音的音频发音");
    if(manager != NULL)
    {
        qDebug() << QString("manager不为空，对其进行清理");
        manager->deleteLater();
        manager = NULL;
    }
    //////////////////////
    if(reply != NULL)
    {
        qDebug() << QString("reply不为空，对其进行清理");
        reply->deleteLater();
        reply = NULL;
    }
/*
    if(file != NULL)
    {
        qDebug() << QString("file不为空，对其进行清理");
        file->flush();
        file->remove();
        if(file->isOpen())
        {
            file->close();
        }

        file->deleteLater();
        file = NULL;
    }
*/
    mediaObject->stop();
//    mediaObject->clear();
}

Phonon::MediaObject *SpeakGoogle::getMediaObject()
{
    return mediaObject;
}

void SpeakGoogle::httpFinished()
{
    ///////////////////////////
    //下载完成
    QMutex mutex;
    mutex.lock();
    if(reply->error() == QNetworkReply::NoError)
    {
        //////////////////////////////////////////
        //如果没有问题的话关闭相关的信号与槽
        qDebug() << QString("QNetworkReply没有问题，关闭相关的信号与槽");
        disconnect(reply, SIGNAL(readyRead()),
                this, SLOT(httpReadyRead()));

        disconnect(reply, SIGNAL(finished()),
                this, SLOT(httpFinished()));

        disconnect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
                this, SLOT(haveError(QNetworkReply::NetworkError)));
        ///////////////////////////////
        //信号与槽关闭后进行最后清理工作
        file->flush();
        file->close();

        reply->deleteLater();
        reply = NULL;

        file->deleteLater();
        file = NULL;

        mutex.unlock();

        qDebug() << "音频文件下载完成开始进行发音";
        //////////////////////////////////////////////////////////////
        //发音
       startSpeak();
    }
    else
    {
        qDebug() << "网络有错误，错误为："<< reply->error();
    }
}

void SpeakGoogle::httpReadyRead()
{
    if ( !file )
    {
        qDebug() << "文件指针丢失";
        emit fileOpenError();
        return;
    }
    QMutex mutex;
    mutex.lock();
    qDebug() << QString("读取HTTP的值，写入文本文档当中");
    QByteArray buffer = reply->readAll();
    file->write(buffer);
    mutex.unlock();
}

void SpeakGoogle::haveError(QNetworkReply::NetworkError error)
{
    //////////////////////////////////////////
    //网络有问题关闭相关的信号与槽
    qDebug() << "网络错误，错误代码为："<< error;
    qDebug() << QString("网络有错误，信号与槽的连接解除，发送网络错误信号");

    disconnect(reply, SIGNAL(readyRead()),
            this, SLOT(httpReadyRead()));

    disconnect(reply, SIGNAL(finished()),
            this, SLOT(httpFinished()));

    disconnect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(haveError(QNetworkReply::NetworkError)));

    googleTTSStop();
    emit NetWorkUnavailable();
}

void SpeakGoogle::NetWorkIsBad()
{
    googleTTSStop();
}
