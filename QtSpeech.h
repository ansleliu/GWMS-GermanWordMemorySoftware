#ifndef SPEECH_H
#define SPEECH_H

#include <QObject>

//namespace QtSpeech_v1 { // API v1.0

class QtSpeech : public QObject
{
    Q_OBJECT
public:
    // exceptions
    struct Error { QString msg; Error(QString s):msg(s) {} };
    struct InitError : Error { InitError(QString s):Error(s) {} };
    struct LogicError : Error { LogicError(QString s):Error(s) {} };
    struct CloseError : Error { CloseError(QString s):Error(s) {} };

    // types
    struct VoiceName { QString id; QString name; };
    typedef QList<VoiceName> VoiceNames;

    // api
    QtSpeech(QObject * parent);
    QtSpeech(VoiceName n = VoiceName(), QObject * parent =0L);
    virtual ~QtSpeech();

    const VoiceName & name() const; //!< Name of current voice
    static VoiceNames voices();     //!< List of available voices in system

    void say(QString) const;                                    //!< Say something, synchronous
    void tell(QString) const;                                   //!< Tell something, asynchronous
    void tell(QString, QObject * obj, const char * slot) const; //!< Tell something, invoke slot at end
    /*******************/
    void pause(void) const;
    void resume(void) const;
    void stop(void) const;
    void setRate(int hpos) const;

    /******************/

signals:
    void finished();

protected:
    virtual void timerEvent(QTimerEvent *);

private:
    class Private;
    Private * d;
};

//}

#endif // SPEECH_H
