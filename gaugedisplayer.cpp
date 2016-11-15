#include "GaugeDisplayer.h"

GaugeDisplayer::GaugeDisplayer(QWidget *parent) :
    QWidget(parent)
{
    this->initVariables();
}

GaugeDisplayer::~GaugeDisplayer()
{
    delete updateTimer;
}

void GaugeDisplayer::initVariables()
{
    m_markClr=Qt::white;
    graphcolor=Qt::darkGreen;
    m_value=0;
    m_currentValue=0;
    m_bucketWidth=width()/3;
    m_markSpace=(qreal)width()/4;
    m_topSpace=(qreal)height()/15;
    updateTimer=new QTimer(this);
    updateTimer->setInterval(10);
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(UpdateGraph()));
    m_bReverse=false;
}

void GaugeDisplayer::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHints(QPainter::TextAntialiasing|QPainter::Antialiasing);
    resetDrawingVariables();
    drawBackground(&painter);
    drawMark(&painter);
    drawBucket(&painter);
    drawGraph(&painter);

    painter.end();
}

void GaugeDisplayer::drawBackground(QPainter *painter)
{
    painter->save();

    QLinearGradient bgGradient(QPointF(0,0),QPointF(0,height()));
    bgGradient.setColorAt(0.0,QColor(200,200,200));
    bgGradient.setColorAt(0.2,QColor(100,100,100));
    bgGradient.setColorAt(0.9,QColor(100,100,100));
    bgGradient.setColorAt(1.0,QColor(200,200,200));

    painter->setBrush(bgGradient);
    painter->drawRect(rect());
    painter->restore();
}
void GaugeDisplayer::drawMark(QPainter *painter)
{
    painter->save();

    qreal initY=m_topSpace;
    qreal initX=m_markSpace;
    qreal length=height()-2*m_topSpace;
    qreal increment=length/100;
    painter->setPen(m_markClr);

    // draw vertical line
    QPointF topPot(m_markSpace,m_topSpace);
    QPointF bottomPot(m_markSpace,height()-m_topSpace);
    painter->drawLine(topPot,bottomPot);

    int vvalue=100;
    QString strValue;
    for(int i=0;i<=100;i++)
    {
        if(i%10==0)
        {
            QPointF leftPot(initX+LONG3,initY);
            QPointF rightPot(initX,initY);
            painter->drawLine(leftPot,rightPot);

            strValue=tr("%1").arg(vvalue);
            qreal fontWidth=painter->fontMetrics().width(strValue);
            qreal fontHeight=painter->fontMetrics().height();

            QPointF textPot(initX-fontWidth-5,initY+fontHeight/2);
            painter->drawText(textPot,strValue);

            vvalue-=10;

        }
        else if(i%5==0 && i%10!=0)
        {
            QPointF leftPot(initX+OK3,initY);
            QPointF rightPot(initX,initY);
            painter->drawLine(leftPot,rightPot);
        }
        else
        {
            QPointF leftPot(initX+SHORT3,initY);
            QPointF rightPot(initX,initY);
            painter->drawLine(leftPot,rightPot);
        }
        initY+=increment;
    }
    painter->restore();
}

void GaugeDisplayer::SetGraphColor(QColor c)
{
    this->graphcolor=c;
}


void GaugeDisplayer::drawGraph(QPainter *painter)
{
    painter->save();
    qreal bucketHeight=m_bucketRect.height();
    qreal increment=(qreal)bucketHeight/100;

    QPointF bottomRightPot(m_bucketRect.bottomRight());
    qreal currentY=m_currentValue*increment;

    QPointF topLeftPot(m_bucketRect.topLeft().x(),m_bucketRect.bottomLeft().y()-currentY);
    QRectF graphRect(topLeftPot,bottomRightPot);
    painter->setPen(Qt::NoPen);

    QLinearGradient graphGradient(graphRect.topLeft(),graphRect.topRight());
    painter->setOpacity(0.6);

//    graphGradient.setColorAt(0.0,this->graphcolor);

    graphGradient.setColorAt(0.0,QColor(0,0,100,100));
    graphGradient.setColorAt(0.6,QColor(0,0,250,240));
    graphGradient.setColorAt(1.0,QColor(0,0,180,200));

    painter->setBrush(graphGradient);
    painter->drawRect(graphRect);
    painter->restore();
}

void GaugeDisplayer::drawBucket(QPainter *painter)
{
    painter->save();

    QPointF bucketTopLeftPot(m_markSpace+MARK_BUCKET_SPACE3,m_topSpace);
    QPointF bucketBottomRightPot(m_markSpace+MARK_BUCKET_SPACE3+m_bucketWidth,height()-m_topSpace);
    QRectF bucketRect(bucketTopLeftPot,bucketBottomRightPot);
    m_bucketRect=bucketRect;

    QLinearGradient bucketGradient(bucketRect.topLeft(),bucketRect.topRight());
    bucketGradient.setColorAt(0.0,QColor(100,100,100));
    bucketGradient.setColorAt(0.6,QColor(200,200,200));
    bucketGradient.setColorAt(1.0,QColor(150,150,150));

    painter->setPen(Qt::NoPen);
    painter->setBrush(bucketGradient);
    painter->drawRect(bucketRect);
    painter->restore();
}

void GaugeDisplayer::resetDrawingVariables()
{
    m_markSpace=(qreal)width()/4;
    m_bucketWidth=(qreal)width()/3;
    m_topSpace=(qreal)height()/15;
}


void GaugeDisplayer::setValue(qreal value)
{
    if(value>m_value)
    {
        m_bReverse=false;
    }
    else if(value<m_value)
    {
        m_bReverse=true;
    }
    else
    {
        return ;
    }
     m_value=value;
    updateTimer->start();
}

void GaugeDisplayer::setMarkColor(const QColor &clr)
{
    m_markClr=clr;
    update();
}


void GaugeDisplayer::UpdateGraph()
{
    if(!m_bReverse)
    {
        m_currentValue+=0.5;
        if(m_currentValue>=m_value)
        {
            updateTimer->stop();
        }
    }
    else
    {
        m_currentValue-=0.5;

        if(m_currentValue<=m_value)
        {
            updateTimer->stop();
        }
    }
    update();
}
