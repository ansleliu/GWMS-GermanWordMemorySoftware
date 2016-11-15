#include "AnsleDictSpeakMgr.h"
#include <QDebug>
AnsleDictSpeakMgr::AnsleDictSpeakMgr(ConfigFile *config, QObject *parent) :
    QObject(parent)
{
    //////////////////////////////////////////////////////////////
    //音频信号与槽连接
    ////////////////////////////////////////////////
    //eSpeakTTS
    sound = new SoundTread();
    connect(sound,SIGNAL(soundEnded()),
            this,SLOT(EmitSpeakFininshSignal()));
    ////////////////////////////////////////////////
    //GoogleTTS
    speakGoogleTTS = new AnsleDictSpeakGoogle();
    connect(speakGoogleTTS,SIGNAL(soundEnded()),
            this,SLOT(EmitSpeakFininshSignal()));
    connect(speakGoogleTTS,SIGNAL(speakError()),
            this,SLOT(changeSpeakEngineToESpeak()));
    ///////////////////////////////////////////////////////////////
    //获取发音方法配置
    speakMethod = config->getSpeakMethod();
    ///////////////////////////////////////
    //QtSpeech
    QtSpeakTTS = NULL;
    if(speakMethod == "OtherTTS")
    {
        otherTTS = config->getQtSpeakTTS();
        qDebug() << QString("第三方发音引擎为：%1").arg(otherTTS);
        ///////////////////////////////////
        //QtSpeech
        foreach(QtSpeech::VoiceName v, QtSpeech::voices())
        {
            qDebug() << "id:" << v.id;
            qDebug() << "name:" << v.name;
            if(v.name == otherTTS)
            {
                qDebug() << QString("找到匹配的发音引擎：%1").arg(v.name);

                QtSpeakTTS = new QtSpeech(v,this);
                qDebug() << QString("建立QtSpeech变量成功");

                QtSpeakTTS->setRate(config->getSpeakSpeed().toInt());
                break;
            }
        }
    }
}

AnsleDictSpeakMgr::~AnsleDictSpeakMgr()
{
    sound->deleteLater();
    sound = NULL;
    speakGoogleTTS->deleteLater();
    speakGoogleTTS = NULL;

    if(QtSpeakTTS != NULL)
    {
        QtSpeakTTS->deleteLater();
        QtSpeakTTS = NULL;
        qDebug() << QString("清除QtSpeech变量成功");
    }
}

void AnsleDictSpeakMgr::Speak(const QString &text,
                     const int &speakInterval,
                     const int &SpeakRepetitions)
{
    textSpeak = text;
    Interval = speakInterval;
    Repetitions = SpeakRepetitions;
    /////////////////////////////////////////
    //eSpeakTTS
    if(speakMethod == "eSpeakTTS")
    {
        qDebug() << "默认语音为：eSpeakTTS , 开始发音";
        sound->getSoundTime(Repetitions);
        sound->getWord(textSpeak);
        sound->getTimeDiff(Interval);
        sound->start();
    }
    //////////////////////////////////////////
    //googleTTS
    if(speakMethod == "GoogleTTS")
    {
        qDebug() << "默认语音为：GoogleTTS , 开始发音";
        speakGoogleTTS->setSoundTime(Repetitions);
        speakGoogleTTS->speakGoogleTTS(textSpeak);
    }
    /////////////////////////////////////////////////
    //OtherTTS
    if(speakMethod == "OtherTTS")
    {
        qDebug() << "默认语音为：OtherTTS , 开始发音";
        QtSpeakTTS->tell(textSpeak,this,SLOT(EmitSpeakFininshSignal()));
    }
}

void AnsleDictSpeakMgr::Stop()
{

}

void AnsleDictSpeakMgr::changeSpeakEngineToESpeak()
{
//    qDebug() << "转换发音方式为：eSpeakTTS";
//    sound->getSoundTime(Repetitions);
//    sound->getWord(textSpeak);
//    sound->getTimeDiff(Interval);
//    sound->start();
    qDebug() << "转换发音方式为：OtherTTS , 开始发音";
    QtSpeakTTS->tell(textSpeak,this,SLOT(EmitSpeakFininshSignal()));
}

void AnsleDictSpeakMgr::EmitSpeakFininshSignal()
{
    emit SpeakFininshed();
}
