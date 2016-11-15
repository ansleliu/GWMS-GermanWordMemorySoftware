#ifndef ANSLEDICTSPEAKMGR_H
#define ANSLEDICTSPEAKMGR_H

#include <QObject>
#include "AnsleDictSpeakGoogle.h"
#include "../Thread/thread.h"
#include "../QtSpeech.h"
#include "../AnsleDictConfigFile.h"

class AnsleDictSpeakMgr : public QObject
{
    Q_OBJECT
public:
    explicit AnsleDictSpeakMgr(ConfigFile *config, QObject *parent = 0);
    ~AnsleDictSpeakMgr();

public:
    void Speak(const QString &text,
               const int &speakInterval,
               const int &SpeakRepetitions);
    void Stop();

private slots:
    void changeSpeakEngineToESpeak();

signals:
    void SpeakFininshed();

public slots:
    void EmitSpeakFininshSignal();

private:
    SoundTread *sound;//eSpeakTTS
    AnsleDictSpeakGoogle *speakGoogleTTS;//GoogleTTS
    QtSpeech *QtSpeakTTS;//QtSpeakTTS

    QString speakMethod;//∑¢“Ù∑Ω∑®
    QString speakRate;
    QString otherTTS;

    QString textSpeak;
    int Interval;
    int Repetitions;
};

#endif // ANSLEDICTSPEAKMGR_H
