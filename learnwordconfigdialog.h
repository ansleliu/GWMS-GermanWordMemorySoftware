#ifndef LEARNWORDCONFIGDIALOG_H
#define LEARNWORDCONFIGDIALOG_H

#include <QDialog>
#include <QString>
#include <QMap>

namespace Ui {
class LearnWordConfigDialog;
}

class LearnWordConfigDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit LearnWordConfigDialog(QWidget *parent = 0);
    ~LearnWordConfigDialog();

public:
    QString getLearnMethod();
    QString getOutWordMethod();
    QString getReviewWordMethod();
    void setOutOrderlyRadioButtonUnable();

    int getSoundTime();
    int getInterval();

    QMap<QString, QString> getShortcuts();

private slots:
    void on_OKButton_clicked();

    void on_QuitButton_clicked();
    void on_TTSRadioButton_clicked(bool checked);

    void on_OnlineRadioButton_clicked(bool checked);

    void on_Real_TTSRadioButton_clicked(bool checked);

private:
    void saveConfig();
private:
    Ui::LearnWordConfigDialog *ui;
    /////////////////////////////////
    QString learnMethod;
    QString outWordMethod;
    QString reviewWordMethod;
    /////////////////////////////////
    int soundTime;
    int interval;
    QString speakMethod;
    QMap<QString,QString> shortcuts;
};

#endif // LEARNWORDCONFIGDIALOG_H
