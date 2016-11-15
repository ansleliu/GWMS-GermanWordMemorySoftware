#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include "myglobal.h"
#include "bcmgr.h"
#include "QMessageBox"
#include "learnmgr.h"
#include "userbookdbmgr.h"
#include "QtSpeech.h"
/////////////////////////////////////////////////////////////////////////////
//
#include <QItemDelegate>
//只读委托
class readonlyDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    readonlyDelegate(QObject* parent = 0) : QItemDelegate(parent)
    {

    }
    QWidget* createEditor(QWidget* /*parent*/,
                          const QStyleOptionViewItem& /*option*/,
                          const QModelIndex& /*index*/) const
    {
        return NULL;
    }
};
//Repetition列，只能输入0－365数字
//利用QLineEdit委托和正则表达式对输入进行限制
class RepetitionDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    RepetitionDelegate(QObject *parent = 0): QItemDelegate(parent)
    {

    }
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem& /*option*/,
                          const QModelIndex& /*index*/) const
    {
        QLineEdit *editor = new QLineEdit(parent);
        QRegExp regExp("[0-365]{0,366}");
        editor->setValidator(new QRegExpValidator(regExp, parent));
        return editor;
    }
    void setEditorData(QWidget *editor, const QModelIndex &index) const
    {
        QString text = index.model()->data(index, Qt::EditRole).toString();
        QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
        lineEdit->setText(text);
    }
    void setModelData(QWidget *editor, QAbstractItemModel *model,
        const QModelIndex &index) const
    {
        QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
        QString text = lineEdit->text();
        model->setData(index, text.toInt(), Qt::EditRole);
    }
    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &/*index*/) const
    {
        editor->setGeometry(option.rect);
    }
};

//Grade列，利用QSpinBox委托进行输入限制，只能输入0－5之间的数字
class GradeDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    GradeDelegate(QObject *parent = 0): QItemDelegate(parent)
    {
    }
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem& /*option*/,
                          const QModelIndex& /*index*/) const
    {
        QSpinBox *editor = new QSpinBox(parent);
        editor->setMinimum(0);
        editor->setMaximum(5);
        return editor;
    }
    void setEditorData(QWidget *editor, const QModelIndex &index) const
    {
        int value = index.model()->data(index, Qt::EditRole).toInt();
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->setValue(value);
    }
    void setModelData(QWidget *editor, QAbstractItemModel *model,
        const QModelIndex &index) const
    {
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->interpretText();
        int value = spinBox->value();
        model->setData(index, value, Qt::EditRole);
    }
    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &/*index*/) const
    {
        editor->setGeometry(option.rect);
    }
};
                                                                                    /////
/////////////////////////////////////////////////////////////////////////////////////////
//测试音频的线程
#include "QThread"
#include "../bcmgr.h"
#include "../SpeakTTS.h"

class TestSoundTread:public QThread
{
    Q_OBJECT
public:
    TestSoundTread(QObject* parent = 0)
        :QThread(parent)
    {
        eSpeakTTS = new SpeakTTS();
    }
    ~TestSoundTread()
    {
        eSpeakTTS->stopSpeakTTS();
        delete eSpeakTTS;
    }
public slots:

signals:
    void soundEnded();

public:
    ///////////////////////////////////////////
    //
    virtual void setSpeakParameter(const int &speakSpeed = 0,
                              const int &speakVolume = 0,
                              const int &speakPitch = 0,
                              const int &speakPitchRange = 0,
                              const int &speakWordGap = 0)
    {
        speed = QString::number(speakSpeed,'i',0);
        volume = QString::number(speakVolume,'i',0);
        pitch = QString::number(speakPitch,'i',0);
        pitchRange = QString::number(speakPitchRange,'i',0);
        wordGap = QString::number(speakWordGap,'i',0);
    }
    virtual void getTextToSpeak(const QString &word)
    {
        text = word;
    }

    virtual void stopSpeakTTS()
    {
        eSpeakTTS->stopSpeakTTS();
    }

protected:
    virtual void run ()
    {
        //////////////////////
        //发音
        eSpeakTTS->stopSpeakTTS();

        eSpeakTTS->initESpeaktts();//初始化TTS
        eSpeakTTS->setSpeakLanguage("de");//设置语言
        eSpeakTTS->setSpeakSpeed(speed.toInt());//音速设定
        eSpeakTTS->setSpeakVolume(volume.toInt());//音量设定
        eSpeakTTS->setSpeakPitch(pitch.toInt(),pitchRange.toInt());//音调设定
        eSpeakTTS->setSpeakWordGap(wordGap.toInt());//间隔设定
        eSpeakTTS->speakTTS(text);//发音
        emit soundEnded();
    }

private:
    QString text;
    SpeakTTS *eSpeakTTS;
    QString speed;
    QString volume;
    QString pitch;
    QString pitchRange;
    QString wordGap;
};
////////////////////////////////////////////////////////////////////////////////
//

namespace Ui {
class OptionsDialog;
}

class OptionsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog();

private:
    void initAll();
    void TTSComboBoxInit();
    void LocalTTSInit();
    void eSpeakTTSInit();
    
private slots:
    void on_listWidget_currentRowChanged(int currentRow);

    void on_tabWidget_currentChanged(int index);

    void on_reviseKeyButton_clicked();

    void on_forgetKeyButton_clicked();

    void on_autoLoginCheckBox_clicked(bool checked);

    void on_rememKeyCheckBox_clicked(bool checked);

    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_deleteRecordButton_clicked();

    void on_applyButton_clicked();

    void on_quitButton_clicked();

    void on_studyRecordTableView_doubleClicked(const QModelIndex &index);

    void on_SearchLineEdit_textChanged(const QString &arg1);

    void on_ShowAllPushButton_clicked();

    void on_SSpeedSlider_valueChanged(int value);

    void on_SVolumeSlider_valueChanged(int value);

    void on_SPitchSlider_valueChanged(int value);

    void on_PRangeSlider_valueChanged(int value);

    void on_GapSlider_valueChanged(int value);

    void on_TestSondButton_clicked();

    void on_BackToSysButton_clicked();

    void on_TTSRadioButton_clicked(bool checked);

    void on_Real_TTSRadioButton_clicked(bool checked);

    void on_OnlineRadioButton_clicked(bool checked);

    void on_TTSComboBox_currentIndexChanged(const QString &localtts);

    void SpeakFinished();

public:
    QString getLearnMethod();
    QString getOutWordMethod();
    QString getReviewWordMethod();
    int getSoundTime();
    int getInterval();
    QMap<QString, QString> getShortcuts();

private:
    void saveConfig();

private:
    Ui::OptionsDialog *ui;
    //////////////////////////////
    QString currUser;

    //////////////////////////////
    QSqlTableModel *userDataModel;
    QSqlTableModel *studyStateModel;

    /////////////////////////////
    QString learnMethod;
    QString outWordMethod;
    QString reviewWordMethod;

    //////////////////////////////
    int soundTime;
    int interval;
    QString speakMethod;
    QString localTTS;
    /////////////////////////////////
    int sysSpeakSpeed;
    int sysSpeakRate;
    int sysSpeakVolume;
    int sysSpeakPitch;
    int sysSpeakPitchRange;
    int sysSpeakWordGap;

    int currSpeakSpeed;
    int currSpeakRate;
    int currSpeakVolume;
    int currSpeakPitch;
    int currSpeakPitchRange;
    int currSpeakWordGap;

    TestSoundTread *testSound;
    QtSpeech *speech;
    /////////////////////////////////
    QMap<QString,QString> shortcuts;
};

#endif // OPTIONSDIALOG_H
