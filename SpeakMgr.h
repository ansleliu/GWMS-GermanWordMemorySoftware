#ifndef SPEAKMGR_H
#define SPEAKMGR_H

#include <QObject>
#include "SpeakGoogle.h"
#include "SpeakReal.h"
#include "Thread/thread.h"
#include "QtSpeech.h"
#include "bcmgr.h"
#include "myglobal.h"
////////////////////////////////////////////////
//
class SpeakMgr : public QObject
{
    Q_OBJECT
public:
    explicit SpeakMgr(QObject *parent = 0,const QString &bookname = "");
    ~SpeakMgr();

public:
//    void setSpeakInterval();
//    void setSpeakRepetitions();

    void Speak(const QString &text,
               const int &speakInterval,
               const int &SpeakRepetitions);
    void Stop();

private slots:
    void changeSpeakEngineToGoogle();
    void changeSpeakEngineToESpeak();

    void QtSpeechTell();
    void judgeSpeakTime();

signals:
    void SpeakFininshed();

public slots:
    void EmitSpeakFininshSignal();

private:
    SoundTread *sound;//eSpeakTTS
    QtSpeech *QtSpeechTTS;//QtSpeechTTS
    SpeakGoogle *speakGoogleTTS;//GoogleTTS
    SpeakReal *speakRealPerson;//RealSpeak

    QString speakMethod;//∑¢“Ù∑Ω∑®
    QString localTTS;
    QString currSpeakMethod;

    QString textSpeak;
    QString bookName;

    int Interval;
    int Repetitions;
    int speakTime;
};

#endif // SPEAKMGR_H
