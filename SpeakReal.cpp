#include "SpeakReal.h"
#include "pathmanage.h"
#include "myglobal.h"
#include "QTimer"

SpeakReal::SpeakReal(QObject *parent, const QString &bookname) :
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
    ////////////////////////////////////////////////////////////////
    //
    currUser = Global::Conf->getCurrentUser();
    qDebug() << QString("真人语音所需的当前用户是: %1").arg(currUser);
    bookName = bookname;
    qDebug() << QString("真人语音所需的当前词库是: %1").arg(bookName);

    wordText = "";
    soundPath = "";
    soundTime = 0;
}

SpeakReal::~SpeakReal()
{

    mediaObject->deleteLater();
    mediaObject = NULL;
    audioOutput->deleteLater();
    audioOutput = NULL;
}

void SpeakReal::stateChanged(Phonon::State newState, Phonon::State oldstate)
{
    Q_UNUSED(oldstate);
    curState = newState;
    if(curState == Phonon::PausedState)
    {
        qDebug() << "状态改变为PausedState，开始启动发音函数realSpeak()";
        realSpeak();
    }
    else if(curState == Phonon::StoppedState)
    {
        qDebug() << "状态改变为StoppedState，发送结束信号";
        emit soundEnded();
    }
    else if(curState == Phonon::ErrorState)
    {
        qDebug() << "状态改变为ErrorState，发送发音错误信号";
        emit speakError();
    }
}

void SpeakReal::realSpeak()
{
    qDebug() << QString("realSpeak()函数启动，初始化发音位子和发音源……");
    mediaObject->setCurrentSource(Phonon::MediaSource(soundPath));
    realSpeakRestart();
    time++;
    if(time == 1)
    {
        realSpeakPlay();
    }
    else if(time > 1 && time <= soundTime)
    {
        qDebug() << QString("realSpeak()函数判断发音次数是否达到……");
        qDebug() << QString("播放次数%1未达到%2，继续播放").arg(time).arg(soundTime);
        qDebug() << QString("启动发音函数realSpeakPlay()……");

//        QTimer::singleShot(Interval, this, SLOT(realSpeakPlay()));
        realSpeakPlay();
    }
    else
    {
        qDebug() << QString("播放次数达到，停止播放");
        realSpeakStop();
    }
}

void SpeakReal::setSoundTime(const int &soundtime)
{
    soundTime = soundtime;
}

void SpeakReal::setInterval(const int &interval)
{
     Interval = interval;
}

void SpeakReal::realPersonSpeak(const QString &text)
{
    qDebug() << QString("启动发音函数真人发音引擎……");
    wordText = "";
    if(mediaObject->currentTime() == mediaObject->totalTime())
    {
        mediaObject->seek(0);
    }
    ///////////////////////////////////////////////////////
    //
    wordText = text;
    if(wordText.contains(QRegExp("[\?\\*\\:<>\\|]")))
    {
        wordText.remove(QRegExp("[\?\\*\\:<>\\|]"));
    }

    soundPath = PathManage::makePathStr(QString("/userdata/%1/RealSpeak/%2/%3.mp3")
                                        .arg(currUser)
                                        .arg(bookName)
                                        .arg(wordText));
    qDebug() << QString("真人语音的音频文件为: %1").arg(soundPath);

    time = 0;
    qDebug() << "寻找真人发音文件……";
    QFile mp3File(soundPath);
    if(mp3File.exists())
    {

        qDebug() << "真人语音在对应词库音频库中存在,将进行播放";
        realSpeak();
    }
    else
    {
        qDebug() << "真人语音在对应词库音频库中不存在,切换寻找路径为根目录音频库";
        soundPath = PathManage::makePathStr(QString("/Sound/%1.mp3")
                                            .arg(wordText));
        qDebug() << QString("真人语音的音频文件为: %1").arg(soundPath);
        time = 0;
        QFile mp3FileSound(soundPath);
        if(mp3FileSound.exists())
        {
            qDebug() << "真人语音根目录音频库中存在,将启动realSpeak()进行播放";
            realSpeak();
        }
        else
        {
            qDebug() << "真人语音不存在,发送信号请求转换发音方式";
            wordText = "";
            soundPath = "";
            soundTime = 0;
            time = 0;
            emit UncontionsFile();
        }
    }
}

void SpeakReal::realSpeakRestart()
{
    if(mediaObject->currentTime() == mediaObject->totalTime())
    {
        mediaObject->seek(0);
    }
}

void SpeakReal::realSpeakPlay()
{
    qDebug() << "realSpeakPlay():真人语音存在,开始播放真人语音";
    mediaObject->play();
}

void SpeakReal::realSpeakStop()
{
    qDebug() << "停止真人语音播放";
    mediaObject->stop();
}

Phonon::MediaObject *SpeakReal::getMediaObject()
{
    return mediaObject;
}
