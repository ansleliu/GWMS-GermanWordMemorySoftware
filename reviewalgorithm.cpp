//////////////////////////////////////////////////////////////////
//学习算法类
//完成单词复习时间的推算
//2014.08.21
//////////////////////////////////////////////////////////////////
#include "reviewalgorithm.h"
#include "QTime"
ReviewAlgorithm::ReviewAlgorithm()
{
    Grade = 0;        //单词等级
    Repetition = 0;   //重复次数
    Interval = 0;     //间隔时间
    EF = 2.50;         //难度因子
}

ReviewAlgorithm::~ReviewAlgorithm()
{
}

QList<QString> ReviewAlgorithm::setInterval_Repetition(int currentInterval, double currentEF,
                                                       int currentGrade, int currentRepetition)
{
    if(currentGrade >= 3)
    {
        if(currentRepetition == 0)
        {
            ////////////////////////////////////////
            //产生随机数1
            QTime time;
            time = QTime::currentTime();
            qsrand(time.msec()+time.second()*1000);
            Interval = 1;
            Repetition = 1;
            EF = setEF(currentEF,currentGrade);
        }
        else if(currentRepetition == 1)
        {
            ////////////////////////////////////////
            //产生随机数2-3
            QTime time;
            time = QTime::currentTime();
            qsrand(time.msec()+time.second()*1000);
            Interval = 2;
            Repetition = 2;
            EF = setEF(currentEF,currentGrade);
        }
        else
        {
            if(currentEF <= 1.3)
            {
                Interval = currentInterval;
                Repetition = currentRepetition + 1;
                EF = setEF(currentEF,currentGrade);
            }
            else
            {
                ////////////////////////////////////////
                //产生随机数
                QTime time;
                time = QTime::currentTime();
                qsrand(time.msec()+time.second()*1000);
                ///////////////////////////////////////////////////////////////////////////
                //
                Interval =(qCeil(currentInterval * (currentEF-0.3))) + (qrand()%3 - 1);
                Repetition = currentRepetition + 1;
                EF = setEF(currentEF,currentGrade);
            }
        }
    }
    else
    {
        Interval = 1;
        Repetition = 0;
        EF = currentEF;
    }
    QList<QString> list;
    list.append(QString::number(Interval,'i',0));
    list.append(QString::number(Repetition,'i',0));
    list.append(QString::number(EF,'g',3));
    return list;
}

QList<QString> ReviewAlgorithm::setInterval_Repetition_curr_Review(int currentInterval,
                                                                   double currentEF,
                                                                   int currentGrade,
                                                                   int currentRepetition)
{
    if(currentGrade >= 3)
    {
        if(currentGrade == 5)
        {
            if(currentEF == 1.3)
            {
                Interval = currentInterval;
                Repetition = currentRepetition + 1;
                EF = setEF(currentEF,currentGrade);
            }
            else
            {
                ////////////////////////////////////////
                //产生随机数
                QTime time;
                time = QTime::currentTime();
                qsrand(time.msec()+time.second()*1000);
                if(currentInterval == 0)
                {
                    Interval =qCeil((qrand()%120 + 120) * (currentEF-0.3));
                    Repetition = currentRepetition + 1;
                    EF = setEF(currentEF,currentGrade);
                }
                else
                {
                    Interval =qCeil((qrand()%currentInterval + 120) * (currentEF-0.3));
                    Repetition = currentRepetition + 1;
                    EF = setEF(currentEF,currentGrade);
                }
            }
        }
        else if(currentGrade == 4)
        {
            if(currentEF == 1.3)
            {
                Interval = currentInterval;
                Repetition = currentRepetition + 1;
                EF = setEF(currentEF,currentGrade);
            }
            else
            {
                ////////////////////////////////////////
                //产生随机数
                QTime time;
                time = QTime::currentTime();
                qsrand(time.msec()+time.second()*1000);
                if(currentInterval == 0)
                {
                    Interval =qCeil((qrand()%90 + 90) * (currentEF-0.3));
                    Repetition = currentRepetition + 1;
                    EF = setEF(currentEF,currentGrade);
                }
                else
                {
                    Interval =qCeil((qrand()%currentInterval + 90) * (currentEF-0.3));
                    Repetition = currentRepetition + 1;
                    EF = setEF(currentEF,currentGrade);
                }
            }
        }
        else if(currentGrade == 3)
        {
            if(currentEF == 1.3)
            {
                Interval = currentInterval;
                Repetition = currentRepetition + 1;
                EF = setEF(currentEF,currentGrade);
            }
            else
            {
                ////////////////////////////////////////
                //产生随机数
                QTime time;
                time = QTime::currentTime();
                qsrand(time.msec()+time.second()*1000);
                if(currentInterval == 0)
                {
                    Interval =qCeil((qrand()%60 + 60) * (currentEF-0.3));
                    Repetition = currentRepetition + 1;
                    EF = setEF(currentEF,currentGrade);
                }
                else
                {
                    Interval =qCeil((qrand()%currentInterval + 60) * (currentEF-0.3));
                    Repetition = currentRepetition + 1;
                    EF = setEF(currentEF,currentGrade);
                }
            }
        }
    }
    else
    {
        Interval = 60;
        Repetition = 0;
        EF = currentEF;
    }
    QList<QString> list;
    list.append(QString::number(Interval,'i',0));
    list.append(QString::number(Repetition,'i',0));
    list.append(QString::number(EF,'g',3));
    return list;
}

double ReviewAlgorithm::setEF(double currentEF, int currentGrade)
{
    EF = currentEF - 0.8 + 0.28*currentGrade - 0.02*currentGrade*currentGrade;
    if(EF < 1.3)
    {
        EF = 1.3;
    }
    else if(EF > 2.50)
    {
        EF = 2.50;
    }
    return EF;
}
