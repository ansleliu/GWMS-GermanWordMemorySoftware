#ifndef MYCONFIG_H
#define MYCONFIG_H
#include "QSettings"
#include "QStringList"
#include "pathmanage.h"

typedef QList< QMap<QString, QVariant> > LISTMAPINFO;
class MyConfig
{
public:
    MyConfig(const QString &path);
    ~MyConfig();

public:
    void initUserConfig()
    {
        LISTMAPINFO LMI;
        QMap<QString, QVariant> learnWordConfig;
        learnWordConfig["LearnMethod"] = "出词忆义";
        learnWordConfig["OutWordMethod"] = "Random";
        learnWordConfig["ReviewWordMethod"] = "Random";
        LMI << learnWordConfig;

        QMap<QString, QVariant> wordSoundConfig;
        wordSoundConfig["OpenSound"] = true;
        wordSoundConfig["SoundTime"] = "1";
        wordSoundConfig["Interval"] = "500";
        LMI << wordSoundConfig;

        QMap<QString, QVariant> wordStateConfig;
        wordStateConfig["RememShortcut"] = "R";
        wordStateConfig["NotSureShortcut"] = "E";
        wordStateConfig["ForgetShortcut"] = "W";
        LMI << wordStateConfig;

        QMap<QString, QVariant> wordLearnStateConfig;
        wordLearnStateConfig["RightShortcut"] = "R";
        wordLearnStateConfig["WrongShortcut"] = "W";
        LMI << wordLearnStateConfig;

        QMap<QString, QVariant> otherConfig;
        otherConfig["EditWortShortcut"] = "F";
        otherConfig["SoundShortcut"] = "S";
        otherConfig["NextShortcut"] = "D";
        otherConfig["ConfigShortcut"] = "C";
        LMI << otherConfig;

        setLMI("ConfigList", LMI);

        /////////////////////////////////////////////
        //设置语音选项
        LISTMAPINFO LMI_SpeakTTS;
        QMap<QString, QVariant> SpeakTTS;
        SpeakTTS["SpeakSpeed"] = "180";
        SpeakTTS["SpeakRate"] = "0";
        SpeakTTS["SpeakVolume"] = "100";
        SpeakTTS["SpeakPitch"] = "50";
        SpeakTTS["SpeakPitchRange"] = "50";
        SpeakTTS["SpeakWordGap"] = "10";
        SpeakTTS["SpeakLanguage"] = "de";
        SpeakTTS["SpeakMethod"] = "LocalTTS";
        SpeakTTS["SpeakLocalTTS"] = "eSpeakTTS";


        LMI_SpeakTTS << SpeakTTS;
        setLMI("SpeakTTS", LMI_SpeakTTS);
    }

    void initMainConfig()
    {
        LISTMAPINFO LMI_Login;
        QMap<QString, QVariant> LoginConfig;
        LoginConfig["LastLoginUser"] = "default";
        LoginConfig["AutoLogin"] = false;
        LMI_Login << LoginConfig;
        setLMI("Login", LMI_Login);

        LISTMAPINFO LMI_CurrentUser;
        QMap<QString, QVariant> CurrentUser;
        CurrentUser["CurrentUser"] = "default";
        CurrentUser["IsNewUser"] = false;
        LMI_CurrentUser << CurrentUser;
        setLMI("CurrentUserInfo", LMI_CurrentUser);
    }

    QSettings *getCfg()
    {
        return cfg;
    }

    QString getLastLoginUser()
    {
        return cfg->value("Login/LastLoginUser", "default").toString();
    }
    void setLastLoginUser(const QString &userName)
    {
        cfg->setValue("Login/LastLoginUser", userName);
    }

    bool getAutoLogin()
    {
        return cfg->value("Login/AutoLogin", true).toBool();
    }
    void setAutoLogin(bool bAuto)
    {
        cfg->setValue("Login/AutoLogin", bAuto);
    }

