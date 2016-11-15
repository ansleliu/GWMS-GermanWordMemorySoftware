#ifndef SPEAKREAL_H
#define SPEAKREAL_H

#include <QObject>
#include "phonon"
#include "QFile"
class SpeakReal : public QObject
{
    Q_OBJECT
public:
    explicit SpeakReal(QObject *parent = 0,const QString &bookname = "");
    ~SpeakReal();
signals:
    void soundEnded();
    void speakError();
    void UncontionsFile();

public slots:
    void stateChanged(Phonon::State newState,Phonon::State oldstate);
    void realSpeak();
    void setSoundTime(const int &soundtime);
    void setInterval(const int &interval);

    void realPersonSpeak(const QString &text);
    void realSpeakRestart();
    void realSpeakPlay();
    void realSpeakStop();

    Phonon::MediaObject *getMediaObject();

private:
    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;
    Phonon::State curState;

    QString wordText;
    QString bookName;
    QString currUser;
    QString soundPath;
    int soundTime;
    int Interval;
    int time;
    
};

#endif // SPEAKREAL_H
