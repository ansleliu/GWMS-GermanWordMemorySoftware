#include "learnwordconfigdialog.h"
#include "ui_learnwordconfigdialog.h"
#include "bcmgr.h"

LearnWordConfigDialog::LearnWordConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LearnWordConfigDialog)
{
    ui->setupUi(this);
    ///////////////////////////////////////////////////////
    //设置当前的Tab
    ui->ConfigTabWidget->setCurrentWidget(ui->LearnTab);
    //////////////////////////////////////////////////////////////////
    //设置学习方法
    QString LearnMethodInConf = bcMgr->userConf->getLearnMethod();
    int index = ui->LearnMethodComboBox->findText(LearnMethodInConf);
    ui->LearnMethodComboBox->setCurrentIndex(index);

    if(bcMgr->userConf->getOutWordMethod() == "Random")
    {
        ui->OutRandomRadioButton->click();
    }
    else
    {
        ui->OutOrderlyRadioButton->click();
    }
    if(bcMgr->userConf->getReviewWordMethod() == "Random")
    {
        ui->ReviewRandomRadioButton->click();
    }
    else
    {
        ui->ReviewOrderlyRadioButton->click();
    }
    //////////////////////////////////////////////////////
    //设置发音
    ////////////////////
    //发音次数
    QString soundTime = bcMgr->userConf->getSoundTime();
    int soundIndex = ui->TimeComboBox->findText(soundTime);
    ui->TimeComboBox->setCurrentIndex(soundIndex);
    /////////////////////
    //发音间隔
    QString interval = bcMgr->userConf->getInterval();
    int intervalIndex = ui->IntervalComboBox->findText(interval);
    ui->IntervalComboBox->setCurrentIndex(intervalIndex);
    /////////////////////
    //发音方式
    speakMethod = bcMgr->userConf->getSpeakMethod();
    if(speakMethod == "LocalTTS")
    {
        ui->TTSRadioButton->click();
    }
    if(speakMethod == "googleTTS")
    {
        ui->OnlineRadioButton->click();
    }
    if(speakMethod == "realSpeak&eSpeakTTS")
    {
        ui->Real_TTSRadioButton->click();
    }
    ////////////////////////////////////////////////////////////////////////
    //设置快捷键
    QMap<QString, QString> shortcutList = bcMgr->userConf->getShortcut();
    ui->RememLineEdit->setText(shortcutList.value("RememShortcut"));
    ui->ObscureLineEdit->setText(shortcutList.value("NotSureShortcut"));
    ui->ForgetLineEdit->setText(shortcutList.value("ForgetShortcut"));
    ui->RightLineEdit->setText(shortcutList.value("RightShortcut"));
    ui->WrongLineEdit->setText(shortcutList.value("WrongShortcut"));
    ui->EditWordLineEdit->setText(shortcutList.value("EditWortShortcut"));
    ui->SoundLineEdit->setText(shortcutList.value("SoundShortcut"));
    ui->NextLineEdit->setText(shortcutList.value("NextShortcut"));
    ui->ConfigLineEdit->setText(shortcutList.value("ConfigShortcut"));
}

LearnWordConfigDialog::~LearnWordConfigDialog()
{
    delete ui;
}

QString LearnWordConfigDialog::getLearnMethod()
{
    learnMethod = ui->LearnMethodComboBox->currentText();
    bcMgr->userConf->setLearnMethod(learnMethod);
    return learnMethod;
}

QString LearnWordConfigDialog::getOutWordMethod()
{
    if(ui->OutOrderlyRadioButton->isChecked())
    {
        outWordMethod = "Orderly";
    }
    else if(ui->OutRandomRadioButton->isChecked())
    {
        outWordMethod = "Random";
    }
    else
    {
        outWordMethod = "Random";
    }
    bcMgr->userConf->setOutWordMethod(outWordMethod);
    return outWordMethod;
}

QString LearnWordConfigDialog::getReviewWordMethod()
{
    if(ui->ReviewOrderlyRadioButton->isChecked())
    {
        reviewWordMethod = "Orderly";
    }
    else if(ui->ReviewRandomRadioButton->isChecked())
    {
        reviewWordMethod = "Random";
    }
    else
    {
        reviewWordMethod = "Random";
    }
    bcMgr->userConf->setReviewWordMethod(reviewWordMethod);
    return reviewWordMethod;
}

