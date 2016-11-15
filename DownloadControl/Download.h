#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QObject>
#include <QThread>
#include <QtNetwork>
#include <QFile>

class Download : public QObject
{
    Q_OBJECT
public:
    explicit Download(int index = 0, QObject *parent = 0);

    void StartDownload(const QUrl &url, QFile *file,
                       qint64 startPoint=0,
                       qint64 endPoint=-1);
    
signals:
    void DownloadFinished();
    
public slots:
    void FinishedSlot();
    void HttpReadyRead();

private:
    QNetworkAccessManager m_Qnam;
    QNetworkReply *m_Reply;
    QFile *m_File;

    const int m_Index;
    qint64 m_HaveDoneBytes;
    qint64 m_StartPoint;
    qint64 m_EndPoint;
};

#endif // DOWNLOAD_H
