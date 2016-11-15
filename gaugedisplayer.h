#ifndef GaugeDisplayer_H
#define GaugeDisplayer_H

#define LONG3 7
#define OK3 5
#define SHORT3 3
#define MARK_BUCKET_SPACE3 20

#include <QWidget>
#include <QtGui>

class GaugeDisplayer : public QWidget
{
    Q_OBJECT
public:
    explicit GaugeDisplayer(QWidget *parent = 0);
    ~GaugeDisplayer();
    void SetGraphColor(QColor c);

protected:
    void paintEvent(QPaintEvent *);
    QSize sizeHint() const
    {
        return QSize(300,300);
    }

    QSize minimumSizeHint() const
    {
        return QSize(200,200);
    }

private:
    void drawMark(QPainter* painter);
    void drawBucket(QPainter* painter);
    void drawBackground(QPainter* painter);
    void drawGraph(QPainter* painter);
    void resetDrawingVariables();

private:
    qreal m_value;
    qreal m_currentValue;
    qreal m_bucketWidth;
    QTimer* updateTimer;
    bool  m_bReverse;
    qreal m_markSpace;
    qreal m_topSpace;
    QColor m_markClr;
    QColor graphcolor;
    QRectF m_bucketRect;

private:
    void initVariables();

signals:

private slots:
    void UpdateGraph();

public slots:
    void setValue(qreal value);
    void setMarkColor(const QColor& clr);
};

#endif // GaugeDisplayer_H
