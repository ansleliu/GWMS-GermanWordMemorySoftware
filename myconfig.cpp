#include "myconfig.h"
#include "QFile"
#include "QFileInfo"

MyConfig::MyConfig(const QString &path)
{
    bool isExists = QFile::exists(path);
    cfg = new QSettings(path, QSettings::IniFormat);
    cfg->setIniCodec("GB18030");
    if (!isExists)
    {
        QFileInfo fd(path);
        QString configName = fd.baseName();
        if(configName == "Config")
        {
            initMainConfig();
        }
        else
        {
            initUserConfig();
        }
    }
}

MyConfig::~MyConfig()
{
    delete cfg;
}

LISTMAPINFO MyConfig::getLMI(const QString &prefix)
{
    LISTMAPINFO result;
    int size = cfg->beginReadArray(prefix);
    for(int i = 0; i < size; i++)
    {
        cfg->setArrayIndex(i);
        QStringList keys = cfg->childKeys();
        QMap<QString, QVariant> learnWordConfig;
        for(int j = 0; j < keys.size(); j++)
        {
            learnWordConfig[keys[j]] = cfg->value(keys[j]).toString();
        }
        result << learnWordConfig;

    }
    cfg->endArray();
    return result;
}

void MyConfig::setLMI(const QString &prefix, LISTMAPINFO &lmi)
{
    cfg->beginWriteArray(prefix);
    for(int i = 0; i < lmi.size(); i++)
    {
//        cfg->setArrayIndex(i);
        QMapIterator<QString, QVariant> iter(lmi.at(i));
        while (iter.hasNext())
        {
            iter.next();
            cfg->setValue(iter.key(), iter.value());
        }
    }
    cfg->endArray();
}