    bool getRememberPassword()
    {
        return cfg->value("Login/RememberPassword", true).toBool();
    }
    void setRememberPassword(bool bRemember)
    {
        cfg->setValue("Login/RememberPassword", bRemember);
    }

    QString getCurrentUser()
    {
        return cfg->value("CurrentUserInfo/CurrentUser", "default").toString();
    }
    void setCurrentUser(const QString &userName)
    {
        cfg->setValue("CurrentUserInfo/CurrentUser", userName);
    }

    bool getIsNewUser()
    {
        return cfg->value("CurrentUserInfo/IsNewUser", true).toBool();
    }
    void setIsNewUser(int loginCount)
    {
        if(loginCount == 1)
        {
            cfg->setValue("CurrentUserInfo/IsNewUser", true);
        }
        else
        {
            cfg->setValue("CurrentUserInfo/IsNewUser", false);
        }
    }

    ///////////////////////////////////////////////////////////////////
    //获取发声方法
    QString getSpeakMethod()
    {
        return cfg->value("SpeakTTS/SpeakMethod", "LocalTTS").toString();
    }
    void setSpeakMethod(const QString &speakMethod)
    {
        cfg->setValue("SpeakTTS/SpeakMethod", speakMethod);
    }

    QString getSpeakLocalTTS()
    {
        return cfg->value("SpeakTTS/SpeakLocalTTS", "eSpeakTTS").toString();
    }
    void setSpeakLocalTTS(const QString &localTTS)
    {
        cfg->setValue("SpeakTTS/SpeakLocalTTS", localTTS);
    }
    ///////////////////////////////////////////////////////////////////
    //SpeakTTS
    ///////////////////////
    //语速调节记录
    QString getSpeakSpeed()
    {
        return cfg->value("SpeakTTS/SpeakSpeed", "180").toString();
    }
    void setSpeakSpeed(const QString &speakSpeed)
    {
        cfg->setValue("SpeakTTS/SpeakSpeed", speakSpeed);
    }

    QString getSpeakRate()
    {
        return cfg->value("SpeakTTS/SpeakRate", "0").toString();
    }
    void setSpeakRate(const QString &speakRate)
    {
        cfg->setValue("SpeakTTS/SpeakRate", speakRate);
    }
    ///////////////////////
    //声音大小调节记录
    QString getSpeakVolume()
    {
        return cfg->value("SpeakTTS/SpeakVolume","100").toString();
    }
    void setSpeakVolume(const QString &volume)
    {
        cfg->setValue("SpeakTTS/SpeakVolume", volume);
    }    
    ///////////////////////
    //音调调节记录
    QString getSpeakPitch()
    {
        return cfg->value("SpeakTTS/SpeakPitch","50").toString();
    }
    void setSpeakPitch(const QString &pitch)
    {
        cfg->setValue("SpeakTTS/SpeakPitch", pitch);
    }
    ///////////////////////
    //音域调节记录
    QString getSpeakPitchRange()
    {
        return cfg->value("SpeakTTS/SpeakPitchRange","50").toString();
    }
    void setSpeakPitchRange(const QString &pitchrange)
    {
        cfg->setValue("SpeakTTS/SpeakPitchRange", pitchrange);
    }
    ///////////////////////
    //间隔调节记录
    QString getSpeakWordGap()
    {
        return cfg->value("SpeakTTS/SpeakWordGap","1").toString();
    }
    void setSpeakWordGap(const QString &wordgap)
    {
        cfg->setValue("SpeakTTS/SpeakWordGap", wordgap);
    }
    ///////////////////////
    //语言调节记录
    QString getSpeakLanguage()
    {
        return cfg->value("SpeakTTS/SpeakLanguage","de").toString();
    }
    void setSpeakLanguage(const QString &language)
    {
        cfg->setValue("SpeakTTS/SpeakLanguage", language);
    }

