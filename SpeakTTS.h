#ifndef SPEAKTTS_H
#define SPEAKTTS_H

#include <QObject>
#include <QByteArray>
//由于是C版的dll文件，在C++中引入其头文件要加extern "C" {}
extern "C"
{
    #include "./eSpeak/speak_lib.h"
}

class SpeakTTS : public QObject
{
    Q_OBJECT
public:
    explicit SpeakTTS(QObject *parent = 0);
    void initESpeaktts();
    void setSpeakSpeed(const int &speed);
    void setSpeakVolume(const int &volume);
    void setSpeakPitch(const int &pitch,const int &range);
    void setSpeakWordGap(const int &wordgap);
    void setSpeakLanguage(const char *language);

    void speakTTS(const QString &text);

    bool isSpeakTTSPlaying();
    void stopSpeakTTS();
    
signals:
    
public slots:
    
};

#endif // SPEAKTTS_H
