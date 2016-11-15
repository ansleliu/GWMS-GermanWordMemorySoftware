#ifndef LEARNSTARTDIALOG_H
#define LEARNSTARTDIALOG_H

#include <QDialog>
#include <QString>
#include "bcmgr.h"
#include "learnmgr.h"
#include "gaugedisplayer.h"
#include "userbookdbmgr.h"
#include "learngaugedisplayer.h"
#include "QStandardItemModel"

namespace Ui {
class LearnStartDialog;
}

class LearnStartDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit LearnStartDialog(QWidget *parent = 0,const QString &bookpath = NULL);
    ~LearnStartDialog();
    
private slots:

    void on_LearnPushButton_clicked();

    void on_ReviewPushButton_clicked();

    void on_ChoiceCheckBox_clicked(bool checked);

    void on_LektionComboBox_currentIndexChanged(const QString &Lektion);

    void on_InfoListWidget_clicked(const QModelIndex &index);

    void on_LektionComboBox_currentIndexChanged(int index);

    void on_LektionLineEdit_textChanged(const QString &lektionNum);

    void on_ReviewLektionComboBox_currentIndexChanged(const QString &lektion);

public:
    bool getLearnByLektion();
    QString learnOrReview();
    int getLektion();
    QStandardItemModel* itemModel;

private:
    Ui::LearnStartDialog *ui;
//    QVBoxLayout *mainLayout;
//    QHBoxLayout *layout;

//    GaugeDisplayer *totalPercent;
//    GaugeDisplayer *haveLearnedPercent;
//    GaugeDisplayer *needReviewPercent;

//    LearnGaugeDisplayer *learnGauge;

    QStringList infolist;
    int wordCount;
    int haveLearnedcount;
    QString bookPath;
    QString LearnOrReview;
    int lektion;
};

#endif // LEARNSTARTDIALOG_H
