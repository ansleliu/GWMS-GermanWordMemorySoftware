#include "SpeakMgr.h"
#include <QDebug>
#include "QTimer"

SpeakMgr::SpeakMgr(QObject *parent, const QString &bookname) :
    QObject(parent)
{
    sound = NULL;
    QtSpeechTTS = NULL;
    speakGoogleTTS = NULL;
    speakRealPerson = NULL;
    ////////////////////////////////////////////////
    textSpeak = "";
    bookName = bookname;
    speakTime = 1;
    Repetitions = 0;
    qDebug() << QString("发音控制器被告知的词库名为: %1").arg(bookName);
    ////////////////////////////////////////////////
    //音频信号与槽连接
    ////////////////////////////////////////////////
    //eSpeakTTS
    sound = new SoundTread();
    connect(sound,SIGNAL(soundEnded()),
            this,SLOT(EmitSpeakFininshSignal()));

    ////////////////////////////////////////////////
    //
    localTTS = bcMgr->userConf->getSpeakLocalTTS();
    qDebug() << QString("第三方发音引擎为：%1").arg(localTTS);
    ////////////////////////////////////////////////
    //GoogleTTS
    speakGoogleTTS = new SpeakGoogle();
    connect(speakGoogleTTS,SIGNAL(soundEnded()),
            this,SLOT(EmitSpeakFininshSignal()));
    connect(speakGoogleTTS,SIGNAL(NetWorkUnavailable()),
            this,SLOT(changeSpeakEngineToESpeak()));
    connect(speakGoogleTTS,SIGNAL(speakError()),
            this,SLOT(changeSpeakEngineToESpeak()));
    connect(speakGoogleTTS,SIGNAL(fileOpenError()),
            this,SLOT(changeSpeakEngineToESpeak()));
    ////////////////////////////////////////////////
    //RealPerson
    speakRealPerson = new SpeakReal(0,bookName);
    connect(speakRealPerson,SIGNAL(soundEnded()),
            this,SLOT(EmitSpeakFininshSignal()));
    connect(speakRealPerson,SIGNAL(speakError()),
            this,SLOT(changeSpeakEngineToESpeak()));
    connect(speakRealPerson,SIGNAL(UncontionsFile()),
            this,SLOT(changeSpeakEngineToESpeak()));
}

SpeakMgr::~SpeakMgr()
{
    if(sound != NULL)
    {
        qDebug() << "~SpeakMgr清除sound";
        sound->deleteLater();
        sound = NULL;
    }

    if(QtSpeechTTS != NULL)
    {
        QtSpeechTTS->deleteLater();
        QtSpeechTTS = NULL;
        qDebug() << QString("清除QtSpeech变量成功");
    }

    if(speakRealPerson != NULL)
    {
        qDebug() << "~SpeakMgr清除speakRealPerson";
        speakRealPerson->deleteLater();
        speakRealPerson = NULL;
    }

    if(speakGoogleTTS != NULL)
    {
        qDebug() << "~SpeakMgr清除speakGoogleTTS";
        speakGoogleTTS->deleteLater();
        speakGoogleTTS = NULL;
    }
}

void SpeakMgr::Speak(const QString &text,
                     const int &speakInterval,
                     const int &SpeakRepetitions)
{
    ///////////////////////////////////////////////////////////////
    //获取发音方法配置
    speakMethod = bcMgr->userConf->getSpeakMethod();
    qDebug() << QString("当前配置文件所设定的默认发音方式为: %1").arg(speakMethod);
    currSpeakMethod = "";
    textSpeak = "";
    speakTime = 1;
    /////////////////////////////////////
    //
    textSpeak = text;
    Interval = speakInterval;
    Repetitions = SpeakRepetitions;
    /////////////////////////////////////////
    //LocalTTS
    if(speakMethod == "LocalTTS")
    {
        qDebug() << "默认语音为：LocalTTS , 开始发音";
        currSpeakMethod = "LocalTTS";
        if(localTTS == QString("eSpeakTTS"))
        {
            qDebug() << QString("默认语音为：%1, 开始发音").arg(localTTS);
            qDebug() << QString("发音次数为：%1").arg(Repetitions);
            sound->getSoundTime(Repetitions);
            sound->getWord(textSpeak);
            sound->getTimeDiff(Interval);
            sound->start();
        }
        else
        {
            QtSpeechTell();
        }
    }
    //////////////////////////////////////////
    //realSpeak&eSpeakTTS
    if(speakMethod == "realSpeak&eSpeakTTS")
    {
        qDebug() << "默认语音为：realSpeak&eSpeakTTS , 开始发音";
        qDebug() << QString("发音次数为：%1").arg(Repetitions);
        currSpeakMethod = "realSpeak&eSpeakTTS";
        speakRealPerson->setSoundTime(Repetitions);
        speakRealPerson->setInterval(Interval);
        speakRealPerson->realPersonSpeak(textSpeak);
    }
    //////////////////////////////////////////
    //googleTTS
    if(speakMethod == "googleTTS")
    {
        qDebug() << "默认语音为：googleTTS , 开始发音";
        qDebug() << QString("发音次数为：%1").arg(Repetitions);
        currSpeakMethod = "googleTTS";
        speakGoogleTTS->setSoundTime(Repetitions);
        speakGoogleTTS->setInterval(Interval);
        speakGoogleTTS->speakGoogleTTS(textSpeak);
    }
}

