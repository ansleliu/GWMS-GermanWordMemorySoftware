#ifndef ANSLEDICTDIALOG_H
#define ANSLEDICTDIALOG_H

#include <QDialog>
#include <QModelIndex>
#include "./AnsleDictCode/AnsleDictSpeakMgr.h"
#include "bcmgr.h"
#include "AnsleDictConfigFile.h"
#include <QTableWidgetItem>
#include <QSqlTableModel>

namespace Ui {
class AnsleDictDialog;
}

class AnsleDictDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AnsleDictDialog(QString word, QWidget *parent = 0);
    ~AnsleDictDialog();
    
private slots:
    void on_ConfigPushButton_clicked();

    void on_AddToNewWordPushButton_clicked();

    void on_SpeakTTSPushButton_clicked();

    void on_WordTableView_customContextMenuRequested(const QPoint &pos);

    void on_WordLineEdit_textChanged(const QString &word);

    void on_WordTableView_clicked(const QModelIndex &index);

    void on_ExpComboBox_currentIndexChanged(int index);

    void on_action_AddToNewWord_triggered();

    void on_action_Speak_triggered();

    void setButtonState();

private:
    Ui::AnsleDictDialog *ui;
    QSqlTableModel *minimodel;
    AnsleDictSpeakMgr *speakMgr;
    /////////////////////////////////
    //
    ConfigFile *speakConfig;

    CreatWordListDB *myDict;
};

#endif // ANSLEDICTDIALOG_H