    //////////////////////////////////////////////////////////////
    //
    QString getLearnMethod()
    {
        return cfg->value("ConfigList/LearnMethod", "出词忆义").toString();
    }
    void setLearnMethod(const QString &LearnMethod)
    {
        cfg->setValue("ConfigList/LearnMethod", LearnMethod);
    }

    QString getOutWordMethod()
    {
        return cfg->value("ConfigList/OutWordMethod", "Random").toString();
    }
    void setOutWordMethod(const QString &OutWordMethod)
    {
        cfg->setValue("ConfigList/OutWordMethod", OutWordMethod);
    }

    QString getReviewWordMethod()
    {
        return cfg->value("ConfigList/ReviewWordMethod", "Random").toString();
    }
    void setReviewWordMethod(const QString &ReviewWordMethod)
    {
        cfg->setValue("ConfigList/ReviewWordMethod", ReviewWordMethod);
    }

    bool getIsOpenSound()
    {
        return cfg->value("ConfigList/OpenSound", true).toBool();
    }
    void setIsOpenSound(bool isopen)
    {
        cfg->setValue("ConfigList/OpenSound", isopen);
    }

    QString getSoundTime()
    {
        return cfg->value("ConfigList/SoundTime", "1").toString();
    }
    void setSoundTime(const QString &SoundTime)
    {
        cfg->setValue("ConfigList/SoundTime", SoundTime);
    }

    QString getInterval()
    {
        return cfg->value("ConfigList/Interval", "500").toString();
    }
    void setInterval(const QString &Interval)
    {
        cfg->setValue("ConfigList/Interval", Interval);
    }

    QMap<QString, QString> getShortcut()
    {
        QMap<QString, QString> shortcutList;
        shortcutList["RememShortcut"] = cfg->value("ConfigList/RememShortcut", "R").toString();
        shortcutList["NotSureShortcut"] = cfg->value("ConfigList/NotSureShortcut", "E").toString();
        shortcutList["ForgetShortcut"] = cfg->value("ConfigList/ForgetShortcut", "W").toString();
        shortcutList["RightShortcut"] = cfg->value("ConfigList/RightShortcut", "R").toString();
        shortcutList["WrongShortcut"] = cfg->value("ConfigList/WrongShortcut", "W").toString();
        shortcutList["EditWortShortcut"] = cfg->value("ConfigList/EditWortShortcut", "F").toString();
        shortcutList["SoundShortcut"] = cfg->value("ConfigList/SoundShortcut", "S").toString();
        shortcutList["NextShortcut"] = cfg->value("ConfigList/NextShortcut", "D").toString();
        shortcutList["ConfigShortcut"] = cfg->value("ConfigList/ConfigShortcut", "C").toString();
        return shortcutList;
    }
    void setShortcut(const QMap<QString, QString> &ShortcutList)
    {
        cfg->setValue("ConfigList/RememShortcut", ShortcutList.value("RememShortcut"));
        cfg->setValue("ConfigList/NotSureShortcut", ShortcutList.value("NotSureShortcut"));
        cfg->setValue("ConfigList/ForgetShortcut", ShortcutList.value("ForgetShortcut"));
        cfg->setValue("ConfigList/RightShortcut", ShortcutList.value("RightShortcut"));
        cfg->setValue("ConfigList/WrongShortcut", ShortcutList.value("WrongShortcut"));
        cfg->setValue("ConfigList/EditWortShortcut", ShortcutList.value("EditWortShortcut"));
        cfg->setValue("ConfigList/SoundShortcut", ShortcutList.value("SoundShortcut"));
        cfg->setValue("ConfigList/NextShortcut", ShortcutList.value("NextShortcut"));
        cfg->setValue("ConfigList/ConfigShortcut", ShortcutList.value("ConfigShortcut"));
    }

private:
    LISTMAPINFO getLMI(const QString & prefix);
    void setLMI(const QString & prefix, LISTMAPINFO &lmi);

private:
    QSettings *cfg;
};

#endif // MYCONFIG_H