void SpeakMgr::Stop()
{
    /////////////////////////////////////////
    //LocalTTS
    if(speakMethod == "LocalTTS")
    {
        qDebug() << "默认语音为：LocaleSpeakTTS";
        if(localTTS == QString("eSpeakTTS"))
        {
            qDebug() << QString("停止eSpeakTTS发音");
            sound->stop();
            qDebug() << QString("已经停止eSpeakTTS发音");
        }
        else
        {
            qDebug() << QString("停止QtSpeechTTS发音");
            QtSpeechTTS->stop();
            qDebug() << QString("已经停止QtSpeechTTS发音");
        }
    }
    //////////////////////////////////////////
    //realSpeak&eSpeakTTS
    if(speakMethod == "realSpeak&eSpeakTTS")
    {
        qDebug() << "默认语音为：realSpeak&eSpeakTTS";
        qDebug() << QString("停止realSpeak&eSpeakTTS发音");
        speakRealPerson->realSpeakStop();
        qDebug() << QString("已经停止realSpeak&eSpeakTTS发音");
    }
    //////////////////////////////////////////
    //googleTTS
    if(speakMethod == "googleTTS")
    {
        qDebug() << "默认语音为：googleTTS";
        qDebug() << QString("停止googleTTS发音");
        speakGoogleTTS->googleTTSStop();
        qDebug() << QString("已经停止googleTTS发音");
    }
}

void SpeakMgr::QtSpeechTell()
{
    if(QtSpeechTTS != NULL)
    {
        QtSpeechTTS->deleteLater();
        QtSpeechTTS = NULL;
    }
    ////////////////////////////////////////////////
    //QtSpeechTTS
    foreach(QtSpeech::VoiceName v, QtSpeech::voices())
    {
        qDebug() << "id:" << v.id;
        qDebug() << "name:" << v.name;
        if(v.name == localTTS)
        {
            qDebug() << QString("找到匹配的发音引擎：%1").arg(v.name);

            QtSpeechTTS = new QtSpeech(v,this);
            qDebug() << QString("建立QtSpeech变量成功");

            QtSpeechTTS->setRate(bcMgr->userConf->getSpeakRate().toInt());
            break;
        }
    }
    qDebug() << QString("默认语音为：%1, 开始发音").arg(localTTS);
    qDebug() << QString("发音次数为：%1").arg(Repetitions);
    QtSpeechTTS->tell(textSpeak,this,SLOT(judgeSpeakTime()));
}

void SpeakMgr::changeSpeakEngineToGoogle()
{
    qDebug() << "转换发音方式为：googleTTS";
    currSpeakMethod = "googleTTS";
    speakGoogleTTS->setSoundTime(Repetitions);
    speakGoogleTTS->speakGoogleTTS(textSpeak);
}

void SpeakMgr::changeSpeakEngineToESpeak()
{
    qDebug() << QString("转换发音方式为：LocalTTS");
    /////////////////////////////////////////
    //LocalTTS
    currSpeakMethod = "LocalTTS";
    if(localTTS == QString("eSpeakTTS"))
    {
        qDebug() << QString("默认二级发音引擎为：%1, 开始发音").arg(localTTS);
        sound->getSoundTime(Repetitions);
        sound->getWord(textSpeak);
        sound->getTimeDiff(Interval);
        sound->start();
    }
    else
    {
        QtSpeechTell();
    }
}

void SpeakMgr::judgeSpeakTime()
{

    if(QtSpeechTTS != NULL)
    {
        QtSpeechTTS->deleteLater();
        QtSpeechTTS = NULL;
    }

    speakTime++;
    qDebug() << QString("播放次数为：%1").arg(speakTime);
    qDebug() << QString("发音次数为：%1").arg(Repetitions);
    if(speakTime <= Repetitions)
    {
        ////////////////////////////////
        //发音次数未到
        qDebug() << QString("%1发音次数未到，继续发音").arg(localTTS);
        QTimer::singleShot(Interval, this, SLOT(QtSpeechTell()));
    }
    else
    {
        EmitSpeakFininshSignal();
    }
}
/*
void SpeakMgr::setSpeakInterval()
{

}

void SpeakMgr::setSpeakRepetitions()
{

}
*/

void SpeakMgr::EmitSpeakFininshSignal()
{
//    speakTime++;
//    qDebug() << QString("播放次数为：%1").arg(speakTime);
//    qDebug() << QString("发音次数为：%1").arg(Repetitions);
//    if(currSpeakMethod == "LocalTTS" &&
//            localTTS != QString("eSpeakTTS") &&
//            speakTime <= Repetitions)
//    {
        ////////////////////////////////
        //发音次数未到
//        qDebug() << QString("%1发音次数未到，继续发音").arg(localTTS);
//        QtSpeechTell();
//    }
//    else
    {
        qDebug() << QString("SpeakMgr发音结束，发射发音结束信号……");
        emit SpeakFininshed();
    }
}
