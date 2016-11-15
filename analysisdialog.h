#ifndef ANALYSISDIALOG_H
#define ANALYSISDIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include "bcmgr.h"
#include "QMessageBox"
#include "learnmgr.h"
#include "QCalendarWidget"
namespace Ui {
class AnalysisDialog;
}

class AnalysisDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AnalysisDialog(QWidget *parent = 0);
    ~AnalysisDialog();

public:
    void colorProjectInit();
    void plotInit();
    void pieChartInit();
    void BookComboBoxInit();
    void getBookList();
    void reviewCalculate();
    
private slots:
    void on_ChoiceListWidget_currentRowChanged(int currentRow);

    void on_LBarRadioButton_clicked();

    void on_LLineRadioButton_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_dateEdit_dateChanged(const QDate &date);

    void on_LRadioButton_clicked();

    void on_RRadioButton_clicked();

    void on_RBarRadioButton_clicked();

    void on_RLineRadioButton_clicked();

    void on_BookComboBox_currentIndexChanged(int index);

    void learnShowToolTip(const QModelIndex& index);
    void reviewShowToolTip(const QModelIndex& index);
    void pieShowToolTip(const QModelIndex& index);

    void on_DataPushButton_clicked();
    void setdate();

    void on_LSpinBox_valueChanged(int arg1);

    void on_RSpinBox_valueChanged(int arg1);

private:
    Ui::AnalysisDialog *ui;
    QStandardItemModel *itemModel;
    QStandardItemModel *reviewItemModel;
    QStandardItemModel *LHLItemModel;
    QStandardItemModel *HG5ItemModel;
    QStandardItemModel *HG4A3ItemModel;
    QStandardItemModel *HGU3ItemModel;
    QCalendarWidget *calendar;

    QStringList dateList;
    QStringList bookpaths;
    QStringList tablenames;

    QList< QMap<QString,QList<int> > > record;

    QMap<int,Qt::GlobalColor> colorProject;
};

#endif // ANALYSISDIALOG_H
