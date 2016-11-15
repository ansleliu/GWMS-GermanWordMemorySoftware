#ifndef ANSLEDICTCONFIGDIALOG_H
#define ANSLEDICTCONFIGDIALOG_H

#include <QDialog>
#include "AnsleDictConfigFile.h"
#include "QtSpeech.h"
////////////////////////////////////////
//
namespace Ui {
class AnsleDictConfigDialog;
}

class AnsleDictConfigDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AnsleDictConfigDialog(QWidget *parent = 0,ConfigFile *config = NULL);
    ~AnsleDictConfigDialog();
    
private slots:
    void on_ApplyButton_clicked();

    void on_CancelButton_clicked();

    void on_OtherRadioButton_clicked(bool checked);

    void on_RateHorizontalSlider_valueChanged(int value);

    void on_ESpeakTTSRadioButton_clicked(bool checked);

    void on_GoogleTTSRadioButton_clicked(bool checked);

public:
    QString voiceMethode();
    void initTTSCombox();
    void otherTTSInit();

private:
    Ui::AnsleDictConfigDialog *ui;
    ConfigFile *speakConfig;
    QString speakMethode;
    QString QtSpeakTTS;
    int QtSpeakTTSID;
};

#endif // ANSLEDICTCONFIGDIALOG_H
