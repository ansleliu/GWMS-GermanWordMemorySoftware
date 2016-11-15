#ifndef ANSLEDICTSPEAKGOOGLE_H
#define ANSLEDICTSPEAKGOOGLE_H

#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include "../DownloadControl/DownloadControl.h"
#include <phonon>
#include <QUrl>
#include <QFile>
#include <QTime>

class AnsleDictSpeakGoogle : public QObject
{
    Q_OBJECT
public:
    explicit AnsleDictSpeakGoogle(QObject *parent = 0);
    ~AnsleDictSpeakGoogle();
    
signals:
    void soundEnded();
    void speakError();

public slots:
    void NetWorkIsBad();

    void stateChanged(Phonon::State newState,
                      Phonon::State oldstate);
    void startSpeak();
    void googleTTS();
    void setSoundTime(const int &soundtime);

    void speakGoogleTTS(const QString &text);
    void speakGoogleRestart();
    void googleTTSPlay();
    void googleTTSStop();

    Phonon::MediaObject *getMediaObject();

private:
    QUrl myurl;   //´æ´¢ÍøÂçµØÖ·

    QTime starttime;

    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;
    Phonon::State curState;

    int soundTime;
    int time;
    QString wordText;
};

#endif // ANSLEDICTSPEAKGOOGLE_H
