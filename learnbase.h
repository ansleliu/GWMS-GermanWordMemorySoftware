#ifndef LEARNBASE_H
#define LEARNBASE_H
#include "mysqlite.h"

class LearnBase : public MySQLite
{
public:
    LearnBase(const QString &dbpath, const QString &connName);
    ~LearnBase();
protected:
    void createStateTable();
    void createCurrTimeStateTable();

public:
    QSqlDatabase *getLearnStatedb();

    bool addNewWordState(const QString &tableName,const QString &bookPath,
                         const int &wid,const QString &word,const QString &mean,
                         const QString &connection,const int &lektion,
                         const double &EF,const int &Grade, const int &Repetition, const int &Interval);
    int isExist(const QString &tableName,const QString &bookPath,
                const int &wid);
    int isExist(const QString &tableName,const QString &bookPath);

    void deleteTable(const QString &tableName);
    bool deleteRecord(const QString &tableName,const int &id);

    bool deleteRecord(const QString &tableName,const QString &bookPath);

    QList<int> getReviewWordIDByLektion(const QString &tableName,
                                        const QString &bookPath,
                                        const int &lektion);
    QList<int> getReviewWordID(const QString &tableName,
                               const QString &bookPath);

    QStringList getImportantInfo(const QString &tableName,const int &id);
    int getRecordCount(const QString &tableName);

    QString getLastTime(const QString &tableName,const int &id);
    QString getWord(const QString &tableName,const int &id);
    QString getMean(const QString &tableName,const int &id);
    QString getConnection(const QString &tableName,const int &id);
    int getLektion(const QString &tableName,const int &id);
    QStringList getWordAll(const QString &tableName,const int &id);

    QList<QString> getWordState(const QString &tableName,const int &id);

    int getGrade(const QString &tableName,const int &id);
    double getEF(const QString &tableName,const int &id);
    int getRepetition(const QString &tableName,const int &id);
    int getInterval(const QString &tableName,const int &id);
    int getTimeDiff(const QString &tableName,const int &id);

    bool setWordAll(const QString &tableName,const int &wid,
                    const QString &bookPath,const QStringList &wordall);
    bool setWord(const QString &tableName,const int &wid,
                 const QString &bookPath,const QString &word);
    bool setMean(const QString &tableName,const int &wid,
                 const QString &bookPath,const QString &mean);
    bool setConnection(const QString &tableName,const int &wid,
                       const QString &bookPath,const QString &connection);
    bool setLektion(const QString &tableName,const int &wid,
                    const QString &bookPath,const int &lektion);

    bool setWordState(const QString &tableName,const int &id,const int &Grade,
                      const double &EF,const int &Repetition,const int &Interval);

    bool setGrade(const QString &tableName,const int &id,const int &Grade);
    bool setEF(const QString &tableName,const int &id,const double &EF);
    bool setRepetition(const QString &tableName,const int &id,const int &Repetition);
    bool setInterval(const QString &tableName,const int &id,const int &Interval);
    bool setTimeDiff(const QString &tableName,const int &id,const int &TimeDiff);

    int getHaveLearnedWordCountByLektion(const QString &bookPath,const int &lektion);
    int getHaveLearnedWordCount(const QString &bookPath);

    int getReviewCountInfo(const QString &bookPath,const int &Interval);
    int getWordCountG5(const QString &bookPath);
    int getWordCountG4A3(const QString &bookPath);
    int getWordCountGU3(const QString &bookPath);

public:
    QSqlTableModel *studyStateDBModel(QWidget *parent);

};

#endif // LEARNBASE_H
