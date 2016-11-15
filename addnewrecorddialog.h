#ifndef ADDNEWRECORDDIALOG_H
#define ADDNEWRECORDDIALOG_H

#include <QDialog>

namespace Ui {
class AddNewRecordDialog;
}

class AddNewRecordDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddNewRecordDialog(QWidget *parent = 0);
    ~AddNewRecordDialog();

public:
    QString getWord();
    QString getMean();
    QString getOther();
    int getLektion();

    void setWord(const QString &word);
    void setMean(const QString &mean);
    void setOther(const QString &other);
    void setLektion(const int &lektion);
    void setGroupTitle(const QString &title);

    void setLektionLineEditRradOnly();

private slots:
    void on_CloseButton_clicked();

    void on_OKButton_clicked();

private:
    Ui::AddNewRecordDialog *ui;
};

#endif // ADDNEWRECORDDIALOG_H