void LearnWordConfigDialog::setOutOrderlyRadioButtonUnable()
{
    ui->OutOrderlyRadioButton->setEnabled(false);
    ui->OutRandomRadioButton->setChecked(true);
    saveConfig();
}

int LearnWordConfigDialog::getSoundTime()
{
    QString time = ui->TimeComboBox->currentText();
    soundTime = time.toInt();
    bcMgr->userConf->setSoundTime(time);
    return soundTime;
}

int LearnWordConfigDialog::getInterval()
{
    QString soundInterval = ui->IntervalComboBox->currentText();
    interval = soundInterval.toInt();
    bcMgr->userConf->setInterval(soundInterval);
    return interval;
}

QMap<QString, QString> LearnWordConfigDialog::getShortcuts()
{
    shortcuts["RememShortcut"] = ui->RememLineEdit->text();
    shortcuts["NotSureShortcut"] = ui->ObscureLineEdit->text();
    shortcuts["ForgetShortcut"] = ui->ForgetLineEdit->text();
    shortcuts["RightShortcut"] = ui->RightLineEdit->text();
    shortcuts["WrongShortcut"] = ui->WrongLineEdit->text();
    shortcuts["EditWortShortcut"] = ui->EditWordLineEdit->text();
    shortcuts["SoundShortcut"] = ui->SoundLineEdit->text();
    shortcuts["NextShortcut"] = ui->NextLineEdit->text();
    shortcuts["ConfigShortcut"] = ui->ConfigLineEdit->text();
    bcMgr->userConf->setShortcut(shortcuts);
    return shortcuts;
}

void LearnWordConfigDialog::saveConfig()
{
    learnMethod = ui->LearnMethodComboBox->currentText();
    bcMgr->userConf->setLearnMethod(learnMethod);

    if(ui->OutOrderlyRadioButton->isChecked())
    {
        outWordMethod = "Orderly";
    }
    else if(ui->OutRandomRadioButton->isChecked())
    {
        outWordMethod = "Random";
    }
    else
    {
        outWordMethod = "Random";
    }
    bcMgr->userConf->setOutWordMethod(outWordMethod);

    if(ui->ReviewOrderlyRadioButton->isChecked())
    {
        reviewWordMethod = "Orderly";
    }
    else if(ui->ReviewRandomRadioButton->isChecked())
    {
        reviewWordMethod = "Random";
    }
    else
    {
        reviewWordMethod = "Random";
    }
    bcMgr->userConf->setReviewWordMethod(reviewWordMethod);
    //////////////////////////////////////////////////////////////////
    //
    QString time = ui->TimeComboBox->currentText();
    soundTime = time.toInt();
    bcMgr->userConf->setSoundTime(time);

    QString soundInterval = ui->IntervalComboBox->currentText();
    interval = soundInterval.toInt();
    bcMgr->userConf->setInterval(soundInterval);
    bcMgr->userConf->setSpeakMethod(speakMethod);
    ///////////////////////////////////////////////////////////////////
    //
    shortcuts["RememShortcut"] = ui->RememLineEdit->text();
    shortcuts["NotSureShortcut"] = ui->ObscureLineEdit->text();
    shortcuts["ForgetShortcut"] = ui->ForgetLineEdit->text();
    shortcuts["RightShortcut"] = ui->RightLineEdit->text();
    shortcuts["WrongShortcut"] = ui->WrongLineEdit->text();
    shortcuts["EditWortShortcut"] = ui->EditWordLineEdit->text();
    shortcuts["SoundShortcut"] = ui->SoundLineEdit->text();
    shortcuts["NextShortcut"] = ui->NextLineEdit->text();
    shortcuts["ConfigShortcut"] = ui->ConfigLineEdit->text();
    bcMgr->userConf->setShortcut(shortcuts);
}

void LearnWordConfigDialog::on_OKButton_clicked()
{
    saveConfig();
    QDialog::accept();
}

void LearnWordConfigDialog::on_QuitButton_clicked()
{
    QDialog::reject();
}

void LearnWordConfigDialog::on_TTSRadioButton_clicked(bool checked)
{
    if(checked)
    {
        speakMethod = "LocalTTS";
    }
}

void LearnWordConfigDialog::on_OnlineRadioButton_clicked(bool checked)
{
    if(checked)
    {
        speakMethod = "googleTTS";
    }
}

void LearnWordConfigDialog::on_Real_TTSRadioButton_clicked(bool checked)
{
    if(checked)
    {
        speakMethod = "realSpeak&eSpeakTTS";
    }
}
