#ifndef DOWNLOADCONTROL_H
#define DOWNLOADCONTROL_H

#include <QObject>
#include <QtNetwork>
#include <QUrl>
#include <QFile>
#include "Download.h"

class DownloadControl : public QObject
{
    Q_OBJECT
public:
    explicit DownloadControl(QObject *parent = 0);

    void StartFileDownload(const QString &url, int count, QFile *file);
    qint64 GetFileSize(QUrl url);

signals:
    void FileDownloadFinished();
    void DownloadFail();
    
private slots:
    void SubPartFinished();

private:
    int m_DownloadCount;
    int m_FinishedNum;
    int m_FileSize;

    QString newName;
    QUrl m_Url;
    QFile *m_File;
};

#endif // DOWNLOADCONTROL_H
