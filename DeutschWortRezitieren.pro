#-------------------------------------------------
#
# Project created by QtCreator 2014-02-10T00:26:47
#
#-------------------------------------------------

QT       += core gui phonon sql network webkit

TRANSLATIONS += DeutschWortRezitieren_english.ts
TARGET = DeutschWortRezitieren
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    usermanage.cpp \
    userdatadb.cpp \
    userbookdbmgr.cpp \
    userbookdb.cpp \
    pathmanage.cpp \
    mysqlite.cpp \
    myconfig.cpp \
    learnmgr.cpp \
    learnbase.cpp \
    myglobal.cpp \
    gaugedisplayer.cpp \
    bookedit.cpp \
    bcmgr.cpp \
    aboutdialog.cpp \
    addbookdialog.cpp \
    addrootdialog.cpp \
    analysisdialog.cpp \
    bookeditdialog.cpp \
    creatnewuserdialog.cpp \
    deletebookdialog.cpp \
    edititemdialog.cpp \
    editordialog.cpp \
    explaindialog.cpp \
    helpdialog.cpp \
    learnstartdialog.cpp \
    learnwordconfigdialog.cpp \
    learnworddialog.cpp \
    logindialog.cpp \
    optionsdialog.cpp \
    learngaugedisplayer.cpp \
    reviewalgorithm.cpp \
    findkeydialog.cpp \
    addnewrecorddialog.cpp \
    editkeydialog.cpp \
    SpeakTTS.cpp \
    SpeakGoogle.cpp \
    SpeakReal.cpp \
    SpeakMgr.cpp \
    DownloadControl/DownloadControl.cpp \
    DownloadControl/Download.cpp \
    AnsleDictDialog.cpp \
    AnsleDictConfigDialog.cpp \
    AnsleDictCode/CreatWordListDB.cpp \
    AnsleDictCode/AnsleDictSpeakGoogle.cpp \
    AnsleDictCode/AnsleDictSpeakMgr.cpp \
    AnsleDictCode/AnsleDictSpeakTTS.cpp \
    AnsleDictCode/PathMgr.cpp \
    SpeakDialog.cpp \
    QtSpeech.cpp \
    AnsleDictDialog.cpp \
    AnsleDictConfigFile.cpp

HEADERS  += mainwindow.h \
    userdatadb.h \
    userbookdbmgr.h \
    userbookdb.h \
    pathmanage.h \
    mysqlite.h \
    myconfig.h \
    learnmgr.h \
    learnbase.h \
    myglobal.h \
    gaugedisplayer.h \
    bookedit.h \
    bcmgr.h \
    usermanage.h \
    aboutdialog.h \
    addbookdialog.h \
    addrootdialog.h \
    analysisdialog.h \
    bookeditdialog.h \
    creatnewuserdialog.h \
    deletebookdialog.h \
    edititemdialog.h \
    editordialog.h \
    explaindialog.h \
    helpdialog.h \
    learnstartdialog.h \
    learnwordconfigdialog.h \
    learnworddialog.h \
    logindialog.h \
    optionsdialog.h \
    learngaugedisplayer.h \
    reviewalgorithm.h \
    findkeydialog.h \
    addnewrecorddialog.h \
    editkeydialog.h \
    eSpeak/speak_lib.h \
    Thread/thread.h \
    SpeakTTS.h \
    SpeakGoogle.h \
    SpeakReal.h \
    SpeakMgr.h \
    DownloadControl/DownloadControl.h \
    DownloadControl/Download.h \
    AnsleDictDialog.h \
    AnsleDictConfigDialog.h \
    AnsleDictCode/CreatWordListDB.h \
    AnsleDictCode/AnsleDictSpeakGoogle.h \
    AnsleDictCode/AnsleDictSpeakMgr.h \
    AnsleDictCode/AnsleDictSpeakTTS.h \
    AnsleDictCode/PathMgr.h \
    SpeakDialog.h \
    QtSpeech.h \
    AnsleDictConfigFile.h

FORMS    += mainwindow.ui \
    aboutdialog.ui \
    addbookdialog.ui \
    addrootdialog.ui \
    analysisdialog.ui \
    bookeditdialog.ui \
    creatnewuserdialog.ui \
    deletebookdialog.ui \
    edititemdialog.ui \
    editordialog.ui \
    explaindialog.ui \
    helpdialog.ui \
    learnstartdialog.ui \
    learnwordconfigdialog.ui \
    learnworddialog.ui \
    logindialog.ui \
    optionsdialog.ui \
    findkeydialog.ui \
    addnewrecorddialog.ui \
    editkeydialog.ui \
    AnsleDictDialog.ui \
    AnsleDictConfigDialog.ui \
    SpeakDialog.ui

UI_DIR = ./ui
MOC_DIR = TEMP/moc
RCC_DIR = TEMP/rcc
OBJECTS_DIR = TEMP/obj

RESOURCES += \
    rc.qrc


win32: LIBS += -L$$PWD/eSpeak/ -lespeak_lib

INCLUDEPATH += $$PWD/eSpeak
DEPENDPATH += $$PWD/eSpeak

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/QSint/lib/ -lQSCharts
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/QSint/lib/ -lQSChartsd

INCLUDEPATH += $$PWD/QSint/include
DEPENDPATH += $$PWD/QSint/include

OTHER_FILES += \
    MyApp.rc
RC_FILE = MyApp.rc
