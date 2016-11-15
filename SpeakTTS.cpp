#include "SpeakTTS.h"
#include "QDebug"

SpeakTTS::SpeakTTS(QObject *parent) :
    QObject(parent)
{

}

void SpeakTTS::initESpeaktts()
{
    espeak_Initialize(AUDIO_OUTPUT_SYNCH_PLAYBACK, 0, "./eSpeak/", 0);
    //espeak_SetSynthCallback(SynthCallback); // 设置回调函数
}

void SpeakTTS::setSpeakSpeed(const int &speed)
{
    //////////////////////////////////////////////////////////////////////
    //espeakRATE: speaking speed in word per minute.
    //Values 80 to 450.
    espeak_SetParameter(espeakRATE,speed,0);
}

void SpeakTTS::setSpeakVolume(const int &volume)
{
    /////////////////////////////////////////////////////////////////////
    //espeakVOLUME:  volume in range 0-200 or more.
    //0=silence, 100=normal full volume,
    //greater values may produce amplitude compression or distortion
    espeak_SetParameter(espeakVOLUME,volume,0);
}

void SpeakTTS::setSpeakPitch(const int &pitch, const int &range)
{
    /////////////////////////////////////////////////////////////////////
    //espeakPITCH:   base pitch, range 0-100.  50=normal
    //espeakRANGE:   pitch range, range 0-100. 0-monotone, 50=normal
    espeak_SetParameter(espeakPITCH,pitch,0);
    espeak_SetParameter(espeakRANGE,range,0);
}

void SpeakTTS::setSpeakWordGap(const int &wordgap)
{
    ///////////////////////////////////////////////////////////////////////////
    //espeakWORDGAP:  pause between words, units of 10mS (at the default speed)
    espeak_SetParameter(espeakWORDGAP,wordgap,0);
}

void SpeakTTS::setSpeakLanguage(const char *language)
{
    espeak_SetVoiceByName(language);
}

void SpeakTTS::speakTTS(const QString &text)
{
    QByteArray byteArray = text.toLatin1();
    const char *word = byteArray.constData();

    espeak_Synth(word, 0, 0, POS_CHARACTER, 0, espeakCHARS_UTF8, NULL ,NULL);
    espeak_Synchronize();
    espeak_Terminate();
}

bool SpeakTTS::isSpeakTTSPlaying()
{
    return espeak_IsPlaying();
}

void SpeakTTS::stopSpeakTTS()
{
    if(espeak_IsPlaying())
    {
        espeak_Cancel();
        qDebug() << QString("停止eSpeakTTS发音成功");
    }
}

