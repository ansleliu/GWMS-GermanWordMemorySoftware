#ifndef LEARNMGR_H
#define LEARNMGR_H
#include <QObject>
#include "pathmanage.h"
#include "learnbase.h"
#include "reviewalgorithm.h"
#include "QMessageBox"
#include "QString"

class LearnMgr : public QObject
{
    Q_OBJECT
public:
    explicit LearnMgr(QObject *parent = 0, const QString &userName = NULL);
    ~LearnMgr();
    
signals:
    
public slots:
    QSqlDatabase *getLearnStatedb();

    bool addNewWordState(const QString &tableName,const QString &bookPath,
                         const int &wid,const QString &word,const QString &mean,
                         const QString &connection,const int &lektion,
                         const double &EF, const int &Grade,
                         const int &Repetition, const int &Interval);
    int isExist(const QString &tableName,const QString &bookPath,
                const int &wid);
    int isExist(const QString &tableName,const QString &bookPath);

    void deleteTable(const QString &tableName);
    bool deleteRecord(const QString &tableName,const QString &bookPath);
    int getRecordCount();
    void transferRecord();

    QList<int> getReviewWordIDByLektion(const QString &tableName,
                                        const QString &bookPath,
                                        const int &lektion);
    QList<int> getReviewWordID(const QString &tableName, const QString &bookPath);

    QStringList getImportantInfo(const QString &tableName,const int &id);

    QString getLastTime(const QString &tableName,const int &id);
    QString getWord(const QString &tableName,const int &id);
    QString getMean(const QString &tableName,const int &id);
    QString getConnection(const QString &tableName,const int &id);
    int getLektion(const QString &tableName,const int &id);
    QStringList getWordAll(const QString &tableName,const int &id);
    //////////////////////////////////////////////////////////////////
    //
    QList<QString> getWordState(const QString &tableName,const int &id);
    int getGrade(const QString &tableName,const int &id);
    double getEF(const QString &tableName,const int &id);
    int getRepetition(const QString &tableName,const int &id);
    int getInterval(const QString &tableName,const int &id);
    int getTimeDiff(const QString &tableName,const int &id);
    //////////////////////////////////////////////////////////
    //
    bool setWordAll(const QString &tableName,const int &wid,
                    const QString &bookPath,const QStringList &wordall);
    bool setWord(const QString &tableName,const int &wid,
                 const QString &bookPath,const QString &word);
    bool setMean(const QString &tableName,const int &wid,
                 const QString &bookPath,const QString &mean);
    bool setConnection(const QString &tableName,const int &wid,
                       const QString &bookPath,const QString &connection);
    ////////////////////////////////////////////////////////////////////////////////
    //
    bool setWordState(const QString &tableName,const int &id,const int &Grade,
                      const double &EF,const int &Repetition,const int &Interval);

    bool setGrade(const QString &tableName,const int &id,const int &Grade);
    bool setEF(const QString &tableName,const int &id,const double &EF);
    bool setRepetition(const QString &tableName,const int &id,const int &Repetition);
    bool setInterval(const QString &tableName,const int &id,const int &Interval);
    bool setTimeDiff(const QString &tableName,const int &id,const int &TimeDiff);
    ////////////////////////////////////////////////////////////////////////////////////
    //
    int getHaveLearnedWordCountByLektion(const QString &bookPath,const int &lektion);
    int getHaveLearnedWordCount(const QString &bookPath);

    int getReviewCountInfo(const QString &bookPath,const int &Interval);
    int getWordCountG5(const QString &bookPath);
    int getWordCountG4A3(const QString &bookPath);
    int getWordCountGU3(const QString &bookPath);
    ////////////////////////////////////////////////////////////////////////////////////
    //
    QList<QString> countInterval_Repetition(int currentInterval, double currentEF,
                                            int currentGrade, int currentRepetition);
    QList<QString> countInterval_Repetition_Curr_Review(int currentInterval, double currentEF,
                                            int currentGrade, int currentRepetition);
    double countEF(double currentEF, int currentGrade);

    QSqlTableModel *studyStateDBModel(QWidget *parent);

protected:
    LearnBase *learnBase;
    ReviewAlgorithm *reviewAlgorithm;

private:
    QString currUserName;

};
extern LearnMgr *learnMgr;
#endif // LEARNMGR_H
