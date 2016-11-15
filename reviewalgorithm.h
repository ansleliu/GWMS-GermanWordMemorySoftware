#ifndef REVIEWALGORITHM_H
#define REVIEWALGORITHM_H
#include "qmath.h"
#include "QString"
#include "QList"

class ReviewAlgorithm
{
public:
    ReviewAlgorithm();
    ~ReviewAlgorithm();

public:
    QList<QString> setInterval_Repetition(int currentInterval,double currentEF,
                                          int currentGrade,int currentRepetition);
    QList<QString> setInterval_Repetition_curr_Review(int currentInterval,double currentEF,
                                          int currentGrade,int currentRepetition);
    double setEF(double currentEF,int currentGrade);

private:
    int Grade;        //单词等级
    int Repetition;   //重复次数
    int Interval;     //间隔时间
    double EF;        //难度因子
};

#endif // REVIEWALGORITHM_H
