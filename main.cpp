#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::addLibraryPath("./plugins");

    QTextCodec *codec = QTextCodec::codecForName("System");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
//    QTranslator qtTranslator;
//    qtTranslator.load("DeutschWortRezitieren_english.qm");
//    a.installTranslator(&qtTranslator);

    MainWindow w;
    w.show();
    return a.exec();
}
