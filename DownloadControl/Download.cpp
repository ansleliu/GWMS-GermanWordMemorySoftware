#include "Download.h"
#include <QDebug>

Download::Download(int index, QObject *parent) :
    QObject(parent),m_Index(index)
{
    m_HaveDoneBytes = 0;
    m_StartPoint = 0;
    m_EndPoint = 0;
    m_File = NULL;
}

void Download::StartDownload(const QUrl &url, QFile *file,
                             qint64 startPoint,
                             qint64 endPoint)
{
    if( NULL == file)
    {
        return;
    }
    m_HaveDoneBytes = 0;
    m_StartPoint = startPoint;
    m_EndPoint = endPoint;
    m_File = file;
    //根据HTTP协议，写入RANGE头部，说明请求文件的范围
    QNetworkRequest qheader;
    qheader.setUrl(url);
    QString range;
    range.sprintf("Bytes=%lld-%lld", m_StartPoint, m_EndPoint);
    qheader.setRawHeader("Range", range.toAscii());
    //开始下载
    qDebug() << "Part " << m_Index << " start download";

    m_Reply = m_Qnam.get(QNetworkRequest(qheader));
    connect(m_Reply, SIGNAL(finished()), this, SLOT(FinishedSlot()));
    connect(m_Reply, SIGNAL(readyRead()), this, SLOT(HttpReadyRead()));
}

void Download::FinishedSlot()
{
    //下载结束
    m_File->flush();
    m_Reply->deleteLater();
    m_Reply = 0;
    m_File = 0;

    qDebug() << "Part " << m_Index << " download finished";
    emit DownloadFinished();
}

void Download::HttpReadyRead()
{
    if ( !m_File )
    {
        return;
    }
    //将读到的信息写入文件
    QByteArray buffer = m_Reply->readAll();
    m_File->seek( m_StartPoint + m_HaveDoneBytes );
    m_File->write(buffer);
    m_HaveDoneBytes += buffer.size();
}
